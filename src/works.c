#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x){
  int j = 0;
  //最終日の仕事をした人の人数を考えるために、最初から人数を1にしておく。
  int human = 1;
  int worklog = 0;
  for(j = 0; j < n; j++){
    worklog = worklog + A[j];
    if (worklog > x){
      return 0;
    }
    if (j!=n-1){
      if ((worklog+A[j+1]) > x){
        human = human + 1;
        worklog = 0;
      }
    }
  }
  return human <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1 ){
    int mid = (lb + ub) / 2;
    if (p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n" , ub);
  return 0;
}