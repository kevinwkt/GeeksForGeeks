#include <iostream>

using namespace std;

int linearsearch(int a[],int n, int x){

    int i;
    for(i=0;i<n;i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

int main() {
    int ar[5]={1,3,5,7,9};
    int ans=linearsearch(ar, sizeof(ar)/ sizeof(ar[0]),2);
    cout<<ans;
}