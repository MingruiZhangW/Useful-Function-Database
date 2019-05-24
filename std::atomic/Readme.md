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
