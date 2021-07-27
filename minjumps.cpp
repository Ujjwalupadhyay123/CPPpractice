#include<iostream>
#include<vector>
using namespace std;
//Top down
int minjump(vector<int>v,int n,vector<int>dp,int i){
    //base cases
    if(i==n-1) return 0;
    if(i>=n) return INT_MAX;
    //recursive cases
    if(dp[i]!=0) return dp[i];
    int steps=INT_MAX;
    int max_jump=v[i];
    for(int jump=1;jump<=max_jump;jump++){
        int next_index=i+jump;
        int subproblem=minjump(v,n,dp,next_index);
        if(subproblem!=INT_MAX){
            steps=min(steps,subproblem+1);
        }
    }
    return dp[i]=steps;
}

int main(){
    vector<int> v{3,4,2,1,2,3,7,1,1,3};
    int n=v.size();
    vector<int>dp(n,0);
    cout<<minjump(v,n,dp,0)<<endl;
}
