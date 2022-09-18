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
        if (s[0] < s.back())
        {

            lol i = 0, j = s.size() - 1;
            while (i < j)
            {
                if (s[i] < s[j])
                {
                    s[i] = char('0' + (s[j] - s[i]));
                    s[j] = '0';
                }
                else if (s[i] > s[j])
                {
                    s[j] = char('0' + (s[i] - s[j]));
                    s[i] = '0';
                }
                else
                {
                    s[i] = '0';
                    s[j] = '0';
                }
                i++;
                j--;
            }
            if (i == j)
                s[i] = '0';
            cout << s << endl;
        }
        else
        {
            if (s[0] != '9')
            {
                lol i = 0, j = s.size() - 1;
                s[j] = char('0' + (s[i] - s[j] + 1));
                s[i] = '1';
                i++;
                j--;
                while (i < j)
                {
                    if (s[i] < s[j])
                    {
                        s[i] = char('0' + (s[j] - s[i]));
                        s[j] = '0';
                    }
                    else if (s[i] > s[j])
                    {
                        s[j] = char('0' + (s[i] - s[j]));
                        s[i] = '0';
                    }
                    else
                    {
                        s[i] = '0';
                        s[j] = '0';
                    }
                    i++;
                    j--;
                }
                if (i == j)
                    s[i] = '0';
                cout << s << endl;
            }
            else
            {
                reverse(s.begin(), s.end());
                lol cary = 0;
                string ans = "";
                for (lol i = 0; i < n; i++)
                {
                    if (s[i] == '0')
                    {
                        if (cary)
                        {
                            ans.push_back('0');
                            cary = 0;
                        }
                        else
                        {
                            ans.push_back('1');
                            cary = 0;
                        }
                    }
                    else
                    {
                        if (cary)
                        {
                            ans.push_back(char(('9' - s[i]) + '1'));
                        }
                        else
                        {
                            if (s[i] == '1')
                            {
                                ans.push_back('0');
                            }
                            else
                            {
                                ans.push_back(char(('9' - s[i]) + '2'));
                                cary = 1;
                            }
                        }
                    }
                }
                reverse(ans.begin(), ans.end());
                cout << ans << endl;
            }
        }
    }

    return 0;
}