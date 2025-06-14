#include<bits/stdc++.h>
using namespace std;

void func(int* head) {
    *head = 10; // modifies the value pointed to
    head = nullptr; // only changes local copy of pointer
}

int main(){
    int x = 5;
    int* p = &x;
    func(p);
// x is now 10
// p is still pointing to x

}