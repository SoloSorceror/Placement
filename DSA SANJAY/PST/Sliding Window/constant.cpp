#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-1, 2, 3, 4, 5, 6, -7, 8};
    int n = arr.size();

    int k = 3;
    int sum = 0;

    // Step 1: sum of first k elements
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int max_sum = sum;
    int start_index = 0; // starting index of best subarray

    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        if (sum > max_sum)
        {
            max_sum = sum;
            start_index = i - k + 1; // new best start index
        }
    }
    cout << "Maximum sum of subarray of size " << k << " is " << max_sum << endl;

    cout << "Subarray: ";
    for (int i = start_index; i < start_index + k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}