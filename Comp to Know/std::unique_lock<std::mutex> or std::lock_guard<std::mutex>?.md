# std::unique_lock or std::lock_guard?

> The difference is that you can lock and unlock a std::unique_lock. std::lock_guard will be locked only once on construction and unlocked on destruction.

So for use case B you definitely need a std::unique_lock for the condition variable. In case A it depends whether you need to relock the guard.

std::unique_lock has other features that allow it to e.g.: be constructed without locking the mutex immediately but to build the RAII wrapper (see here).

std::lock_guard also provides a convenient RAII wrapper, but cannot lock multiple mutexes safely. It can be used when you need a wrapper for a limited scope, e.g.: a member function:

    class MyClass{
        std::mutex my_mutex;
        void member_foo() {
            std::lock_guard<mutex_type> lock(this->my_mutex);            
            /*
             block of code which needs mutual exclusion (e.g. open the same 
             file in multiple threads).
            */
            //mutex is automatically released when lock goes out of scope           
    };
To clarify a question by chmike, by default std::lock_guard and std::unique_lock are the same. So in the above case, you could replace std::lock_guard with std::unique_lock. However, std::unique_lock might have a tad more overhead.

Note that these days one should use std::scoped_lock instead of std::lock_guard.
