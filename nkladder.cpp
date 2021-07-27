#include<iostream>
#include<vector>
using namespace std;
int countRecursive(int n,int k){
   if(n==0) return 1;
   if(n<1) return 0;
   int ans=0;
   for(int j=1;j<=k;++j){
       ans+=countRecursive(n-j,k);
   }
   return ans;
}
//topdownapproach O(n*k)
int countTopdown(int n,int k,int*dp){
   if(n==0) return 1;
   if(n<1) return 0;
   
   if(dp[n]!=0) return dp[n];
   int ans=0;
   for(int j=1;j<=k;++j){
       ans+=countTopdown(n-j,k,dp);
   }
   return dp[n]=ans;
}
//bottom up approack O(n*k)
int countbottomup(int n,int k){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int jump=1;jump<=k;++jump){
            if(i-jump>=0)
            dp[i]+=dp[i-jump];
        }
    }
  return dp[n];
    
}

//optimized version bottom up O(n)
int countwaysoptimised(int n,int k){
  vector<int>dp(n+1,0);
  dp[0]=dp[1]=1;
  for(int i=2;i<=k;++i) dp[i]=2*dp[i-1];
  for(int i=k+1;i<=n;++i) dp[i]=2*dp[i-1]-dp[i-k-1];

  return dp[n];
}
int main(){
    int n,k;
    int dp[100]={0};
    cin>>n>>k;
    cout<<countRecursive(n,k)<<endl;
    cout<<countTopdown(n,k,dp)<<endl;
    cout<<countbottomup(n,k)<<endl;
    return 0;
}