// https://codeforces.com/problemset/problem/363/A
// December 14,2023

#include <stdio.h>
void printSoroban(int n);
int main()
{
  long int n;
  scanf("%ld",&n);
  while(1)
  { 
    int digit;
    digit = n%10;
    printSoroban(digit);
    n /= 10;
    if(n==0)
       break;
  }
}

void printSoroban(int n)
{
  if(n==0)
  { 
    printf("O-|-OOOO");
  }
  else if(n==1)
      printf("O-|O-OOO");
  else if(n==2)
      printf("O-|OO-OO");
  else if(n==3)
      printf("O-|OOO-O");
   else if(n==4)
      printf("O-|OOOO-");
  else if(n==5)
      printf("-O|-OOOO");
  else if(n==6)
      printf("-O|O-OOO");
  else if(n==7)
      printf("-O|OO-OO");
  else if(n==8)
      printf("-O|OOO-O");
   else if(n==9)
      printf("-O|OOOO-");
 else
    printf("Input between 0-9!");
   
   printf("\n") ;
  return;
  
}