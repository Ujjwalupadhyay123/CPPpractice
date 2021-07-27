#include<iostream>
using namespace std;
//recursive solution
int maxp(int* a,int n){
    //base case:
    if(n<=0) return 0;
    //recursive case:
    int ans=INT_MIN;
    for(int i=0;i<n;++i){
        int cut=i+1;
       ans=max(ans,a[i]+maxp(a,n-cut));
    }

    return ans;
}

//TOpdown approach
int maxpTopdown(int* a,int n,int*dp){
    //base case:
    if(n<=0) return 0;
    //recursive case:
    if(dp[n]!=0) return dp[n];
    int ans=INT_MIN;
    for(int i=0;i<n;++i){
        int cut=i+1;
       ans=max(ans,a[i]+maxpTopdown(a,n-cut,dp));
    }

    return dp[n]=ans;
}

//bottomup approach:
int maxpbottomup(int* a, int n){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;++i){
        int ans=INT_MIN;
        for(int j=0;j<n;++j){
            int cut=j+1;
            if(i-cut>=0)
            ans=max(ans,a[j]+dp[i-cut]);
         }
        dp[i]=ans;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;++i){
        cin>>a[i];
    }
    int dp[100]={0};
   cout<<maxp(a,n)<<endl;
   cout<<maxpTopdown(a,n,dp)<<endl;
   cout<<maxpbottomup(a,n)<<endl;
    
    return 0;
}