#include <iostream>
using namespace std;

int main(){
    long long L,R;
    cin>>L>>R;

    long long odd=(R+1)/2 - L/2;

    if(odd%2==0){
        cout<<"even";
    }
    else{
        cout<<"odd";
    }
}
