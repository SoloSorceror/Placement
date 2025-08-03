#include <bits/stdc++.h>
using namespace std;

bool palindrome(string word, int p, int q)
{
    if (q <= p)
        return true;

    if (word[p] != word[q])
        return false;

    return palindrome(word, p + 1, q - 1);
}

int main()
{

    string word;
    cout << "Enter the string to check for palindrome: ";
    cin >> word;
    int p = 0, q = word.length() - 1;

    if (palindrome(word, p, q))
    {
        cout << "IS palindrome";
    }
    else
    {
        cout << "Not a palindrome";
    }

    return 0;
}