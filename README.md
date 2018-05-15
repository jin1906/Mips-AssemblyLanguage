# Mips-AssemblyLanguage
# © 2018 TAN RUAN ZHEN XIN ALL RIGHTS RESERVED
# Reverse_String.asm

 • read a string from a keyboard<br /> 
 • use a character array<br /> 
 • count the number of characters in the string using a loop<br /> 
 • reverse the string and print the reversed string<br /> 
 • use loop and a temp character array for reversing<br /> 
 
# Reverse String Program in C

main() {<br /> 
  char input[1024];<br /> 
  char temp[1024];<br /> 
  int i, str_length = 0;<br /> 
  scanf("%s", input);<br /> 
  while( input[i] != '\0' ){<br /> 
    i++;<br /> 
  }<br /> 
  str_length = i;<br /> 
  for(i=0; str_length >= 1; str_length--){<br /> 
    temp[i] = input[str_length - 1];<br /> 
    i++;<br /> 
  }<br /> 
  temp[i] = '\0';<br /> 
  printf("Original string is %s\n", input);<br /> 
  printf("Reversed string is %s", temp);<br /> 
}<br /> 

# Selection_Sort_Mips.asm

Write a MIPS program to do the following: (selection sort)<br /> 

• Get a number of input (n)<br /> 
• Get n number of integer input<br /> 
• save into an integer array<br /> 
• Display the input array<br /> 
• Call selectionSort function to sort the input array<br /> 
• Display the sorted array<br /> 

# Selection Sort Program in C

void display ( int * array , int size ) {<br /> 
int i ;<br /> 
printf ( " [ " ) ;<br /> 
// navigate through all items<br /> 
for ( i = 0; i < size ; i ++) {<br /> 
printf ( " % d " , array ++) ;<br /> 
 }<br /> 
printf ( " ]\ n " ) ;<br /> 
 }<br /> 
void selectionSort ( int array [] , int size ) {<br /> 
int indexMin ,i , j ;<br /> 
// loop through all numbers<br /> 
for ( i = 0; i < size -1; i ++) {<br /> 
<br /> 
// set current element as minimum<br /> 
indexMin = i ;<br /> 
// check the element to be minimum<br /> 
for ( j = i +1; j < size ; j ++) {<br /> 
if ( array [ j ] < array [ indexMin ]) {<br /> 
indexMin = j ;<br /> 
}<br /> 
}<br /> 
<br /> 
if ( indexMin != i ) {<br /> 
// swap the numbers<br /> 
int temp = array [ indexMin ];<br /> 
array [ indexMin ] = array [ i ];<br /> 
array [ i ] = temp ;<br /> 
 }<br /> 
printf ( " Iteration % d #: " ,( i +1) ) ;<br /> 
display ( array , size ) ;<br /> 
}<br /> 
}<br /> 
<br /> 
int main () {<br /> 
int inputArray [256];<br /> 
int i , num ;<br /> 
printf ( " Number of Input : " ) ;<br /> 
scanf ( " % d " , & num ) ;<br /> 
for ( i = 0; i < num ; i ++)<br /> 
scanf ( " % d " , & inputArray [ i ]) ;<br /> 
printf ( " Input Array : " ) ;<br /> 
display ( inputArray , num ) ;<br /> 
selectionSort ( inputArray , num ) ;<br /> 
printf ( " Output Array : " ) ;<br /> 
display ( inputArray , num ) ;<br /> 
 }<br /> 
<br /> 
# Quick_Sort_Mips.asm
<br /> 
• Get a number of input (n)<br /> 
• Get n number of integer input<br /> 
• save into an integer array<br /> 
• Display the input array<br /> 
• Call quicksort function to sort the input array<br /> 
• Display the sorted array<br /> 
<br /> 

# Quick Sort Program in C
<br /> 
void display ( int * array , int size ) {<br /> 
int i ;<br /> 
printf ( " [ " ) ;<br /> 
// navigate through all items<br /> 
for ( i = 0; i < size ; i ++) {<br /> 
printf ( " % d " , array ++) ;<br /> 
}<br /> 
printf ( " ]\ n " ) ;<br /> 
}<br /> 
<br /> 
void quicksort ( int array [] , int first , int last ) {<br /> 
int i , j , pivot , temp ;<br /> 
<br /> 
if ( first < last ) {<br /> 
pivot = first ;<br /> 
i = first ;<br /> 
j = last ;<br /> 
<br /> 
while ( i < j ) {<br /> 
while ( array [ i ] <= array [ pivot ] && i < last )<br /> 
i ++;<br /> 
<br /> 
while ( array [ j ] > array [ pivot ] )<br /> 
j - -;<br /> 
<br /> 
if ( i < j ) {<br /> 
temp = array [ i ];<br /> 
array [ i ] = array [ j ];<br /> 
array [ j ] = temp ;<br /> 
 }<br /> 
 }<br /> 
temp = array [ pivot ];<br /> 
array [ pivot ] = array [ j ];<br /> 
array [ j ] = temp ;<br /> 
quicksort ( array , first , j -1) ;<br /> 
quicksort ( array , j +1 , last ) ;<br /> 
<br /> 
 }<br /> 
 }<br /> 
<br /> 
int main () {<br /> 
int inputArray [256];<br /> 
int i , num ;<br /> 
printf ( " Number of Input : " ) ;<br /> 
scanf ( " % d " , & num ) ;<br /> 
for ( i = 0; i < num ; i ++)<br /> 
scanf ( " % d " , & inputArray [ i ]) ;<br /> 
printf ( " Input Array : " ) ;<br /> 
display ( inputArray , num ) ;<br /> 
<br /> 
quicksort ( inputArray , 0 , num - 1) ;<br /> 
<br /> 
printf ( " Output Array : " ) ;<br /> 
display ( inputArray , num ) ;<br /> 
 }<br /> 
