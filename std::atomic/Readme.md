# class template <atomic>
# std::atomic
 
The main characteristic of atomic objects is that access to this contained value from different threads cannot cause data races (i.e., doing that is well-defined behavior, with accesses properly sequenced). Generally, for all other objects, the possibility of causing a data race for accessing the same object concurrently qualifies the operation as undefined behavior.

Additionally, atomic objects have the ability to synchronize access to other non-atomic objects in their threads by specifying different memory orders.

    typedef enum memory_order {
        memory_order_relaxed,   // relaxed
        memory_order_consume,   // consume
        memory_order_acquire,   // acquire
        memory_order_release,   // release
        memory_order_acq_rel,   // acquire/release
        memory_order_seq_cst    // sequentially consistent
    } memory_order;

- memory_order_relaxed
The operation is ordered to happen atomically at some point.
This is the loosest memory order, providing no guarantees on how memory accesses in different threads are ordered with respect to the atomic operation.
- memory_order_consume
[Applies to loading operations]
The operation is ordered to happen once all accesses to memory in the releasing thread that carry a dependency on the releasing operation (and that have visible side effects on the loading thread) have happened.
- memory_order_acquire
[Applies to loading operations]
The operation is ordered to happen once all accesses to memory in the releasing thread (that have visible side effects on the loading thread) have happened.
- memory_order_release
[Applies to storing operations]
The operation is ordered to happen before a consume or acquire operation, serving as a synchronization point for other accesses to memory that may have visible side effects on the loading thread.
- memory_order_acq_rel
[Applies to loading/storing operations]
The operation loads acquiring and stores releasing (as defined above for memory_order_acquire and memory_order_release).
- memory_order_seq_cst
The operation is ordered in a sequentially consistent manner: All operations using this memory order are ordered to happen once all accesses to memory that may have visible side effects on the other threads involved have already happened.
This is the strictest memory order, guaranteeing the least unexpected side effects between thread interactions though the non-atomic memory accesses.
For consume and acquire loads, sequentially consistent store operations are considered releasing operations.

http://www.cplusplus.com/reference/atomic/atomic/
# std::atomic_flag
http://www.cplusplus.com/reference/atomic/atomic_flag/test_and_set/

     // atomic::load/store example
     #include <iostream>       // std::cout
     #include <atomic>         // std::atomic, std::memory_order_relaxed
     #include <thread>         // std::thread

     std::atomic<int> foo (0);

     void set_foo(int x) {
       foo.store(x,std::memory_order_relaxed);     // set value atomically
     }

     void print_foo() {
       int x;
       do {
         x = foo.load(std::memory_order_relaxed);  // get value atomically
       } while (x==0);
       std::cout << "foo: " << x << '\n';
     }

     int main ()
     {
       std::thread first (print_foo);
       std::thread second (set_foo,10);
       first.join();
       second.join();
       return 0;
     }
     
store
Modify contained value (public member function )
load
Read contained value (public member function )
