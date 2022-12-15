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
    for (lol i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
        {
            s.erase(i, 1);
            i--;
        }
    }

    for (lol i = 0; i < s.size(); i++)
    {
        cout << '.' << s[i];
    }
    

    return 0;
}