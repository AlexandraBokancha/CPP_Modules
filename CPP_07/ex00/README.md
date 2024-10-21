**template functions**

A function template is a “generic” function that can work with any data type. 
When the compiler encounters a call to the function,
it generates code to handle the specific data type(s) used in the call.

If the only difference between two functions is a data type, it is more convenient to write
a function template than an overloaded function. Function templates allow you to write a single
function definition that works with many different data types, instead of having to write a separate
function for each data type used.

Always remember a class object passed to a function template 
**must support all the operations the function will perform on the object**. 
For instance, if the function performs a comparison on the object (with >, <, ==,
or another relational operator), those operators must be overloaded by the class object.

Function templates may be **overloaded**. As with regular functions, function templates are
overloaded by having **different parameter lists**.