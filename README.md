# Optimization Level 3 -O3
# © 2018 TAN RUAN ZHEN XIN ALL RIGHTS RESERVED

Optimization Matrix Program Level 3 -O3

The Objective of this project is to design and implement a C program that performs computations on large matrices. 
The size of a matrix is large enough so that the execution of program causes paging.

Different choices of copying the matrix may have different impacts on the program runtime. 
Using optimization level3(-O3) we can improve the perfmance of the code and reduce the execution time of the program. 



![Optimization](https://user-images.githubusercontent.com/28322834/123498496-31de6500-d5fe-11eb-94e9-2ae55a691cf8.png)


# Mechanisms:
1.	Caching: different cache block size can affect the runtime when integrated with other techniques (SIMD and superscalar mechanism)
2.	SIMD: Single Instruction Multiple Data (SIMD). It means performing a single operation on multiple data points simultaneously.
3.	Superscalar mechanisms: A superscalar processor executes more than one instruction 
during a clock cycle by simultaneously dispatching multiple instructions to different components on the processor. 
