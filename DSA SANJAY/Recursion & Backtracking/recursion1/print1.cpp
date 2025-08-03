#include <iostream>
using namespace std;

void prints(int n)
{
    if (n == 0)
        return;

    prints(n - 1);
    cout << n << " ";
}

int main()
{

    prints(10);
    return 0;
}