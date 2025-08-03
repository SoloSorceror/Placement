// #include <iostream>
// using namespace std;

// int sumOf(int n)
// {
//     if (n == 0)
//         return 0;

//     return n + sumOf(n - 1);
// }

// int main()
// {
//     int n = 10;
//     cout << sumOf(n) << " ";
//     return 0;
// }

#include <iostream>
using namespace std;

int sumOf(int &sum, int n)
{
    if (n == 0)
        return sum;

    sum += n;

    return sumOf(sum, n - 1);
}

int main()
{
    int n = 10;
    int sum = 0;

    cout << sumOf(sum, n) << " ";
    return 0;
}