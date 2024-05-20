#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol n = s.size();
    lol c = 0;
    lol block[n];
    map<lol, lol> str;
    map<lol, lol> stc;
    map<lol, lol> st;
    for (lol i = 0; i < n; i++)
    {
        block[i] = c;
        lol j = i + 1;

        while (j < n && s[j] >= 'a' && s[j] <= 'z')
        {
            block[j] = c;
            j++;
        }
        str[c] = j - i;
        st[c] = i;
        string q = "";
        while (j < n && s[j] >= '0' && s[j] <= '9')
        {
            block[j] = c;
            q += s[j];
            j++;
        }
        if (q == "")
            q = "0";
        stc[c] = stoll(q);
        i = j - 1;
        c++;
    }
    lol q;
    cin >> q;
    while (q--)
    {
        lol l,r;
        
    }

    return 0;
}
