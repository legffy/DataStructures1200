HOMEWORK 3: MATRIX CLASS


NAME:  Randy Taylor


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Ethan Guo, Tony yu

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 15 hours >



ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.
O(1)
get
O(1)
set
O(1)
num_rows
O(N)
get_column
O(N^2)
operator<<
o(N^2)
quarter
O(N^2)
operator==
O(N^2)
operator!=
O(N)
swap_rows
O(N^3)
rref (provided in matrix_main.cpp)



TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  
What tools did you use (gdb/lldb/Visual Studio debugger,
Valgrind/Dr. Memory, std::cout & print, etc.)?  How did you test the
"corner cases" of your Matrix class design & implementation?


In order to address memory issues, I used Valgrind, and gdb for debugging. I had a lot of problems with the student test cases and the batch test
This was due to excess memory leaks. In order to fix this I had to fix my destructor and how I allocted memory in my constructors and helper functions
MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

