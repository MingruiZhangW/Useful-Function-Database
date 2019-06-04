# const_cast in C++ | Type Casting operators

C++ supports following 4 types of casting operators:
1. const_cast
2. static_cast
3. dynamic_cast
4. reinterpret_cast

1. const_cast
const_cast is used to cast away the constness of variables. Following are some interesting facts about const_cast.

> 1) const_cast can be used to change non-const class members inside a const member function. Consider the following code snippet. Inside const member function fun(), ‘this’ is treated by the compiler as ‘const student* const this’, i.e. ‘this’ is a constant pointer to a constant object, thus compiler doesn’t allow to change the data members through ‘this’ pointer. const_cast changes the type of ‘this’ pointer to ‘student* const this’.

    #include <iostream> 
    using namespace std; 

    class student 
    { 
    private: 
        int roll; 
    public: 
        // constructor 
        student(int r):roll(r) {} 

        // A const function that changes roll with the help of const_cast 
        void fun() const
        { 
            ( const_cast <student*> (this) )->roll = 5; 
        } 

        int getRoll()  { return roll; } 
    }; 

    int main(void) 
    { 
        student s(3); 
        cout << "Old roll number: " << s.getRoll() << endl; 

        s.fun(); 

        cout << "New roll number: " << s.getRoll() << endl; 

        return 0; 
    } 
    
Output:
Old roll number: 3
New roll number: 5


> 2) const_cast can be used to pass const data to a function that doesn’t receive const. For example, in the following program fun() receives a normal pointer, but a pointer to a const can be passed with the help of const_cast.

    #include <iostream> 
    using namespace std; 

    int fun(int* ptr) 
    { 
        return (*ptr + 10); 
    } 

    int main(void) 
    { 
        const int val = 10; 
        const int *ptr = &val; 
        int *ptr1 = const_cast <int *>(ptr); 
        cout << fun(ptr1); 
        return 0; 
    } 
    
Output:

20


> 3) It is undefined behavior to modify a value which is initially declared as const. Consider the following program. The output of the program is undefined. The variable ‘val’ is a const variable and the call ‘fun(ptr1)’ tries to modify ‘val’ using const_cast.

    #include <iostream> 
    using namespace std; 

    int fun(int* ptr) 
    { 
        *ptr = *ptr + 10; 
        return (*ptr); 
    } 

    int main(void) 
    { 
        const int val = 10; 
        const int *ptr = &val; 
        int *ptr1 = const_cast <int *>(ptr); 
        fun(ptr1); 
        cout << val; 
        return 0; 
    } 
Output:

Undefined Behavior 
 
It it fine to modify a value which is not initially declared as const. For example, in the above program, if we remove const from declaration of val, the program will produce 20 as output.

    #include <iostream> 
    using namespace std; 

    int fun(int* ptr) 
    { 
        *ptr = *ptr + 10; 
        return (*ptr); 
    } 

    int main(void) 
    { 
        int val = 10; 
        const int *ptr = &val; 
        int *ptr1 = const_cast <int *>(ptr); 
        fun(ptr1); 
        cout << val; 
        return 0; 
    } 


> 4) const_cast is considered safer than simple type casting. It’safer in the sense that the casting won’t happen if the type of cast is not same as original object. For example, the following program fails in compilation because ‘int *’ is being typecasted to ‘char *’

    #include <iostream> 
    using namespace std; 

    int main(void) 
    { 
        int a1 = 40; 
        const int* b1 = &a1; 
        char* c1 = const_cast <char *> (b1); // compiler error 
        *c1 = 'A'; 
        return 0; 
    } 
output:

prog.cpp: In function ‘int main()’:
prog.cpp:8: error: invalid const_cast from type 'const int*' to type 'char*'


> 5) const_cast can also be used to cast away volatile attribute. For example, in the following program, the typeid of b1 is PVKi (pointer to a volatile and constant integer) and typeid of c1 is Pi (Pointer to integer)

    #include <iostream> 
    #include <typeinfo> 
    using namespace std; 

    int main(void) 
    { 
        int a1 = 40; 
        const volatile int* b1 = &a1; 
        cout << "typeid of b1 " << typeid(b1).name() << '\n'; 
        int* c1 = const_cast <int *> (b1); 
        cout << "typeid of c1 " << typeid(c1).name() << '\n'; 
        return 0; 
    } 
Output:

typeid of b1 PVKi
typeid of c1 Pi
