#include<iostream>
#include<vector>
using namespace std;
int maxnonadjacentsum(int* a,int n){
    vector<int>dp(n+1,0);
    dp[0]=a[0];
    dp[1]=max(dp[0],dp[1]);
    for(int i=2;i<=n;++i){
        dp[i]=max(dp[i-2]+a[i],dp[i-1]);
    }

    return dp[n];
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;++i) cin>>a[i];
cout<<maxnonadjacentsum(a,n);

}