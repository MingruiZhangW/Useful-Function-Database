# std::advance
> **Increments given iterator it by n elements.**

    #include <iostream>
    #include <iterator>
    #include <vector>
    int main() 
    {
        std::vector<int> v{ 3, 1, 4 };

        auto vi = v.begin();

        std::advance(vi, 2);

        std::cout << *vi << '\n';
    }

Output:

    4

### Notes
The behavior is undefined if the specified sequence of increments or decrements would require that a non-incrementable iterator (such as the past-the-end iterator) is incremented, or that a non-decrementable iterator (such as the front iterator or the singular iterator) is decremented.

https://en.cppreference.com/w/cpp/iterator/advance
