#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class Car{
    public:
    string id;
    int x,y;
    Car(string id,int x,int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int getdist() const{
        return x*x+y*y;
    }
    string getname() const{
        return this->id;
    }
};
// bool static compare(Car car1,Car car2){
//     return car1.getdist()<car2.getdist();
// }

class Carcomp{
    public:
    bool operator()(const Car a,const Car b){
        return a.getdist()<b.getdist();         //maxheap
    }
};

void printnearest(vector<Car> cars,int k){
    // sort(cars.begin(),cars.end(),compare);
    // for(int i=0;i<k;++i){
    //     cout<<cars[i].getname()<<endl;
    // }
    priority_queue<Car,vector<Car>,Carcomp> p(cars.begin(),cars.begin()+k);
    for(int i=k;i<cars.size();++i){
        auto car= cars[i];
        if(car.getdist()<p.top().getdist()){
            p.pop();
            p.push(car);
        }
    }
    
    while(!p.empty()){
        cout<<p.top().getname()<<endl;
        p.pop();
    }

}
int main(){
    int n,k;
    cin>>n>>k;
    vector<Car> cars;
    string s;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>s>>x>>y;
        Car car(s,x,y);
        cars.push_back(car);
    }
    
    printnearest(cars,k);

}