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
    // initialize of a double pointer (a pointer to a char pointer)
    char** newArgv = new char* [newArgc];
    for (int i = 0; i < argc; i++) {
        // deference once
        newArgv[i] = argv[i];
    }
    newArgv[argc] = ARG_DISABLE_WEB_SECURITY;
    newArgv[argc + 1] = nullptr;
```
![alt text][image_double_pointer]
[image_double_pointer]: https://www.geeksforgeeks.org/wp-content/uploads/Double-Pointer-in-C.png "Logo Title Text 2"
