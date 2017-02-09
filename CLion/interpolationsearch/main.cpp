#include <iostream>
#include <stdio.h>

using namespace std;

int interpolationsearch(int a[],int n ,int x){
    int lo=0;
    int hi=n-1;

    while(lo<=hi && x>=a[lo] && x<=a[hi]){
        int pos=lo+(((double)(hi-lo)/(a[hi]-a[lo]))*(x-a[lo])); //formula using the difference between the value of high and low
        if(a[pos]==x) return pos; //THE REST IS SAME AS BINARY SEARCH
        if(a[pos]<x) lo=pos+1;
        else hi=pos-1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40,50,70,100,102,103,155,178};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 155;
    int result = interpolationsearch(arr, n, x);
    (result == -1)? printf("Element is not present in array")
                  : printf("Element is present at index %d", result);
    return 0;
}