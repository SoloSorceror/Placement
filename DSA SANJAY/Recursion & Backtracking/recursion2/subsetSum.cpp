#include <bits/stdc++.h>
using namespace std;

void subSum(int index, int sum, vector<int> arr, vector<int> path)
{
    if (index == arr.size())
    {
        if (sum == 7)
        {
            for (auto &it : path)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    path.push_back(arr[index]);
    sum += arr[index];
    subSum(index + 1, sum, arr, path);

    path.pop_back();
    sum -= arr[index];
    subSum(index + 1, sum, arr, path);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> path;
    int sum = 0;
    int index = 0;

    subSum(index, sum, arr, path);
    return 0;
}