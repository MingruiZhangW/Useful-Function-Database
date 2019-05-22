
Constant pointer vs Pointer to constant [duplicate]

const int* ptr; 
declares ptr a pointer to const int type. 
You can modify ptr itself but the object pointed to by ptr shall not be modified.

const int a = 10;
const int* ptr = &a;  
*ptr = 5; // wrong
ptr++;    // right  
While

int * const ptr;  
declares ptr a const pointer to int type. You are not allowed to modify ptr but the object pointed to by ptr.

int a = 10;
int *const ptr = &a;  
*ptr = 5; // right
ptr++;    // wrong
Generally I would prefer the declaration like this which make it easy to read and understand (read from right to left):

int const  *ptr; // ptr is a pointer to constant int 
int *const ptr;  // ptr is a constant pointer to int
