// https://codeforces.com/contest/1916/problem/A 
// December 30,2023

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//int fact[] = {7,17,119,289}; //  factors of 2023

const int num = 2023;

void print(int,int);
int main(void) {

  int t;
  scanf("%d", &t);
  while(t--) {
    // Input

    int n,
    k;
    scanf("%d%d", &n, &k);
    int str[n]; // set b
    long long int product = 1;
    for(int i = 0; i < n; i++) {
      scanf("%d", &str[i]);
      product *= str[i];
    }

    // processing
    if(product == 2023) {
      printf("YES\n");
      if(k != 0) {
        for(int i = 0; i < k; i++)
        printf("1 ");
      }
      printf("\n");
    }
    else if(num % product == 0) {
       print((int)product,k);
    }
    else
       printf("NO\n");



  }
  return 0;
}

void print(int product, int k) {
  if(product== 1)
  {
    if(k == 1)
    printf("YES\n2023");
    else if(k == 2)
    printf("YES\n7 289");
    else if(k >= 3) {
      printf("YES\n7 17 17 ");
      for(int i = 0; i < k-3; i++)
            printf("1 ");
    }
  }
  else if(product == 7) {
    if(k == 1)
    printf("YES\n289");
    else if(k >= 2) {
      printf("YES\n17 17 ");
      for(int i = 0; i < k-2; i++)
      printf("1 ");
    }
  }
  else if(product == 17) {

    if(k == 1)
    printf("YES\n119");
    else if(k >= 2) {
      printf("YES\n7 17 ");
      for(int i = 0; i < k-2; i++)
      printf("1 ");
    }
  }
  else if(product == 119) {

      printf("YES\n17 ");
      for(int i = 0; i < k-1; i++)
         printf("1 ");
    
  }
  else
  {

      printf("YES\n7 ");
      for(int i = 0; i < k-1; i++)
        printf("1 ");
    
  }
  
 printf("\n");
  return;
}