# Explanation

Embedded devices are memory constraint hence require a sorting algorithm with a a particular set of characteristics. This include:

### 1. Sort in place
This is an important characteristic not because it not only saves on space but also does away with the need for dynamic memeory allocation (which should be avoided as much as possible in embedded systems).

### 2. Should not be recursive.
Recursive algorithms are not very safe especially for embedded devices since they easily lead to stackoverflow.

### 3. Running time vulnerability 
Most embedded systems have real time constraints hence a result a function whose execution time varies enormously with the input data can often be problematic

### 4. Small code size
Due do memeory constraint of such a system the algorithm shoould have a contribute as small as possible to the code size of the embedded software.

## Conclusion
Considering the above mentioned characteristics Insertion sort becomes the best sorting algorithm for use since not only is it faster but also has reasonable variability with the smallest code size.

## Other options
Bubble sort algorithm could be an alternative sorting algorithm but consumes a little bit more code space and is very slow.

## How to run the code.

Compilation requires prior instalation of both *gcc* and *make*.

To compile simple run the command "make all".

To run the program use the "make run" command.