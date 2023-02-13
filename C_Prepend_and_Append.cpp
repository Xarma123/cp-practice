#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
                break;
            i++;
            j--;
        }
        cout << j - i + 1 << '\n';
    }

    return 0;
}