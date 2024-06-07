// https://codeforces.com/contest/1927/problem/B 
// February 06,2024


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


typedef struct {
  char ch;
  int count;
}pair;

int main(void)
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    long int n;
    scanf("%ld",&n);
    int str[n];
    for(int i=0;i<n;i++)
         scanf("%d",&str[i]);
    
    pair str2[26];     
    for(int i=0;i<26;i++)     
    {
      str2[i].ch =(char)('a'+i);
      str2[i].count = 0;
    }
    
    char str3[n+1];
    int k =0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<26;j++)
      {
        if(str[i] == str2[j].count)
        {
          str3[k++] = str2[j].ch;
          str2[j].count++ ;
          break;
        }
      }
    }
    
    str3[k] = '\0';
    
    printf("%s\n",str3);
    
         
    
  }
  return 0;
}

