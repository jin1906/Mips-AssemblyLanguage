# TAN RUAN ZHEN XIN
# Reverse String Array

.data

str:  .space 1024  # set the maximum length of the buffer to be 1024 / allocate 1024 bytes = array of 256 chars/integers
input: .asciiz "Please enter your string:"	# declare and initialize a string (input)
output: .asciiz "\nReversed string:"	# declare and initialize a string (output)
output2: .asciiz "String length:"	# declare and initialize a string (output2)

.text

.globl main

main:                 
# Display the message into the console ("input" string)

li $v0, 4	# system call code for printing a string (input) / load appropriate system call code into register $v0 
la $a0, input	# load address of string to be printed into $a0 /  $a0 = address of input
syscall	# call operating system to perform print operation / call OS to perform operation specified in $v0

# Load string from console
li    $v0, 8		# system call code for reading an string / read string
la    $a0, str	# load address of str to $a0 / $a0 = address of str
li    $a1, 1024	 #	buffer length / allocate 1024 bytes = array of 256 chars/integers
syscall	# call operating system to perform operation / call OS to perform operation specified in $v0

# Display the message into the console ("output2" string)
li $v0, 4		# load appropriate system call code into register $v0  /  system call code for printing a string
la $a0, output2		# load address of string to be printed into $a0 / $a0 = address of output2
syscall		# call operating system to perform print operation / call OS to perform operation specified in $v0

la $t0, str  	# load address of str to $t0 / $t0 = address of str
li $t1, -1		# set counter ($t1) to -1 because of "\n" char

	
# Count characters 
countChr:
lb $t2, 0($t0)	# Load the first byte in $t0
beqz $t2, endCount		# if $t2 == 0 its end of string
add $t0, $t0, 1		# else increment the address 
add $t1, $t1, 1		# increment counter  
j countChr      	# loop / Next iteration of loop

	
endCount:
li $v0, 1   # load appropriate system call code into register $v0 /  code for printing integer is 1
move $a0, $t1  # move integer to be printed into $a0:  $a0 = $t1
syscall   # call operating system to perform operation

	
# Push a null into stack to point that its end of string
li    $t0, 0    # Push a null /n
subi  $sp, $sp, 4   # Onto the stack
sw    $t0, ($sp)     # To signal its bottom
li    $t1, 0         # index of first char in str

	
# Push all characters into stack
pushStack:                 
lbu   $t0, str($t1)  # Get current char into a full word
beqz  $t0, stackEnd  # if null byte then it is end of string / exit loop if null byte


subi  $sp, $sp, 4    # push the full word
sw    $t0, ($sp)     # store the char / save $t0

addi  $t1, $t1 1     # increment the index / i = i + 1
j      pushStack         # loop to push1 / Next iretation of loop

# Pop chars from stack
stackEnd:                	    
li    $t1, 0         # index of first byte

popStack:
lw    $t0, ($sp)     # Pop a char off the stack / retsore saved $t0
addi  $sp, $sp, 4    # Pop 1 item from stack
beqz  $t0, end      # null tell us its empty stack

sb    $t0, str($t1)  # store at string[$t1]
addi  $t1, $t1, 1    # increment the index / i = i + 1
j      popStack  #  loop / next iteration of loop



end:                  
# Display the message into the console ("output" string)
li $v0, 4	# system call code for printing a string (input) / load appropriate system call code into register $v0 
la $a0, output   #  load address of string to be printed into $a0 /  $a0 = address of output
syscall   # call operating system to perform print operation / call OS to perform operation specified in $v0

li    $v0, 4 	# system call code for printing a string (input) / load appropriate system call code into register $v0 
la    $a0, str 	# load address of string to be printed into $a0 /  $a0 = address of str
syscall    # call operating system to perform print operation / call OS to perform operation specified in $v0

li    $v0, 10      # syscall code 10 is for exit / terminate your program
syscall   # call OS to perform operation specified in $v0

