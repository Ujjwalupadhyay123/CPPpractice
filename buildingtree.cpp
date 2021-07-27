#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* buildtree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;
    node* root=new node(x);
    root->left=buildtree();
    root->right=buildtree();

    return root;
}
void print(node* root){
    if(!root) return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

}
int main(){
  node* root=buildtree();
  print(root);
  return 0;
}