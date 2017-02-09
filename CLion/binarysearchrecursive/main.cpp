#include <iostream>
#include <stdio.h>

using namespace std;

int binarysearchR(int a[], int l, int r, int x){

    if(l<=r){

        int mid=l+(r-l)/2;
        if(a[mid]==x) return mid;
        if(a[mid]>x) return binarysearchR(a,l,mid-1,x);
        if(a[mid]<x) return binarysearchR(a,mid+1,r,x);
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 10;
    int result = binarysearchR(arr, 0, n-1, x);
    (result == -1)? printf("Element is not present in array")
                  : printf("Element is present at index %d", result);
    return 0;
}