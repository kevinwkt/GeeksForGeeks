#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int lcs(string a, string b){
	vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[a.length()][b.length()];
}

int main(){
	printf("%d\n",lcs("abcdaf","acbcf"));
	return 0;
}
