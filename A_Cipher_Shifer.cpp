#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        string a[n + 1];
        a[0] = "";
        for (lol i = 0; i < n; i++)
        {
            lol j;
            for (j = i - 1; j >= 0; j--)
            {
                if (s[i] == s[j] && a[j] != "A")
                {
                    a[i + 1] = a[j];
                    a[i + 1].push_back(s[i]);
                  
                    break;
                }
            }
            if (j < 0)
                a[i + 1] = "A";
            
        }
        cout << a[n] << "\n";
    }
}