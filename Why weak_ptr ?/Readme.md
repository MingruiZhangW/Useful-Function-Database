# When is std::weak_ptr useful?

std::weak_ptr is a very good way to solve the dangling pointer problem. By just using raw pointers it is impossible to know if the referenced data has been deallocated or not. Instead, by letting a std::shared_ptr manage the data, and supplying std::weak_ptr to users of the data, the users can check validity of the data by calling expired() or lock().

>You could not do this with std::shared_ptr alone, because all std::shared_ptr instances share the ownership of the data which is not removed before all instances of std::shared_ptr are removed. Here is an example of how to check for dangling pointer using lock():

    #include <iostream>
    #include <memory>

    int main()
    {
        // OLD, problem with dangling pointer
        // PROBLEM: ref will point to undefined data!

        int* ptr = new int(10);
        int* ref = ptr;
        delete ptr;

        // NEW
        // SOLUTION: check expired() or lock() to determine if pointer is valid

        // empty definition
        std::shared_ptr<int> sptr;

        // takes ownership of pointer
        sptr.reset(new int);
        *sptr = 10;

        // get pointer to data without taking ownership
        std::weak_ptr<int> weak1 = sptr;

        // deletes managed object, acquires new pointer
        sptr.reset(new int);
        *sptr = 5;

        // get pointer to new data without taking ownership
        std::weak_ptr<int> weak2 = sptr;

        // weak1 is expired!
        if(auto tmp = weak1.lock())
            std::cout << *tmp << '\n';
        else
            std::cout << "weak1 is expired\n";

        // weak2 points to new data (5)
        if(auto tmp = weak2.lock())
            std::cout << *tmp << '\n';
        else
            std::cout << "weak2 is expired\n";
    }
