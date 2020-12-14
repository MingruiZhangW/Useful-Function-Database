# Comp to Know

### Basic:
- [C++ Order of Definition](https://stackoverflow.com/questions/2133250/x-does-not-name-a-type-error-in-c)<br>
- [Conditional Operator ?](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Conditional%20Operator%20%3F.md)<br>
- [Why do you need int myclass::getInteger() const&](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Const%26%20at%20last%20function.md)<br>
- [Bitwise Operator](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)<br>
- [Inline member function - Where to declare](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Inline%20function%20where%20to%20define.md)<br>
- [std::advance](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/std::advance.md)<br>
> - [String Manipulation](https://www.systutorials.com/131/convert-string-to-int-and-reverse/)<br>
- [Intialization Lists](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Initialization_LIsts.md)

### Intermediate:
- [Clear std::queue or other container](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Clear_std::queue.md)<br>
- [Const member functions](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Const%20member%20functions%20in%20C%2B%2B.md)<br>
- [Constant pointer vs Pointer to constant](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Constant_pointer_vs_pointer_to_const.md)<br>
- [Explicit Keyword](https://drive.google.com/open?id=1SgI5uVEQNXnk_8LhMSCDR5HVvoJ-GQxSfRc9mqVr_z0)<br>
- [Lambda Expression](https://drive.google.com/open?id=1vcgD99RtXAhN9gaVsGe7ueGiao-EZZYHd5ojxIqGGzs)<br>
- [Select() Usage](https://drive.google.com/open?id=1TI29UiUzfKljZbGLpQOlep2i0gTgtknrucborCGvq5k)<br>
- [Is it safe to delete a void pointer?](https://stackoverflow.com/questions/941832/is-it-safe-to-delete-a-void-pointer)<br>
- [C++ function: pass non const argument to const reference parameter](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/c%2B%2B%20function:%20pass%20non%20const%20argument%20to%20const%20reference%20parameter.md)<br>
- [std::unique_lock or std::lock_guard?](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/std::unique_lock%3Cstd::mutex%3E%20or%20std::lock_guard%3Cstd::mutex%3E%3F.md)<br>
- [How to iterate a Map](https://exceptionshub.com/c-loop-through-map.html)<br>
```
With C++17 ( and onwards ),
for( auto const& [key, val] : symbolTable )
{
    std::cout << key         // string (key)
              << ':'  
              << val        // string's value
              << std::endl ;
}
```

### Advanced:
> **Const Vs Constexpr**
- [Difference between const and constexpr](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/const_constexpr.md)<br>
> **Rvalue Reference**
- [RValue Reference](https://www.learncpp.com/cpp-tutorial/15-2-rvalue-references/)<br>
- [std::forward](http://www.cplusplus.com/reference/utility/forward/)<br>
- [std::move - convert args into r-value](https://www.learncpp.com/cpp-tutorial/15-4-stdmove/)<br>
> **push_back vs emplace_back**
- https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back <br>
Avoid push_back and prefer emplace_back instead (using move semanic, and For possible big maps, add
```reserve()```when you use a vector to avoid a lot of resize.
> **Different Cast In C++**
- [Casts](https://github.com/MingruiZhangW/Useful-Function-Database/tree/master/Differetn_cast_in%20C%2B%2B)<br>
> **Variadic Function**
- [Variadic](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Variadic%20function/Variadic_function.md)<br>
> **Std::tuple**
- [Tuple](https://en.cppreference.com/w/cpp/utility/tuple)<br>
> **Shared_ptr**
- [Shared_ptr and circular reference](https://www.learncpp.com/cpp-tutorial/15-7-circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/)<br>

> [Why Why emplace_back is faster than push_back?](https://stackoverflow.com/questions/23717151/why-emplace-back-is-faster-than-push-back)<br>
### CMake List
[Learn CMake](https://preshing.com/20170522/learn-cmakes-scripting-language-in-15-minutes/)<br>
[Use add_custom_target and add_custom_command](https://gist.github.com/baiwfg2/39881ba703e9c74e95366ed422641609)<br>
>[CMake & Visual Studio](https://cognitivewaves.wordpress.com/cmake-and-visual-studio/)<br>
[CMake Target Link issue(static lib cannot have additional dependencies)](https://gitlab.kitware.com/cmake/cmake/issues/16931)<br>
[CMake subdirectories](https://cgold.readthedocs.io/en/latest/tutorials/cmake-sources/subdirectories.html)<br>
[CMake subdirectory Parent Scope var](https://stackoverflow.com/questions/34028300/set-a-variable-in-current-scope-and-parent-scope)<br>
### Function Pointer
> **Best Function Pointer Explaination** [Learn C++ 7.8](https://www.learncpp.com/cpp-tutorial/78-function-pointers/)<br>
- [Member Function Function Pointer](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_74/rzarg/cplr034.htm)<br>

### Move Semantics - the whole thing
[Move Semantics](https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/)<br>

# OSI Model
- [OSI Model](https://www.cloudflare.com/learning/ddos/glossary/open-systems-interconnection-model-osi/)<br>
https://www.networkworld.com/article/3239677/the-osi-model-explained-how-to-understand-and-remember-the-7-layer-network-model.html

# Singleton
- [Singleton](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/Comp%20to%20Know/Singleton.md)

# How does SSH works
- [SSH](https://www.hostinger.com/tutorials/ssh-tutorial-how-does-ssh-work)<br>

# Linking static libraries to other static libraries
https://stackoverflow.com/questions/2157629/linking-static-libraries-to-other-static-libraries/2157735#2157735

# Double Pointer
```
    int argc;
    char* argv[];
    int newArgc = argc + 1 + 1;
    // initialize of a double pointer (a pointer to a array pointer - array of char pointers)
    // so when the double pointer deference, it is the pointer of the array which is the first element of the array
    // example int arr[5] = { 1, 2, 3, 4, 5 };
    // printf("%d", *arr); = 1
    char** newArgv = new char* [newArgc];
    for (int i = 0; i < argc; i++) {
        // deference once
        newArgv[i] = argv[i];
    }
    newArgv[argc] = ARG_DISABLE_WEB_SECURITY;
    newArgv[argc + 1] = nullptr;
```
![alt text](https://www.geeksforgeeks.org/wp-content/uploads/Double-Pointer-in-C.png "Logo Title Text 2")

```
#include <iostream>

int
main(int argc, char* argv[])
{
    for (size_t i = 0; i < argc; i++)
    {
        std::cout<< *(argv + i) << std::endl;
    }
    
}
```

# Const Member Function

https://www.geeksforgeeks.org/const-member-functions-c/
```
Const class object -> const member function
```

# Complied Vs Interpreted
https://guide.freecodecamp.org/computer-science/compiled-versus-interpreted-languages/


# void foo(int)&
```
class Test{
public: 
    // overloading
    void foo(int)&
    void foo(int)&&
    void foo(int)const;
}

// obj
Test obj;
obj.foo(1);

// Actually
//隐藏 this 参数
foo(*this, 1);
```
So, actual full declaration
```
void foo(Test&, int);
void foo(Test&&, int);
void foo(const Test&, int);

// Reminder
D(D&&) = default; // forces a move constructor anyway
```

# The Monostate Pattern
- [This is accomplished mostly by using static data members.](https://riptutorial.com/design-patterns/example/21458/the-monostate-pattern)

# size_t & ptrdiff_t

[size_t](https://prateekvjoshi.com/2015/01/03/why-do-we-need-size_t/#:~:text=It%20is%20an%20unsigned%20integer,are%20dealing%20with%20memory%20ranges.&text=One%20thing%20to%20note%20is%20that%20size_t%20is%20never%20negative.)
```
We can avoid all these performance issues by using size_t.
When we use the type “size_t”, we are actually using a typedef that’s an alias for some unsigned integer type.
That unsigned integer type can unsigned int, unsigned long, or unsigned long long.
When we use this, then the standard C implementation is free to choose the unsigned integer that’s big enough for our needs,
but not bigger than what’s needed, to represent the size of the largest possible object on our platform.
```

- ptrdiff_t is signed (because subtraction). size_t is unsigned (because length).

```
This is the signed integer type of the result of subtracting two pointers.
For example, with the declaration char *p1, *p2;, the expression p2 - p1 is of type ptrdiff_t.
This will probably be one of the standard signed integer types (short int, int or long int),
but might be a nonstandard type that exists only for this purpose.
```


# Mix C and C++
[What do I need to know when mixing C and C++ code?](https://isocpp.org/wiki/faq/mixing-c-and-cpp) <br>
[What is the effect of extern “C” in C++?](https://stackoverflow.com/questions/1041866/what-is-the-effect-of-extern-c-in-c)

# Concept
- [SFINAE](https://www.bfilipek.com/2016/02/notes-on-c-sfinae.html#:~:text=Substitution%20failure%20is%20not%20an,to%20describe%20related%20programming%20techniques.)
```
https://stackoverflow.com/questions/44025340/purpose-of-class-void-in-c
```
