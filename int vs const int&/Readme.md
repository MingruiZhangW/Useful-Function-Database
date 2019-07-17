# int vs const int&
https://stackoverflow.com/questions/4705593/int-vs-const-int

In C++ it's very common what I consider an anti-pattern that uses const T& like a smart way of just saying T when dealing with parameters. However a value and a reference (no matter if const or not) are two completely different things and always and blindly using references instead of values can lead to subtle bugs.

> The reason is that when dealing with references you must consider two issues that are not present with values: lifetime and aliasing.

Just as an example one place where this anti-pattern is applied is the standard library itself, where std::vector<T>::push_back accepts as parameter a const T& instead of a value and this can bite back for example in code like:

    std::vector<T> v;
    ...
    if (v.size())
        v.push_back(v[0]); // Add first element also as last element
This code is a ticking bomb because std::vector::push_back wants a const reference but doing the push_back may require a reallocation and if that happens means that after the reallocation the reference received would not be valid any more (lifetime issue) and you enter the Undefined Behaviour realm.

Aliasing issues are also a source of subtle problems if const references are used instead of values. I've been bitten for example by code of this kind:

    struct P2d
    { 
        double x, y;
        P2d(double x, double y) : x(x), y(y) {}
        P2d& operator+=(const P2d& p) { x+=p.x; y+=p.y; return *this; }
        P2d& operator-=(const P2d& p) { x-=p.x; y-=p.y; return *this; }
    };

    struct Rect
    {
        P2d tl, br;
        Rect(const P2d& tl, const P2d& br) : tl(tl), bt(br) {}
        Rect& operator+=(const P2d& p) { tl+=p; br+=p; return *this; }
        Rect& operator-=(const P2d& p) { tl-=p; br-=p; return *this; }
};
The code seems at a first glance pretty safe, P2d is a bidimensional point, Rect is a rectangle and adding/subtracting a point means translating the rectangle.

> If however to translate the rectangle back in the origin you write myrect -= myrect.tl; 
the code will not work because the translation operator has been defined accepting a reference that (in that case) is referencing a member of same instance.

This means that after updating the topleft with tl -= p; the topleft will be (0, 0) as it should but also p will become at the same time (0, 0) because p is just a reference to the top-left member and so the update of bottom-right corner will not work because it will translate it by (0, 0) hence doing basically nothing.

Please don't be fooled into thinking that a const reference is like a value because of the word const. That word exists only to give you compile errors if you try to change the referenced object using that reference, but doesn't mean that the referenced object is constant. More specifically the object referenced by a const ref can change (e.g. because of aliasing) and can even get out of existence while you are using it (lifetime issue).

In const T& the word const expresses a property of the reference, not of the referenced object: it's the property that makes impossible to use it to change the object. Probably readonly would have been a better name as const has IMO the psychological effect of pushing the idea that the object is going to be constant while you use the reference.

You can of course get impressive speedups by using references instead of copying the values, especially for big classes. But you should always think about aliasing and lifetime issues when using references because under the cover they're just pointers to other data. For "native" data types (ints, doubles, pointers) references however are actually going to be slower than values and there's nothing to gain in using them instead of values.

Also a const reference will always mean problems for the optimizer as the compiler is forced to be paranoid and every time any unknown code is executed it must assume that all referenced objects may have now a different value (const for a reference means absolutely NOTHING for the optimizer; that word is there only to help programmers - I'm personally not so sure it's such a big help, but that's another story).
