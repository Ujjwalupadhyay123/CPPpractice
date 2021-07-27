#include<iostream>
using namespace std;
int sol[100][100]={0};
bool ratinamaze(char maze[][10],int i,int j,int n,int m){
  //base case
  if(i==n-1&&j==m-1){         //assumed cheeze at the bottom right
    sol[i][j]=1;
    for (int k = 0; k <n; k++)
		{
			for (int l = 0; l <m; l++)
			{
				cout<<sol[k][l]<<" ";
			}
			cout<<endl;
		}
		 cout<<endl;
    return true;
    //return false; //for all possible ways for rat to eat cheeze.
  }
  //recursivecase
  //to right
  sol[i][j]=1;
  if(j+1<m&&maze[i][j+1]!='X'){
    bool kyaright=ratinamaze(maze,i,j+1,n,m);
    if(kyaright){
      return true;
    }
  }
  //to bottom
  if(i+1<n && maze[i+1][j]!='X'){
    bool kyabottom=ratinamaze(maze,i+1,j,n,m);
    if(kyabottom){
      return true;
    }
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
  int m=4,n=4;
  ratinamaze(maze,0,0,n,m);
  return 0;
}
