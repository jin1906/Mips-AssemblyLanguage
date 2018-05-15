# TAN RUAN ZHEN XIN
# Selection Sort Array

.data

array: .space 1024    # set the maximum length of the buffer to be 1024 / allocate 1024 
message1: .asciiz "ENTER THE ARRAY SIZE : "   # declare and initialize a string (message1)
message2: .asciiz "PLASE INSERT THE ARRAY THE ELEMENTS, ONE PER LINE\n"   # declare and initialize a string (message2)
message3: .asciiz "THE SORTED ARRAY IS : "    # declare and initialize a string (message3)
message4: .asciiz "ENTER ELEMENT :  "     # declare and initialize a string (message4) 
newLine: .asciiz "\n "  # declare and initialize newLine (newLine)
space: .asciiz " "   # declare and initialize space (Space)

.text
.globl main

main:
# Display the message into the console ("message1" string)
# Print of message1
la $a0, message1 # load address of string to be printed into $a0 /  $a0 = address of message1
li $v0, 4 # load appropriate system call code into register $v0  /  system call code for printing a string
syscall   # call operating system to perform print operation / call OS to perform operation specified in $v0

# integer to print
li $v0, 5 	# $v0 = array size (n) 
syscall  # call operating system to perform print operation / call OS to perform operation specified in $v0	
move $s2, $v0  # $s2 = n /  # move $v0 to $s2
sll $s0, $v0, 2    # $s0 = n*4 /  shift to the left / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
sub $sp, $sp, $s0  # $sp-$s0

							
la $a0, message2  # load address of string to be printed into $a0 /  $a0 = address of message2
li $v0, 4 	# Print message2 /  load appropriate system call code into register $v0  /  system call code for printing a string
syscall  # call operating system to perform print operation / call OS to perform operation specified in $v0
move $s1, $zero  # $s1 will be i=0 

# Loop to get the minimum value
jal loopForGet   # jump and link

loopExitGet: 
move $a0, $sp   # $a0 = address af the array / move $sp to $a0
move $a1, $s2    # move $s2 to $a1 / $a1 = size of the array selectionSort(a,n)

# Sort the list using selection sort
jal selectionSort  #  jump and link

la $a0, message3 	# load address of string to be printed into $a0 /  $a0 = address of message3
li $v0, 4   # Print of message3 /  load appropriate system call code into register $v0  /  system call code for printing a string
syscall  # call operating system to perform print operation / call OS to perform operation specified in $v0

move $s1, $zero   # i=0 /  $s1 will be i=0 

# Print list
jal loopPrint  #  jump and link

exitPrint: 
add $sp, $sp, $s0  # elimination of the stack frame 
li $v0, 10 	 #  syscall code 10 is for exit / terminate your program
syscall   #call operating system to perform print operation / call OS to perform operation specified in $v0

#############################################################################################	

# selection sort

selectionSort: 
addi $sp, $sp, -20 	# save values on stack /  make space on stack
sw $ra, 0($sp)   # save $ra (Array) on stack
sw $s0, 4($sp)  # save $s0 (Array) on stack
sw $s1, 8($sp)  # save $s1 (Array) on stack
sw $s2, 12($sp)  # save $s2 (Array) on stack
sw $s3, 16($sp)  # save $s3 (Array) on stack
move $s0, $a0   # address of the array / move $a0 to $s0
move $s1, $zero 	# i=0 /  $s1 will be i=0
subi $s2, $a1, 1  # lenght -1 / $a1 minus 1 and save the result in $s2

selectionSortFor: 
bge $s1, $s2, sortExit   # if i >= length-1 -> exit loop
move $a0, $s0   # base address / move $s0 to $a0
move $a1, $s1   # i / move $s1 to $a1
move $a2, $s2  # length - 1 / move $s2 to $a2

jal minimum  # jump minimum and link

move $s3, $v0   # return value of minimum
move $a0, $s0  # move $s0 to $a0
move $a1, $s1  # move $s1 to $a1		
move $a2, $s3  # move $s3 to $a2		 

jal swap  # jump swap  and link

addi $s1, $s1, 1  # i = i + 1 / add 1 to $s1 and store the result in $s1
j selectionSortFor  # go back to the beginning of the loop


sortExit: 
lw $ra, 0($sp) 	# restore values from stack
lw $s0, 4($sp)   # restore $s0 from stack
lw $s1, 8($sp)  # restore $s1 from stack
lw $s2, 12($sp)  # restore $s2 from stack
lw $s3, 16($sp)  # restore $s3 from stack
addi $sp, $sp, 20  # restore stack pointer

