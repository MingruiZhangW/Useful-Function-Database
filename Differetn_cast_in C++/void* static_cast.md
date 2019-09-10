### The C++ standard guarantees the following:

> static_casting a pointer to and from void* preserves the address. That is, in the following, a, b and c all point to the same address:
```
int* a = new int();
void* b = static_cast<void*>(a);
int* c = static_cast<int*>(b);
```
reinterpret_cast only guarantees that if you cast a pointer to a different type, and then reinterpret_cast it back to the original type, you get the original value. So in the following:
```
int* a = new int();
void* b = reinterpret_cast<void*>(a);
int* c = reinterpret_cast<int*>(b);
a and c contain the same value, but the value of b is unspecified. (in practice it will typically contain the same address as a and c, but that's not specified in the standard, and it may not be true on machines with more complex memory systems.)
```
For casting to and from void*, static_cast should be preferred.
