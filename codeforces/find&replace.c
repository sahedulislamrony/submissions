// https://codeforces.com/problemset/problem/1807/C
// December 18,2023

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int size,status =1;
    scanf("%d",&size);
    char str[size+1];
    scanf("%s",str);
 
    for(int i=0;i<size;i++)
    {
     
      for(int j=i+1;j<size;j++)
      {
        if(str[i] == str[j])
        {
          if((abs(j-i)+1)%2==0)
          {
            status =0;
            break;
          }
          if(status == 0)
             break;
        }
        
      }
      
          if(status == 0)
             break;
    }
    
    if(status)
        printf("YES\n");
     else 
        printf("NO\n");
  }
  return 0;
}

