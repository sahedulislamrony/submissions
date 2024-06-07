// https://codeforces.com/contest/1613/problem/A
// December 19,2023
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



int main()
{
  long int t;
  scanf("%ld", &t);
  while(t--)
  {
    int x1, p1, x2, p2;
    scanf("%d %d", &x1, &p1);
    scanf("%d %d", &x2, &p2);
    double result = log10((double)x1/x2) + (p1-p2);

    if(result > 0)
      printf(">");
    else if(result < 0)
      printf("<");
    else 
       printf("=");
    
    printf("\n");
  }
  
  return 0;
}