#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    char z = s[0];
    cout << "Mike" << endl;
    for (lol i = 1; i < s.size(); i++)
    {
        if (s[i] <= z)
        {
            cout << "Mike" << endl;
            z = s[i];
        }
        else
        {
            cout << "Ann" << endl;
        }
    }

    return 0;
}