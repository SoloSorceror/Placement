#include<bits/stdc++.h>
using namespace std;

int main(){
    
    stack <int> s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"top element" <<s.top()<<endl;

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}