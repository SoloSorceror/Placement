#include <iostream>
using namespace std;

int main()
{

    // reverse right triangle
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = i; j < 5; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // right triangle

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // numbers

    // for (int i = 1; i < 6; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // reverse traingle of number

    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 5; j >= i; j--)
    //     {
    //         cout << 6 - j << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 5; i >= 1; i--)
    // {
    //     for (int j = 5; j >= i; j--)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // complete triangle

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5 - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}