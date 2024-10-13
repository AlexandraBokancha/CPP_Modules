Shallow & Deep Copies

![alt text](image.png)

**Shallow Copy:**

- stores the references of objects to the original memory adress;

- reflects changes made to the new/copied object in the original object;

- stores the copy of the original object and point the references to the objects;

- it's faster;

**Deep Copy:**

- if the variables of an object have been dynamically allocated, it is required to a Deep Copy;

- it provides isolation between objects; 

- it allocates similiar memory resources with the
    same value to the object;

- stores copies of the object's value;

- doesn't reflect changes made to the new/copied object in the original object;

- stores the copy of the original object and recursively copies the objects as well;

- is slower;


more about this subject: https://medium.com/@burakroccia/understanding-copying-in-c-shallow-vs-deep-copying-demystified-d6495fc1eb36