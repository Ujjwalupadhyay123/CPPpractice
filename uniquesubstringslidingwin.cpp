#include <iostream>
#include<unordered_map>
using namespace std;
string subst(string s){
    int i=0,j=0;
    unordered_map<char,int>mp;
    int win_length=0,start_idx=-1,max_wind=0;
    while(j<s.length()){
        char ch=s[j];

        //check for existing in map and that the idx>=i
        if(mp.count(ch) and mp[ch]>=i){
            i=mp[ch]+1;
            win_length=j-i; //updated remaining wind len excluding current cha
        }
        //upadating the last occ
        mp[ch]=j;
        win_length++;//updated for including current char
        j++;
        //checking for max window
        if(max_wind<win_length){
            max_wind=win_length;
            start_idx=i;
        }
    }
    return s.substr(start_idx,max_wind);
}
int main() {
    string s;
    cin>>s;
    string x="";
    x=subst(s);
    cout<<x;
}
