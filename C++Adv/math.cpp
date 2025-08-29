#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

void reverseArray(vector<int> &arr)
{
    // code here
    int end = arr.size() - 1;
    int start = 0;
    reverse(arr, start, end);

    for (int i = 0; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 7};
    reverseArray(arr);
}