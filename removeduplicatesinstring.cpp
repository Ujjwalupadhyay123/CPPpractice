#include<iostream>
using namespace std;
void removedup(string &s){
   int idx=0;
   for(int i=0;i<s.length();++i){
       if(s[i]!=s[i+1]){
           s[idx++]=s[i];
       }
   }
   s.erase(s.begin()+idx,s.end());
}
int main(){
    string s;
    cin>>s;
    removedup(s);
    cout<<s;
}