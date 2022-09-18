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
        lol n, m, k;
        cin >> n >> m >> k;
        string a;
        cin >> a;
        string b;
        cin >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = a.size() - 1;
        int j = b.size() - 1;
        int ca = 0;
        int cb = 0;
        string ans = "";
        while (i >= 0 && j >= 0)
        {
            if (a[i] < b[j])
            {
                if (ca == k)
                {
                    ca = 0;
                    cb = 1;
                    ans.push_back(b[j]);
                    b.pop_back();
                }
                else
                {
                    ca++;
                    cb = 0;
                    ans.push_back(a[i]);
                    a.pop_back();
                }
            }
            else if (a[i] > b[j])
            {
                if (cb == k)
                {
                    cb = 0;
                    ca = 1;
                    ans.push_back(a[i]);
                    a.pop_back();
                }
                else
                {
                    cb++;
                    ca = 0;
                    ans.push_back(b[j]);
                    b.pop_back();
                }
            }
            else
            {
                if (a.size() <= b.size())
                {
                    if (ca == k)
                    {
                        ca = 0;
                        cb = 1;
                        ans.push_back(b[j]);
                        b.pop_back();
                    }
                    else
                    {
                        ca++;
                        cb = 0;
                        ans.push_back(a[i]);
                        a.pop_back();
                    }
                }
                else
                {
                    if (cb == k)
                    {
                        cb = 0;
                        ca = 1;
                        ans.push_back(a[i]);
                        a.pop_back();
                    }
                    else
                    {
                        cb++;
                        ca = 0;
                        ans.push_back(b[j]);
                        b.pop_back();
                    }
                }
            }

            i = a.size() - 1;
            j = b.size() - 1;
        }
        cout << ans << endl;
    }

    return 0;
}