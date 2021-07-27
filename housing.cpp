#include <iostream>
using namespace std;
void check(int*a, int n, int k){
    int i=0,j=0,cs=0;
    while(j<n){
        //expand window
        cs+=a[j];
        ++j;
        //remove elements till cs>k and i<j
        while(cs>k and i<j){
            cs-=a[i];
            ++i;
        }
        //check for equal cs and k
        if(cs==k){
            cout<<i<<" "<<j-1<<endl;
        }
    }
    return;
}
int main() {
   int n;
   cin>>n;
   int k;
   cin>>k;
   int * a =new int;
   for(int i=0;i<n;++i) cin>>a[i];
   check(a,n,k);
   return 0;
}
