#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        string s = a;
        sort(s.begin(), s.end());
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] != s[i])
            {
                lol j = i + 1;
                lol l;
                while (j < a.size())
                {
                    if (a[j] == s[i])
                        l = j;
                    j++;
                }
                swap(a[i], a[l]);
                break;
            }
        }
        if (a < b)
            cout << a << '\n';
        else
            cout << "---\n";
    }
}