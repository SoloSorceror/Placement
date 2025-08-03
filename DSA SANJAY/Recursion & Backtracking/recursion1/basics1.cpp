#include <bits/stdc++.h>
using namespace std;

// write a recursion to find nth fibonnaci number

int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    return (fibo(n - 1) + fibo(n - 2));
}

int main()
{

    int n;
    cout << "Enter the fibonnaci number position: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Enter a non-negative number.";
        return 0;
    }

    cout << fibo(n);

    return 0;
}