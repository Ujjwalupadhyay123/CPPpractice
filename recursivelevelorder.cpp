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
int height(node* root){
    if(!root) return 0;
    return max(height(root->left), height(root->right))+1;
}
void printKthlevel(node*root,int k){
    if(!root) return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);

}
void printlevelorder(node* root){
    int h=height(root);
    for(int i=1;i<=h;++i){
        printKthlevel(root,i);
        cout<<endl;
    }
}
int main(){
  node* root=buildtree();
//   print(root);
  printlevelorder(root);
  return 0;
}