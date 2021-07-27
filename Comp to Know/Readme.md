# Comp to Know

[C++ 20](https://oleksandrkvl.github.io/2021/04/02/cpp-20-overview.html)

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
> **Type traits in modern C++**
- [Type traits are a clever technique used in C++ template metaprogramming that gives you the ability to inspect and transform the properties of types.](https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp)<br>
> Why emplace_back is faster than push_back?
- [Why emplace_back is faster than push_back?](https://stackoverflow.com/questions/23717151/why-emplace-back-is-faster-than-push-back)<br>
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

# Forward declaration

In some object-oriented languages like C++ and Objective-C, it is sometimes necessary to forward-declare classes. <br>
This is done in situations when it is necessary to know that the name of the class is a type, but where it is unnecessary to know the structure.

In C++, classes and structs can be forward-declared like this:

```
class MyClass;
struct MyStruct;
```

In C++, classes can be forward-declared if you only need to use the pointer-to-that-class type (since all object pointers are the same size, and this is what the compiler cares about). This is especially useful inside class definitions, e.g. if a class contains a member that is a pointer (or a reference) to another class.

Forward-declaration is used to avoid unnecessary coupling which help reducing compilation time by reducing the number of header inclusion. This has a triple advantage:

- reduce the number of files opened by #include (hence the number of operating system calls)
- reducing the volume of the pre-processed files (as the header is not included)
- reducing recompilation impact when the forward declared class is modified.

https://stackoverflow.com/a/1280969
```
Forward declaration of enums is possible since C++11.
Previously, the reason enum types couldn't be forward declared was because the size of the enumeration depended on its contents.
As long as the size of the enumeration is specified by the application, it can be forward declared:

enum Enum1;                     // Illegal in C++ and C++0x; no size is explicitly specified.
enum Enum2 : unsigned int;      // Legal in C++0x.
```

https://stackoverflow.com/a/45852594

```
You can forward-declare enum in C++ starting from C++11. It's called "opaque declaration" rather than "forward declaration"
because technically it results in a bit different effect: the size of the enum is known after its opaque declaration,
while with the forward-declared types that's not the case.
```

# C++ functor
A functor is pretty much just a class which defines the operator(). That lets you create objects which "look like" a function:
```
// this is a functor
struct add_x {
  add_x(int val) : x(val) {}  // Constructor
  int operator()(int y) const { return x + y; }

private:
  int x;
};

// Now you can use it like this:
add_x add42(42); // create an instance of the functor class
int i = add42(8); // and "call" it
assert(i == 50); // and it added 42 to its argument

std::vector<int> in; // assume this contains a bunch of values)
std::vector<int> out(in.size());
// Pass a functor to std::transform, which calls the functor on every element 
// in the input sequence, and stores the result to the output sequence
std::transform(in.begin(), in.end(), out.begin(), add_x(1)); 
assert(out[i] == in[i] + 1); // for all i
```

https://stackoverflow.com/questions/356950/what-are-c-functors-and-their-uses

# Soft (symbolic) Link & Hard Link

https://medium.com/@673/a-hard-link-and-a-symbolic-link-what-is-the-difference-between-them-9f207654f2d9

### Hard links
A hard link is a link that connects many files with the same inode, so the same data block is shared with these files.
A change in the data of a file will reflect on the others. If the original file is deleted, the hard link still exists as long as there is a file linked to the inode.
- The hard link can be flexible and can be moved everywhere in the fixed file system, but it cannot cross or use in the different file system.
- The hard link can be used as a backup plan in the system because each file is the same. Therefore, if we lose a file, we still have the others.
- The hard link cannot link to directories, only files.

### Symbolic links
A symbolic link, also known as a soft link or a symlink, is a link that acts as a pointer to another file or a shortcut of a file.
Each soft link file contains a different inode which links to the original file.
Just like hard links, changing the content of a soft link file will reflect on the others.
- The soft link can cross to other file systems because of the difference of inodes.
- If the symbolic file is deleted, the original still exists. However, if the original file is deleted, the symbolic file is not gonna work correctly because it links to the nonexistent file.
- The symbolic link can link to file or directory.
- You can use the command ls -l to which one is the symbolic link.

![image](https://user-images.githubusercontent.com/46324965/122941516-74c0e400-d343-11eb-8951-03b73b1061c3.png)

# Move Constructor Implicitly deletion
![image](https://user-images.githubusercontent.com/46324965/124510591-2a5b5080-dda2-11eb-85ef-6a7f902ab561.png)

# Copy elision
[Copy elision is an optimization implemented by most compilers to prevent extra (potentially expensive) copies in certain situations.](https://stackoverflow.com/questions/12953127/what-are-copy-elision-and-return-value-optimization)
