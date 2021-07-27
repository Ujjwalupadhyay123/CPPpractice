#include <iostream>
#include<unordered_map>
#include<climits>
using namespace std;
string find(string s, string p){
    unordered_map<char,int>ms,mp;
    for(int i=0;i<p.size();++i) mp[p[i]]++;

    //sliding window algo
    int cnt=0,start=0;
    int start_idx=-1,min_so_far=INT_MAX,win_size;
    for(int i=0;i<s.size();++i){
        //expand window by including currenct character
        char ch=s[i];
        ms[ch]++;
        
        //count no. of characters matched till now
        if(mp[ch]!=0 and ms[ch]<=mp[ch]){
               cnt++;
        }

        //another thing
        //if all characters of patterns are found in curr window the start contracting
        if(cnt==p.length()){
            
            //start contracting from left to remove unwanted characters
            while(mp[s[start]]==0 or ms[s[start]]>mp[s[start]]){
                ms[s[start]]--;
                start++;
            }

            //note the window size
            int win_size=i-start+1;
            if(win_size<min_so_far){
                min_so_far=win_size;
                start_idx=start;
            }
        }

    }
    if(start_idx==-1) return "NO window found";
    return s.substr(start_idx,min_so_far);
}


int main() {
    string s,t;
    cin>>s>>t;
    cout<<find(s,t)<<endl;
}
