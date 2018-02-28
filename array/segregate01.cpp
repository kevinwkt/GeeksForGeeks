//Given an array of 0s and 1s in random order, segregate so that 0s are in the front and 1s on the back.

#include <stdio.h>

using namespace std;

void indexes(int* arr, int size){
	int zeroInd=0;
	int oneInd=size-1;

	while(zeroInd<oneInd){
		while(!arr[zeroInd+1]) zeroInd++;
		while(arr[oneInd-1]) oneInd--;
		if(zeroInd<oneInd) break;		
		arr[zeroInd]^=1;
		arr[oneInd]^=1;
	}

	for(int i=0;i<size;i++) printf("%3d",arr[i]);
	printf("\n");
}

int main(){
	int total;
	int arr[100000];

	scanf("%d",&total);
	for(int i=0;i<total;i++)scanf("%d",&arr[i]);

	indexes(arr,total);
	
	return 0;
}
