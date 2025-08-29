#include <bits/stdc++.h>
using namespace std;

int solveUtil(int index, vector<int> &height, vector<int> &dp, int k)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];
    int min_steps = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int steps = solveUtil(index - i, height, dp, k) + abs(height[index] + height[index - i]);
            min_steps = min(steps, min_steps);
        }
    }
    return dp[index] = min_steps;
}

int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);               // Initialize a memoization array for the main function
    cout << solve(n, height, k) << endl; // Print the result of the solve function
    return 0;
}