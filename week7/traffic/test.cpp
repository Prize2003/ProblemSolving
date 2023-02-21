#include "traffic.h"
#include <vector>
#include <iostream>

using namespace std;

int n, k;

int main()
{
  traffic_init(&n, &k);
  int x1, y1, x2, y2;

  for (int i = 1; i <= n; i++)
  {
    if (traffic_query(i, 1, i, n) != n - 1)
    {
      x1 = x2 = i;
      int l = 1, r = n;
      int mid;
      while (l < r)
      {
        mid = (l + r) / 2;
        if(traffic_query(i, mid-1, i, mid) == 2||traffic_query(i, mid, i, mid+1) == 2){
          break;
        }
        if (traffic_query(i, l, i, mid) == mid - l)
        {
          l = mid+1;
        }
        else
        {
          r = mid;
        }
      }
      if (traffic_query(i, mid, i, mid + 1) == 2)
      {
        y1 = mid;
        y2 = mid + 1;
        // cout<<"("<<x1<<" "<<y1<<")"<<","<<"("<<x2<<" "<<y2<<")"<<"\n";
        traffic_report(x1, y1, x2, y2, 0, 0, 0, 0);
      }
      else
      {
        y1 = mid - 1;
        y2 = mid;
        traffic_report(x1, y1, x2, y2, 0, 0, 0, 0);
      }
    }
    else if (traffic_query(1, i, n, i) != n - 1)
    {
      y1 = y2 = i;
      int l = 1, r = n;
      int mid;
      while (l < r)
      {
        mid = (l + r) / 2;
        if(traffic_query(mid-1,i, mid, i) == 2||traffic_query(mid,i, mid+1, i) == 2){
          break;
        }
        if (traffic_query(l, i, mid, i) == mid - l)
        {
          l = mid+1;
        }
        else
        {
          r = mid;
        }
      }
      if (traffic_query(mid, i, mid + 1, i) == 2)
      {
        x1 = mid;
        x2 = mid + 1;
        traffic_report(x1, y1, x2, y2, 0, 0, 0, 0);
      }
      else
      {
        x1 = mid - 1;
        x2 = mid;
        traffic_report(x1, y1, x2, y2, 0, 0, 0, 0);
      }
    }
  }
}
