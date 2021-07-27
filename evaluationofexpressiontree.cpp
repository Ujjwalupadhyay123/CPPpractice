#include <bits/stdc++.h> 
using namespace std; 
  
// Class to represent the nodes of syntax tree 
class node 
{ 
public: 
    string info; 
    node *left = NULL, *right = NULL; 
    node(string x) 
    { 
        info = x; 
    } 
};

int toint(string s){
    int num=0;
    if(s[0]!='-'){
        for(int i=0;i<s.length();++i)
        num=num*10+s[i]-'0';
    }
    else{
       for(int i=1;i<s.length();++i){
           num=num*10+(s[i]-'0');  
       }
       num=num*-1;
    }

    return num;
}

int eval(node* root){
    if(!root) return 0;
    if(!root->left and !root->right) return toint(root->info);

    //recursive case
    int lnum=eval(root->left);
    int rnum=eval(root->right);
    if(root->info=="+") return lnum+rnum;
    else if(root->info=="-") return lnum-rnum;
         else if(root->info=="*") return lnum*rnum;
         else return lnum/rnum;
}

int main(){
    node *root = new node("+"); 
    root->left = new node("*"); 
    root->left->left = new node("5"); 
    root->left->right = new node("-4"); 
    root->right = new node("-"); 
    root->right->left = new node("100"); 
    root->right->right = new node("20"); 
    cout << eval(root) << endl; 
  
    delete(root); 
  
    root = new node("+"); 
    root->left = new node("*"); 
    root->left->left = new node("5"); 
    root->left->right = new node("4"); 
    root->right = new node("-"); 
    root->right->left = new node("100"); 
    root->right->right = new node("/"); 
    root->right->right->left = new node("20"); 
    root->right->right->right = new node("2"); 
  
    cout << eval(root); 
    return 0;
}