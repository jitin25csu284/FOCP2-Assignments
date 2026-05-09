#include<bits/stdc++.h>
using namespace std;

class Bank{
    map<int,long long> accounts;
    
    public:
    
    bool CREATE(int x, long long y){
        if(accounts.find(x)!=accounts.end()){
            accounts[x]+=y;
            return false;
        }
        accounts[x]=y;
        return true;
    }
    
    bool DEBIT(int x, long long y){
        if(accounts.find(x)==accounts.end()){
            return false;
        }
        if(accounts[x]<y){
            return false;
        }
        accounts[x]-=y;
        return true;
    }
    
    bool CREDIT(int x, long long y){
        if(accounts.find(x)==accounts.end()){
            return false;
        }
        accounts[x]+=y;
        return true;
    }
    
    long long BALANCE(int x){
        if(accounts.find(x)==accounts.end()){
            return -1;
        }
        return accounts[x];
    }
};

int main(){
    int q;
    cin>>q;
    Bank b;
    while(q--){
        string type;
        cin>>type;
        if(type=="CREATE"){
            int x;
            long long y;
            cin>>x>>y;
            if(b.CREATE(x,y)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if(type=="DEBIT"){
            int x;
            long long y;
            cin>>x>>y;
            if(b.DEBIT(x,y)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if(type=="CREDIT"){
            int x;
            long long y;
            cin>>x>>y;
            if(b.CREDIT(x,y)) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        else if(type=="BALANCE"){
            int x;
            cin>>x;
            cout<<b.BALANCE(x)<<endl;
        }
    }
    return 0;
}
