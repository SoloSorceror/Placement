#include <bits/stdc++.h>
using namespace std;

int frogJumpK(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int cost = dp[i - j] + abs(heights[i] - heights[i - j]);
                dp[i] = min(dp[i], cost);
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    vector<int> heights1 = {2, 1, 3, 5, 4};
    cout << frogJumpK(heights1, 2) << endl; // Output: 2 (same as normal problem)

    vector<int> heights2 = {10, 30, 40, 20};
    cout << frogJumpK(heights2, 3) << endl; // Example with k=3
}
