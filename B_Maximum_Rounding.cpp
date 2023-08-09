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
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        lol i;
        lol j = -1;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] >= '5')
            {

                lol k = i + 1;
                while (k < s.size() && s[k] == '9')
                {
                    k++;
                }
                j = k - 1;
                if (k >= s.size())
                {
                    s.push_back('1');
                }
                else
                {
                    s[k]++;
                }
                i = k - 1;
            }
        }
        for (lol i = 0; i <= j; i++)
        {
            s[i] = '0';
        }
        reverse(s.begin(), s.end());

        cout << s << '\n';
    }
}