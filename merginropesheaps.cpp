#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    vector<int> v={4,3,2,6};
    priority_queue<int,vector<int>,greater<int>> p(v.begin(),v.end());
    int cost=0;
    // while(!p.empty()){
    //     cout<<p.top()<<endl;
    //     p.pop();
    // }
    while(p.size()>1){
        int a=p.top();
        p.pop();

       int b=p.top();
        p.pop();

        int newrop=(a+b);
        cost +=newrop;
        p.push(newrop);
    }
  cout<<cost<<endl;

  return 0;
}
