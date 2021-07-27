#include<iostream>
using namespace std;

bool ratinmaze(char maze[][10],int sol[][10],int i,int j,int m,int n){
    //base case
    if(i==m-1 and j==n-1){
        sol[i][j]=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    //recursive case
    sol[i][j]=1;
    if(j+1<n and (maze[i][j+1]!='X')){
        bool kyaright=ratinmaze(maze,sol,i,j+1,m,n);
        if(kyaright==true) return true;
    }
    if(i+1<m and (maze[i+1][j]!='X')){
        bool kyadown=ratinmaze(maze,sol,i+1,j,m,n);
        if(kyadown==true) return true;
    }
    sol[i][j]=0;

    return false;
}
int main(){
    char maze[][10]={
		"0000",
		"00XX",
		"0000",
		"XX00"

	};
    int sol[10][10]={0};
    int m=4,n=4;
    ratinmaze(maze,sol,0,0,m,n);
    return 0;
}