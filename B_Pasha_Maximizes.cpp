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
    lol k;
    cin >> k;
    for (lol i = 0; i < s.size(); i++)
    {

        for (char c = '9'; c >= '0' && c > s[i]; c--)
        {

            lol j;
            for (j = i + 1; j < s.size(); j++)
            {
                if (s[j] == c)
                    break;
            }

            if (j != s.size() && j - i <= k)
            {

                while (j != i)
                    swap(s[j], s[j - 1]), j--, k--;

                break;
            }
        }
    }
    cout << s;

    return 0;
}