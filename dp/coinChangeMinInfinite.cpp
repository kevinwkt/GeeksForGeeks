#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int min(int a, int b){return a<b?a:b;}

int coin(vector<int> &v, int target){
	vector<int> dp(target+1,INT_MAX-1);
	dp[0]=0;
	for(int i=0;i<v.size();i++) for(int j=v[i];j<=target;j++) dp[j]=min(dp[j],dp[j-v[i]]+1);
	return dp[target];
}

int main(){
	vector<int> v={1,5,6,8};
	int target= 11;
	printf("%d\n",coin(v,target));
	return 0;
}
