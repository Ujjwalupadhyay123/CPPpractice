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
class Pair{
    public:
    int height;
    int diameter;
};
Pair diameter(node*root){
    Pair p;
    if(!root){
      p.height=0;
      p.diameter=0;
      return p;
    }
    Pair left=diameter(root->left);
    Pair right=diameter(root->right);
    p.height=max(left.height,right.height)+1;
    p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));

    return p;
}

int main(){
  node* root=buildtree();
  print(root);
  cout<<endl;
  Pair p=diameter(root);
  cout<<"Height="<<p.height<<"________"<<"Diameter="<<p.diameter<<endl;
  return 0;
}