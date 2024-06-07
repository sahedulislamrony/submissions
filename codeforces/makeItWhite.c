// https://codeforces.com/contest/1927/problem/A 
// February 06,2024

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main(void) {
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    
    int left, right;
    for(int i=0;i<n;i++)
    {
      if(str[i] == 'B')
      {
        left = i;
        break;
      }
    }
    
    for(int i=n-1;i>=0;i--)
    {
      if(str[i] == 'B')
      {
        right = i;
        break;
      }
    }
    
    printf("%d\n",(right-left)+1);
  }
  
  return 0;
}