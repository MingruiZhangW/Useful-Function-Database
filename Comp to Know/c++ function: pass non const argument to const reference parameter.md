# c++ function: pass non const argument to const reference parameter

suppose I have a function which accept const reference argument pass,

    int func(const int &i)
    {
      /*    */
    }

    int main()
    {
      int j = 1;
      func(j); // pass non const argument to const reference
      j=2; // reassign j
    }
this code works fine.according to C++ primer, what this argument passing to this function is like follows,

int j=1;
const int &i = j;
in which i is a synonym(alias) of j,

my question is: if i is a synonym of j, and i is defined as const, is the code:

const int &i = j

redelcare a non const variable to const variable? why this expression is legal in c++?

# Answer:

The reference is const, not the object. It doesn't change the fact that the object is mutable, but you have one name for the object (j) through which you can modify it, and another name (i) through which you can't.

In the case of the const reference parameter, this means that main can modify the object (since it uses its name for it, j), whereas func can't modify the object so long as it only uses its name for it,  i. func could in principle modify the object by creating yet another reference or pointer to it with a const_cast, but don't.

# Unlike const int* x and int* const x, Reference only have const reference to an object

What is the difference between the arguments in:

    int foo1(const Fred &arg) {
    ...
    }
    and

    int foo2(Fred const &arg) {
    ...
    }
? I don't see this case covered in the parashift FAQ.

No difference as const is read right-to-left with respect to the &, so both represent a reference to an immutable Fred instance.

Fred& const would mean the reference itself is immutable, which is redundant; when dealing with const pointers both  Fred const* and Fred* const are valid but different.

It's a matter of style, but I prefer using const as a suffix since it can be applied consistently including const member functions.
