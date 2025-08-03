#include <bits/stdc++.h>
using namespace std;

void rev(int arr1[], int p, int q)
{

    if (q <= p)
        return;
    swap(arr1[p], arr1[q]);
    return rev(arr1, p + 1, q - 1);
}

int main()
{

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int p = 0, q = 7;

    rev(arr1, p, q);

    for (int i = 0; i < 8; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}