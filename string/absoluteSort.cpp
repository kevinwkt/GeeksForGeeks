#include <stdio.h>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int main(){

	int arr[]={10,5,3,9,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int target = 7;

	map<int,vector<int> > mp;

	for(int i=0;i<size;i++){
		if(mp.find(abs(arr[i]-target))==mp.end()) mp[abs(arr[i]-target)]=vector<int>();
		mp[abs(arr[i]-target)].push_back(arr[i]);
	}

	int ans[5] = {};

	int i=0;

	for(auto it=mp.begin(); it!=mp.end(); it++){
		//printf("%3d",it->second);
		for(int t=0; t<it->second.size();t++){
			ans[i++]=it->second[t];
		}
	}

	for(int i=0;i<5;i++) printf("%3d",ans[i]);

	printf("\n");

	return 0;
}
