    #include <bits/stdc++.h>
    using namespace std;
    #define lol long long
    int main()
    {
        lol t;
        cin >> t;
        while (t--)
        {
            string s;
            cin >> s;
            char c = '\n';
            bool ans = false;
            for (lol i = 0; i < (s.size()) / 2ll; i++)
            {
                if (c == '\n')
                    c = s[i];
                else if (c != s[i])
                    ans = true;
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }