**class templates**

Class templates allow you to create one general version of a class without having to duplicate code to handle multiple data types.

Class template objects are defined like objects of ordinary classes, with one small difference:
the data type you wish to pass to the type parameter must be specified. Placing the data type
name inside angled brackets immediately following the class name does this. For example,
the following statements create two SimpleVector objects: intTable and doubleTable.

SimpleVector<int> intTable(10);
SimpleVector<double> doubleTable(10);