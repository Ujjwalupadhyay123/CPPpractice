#include<iostream>
#include<queue>
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
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp-> right);
        }
    }
}

int changesum(node*root){
    if(!root) return 0;
    if(!root->left and !root->right) return root->data;
    int temp=root->data;
    int lsum=
   root->data=changesum(root->left)+changesum(root->right);
   return temp+root->data;
}
int main(){
  node* root=buildtree();
  print(root);
  changesum(root);
  print(root);
  return 0;
}