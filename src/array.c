#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = n;
  while (ub - lb > 1 ){
    int mid = (lb + ub) / 2;
    if (A[mid] >= k){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n" , ub);
  return 0;
}