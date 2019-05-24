# class template
 - <atomic>
# std::atomic
template <class T> struct atomic;
Atomic
Objects of atomic types contain a value of a particular type (T).

The main characteristic of atomic objects is that access to this contained value from different threads cannot cause data races (i.e., doing that is well-defined behavior, with accesses properly sequenced). Generally, for all other objects, the possibility of causing a data race for accessing the same object concurrently qualifies the operation as undefined behavior.

Additionally, atomic objects have the ability to synchronize access to other non-atomic objects in their threads by specifying different memory orders.
