#include <bits/stdc++.h>
using namespace std;

// int frogJumpRec(int i, vector<int>& heights) {
//     if (i == 0) return 0;
//     if (i == 1) return abs(heights[1] - heights[0]);

//     int oneStep = frogJumpRec(i-1, heights) + abs(heights[i] - heights[i-1]);
//     int twoStep = frogJumpRec(i-2, heights) + abs(heights[i] - heights[i-2]);
//     return min(oneStep, twoStep);
// }

int frogJumpRec(int i, vector<int> &heights)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return abs(heights[1] - heights[0]);

    int left = frogJumpRec(i - 1, heights) + abs(heights[i] - heights[i - 1]);
    int right = frogJumpRec(i - 2, heights) + abs(heights[i] - heights[i - 2]);
    return min(left, right);
}

int frogJumpMemo(int i, vector<int> &heights, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int left = frogJumpMemo(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;
    if (i > 1)
        right = frogJumpMemo(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
    return dp[i] = min(left, right);
}

int frogJumpTab(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n, 0);

    dp[0] = 0; // base case

    for (int i = 1; i < n; i++)
    {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if (i > 1)
            twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneStep, twoStep);
    }

    return dp[n - 1];
}

int frogJumpOptimized(vector<int> &heights)
{
    int n = heights.size();

    int prev = 0;  // dp[i-1]
    int prev2 = 0; // dp[i-2]

    for (int i = 1; i < n; i++)
    {
        int oneStep = prev + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if (i > 1)
            twoStep = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(oneStep, twoStep);
        prev2 = prev; // shift forward
        prev = curr;
    }

    return prev; // answer will be at the last "prev"
}
int main()
{
    vector<int> heights1 = {2, 1, 3, 5, 4};
    int n1 = heights1.size();
    vector<int> dp(n1, -1);
    cout << frogJumpMemo(heights1.size() - 1, heights1, dp) << endl; // Output: 2

    vector<int> heights2 = {7, 5, 1, 2, 6};
    cout << frogJumpRec(heights2.size() - 1, heights2) << endl; // Output: 9
}
