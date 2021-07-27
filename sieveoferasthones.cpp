#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> ans;
	vector<bool>prime(n+1,true);
	prime[0]=prime[1]=false;
	for(int i=2;i<=n;++i){
	    if(prime[i]){
	        ans.push_back(i);
	    }
	    for(int j=i;j<=n;j+=i){
	        prime[j]=false;
	    }
	}
	for(auto ch:ans){
	    cout<<ch<<" ";
	}
	return 0;
}