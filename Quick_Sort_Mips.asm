# TAN RUAN ZHEN XIN
# Quick Sort Array

.data

Array: .space 1024 # set the maximum length of the buffer to be 1024 / allocate 1024
Message0: .asciiz "QUICK SORT IN MIPS" # declare and initialize a string (message0)
Message1: .asciiz "ENTER THE NUMBER OF ELEMENTS : " # declare and initialize a string (message1)
Input: .asciiz "ENTER THE NUMBER : " # declare and initialize a string (Input)
Message2: .asciiz "THE ORIGINAL ARRAY IS : " # declare and initialize a string (message2)
Message3: .asciiz "THE ARRAY AFTER QUICK SORT : " # declare and initialize a string (message3)
Space: .asciiz " " # declare and initialize a string (Space)
NewLine: .asciiz "\n" # declare and initialize a string (NewLine)

.text
.globl main

main:
# Display the message into the console ("message0" string)
# Print of message1
li $v0, 4 # load appropriate system call code into register $v0 / system call code for printing astring
la $a0, Message0 # load address of string to be printed into $a0 / $a0 = address of message0
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0

li $v0, 4 # load appropriate system call code into register $v0 / system call code for printing astring
la $a0, NewLine # load address of string to be printed into $a0 / $a0 = address of NewLine
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0

li $v0, 4 # load appropriate system call code into register $v0 / system call code for printing a string
la $a0, Message1 # load address of string to be printed into $a0 / $a0 = address of Message1
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0


# Read user input (Integer)
# integer to print
li $v0, 5 # $v0 = array size (n)
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0
move $t4,$v0 # move $v0 to $t4

# Use stack Pointer to save/store the Array size
StackPointerStoreSize :
addi $sp, $sp , -4 # Create the space in the Stack to store the data
sw $t4,28($sp) # Store the data located in resistor $t4 into the stack position (28($sp))
la $s0, Array # load address of string to be printed into $s0 / $s0 = address of the Array
li $t3,0 # set the count / Resistir $t3 to 0

Store:
li $v0, 4 # load appropriate system call code into register $v0 / system call code for printing a string
la $a0, Input # load address of string to be printed into $a0 / $a0 = address of Input
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0

# Read user Input
li $v0, 5 # $ System Call to read user input / keyboard
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0

sw $v0,0 ($s0) # The element is stored at the address $v0
addi $s0,$s0,4 # shift / move the array by 4. add 4 to $s0 and store the result into $s0
addi $t3,$t3,1 # add 1 to $t3 and store the result into $t3 / Add one to the counting
bne $t3,$t4,Store # if $t3 != $t4 advance pc (Store << 2) else advance pc (4)
li $v0, 4 # load appropriate system call code into register $v0 / system call code for printing a string
la $a0, Message2 # load address of string to be printed into $a0 / $a0 = address of Message2
syscall # call operating system to perform print operation / call OS to perform operation specified in $v0

# Print the original Array before sorting
jal printStatement # Jumps to the calculated address (printStatement)
la $a0, Array # load address of string to be printed into $s0 / $s0 = address of the Array
li $a1, 0 # load immediate $a1 = 0

# a2 = Array_size - 1
lw $t0, 28($sp) # load word $t0 from the data located in 28($sp) / Load the size of the Array
addi $t0, $t0, -1 # add -1 to resistor $t0 and store the result in $t0
move $a2, $t0 #move the data locate in $t0 to $a2

# Call the funtion Sort
jal Sort # Jumps to the calculated address (Sort)
li $v0, 4 # load appropriate system call code into register $v0 / system call code for printing a string
la $a0, Message3 # load address of string to be printed into $a0 / $a0 = address of Message3
syscall# call operating system to perform print operation / call OS to perform operation specified in $v0

# Print the original Array after sorting
jal printStatement # Jumps to the calculated address (printStatement)

# end program
li $v0, 10 # syscall code 10 is for exit / terminate your program
syscall #call operating system to perform print operation / call OS to perform operation specified in $v0

##############################################################################
###########
# Define Function for printing the Array
printStatement:
lw $t4,28($sp)# load word the size of the Array
la $s0, Array# load address of string to be printed into $s0 / $s0 = address of the Array

