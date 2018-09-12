#include <stdio.h>
#include <vector>

using namespace std;

int max(int a, int b){return a>b?a:b;}

int ks(vector<int> &val, vector<int> &wt, int maxW){
	vector<int> dp(maxW+1,0);
	for(int i=0;i<val.size();i++) for(int j=maxW;j>=wt[i];j--) dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
	return dp[maxW];
}

int main() {
	vector<int> val = {60, 100, 120};
	vector<int> wt = {10, 20, 30};
	int maxW = 50;

	printf("%d\n",ks(val,wt,maxW)); 

	return 0;
}
