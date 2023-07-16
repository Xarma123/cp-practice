#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol i = 0, j = n - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                break;
        }
        while (i < j)
        {
            if (s[i] != s[j])
            {
                i++;
                j--;
            }
            else
                break;
        }
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                break;
        }
        if (i < j)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}