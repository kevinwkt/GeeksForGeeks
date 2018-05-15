#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool myCmp(string a, string b){
	string ab = a.append(b);
	string ba = b.append(a);

	return ab.compare(ba)>0? 1:0;  
}

int main(){

	vector<string> arr;
	
	arr.push_back("54");
    	arr.push_back("546");
    	arr.push_back("548");
    	arr.push_back("60");

	sort(arr.begin(),arr.end(),myCmp);


	string ans="";
	for(int i=0;i<arr.size();i++) ans.append(arr[i]);

	printf("%s\n",ans.c_str()); 

	return 0;
}
