#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    // Build prefix sum
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Compute subarray sums
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = prefix[j + 1] - prefix[i];
            cout << "Sum of [" << i << "," << j << "] = " << sum << endl;
        }
    }
}
