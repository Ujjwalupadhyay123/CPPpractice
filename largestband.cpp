#include<iostream>
#include<unordered_set>
using namespace std;
int largest(int *a,int n)
{
unordered_set <int> s(a,a+n);
int  maxl=0,l;
for(int i=0;i<n;++i){
     int temp=a[i];
     if(s.find(temp)!=s.end())
     {   l=1;
         while(s.find(temp-1)!=s.end()){
         l++;
         temp-=1;
     }}

     maxl=max(maxl,l);
}
return maxl;

}
int main(){
   int a[]={1,9,3,0,18,5,2,4,10,7,12,6};
   int x=largest(a,12);
   cout<<x<<endl;
    return 0;
}