# Define Function for the Quick Sort
WhileLoop:
beq $t4, $zero, WhileLoop1# if $t4 != Zero advance pc (WhileLoop1 << 2) else advance pc (4)
# Print a space between the element of the Array
li $v0, 4# load appropriate system call code into register $v0 / system call code for printing a string
la $a0, Space# load address of string to be printed into $a0 / $a0 = address of Space
syscall#call operating system to perform print operation / call OS to perform operation specified in $v0

# Print Array elements
li $v0, 1# print of the element a[i] / system call code for printing the elements in a[i]
lw $a0, 0($s0)# load word $a0 from the data located in 0($sp)
syscall# call operating system to perform print operation / call OS to perform operation specified in $v0
addi $t4, $t4, -1# add -1 to resistor $t0 and store the result in $t0
addi $s0, $s0, 4# add 4 to $s0 and store the result into $s0

j WhileLoop# Jumps to the calculated address (WhileLoop)
# Define Function WhileLoop1
WhileLoop1:
# make new line
li $v0, 4#Load immediate $v0 = 4
la $a0, NewLine# load address of string to be printed into $a0 / $a0 = address of Space
syscall#call operating system to perform print operation / call OS to perform operation specified in $v0
jr $ra# Jump to the address contained in register $s

# Define Function Quick Sort
Sort:
# store $s and $ra
addi $sp, $sp, -24# Adjust the Stack Pointer sp
sw $s0, 0($sp)# store s0 / save $s0 (Array) on stack
sw $s1, 4($sp)# store s1 / save $s1 (Array) on stack
sw $s2, 8($sp)# store s2 / save $s2 (Array) on stack
sw $a1, 12($sp)# store a1 / save $a1 (Array) on stack
sw $a2, 16($sp)# store a2 / save $a2 (Array) on stack
sw $ra, 20($sp)# store ra / save $ra (Array) on stack

# set $s
move $s0, $a1# Move data from resistor $a1 to $a0 (left partition)
move $s1, $a2# Move data from resistor $a2 to $s1 (right partition)
move $s2, $a1# Move data from resistor $a1 to $a2 (pivot / left point)

# while (left partition < right partition)
# Define Function FirstLoop
FirstLoop:
bge $s0, $s1, FirstLoopEnd# if $s0 != $s1 advance pc (FirstLoopEnd << 2) else advance pc (4)

# while (arr[l] <= arr[p] && left Parttion < right Partition)
# Define Function FirstLoop1
FirstLoop1:
li $t7, 4#Load immediate $t7 = 4
mult $s0, $t7# Multiplies $t7 by $s0 and stores the result in $LO
mflo $t0# t0 = l * 4bit / The contents of register LO are moved to the specified register
add $t0, $t0, $a0# t0 = &arr[l] / add data in resistor $t0 to $a0 and store the result/answer in resistor $t0
lw $t0, 0($t0)# load word $t0 from the data located in 0($t0)
mult $s2, $t7# Multiplies $t7 by $s2 and stores the result in $LO.
mflo $t1# The contents of register LO are moved to the specified register.
add $t1, $t1, $a0# add data in resistor $a0 to $t1 and store the result/answer in resistor $t1
lw $t1, 0($t1)# load word $t1 from the data located in 0($t1)
bgt $t0, $t1, FirstLoop1End# if $t0 <= $t1 advance_pc (FirstLoop1End << 2)); else advance_pc (4);
# check left partition < right partition
bge $s0, $a2, FirstLoop1End# if $s0 >= a2 advance_pc (FirstLoop1End << 2)); else advance_pc (4);
addi $s0, $s0, 1# add data in resistor $s0 to $1 and store the result/answer in resistor $s0
j FirstLoop1# Jumps to the calculated address (FirstLoop1)

# Define Functio FirstLoop1End
FirstLoop1End:
# Define Fucntio FirstLoop2
# while (arr[r] >= arr[p] && right partition > left partition)
FirstLoop2:
li $t7, 4 #Load immediate $t7 = 4
mult $s1, $t7# Multiplies $t7 by $s1 and stores the result in $LO.
mflo $t0# The contents of register LO are moved to the specified register.
add $t0, $t0, $a0# add data in resistor $t0 to $a0 and store the result/answer in resistor $t0
lw $t0, 0($t0)# load word $t0 from the data located in 0($t0)
mult $s2, $t7# Multiplies $t7 by $s1 and stores the result in $LO.
mflo $t1# The contents of register LO are moved to the specified register.
add $t1, $t1, $a0# add data in resistor $a0 to $t1 and store the result/answer in resistor $t1
lw $t1, 0($t1)# load word $t1 from the data located in 0($t1)

