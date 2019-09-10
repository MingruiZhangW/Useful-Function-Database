# What static_cast<> is actually doing

### Introduction
> Most programmers learn C before C++, and get used to C style casting. When writing C++, sometimes we may be confused about when to use static_cast<> and when to use reinterpret_cast<>. In this article, I will illustrate what static_cast<> actually does, and will show some cases that will lead to errors.

**Generic Types**
```
float f = 12.3;
float* pf = &f;

// static cast<>
// OK, n = 12
int n = static_cast<int>(f);
// Error, types pointed to are unrelated
//int* pn = static_cast<int*>(pf);
// OK
void* pv = static_cast<void*>(pf);
// OK, but *pn2 is rubbish
int* pn2 = static_cast<int*>(pv);

// reinterpret_cast<>
// Error, the compiler know you should
// call static_cast<>
//int i = reinterpret_cast<int>(f);
// OK, but *pn is actually rubbish, same as *pn2
int* pi = reinterpret_cast<int*>(pf);
```
In short, static_cast<> will try to convert, e.g., float-to-integer, while reinterpret_cast<> simply changes the compiler's mind to reconsider that object as another type.

**Pointer Types**<br>
Pointer casting is a bit complicated, we will use the following classes for the rest of the the article:

```
class CBaseX
{
public:
    int x;
    CBaseX() { x = 10; }
    void foo() { printf("CBaseX::foo() x=%d\n", x); }
};

class CBaseY
{
public:
    int y;
    int* py;
    CBaseY() { y = 20; py = &y; }
    void bar() { printf("CBaseY::bar() y=%d, *py=%d\n", y, *py); }
};

class CDerived : public CBaseX, public CBaseY
{
public:
    int z;
};
```

- Case 1: Casting between unrelated classes
```
// Convert between CBaseX* and CBaseY*
CBaseX* pX = new CBaseX();
// Error, types pointed to are unrelated
// CBaseY* pY1 = static_cast<CBaseY*>(pX);
// Compile OK, but pY2 is not CBaseX
CBaseY* pY2 = reinterpret_cast<CBaseY*>(pX);
// System crash!!
// pY2->bar();
```
As we learnt in the generic types example, static_cast<> will fail if you try to cast an object to another unrelated class, while reinterpret_cast<> will always succeed by "cheating" the compiler to believe that the object is really that unrelated class.

- Case 2: Casting to related classes
```
CDerived* pD = new CDerived();
printf("CDerived* pD = %x\n", (int)pD);

// static_cast<> CDerived* -> CBaseY* -> CDerived*
// OK, implicit static_cast<> casting
CBaseY* pY1 = pD;
printf("CBaseY* pY1 = %x\n", (int)pY1);
// OK, now pD1 = pD
CDerived* pD1 = static_cast<CDerived*>(pY1);
printf("CDerived* pD1 = %x\n", (int)pD1);

// reinterpret_cast
// OK, but pY2 is not CBaseY*
CBaseY* pY2 = reinterpret_cast<CBaseY*>(pD);
printf("CBaseY* pY2 = %x\n", (int)pY2);
 
// unrelated static_cast<>
CBaseY* pY3 = new CBaseY();
printf("CBaseY* pY3 = %x\n", (int)pY3);
// OK, even pY3 is just a "new CBaseY()"
CDerived* pD3 = static_cast<CDerived*>(pY3);
printf("CDerived* pD3 = %x\n", (int)pD3);
```
---------------------- output ---------------------------
```
CDerived* pD = 392fb8
CBaseY* pY1 = 392fbc
CDerived* pD1 = 392fb8
CBaseY* pY2 = 392fb8
CBaseY* pY3 = 390ff0
CDerived* pD3 = 390fec
```
Noted that when static_cast<>-ing CDerived* to CBaseY* (line 5), the result is CDerived* offset by 4. To know what static_cast<> is actually doing, we have to take a look at the memory layout of CDerived.

**Memory Layout of CDerived**<br>
Class Memory Layout

> As shown in the diagram, CDerived's memory layout contains two objects, CBaseX and CBaseY, and the compiler knows this. Therefore, when you cast CDerived* to CBaseY*, it adds the pointer by 4, and when you cast CBaseY to CDerived, it subtracts the pointer by 4. However, you can do this even if it is not a CDerived (line 14-18) [1].

Of course, the problem happens only if you have multiple inheritance. static_cast<> and reinterpret_cast<> make no different if you are casting CDerived to CBaseX.

- Case 3: Casting back and forth between void*
Because any pointer can be cast to void*, and void* can be cast back to any pointer (true for both static_cast<> and reinterpret_cast<>), errors may occur if not handled carefully.
```
CDerived* pD = new CDerived();
printf("CDerived* pD = %x\n", (int)pD);

CBaseY* pY = pD;                // OK, pY = pD + 4
printf("CBaseY* pY = %x\n", (int)pY);

void* pV1 = pY;                    // OK, pV = pY
printf("void* pV1 = %x\n", (int)pV1);

// pD2 = pY, but we expect pD2 = pY - 4
CDerived* pD2 = static_cast<CDerived*>(pV1);
printf("CDerived* pD2 = %x\n", (int)pD2);
// System crash
// pD2->bar();
```
---------------------- output ---------------------------
```
CDerived* pD = 392fb8
CBaseY* pY = 392fbc
void* pV1 = 392fbc
CDerived* pD2 = 392fbc
```
Once we have cast the pointer to void*, we can't cast it back to the original class easily. In the above example, the only way to get back a CDerived* from a void* is to cast it to a CBaseY* and then to CDerived*. But if we are not sure whether it is CBaseY* or CDerived*, then we have to use dynamic_cast<> or typeid [2].

Footnote
dynamic_cast<>, on the other hand, can guard against casting a generic CBaseY* to CDerived*.
dynamic_cast<> requires the classes to be "polymorphic", i.e., contains "virtual" function, and hence can't be void*.
