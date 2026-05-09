#include<bits/stdc++.h>
using namespace std;

class MovieTicket{
    map<int,set<int>> movieCustomers;
    map<int,int> availableSlots;
    
    public:
    
    bool BOOK(int x, int y){
        if(availableSlots.find(y)==availableSlots.end()){
            availableSlots[y]=100;
        }
        if(availableSlots[y]<=0){
            return false;
        }
        if(movieCustomers[y].count(x)){
            return false;
        }
        movieCustomers[y].insert(x);
        availableSlots[y]--;
        return true;
    }
    
    bool CANCEL(int x, int y){
        if(!movieCustomers[y].count(x)){
            return false;
        }
        movieCustomers[y].erase(x);
        if(availableSlots.find(y)==availableSlots.end()){
            availableSlots[y]=100;
        }
        availableSlots[y]++;
        return true;
    }
    
    bool IS_BOOKED(int x, int y){
        if(movieCustomers[y].count(x)){
            return true;
        }
        return false;
    }
    
    int AVAILABLE_TICKETS(int y){
        if(availableSlots.find(y)==availableSlots.end()){
            return 100;
        }
        return availableSlots[y];
    }
};

int main(){
    int q;
    cin>>q;
    MovieTicket mt;
    while(q--){
        string type;
        cin>>type;
        if(type=="BOOK"){
            int x,y;
            cin>>x>>y;
            if(mt.BOOK(x,y)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if(type=="CANCEL"){
            int x,y;
            cin>>x>>y;
            if(mt.CANCEL(x,y)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if(type=="IS_BOOKED"){
            int x,y;
            cin>>x>>y;
            if(mt.IS_BOOKED(x,y)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if(type=="AVAILABLE_TICKETS"){
            int y;
            cin>>y;
            cout<<mt.AVAILABLE_TICKETS(y)<<endl;
        }
    }
    return 0;
}
