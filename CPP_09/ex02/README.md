# Ford-Johnson merge-insertion sort

The FJ algorithm sorts a set of keys of size N by exploring **binary insertion** maximally according to the following three steps :

1.The given input set of keys is divided into [n/2] subsets of two keys that are ordered as pairs, whose greater and smaller keys are denoted as **max** and **pend** elements. The remaining key, in the case N is odd, is considered a **pend** element.

2. Recursively, order the set of [n/2] **max** elements.

3. Insertig **pend** elements in the ordered list consisting
of the **max** elements, that is called the **main chain**.
The **pend** elements are inserted in the **main chain** by
exploring binary insertion maximally.
