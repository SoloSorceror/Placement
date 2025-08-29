#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;

    int prev2 = 0;
    int prev = 1;

    for (int i = 0; i <= n; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
}