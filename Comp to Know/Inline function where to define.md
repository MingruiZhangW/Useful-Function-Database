# How Inline member function should be declared?

You need to put function definition into the header then. 
The simplest way to hint the compiler to inline is to include method body in the class declaration like:

    class NeedleUSsim
    {
      // ...
      int GetTplLSize() const { return sampleDim[1]; }
      // ...
    };
    
or, if you insist on separate declaration and definition:

    class NeedleUSsim
    {
      // ...
      int GetTplLSize() const;
      // ...
    };

    inline int NeedleUSsim::GetTplLSize() const
    { return sampleDim[1]; }
    
The definition has to be visible in each translation unit that uses that method.

**Which means, usually the definition of inline functions should be in the same file as the definition of the class**
