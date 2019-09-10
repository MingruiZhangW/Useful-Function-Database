# static_cast   

> It can be used for any normal conversion between types, conversions that rely on static (compile-time) type information. This includes any casts between numeric types (for instance : from short to int or from int to float), casts of pointers and references up the hierarchy (upcasting).

```static_cast``` performs no run-time checks and hence no runtime overhead.
```
int a = 5, b = 2;
double result = static_cast<double>(a) /  b;
```
# dynamic_cast

> It can only be used with pointers and references to objects. It's almost exclusively used for handling polymorphism. It makes sure that the result of the type conversion is valid and complete object of the requested class.
```
class Base { };
class Derived : public Base { };
 
Base a, *ptr_a;
Derived b, *ptr_b;
 
ptr_a = dynamic_cast<Base *>(&b);  // Fine
ptr_b = dynamic_cast<Derived *>(&a);  // Fail
```
The first dynamic_cast statement will work because we cast from derived class to base. The second dynamic_cast statement will produce a compilation error because base class to derived conversion is not allowed with dynamic_cast unless the base class is polymorphic (a polymorphic type has at least one virtual function, declared or inherited).

- If a class is polymorphic then dynamic_cast will perform a special check during runtime.
```
class Base { virtual void dummy() {} }; // polymorphic class
class Derived : public Base { int a; }; // so is this
 
Base *ptr_a = new Derived{};
Base *ptr_b = new Base{};
 
Derived *ptr_c = nullptr;
Derived *ptr_d = nullptr;
 
ptr_c = dynamic_cast<Derived *>(ptr_a);  // Fine
ptr_d = dynamic_cast<Derived *>(ptr_b);  // ptr_d will be NULL
 
// Check if downcasting succeeded
if (ptr_c != nullptr) {
	// ptr_a actually points to a Derived object 
}
 
if (ptr_d != nullptr) {
    // ptr_b actually points to a Derived object 
}
```
When the dynamic_cast is performed,  ptr_a is pointing to a full object of class Derived, but the pointer ptr_b points to an object of class Base. This object is an incomplete object of class Derived; thus this cast will result in a null pointer !

### Important:

A null pointer is returned to indicate a failure while dealing with a pointer.

When a reference type conversion fails then there will be an exception thrown.

**NOTE: dynamic_cast have a significant runtime overhead.**

- In QT: https://stackoverflow.com/questions/43994584/what-is-qobject-cast

# reinterpret_cast

> It is used for casts that are not type-safe. It converts between types by reinterpreting the underlying bit pattern.

- Unlike static_cast, but like const_cast, the reinterpret_cast expression does not compile to any CPU instructions. It is purely a compiler directive which instructs the compiler to treat the sequence of bits (object representation) of expression as if it had the new_type (that you are casting to).

In short, you tell the compiler, believe me I know what am I doing.

```
class A { /* ... */ }; 
class B { /* ... */ }; 
A *a = new A{}; 
B *b = reinterpret_cast<B*>(a);  // Fine
 
const char* message = "hello"; 
int* data = reinterpret_cast<int*>(message);  // Fail
```

# const_cast

> The only way to cast away the constness of an object is to use const_cast. But this is not the end of story,

**Important:**

- const_cast can be safely used to remove constness from a reference or a pointer used to access a non-const object.
```
int a = 5; // NOTE: non-const object
const int* pA = &a;
*pA = 10; // compiler error, pA is a pointer to const int 
int* pX = const_cast<int*>(pA); // cast away constness
*pX = 10 // fine and a is now 10
```
But if your actual object is declared const, that constness can never be removed. Modifying a const object through a non-const access path results in undefined behavior.
```
const int a = 5; // NOTE: const object
const int* pA = &a;
*pA = 10; // compiler error, pA is a pointer to const int 
int* pX = const_cast<int*>(pA); // cast away constness 
*pX = 10 // Free ticket to a long journey of UNDEFINED BEHAVIOR
```
The const_cast can not be used to cast to other data-types, as it is possible with the other casts.
```
int* a = nullptr;
const char* ptr = "Hello";
a = const_cast<int*>(ptr); // Fail
a = reinterpret_cast<int*>(ptr); // Fail, reinterpret_cast can't cast away const qualifiers
a = reinterpret_cast<int*>(const_cast<char*>(ptr)); // Fine, as long as you know why you are doing it
```
