#include "probelib.h"
#include <cstdio>

int n;


int main()
{
  int n = probe_init();

  // for(int i=0; i<n; i++) {
  //   if(probe_check(i,i)) {
  //     probe_answer(i);
  //   }
  // }
  int a=0;
  int b=n-1;
  int mid;
  while (a<b)
  {
    mid=(a+b)/2;
    if(probe_check(a,mid)){
      b=mid;
    }
    else{
      a=mid+1;
    }
  }
  
  probe_answer(a);

}