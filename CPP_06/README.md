** additional rules of 42 for this module **

For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense

**casts in c++**


1. **type conversion**


int main(void){
    
    int a = 42; // reference value
    double b = a; // implicit conversion cast 
    double c = (double) a; // excplicit conversion cast

}

2. **type reinterpretation**

int main(void){

    float a = 420.042f; // reference value
    void *b = &a; // implicit  reinterpretation
    void *c = (void *) &a; explicit reinterpretation
}