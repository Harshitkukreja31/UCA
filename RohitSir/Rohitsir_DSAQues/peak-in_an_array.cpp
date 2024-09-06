#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
     {
        int mid = left + (right - left) / 2;

        if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1]))
            return mid;

        if (mid > 0 && arr[mid - 1] > arr[mid])
            right = mid - 1;
         else
            left = mid + 1;
     }
    return -1;
}

int main()
{
  vector<int>arr={0,10,5,2};
  int ans=findPeakElement(arr);
  cout<<"Peak element: "<<ans<<endl;

    return 0;
}