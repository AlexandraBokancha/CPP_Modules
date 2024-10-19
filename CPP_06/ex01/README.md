**uinptr_t** is an unsigned integer type
that is capable of storing a data pointer
of any object in C++, ensuring **portability** and
**precision**;

Practices for using uinptr_t:

1. Use for Address Manipulation Only;

2. Avoid Unnecessary Casts;

3. Understand Platform Specifics:
    The size of **uinptr_t** is platform-dependent.
    Be careful, especially when targeting 32-bit and
    64-bit environments.

more about the subject : https://blog.feabhas.com/2024/02/navigating-memory-in-c-a-guide-to-using-stduintptr_t-for-address-handling/#Understanding_std_uintptr_t_The_Key_to_Portable_Address_Manipulation