# Difference Between Const and Constexpr

- https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=vs-2019
- https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const

> A constexpr function or constructor is implicitly inline. <br>
> A constexpr function must accept and return only literal types.

runtime/compile time

    #include <iostream>

    using namespace std;

    // Pass by value
    constexpr float exp(float x, int n)
    {
        return n == 0 ? 1 :
            n % 2 == 0 ? exp(x * x, n / 2) :
            exp(x * x, (n - 1) / 2) * x;
    };

    // Pass by reference
    constexpr float exp2(const float& x, const int& n)
    {
        return n == 0 ? 1 :
            n % 2 == 0 ? exp2(x * x, n / 2) :
            exp2(x * x, (n - 1) / 2) * x;
    };

    // Compile-time computation of array length
    template<typename T, int N>
    constexpr int length(const T(&ary)[N])
    {
        return N;
    }

    // Recursive constexpr function
    constexpr int fac(int n)
    {
        return n == 1 ? 1 : n*fac(n - 1);
    }

    // User-defined type
    class Foo
    {
    public:
        constexpr explicit Foo(int i) : _i(i) {}
        constexpr int GetValue()
        {
            return _i;
        }
    private:
        int _i;
    };

    int main()
    {
        // foo is const:
        constexpr Foo foo(5);
        // foo = Foo(6); //Error!

        // Compile time:
        constexpr float x = exp(5, 3);
        constexpr float y { exp(2, 5) };
        constexpr int val = foo.GetValue();
        constexpr int f5 = fac(5);
        const int nums[] { 1, 2, 3, 4 };
        const int nums2[length(nums) * 2] { 1, 2, 3, 4, 5, 6, 7, 8 };

        // Run time:
        cout << "The value of foo is " << foo.GetValue() << endl;

    }

### Literal types

A literal type is one whose layout can be determined at compile time. The following are the literal types:

void<br>
scalar types<br>
references<br>
Arrays of void, scalar types or references<br>
A class that has a trivial destructor, and one or more constexpr constructors that are not move or copy constructors. Additionally, all its non-static data members and base classes must be literal types and not volatile.
