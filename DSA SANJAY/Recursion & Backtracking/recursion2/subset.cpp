#include <bits/stdc++.h>
using namespace std;

void subs(int index, vector<int> &arr, vector<int> &path)
{
    if (index == arr.size())
    {
        for (auto &it : path)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    path.push_back(arr[index]);
    subs(index + 1, arr, path);

    path.pop_back();
    subs(index + 1, arr, path);
}

int main()
{

    vector<int> arr = {3, 2, 1};
    vector<int> path;
    subs(0, arr, path);
    return 0;
}