jr $ra  # return

# find minimum index
minimum: 
move $t0, $a0 	 # base of the array / move data in $a0 to $t0
move $t1, $a1 	  # mini = first = i / move data in $a1 to $t1
move $t2, $a2 	 # last / move the data in$a0 to $t2

sll $t3, $t1, 2 	# first * 4 / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
add $t3, $t3, $t0   # index = base array + first * 4 / add $t3 to $t0 and store the result in $t3
lw $t4, 0($t3) 	# min = v[first] /  load data/ word $t3 to $t4
addi $t5, $t1, 1  # i = 0 / add 1 to $t1 and store the result in $t5

minimumFor: 
bgt $t5, $t2, minimumEnd  # go to minimumEnd / branch to target if  $t5 > $t2
sll $t6, $t5, 2 	# i * 4 / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
add $t6, $t6, $t0   # index = base array + i * 4
lw $t7, 0($t6) 	# v[index]


bge $t7, $t4, minimumIfExit  # skip the if when v[i] >= min
move $t1, $t5 	 # minimum = i / move the data store in  $t5 to $t1
move $t4, $t7 	 # minimum = v[i] / move the data store in $t7 to $t4

minimumIfExit: 
addi $t5, $t5, 1  # i = i + 1 / add 1 to $t5 and store the result in $t5
j minimumFor  # Jumps to the calculated address (minimumFor)

minimumEnd: 
move $v0, $t1 	# return minimum / move the data in $t1 to $v0
jr $ra  # Jump to the address contained in register $s

# swap routine
swap: 
sll $t1, $a1, 2 	# i * 4 / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
add $t1, $a0, $t1   # v + i * 4 / add $a0 to $t1 and store the result in $t1
sll $t2, $a2, 2 	 # j * 4 / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
add $t2, $a0, $t2 	# v + j * 4 / add $a0 to $t2 and store the result in resistor $t2

lw $t0, 0($t1) 	 # v[i] / load data/ word $t1 to $t0
lw $t3, 0($t2) 	  # v[j]  / load data/word $t1 to $t3
sw $t3, 0($t1) 	  # v[i] = v[j] / save the data in $t1 on $t3
sw $t0, 0($t2) 	  # v[j] = $t0 / save the data in $t2 on $t0

jr $ra  # Jump to the address contained in register $s

loopForGet: 
bge $s1, $s2, loopExitGet  # if i >= n go to loopExitGet
sll $t0, $s1, 2	 # $t0 = i*4 / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
add $t1, $t0, $sp 	# $t1 = $sp + i*4 / add $t0 to $sp and store the result in $t1
la $a0, message4 	# Print of message4 /   load address of string to be printed into $a0 /  $a0 = address of message4
li $v0, 4  #  Print of space /  load appropriate system call code into register $v0  /  system call code for printing a string	
syscall  # call operating system to perform print operation / call OS to perform operation specified in $v0

li $v0, 5 	# Get one element of the array 
syscall 	# call operating system to perform print operation / call OS to perform operation specified in $v0
sw $v0, 0($t1) 	 # The element is stored at the address $t1
addi $s1, $s1, 1  # i = i + 1  / add 1 to $s1 and store it in resistor $s1

j loopForGet  # Jumps to the calculated address (loopForGet)


loopPrint: 
bge $s1, $s2, exitPrint 	# if i>=n go to exitPrint / #  branch to target if  $s1 >= $s2
sll $t0, $s1, 2 	# $t0=i*4 / shift to the left / moves each bit to the left by 2 meaning multiply by 4 / set the size of the array
add $t1, $sp, $t0  # $t1=address of a[i] / add $t0 to $sp and store it in resistor $t1 / # add offset to the address of Array[0]
lw $a0, 0($t1) 	 #load  / $a0 = whatever is in Array[i] /  load in $a0 the contents of the word located at address specified by $t1
li $v0, 1 	# print of the element a[i] / system call code for printing the elements in a[i]
syscall  # call operating system to perform print operation / call OS to perform operation specified in $v0 


la $a0, space  # load address of string to be printed into $a0 /  $a0 = address of space
li $v0, 4  # Print of space /  load appropriate system call code into register $v0  /  system call code for printing a string
syscall  # call operating system to perform print operation / call OS to perform operation specified in $v0

	
addi $s1, $s1, 1   # i=i+1 / add 1 to $s1 and store it in resistor $s1
j loopPrint  # Jumps to the calculated address (loopPrint)		