#include<iostream>
#include<map>
using namespace std;
int check(int *a,int r,int n){
    map<int,int>right;
    map<int,int>left;
   for(int i=0;i<n;++i){
       right[a[i]]++;
       left[a[i]]=0;
   }
   int ans=0;
   for(int i=0;i<n;++i){
         right[a[i]]--;
         if(a[i]%2==0){
            int b=a[i];
            int  arr=a[i]/r;
            int c=a[i]*r;
            ans+=left[arr]*right[c];
         }
         left[a[i]]++;
   }
  return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int r;
    cin>>r;
    int cnt=check(a,r,n);
    cout<<cnt<<endl;
    return 0;
}