# check arr[r] >= arr[p]
blt $t0, $t1, FirstLoop2End#if $t0 < $t1 advance_pc (FirstLoop2End << 2)); else advance_pc (4);
# check right partition > left partition
ble $s1, $a1, FirstLoop2End# if $s1 <= $a1 advance_pc (FirstLoop2End << 2)); else advance_pc(4);

# Right Partition--
addi $s1, $s1, -1# add -1 to resistor $s1 and store the result in $s1
j FirstLoop2# Jumps to the calculated address (FirstLoop2)
# Define Function FirstLoop2End
FirstLoop2End:
# if (left partition >= right partition)
blt $s0, $s1, Swap#if $s0 < $s1 advance_pc (Swap << 2)); else advance_pc (4);

# SWAP (arr[p], arr[r])
li $t7, 4#Load immediate $t7 = 4
mult $s2, $t7# Multiplies $t7 by $s1 and stores the result in $LO.
mflo $t6# The contents of register LO are moved to the specified register.
add $t0, $t6, $a0# add -$t6 to resistor $a0 and store the result in $t0
mult $s1, $t7# Multiplies $t7 by $s1 and stores the result in $LO.
mflo $t6# The contents of register LO are moved to the specified register.
add $t1, $t6, $a0# add $t6 to resistor $a0 and store the result in $t1

# Swap Function / Method
lw $t2, 0($t0)# restore values $t2 from stack
lw $t3, 0($t1)# restore values $t3 from stack
sw $t3, 0($t0)# v[i] = v[j] / save the data in $t0 on $t3
sw $t2, 0($t1)# v[i] = v[j] / save the data in $t1 on $t2

# quick(arr, left partition, r - 1)
move $a2, $s1# move data store in resistor $s1 to $a2
addi $a2, $a2, -1# add -1 to resistor $a2 and store the result in $a2
jal Sort# jump Sort and link

# pop stack
lw $a1, 12($sp)# load word / data a1
lw $a2, 16($sp)# load word / data $a2
lw $ra, 20($sp)# load word / data $ra

# quick sort (arr, r + 1, right partition)
move $a1, $s1# move data store in $s1 to resistor $a1
addi $a1, $a1, 1# add 1 to resistor $a1 and store the result in $a1
jal Sort# jump Sort and link
# pop stack
lw $a1, 12($sp)# load word / data a1
lw $a2, 16($sp)# load word / data a2
lw $ra, 20($sp)# load word / data $ra
# return
lw $s0, 0($sp)# load word / data store in s0
lw $s1, 4($sp)# load word / data store in s1
lw $s2, 8($sp)# load word / data store in s2
addi $sp, $sp, 24# Adjust stack / add $sp to resistor 24 and store the result in $sp

jr $ra # return

#Define Function Swap
Swap:
# SWAP (arr[l], arr[r])
li $t7, 4#Load immediate $t7 = 4
mult $s0, $t7# Multiplies $t7 by $s1 and stores the result in $LO.
mflo $t6# The contents of register LO are moved to the specified register.
add $t0, $t6, $a0# add $t6 to resistor $a0 and store the result in $t0
mult $s1, $t7# Multiplies $t7 by $s1 and stores the result in $LO.
mflo $t6# The contents of register LO are moved to the specified register.
add $t1, $t6, $a0# add $t6 to resistor $a0 and store the result in $t1 

# Swap
lw $t2, 0($t0)# load t2 / restore values $t2 from stack
lw $t3, 0($t1)# load $t3 / restore values $t3 from stack
sw $t3, 0($t0)# save $t3 (Array) on stack
sw $t2, 0($t1)# save $t2 (Array) on stack

j FirstLoop# Jumps to the calculated address (FirstLoop)

# Define Function FirstLoopEnd
FirstLoopEnd:
lw $s0, 0($sp)# load s0 / restore values $s0 from stack
lw $s1, 4($sp)# load s1 / restore values $s1 from stack
lw $s2, 8($sp)# load s2 / restore values $s2 from stack
addi $sp, $sp, 24# Adjust stack pointer
jr $ra# return

