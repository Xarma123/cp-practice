#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    bool out = true;
    lol l = 0, no = 0;
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            out = false;
        }
        else if (s[i] == ')')
        {
            out = true;
        }
        else if (s[i] != '_')
        {
            lol j = i + 1;
            while (j < n && s[j] != ')' && s[j] != '_' && s[j] != '(')
                j++;
            if (out)
                l = max(l, j - i);
            else
                no++;

            i = j - 1;
        }
    }
    cout << l << " " << no << endl;

    return 0;
}