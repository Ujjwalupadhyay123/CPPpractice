#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int minfrogjump(int *a,int n){
   vector<int> dp(n,0);
   dp[0]=0;
   dp[1]=abs(dp[1]-dp[0]);
   for(int i=2;i<n;++i){
     dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
   } 
   return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    cout<<minfrogjump(a,n)<<endl;
    return 0;
}