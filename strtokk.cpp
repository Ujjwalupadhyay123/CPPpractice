#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char s[]="Today &@is a rainy day &@     guyzzzz";
    char *ptr=strtok(s,"&@");
    
    while(ptr!=NULL){
    cout<<ptr<<endl;
    ptr=strtok(NULL,"&@");
    
    }
    
    return 0;
}