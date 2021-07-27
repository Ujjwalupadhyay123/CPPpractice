#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    int dp[100]={0};
    for(int i=2;i<=n;++i){ 
        int a,b,c;
        a=b=c=INT_MAX;
        if(n%3==0){
            a=dp[i/3];

        }
        if(n%2==0){
            b=dp[i/2];
        }
        c=dp[i-1];

        dp[i]=min(a,min(b,c))+1;
    }
    cout<<dp[n];
    return 0;
}