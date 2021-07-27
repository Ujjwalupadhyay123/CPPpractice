#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    // for(int i=0;i<n;++i) cin>>a[i];    //Approach 1 0(n^3)
    // int maxsum=0;         
    // int id1=-1,id2=-1;
    // for(int i=0;i<n;++i){
    //     for (int j=i+1;j<n;++j){
    //         int csum=0;
    //         for(int k=i;k<=j;++k){
    //             csum+=a[k];
    //         }
    //        if(maxsum<csum){
    //            maxsum=csum;
    //            id1=i;
    //            id2=j;
    //        }
    //     }
       
    // }
    //  cout<<maxsum<<endl;
    //     for(int i=id1;i<=id2;++i){
    //         cout<<a[i]<<" ";
    //     }

    // //cumulatime sum approach O(n^2)
    // cin>>a[0];
    // int culsum[n];
    // culsum[0]=a[0];
    // for(int i=1;i<n;++i){
    //     cin>>a[i];
    //     culsum[i]=culsum[i-1]+a[i];
    // }
    // int csum,id1=-1,id2=-1;
    // int maxsum=0;
    // for(int i=0;i<n;++i){
    //     for(int j=i+1;j<n;++j){
    //         csum=0;
    //         csum=culsum[j]-culsum[i-1];
    //           if(maxsum<csum){
    //            maxsum=csum;
    //            id1=i;
    //            id2=j;
    //        }
    //     }
        

    // }
    // // cout<<endl;
    // // for(int i=0;i<n;++i){
    // //     cout<<culsum[i]<<" ";
    // // }
    // // cout<<endl;
    //  cout<<maxsum<<endl;
    //     for(int i=id1;i<=id2;++i){
    //         cout<<a[i]<<" ";
    //     }


   //kadens algo O(n)
   for(int i=0;i<n;++i){
       cin>>a[i];
   }
   int csum=0,tsum=0,id1=-1,id2=-1;
   for(int i=0;i<n;++i){
       csum=csum+a[i];
       if(csum<0){
           csum=0;
       }
       if(tsum<csum){
           tsum=csum;
       }
   }
   cout<<tsum<<endl;
   for(int i=id1;i<=id2;++i){
       cout<<a[i];
   }
    return 0;
}