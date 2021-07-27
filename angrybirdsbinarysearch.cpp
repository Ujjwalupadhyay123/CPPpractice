#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canplace(int b,int n, vector<int>&v,int seperation){
    int birds=1;
    int location=v[0];
    for(int i=1;i<=n-1;++i){
        int current_location=v[i];
        if(current_location-location>=seperation){
            ++birds;
            location=current_location;

            if(birds==b) return true;
        }
    }
    return false;
}
int main() {
    vector<int>v{1,2,4,8,9};
    sort(v.begin(),v.end());
    int b=3;
    int n=v.size(),ans=-1;;
    int s=0;
    int e=v[n-1]-v[0];
    while(s<=e){
        int mid=(s+e)/2;
        if(canplace(b,n,v,mid)){ 
            ans=mid;
            s=mid+1;}
        else e=mid-1;
    }
    cout<<ans<<endl;
}
