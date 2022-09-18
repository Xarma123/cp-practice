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
    if (s.size()==1)
        cout << 0;
    else
    {
        lol ans = 1;
        lol n = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            n += s[i] - '0';
        }
        while (n >= 10)
        {   
            ans++;
            lol ne = 0;
            while (n)
            {
                ne += n % 10;
                n /= 10;
            }
            n = ne;
        }
        cout<<ans;
    }

    return 0;
}