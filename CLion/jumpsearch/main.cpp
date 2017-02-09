#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int jumpsearch(int a[],int n, int x){

    int step=(int)floor(sqrt(n)); //find the interval of skip by getting the sqrt of total
    int always=step;
    int prev=0; //
    while(a[min(step,n)-1]<x){ //index of a will either be n (when it hits maximum) or step, while a[step] is less than x
        prev=step; //prev becomes step
        step+=always; //check next range
        if(prev>=n) return -1; //It's not here
    }

    //once you find the range between prev and step

    while(a[prev]<x){ //search the subarray
        prev++;
        if(a[prev]==x) return prev; //if found return
        if(step==min(prev,n)) return -1; //if it reaches end or end of range prev, its not there
    }
    return -1; //return if didnt find anything
}

int main() {
    int arr[] = {2, 3, 4, 10, 40,50,70,100,102,103,155,178};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 155;
    int result = jumpsearch(arr, n, x);
    (result == -1)? printf("Element is not present in array")
                  : printf("Element is present at index %d", result);
    return 0;
}