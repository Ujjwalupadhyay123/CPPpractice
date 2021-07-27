#include <iostream>
#include<list>
#include<unordered_map>

using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<T,list<T> >l;
    
    void addEdge(T u,T v,bool bir=false){
        l[u].push_back(v);
        if(bir){
            l[v].push_back(u);
        }
    }

    void printgraph(){
        for(auto node:l){
            cout<<node.first<<"-->";
            for(auto x: node.second){
                cout<<x<<",";
            }

            cout<<endl;
        }
    }
};

int main() {
    graph<string>s;
    s.addEdge("putin","trump");
     s.addEdge("putin","modi");
      s.addEdge("putin","pope");
       s.addEdge("modi","trump",true);
        s.addEdge("modi","yogi",true);
         s.addEdge("yogi","prabhu");
         s.addEdge("prabhu","modi");

         s.printgraph();
         cout<<endl;
}
