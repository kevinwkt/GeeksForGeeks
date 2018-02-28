//Given three numbers sum S, prime P, and N, find all N prime numbers after prime P such that their sum is equal to S.

#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int a){

	for(int i=2;i<sqrt(a)+1;i++) if(!(a%i)) return false;

	return true;
}

void primeSumPrint(int N, int S, vector<int> primes, vector<int> answer, int index, int sum){

	if(answer.size()==N&&sum==S){
		for(int i=0;i<answer.size();i++) printf("%3d",answer[i]);
		printf("\n");
		return;
	}

	if(sum>S||index==primes.size()) return;

	answer.push_back(primes[index]);

	primeSumPrint(N,S,primes,answer,index+1,sum+primes[index]);

	answer.erase(answer.begin()+answer.size()-1);

	primeSumPrint(N,S,primes,answer,index+1,sum);
}

int main(){

	int N,P,S;
	vector<int> primes;
	vector<int> answer;

	scanf("%d %d %d",&N,&P,&S);

	//Find primes greater than P but smaller than S
	for(int i=P+1;i<=S;i++) if(isPrime(i)) primes.push_back(i);

	//Call recursive backtrack function
	primeSumPrint(N,S,primes,answer,0,0);
	
	return 0;
}
