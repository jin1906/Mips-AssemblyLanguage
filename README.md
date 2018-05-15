# Mips-AssemblyLanguage
# © 2018 TAN RUAN ZHEN XIN ALL RIGHTS RESERVED
# Reverse_String.asm

 • read a string from a keyboard
 • use a character array
 • count the number of characters in the string using a loop
 • reverse the string and print the reversed string
 • use loop and a temp character array for reversing
 
# Reverse String Program in C

main() {
  char input[1024];
  char temp[1024];
  int i, str_length = 0;
  scanf("%s", input);
  while( input[i] != '\0' ){
    i++;
  }
  str_length = i;
  for(i=0; str_length >= 1; str_length--){
    temp[i] = input[str_length - 1];
    i++;
  }
  temp[i] = '\0';
  printf("Original string is %s\n", input);
  printf("Reversed string is %s", temp);
}

# Selection_Sort_Mips.asm

Write a MIPS program to do the following: (selection sort)

• Get a number of input (n)
• Get n number of integer input
• save into an integer array
• Display the input array
• Call selectionSort function to sort the input array
• Display the sorted array

# Selection Sort Program in C

void display ( int * array , int size ) {
int i ;
printf ( " [ " ) ;
// navigate through all items
for ( i = 0; i < size ; i ++) {
printf ( " % d " , array ++) ;
 }
printf ( " ]\ n " ) ;
 }
void selectionSort ( int array [] , int size ) {
int indexMin ,i , j ;
// loop through all numbers
for ( i = 0; i < size -1; i ++) {

// set current element as minimum
indexMin = i ;
// check the element to be minimum
for ( j = i +1; j < size ; j ++) {
if ( array [ j ] < array [ indexMin ]) {
indexMin = j ;
}
}

if ( indexMin != i ) {
// swap the numbers
int temp = array [ indexMin ];
array [ indexMin ] = array [ i ];
array [ i ] = temp ;
 }
printf ( " Iteration % d #: " ,( i +1) ) ;
display ( array , size ) ;
}
}

int main () {
int inputArray [256];
int i , num ;
printf ( " Number of Input : " ) ;
scanf ( " % d " , & num ) ;
for ( i = 0; i < num ; i ++)
scanf ( " % d " , & inputArray [ i ]) ;
printf ( " Input Array : " ) ;
display ( inputArray , num ) ;
selectionSort ( inputArray , num ) ;
printf ( " Output Array : " ) ;
display ( inputArray , num ) ;
 }

# Quick_Sort_Mips.asm

• Get a number of input (n)
• Get n number of integer input
• save into an integer array
• Display the input array
• Call quicksort function to sort the input array
• Display the sorted array

# Quick Sort Program in C

void display ( int * array , int size ) {
int i ;
printf ( " [ " ) ;
// navigate through all items
for ( i = 0; i < size ; i ++) {
printf ( " % d " , array ++) ;
}
printf ( " ]\ n " ) ;
}

void quicksort ( int array [] , int first , int last ) {
int i , j , pivot , temp ;

if ( first < last ) {
pivot = first ;
i = first ;
j = last ;

while ( i < j ) {
while ( array [ i ] <= array [ pivot ] && i < last )
i ++;

while ( array [ j ] > array [ pivot ] )
j - -;

if ( i < j ) {
temp = array [ i ];
array [ i ] = array [ j ];
array [ j ] = temp ;
 }
 }
temp = array [ pivot ];
array [ pivot ] = array [ j ];
array [ j ] = temp ;
quicksort ( array , first , j -1) ;
quicksort ( array , j +1 , last ) ;

 }
 }

int main () {
int inputArray [256];
int i , num ;
printf ( " Number of Input : " ) ;
scanf ( " % d " , & num ) ;
for ( i = 0; i < num ; i ++)
scanf ( " % d " , & inputArray [ i ]) ;
printf ( " Input Array : " ) ;
display ( inputArray , num ) ;

quicksort ( inputArray , 0 , num - 1) ;

printf ( " Output Array : " ) ;
display ( inputArray , num ) ;
 }
