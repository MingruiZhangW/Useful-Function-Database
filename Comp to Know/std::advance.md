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
