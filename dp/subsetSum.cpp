#include <stdio.h>
#include <vector>

using namespace std;

bool subset(vector<int> &v, int target){
	vector<vector<bool> > dp(v.size()+1,vector<bool>(target+1,1));
	for(int i=0;i<=v.size();i++){
		for(int j=0;j<=target;j++){
			if(j==0) dp[i][j]=1;
			else if(i==0) dp[i][j]=0;
			else if(j-v[i-1]>=0) dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
			else dp[i][j]=dp[i-1][j]; 
		}
	}

	for(int i=1;i<=v.size();i++){
		for(int j=1;j<=target;j++){
			printf("%3d",dp[i][j]? 1:0);
		}
		printf("\n");
	}
	return dp[v.size()][target];
}

int main(){
	vector<int> v = {2,3,7,8,10};
	int target = 32;
	printf("%d\n",subset(v,target)? 1:0);
	return 0;
}
