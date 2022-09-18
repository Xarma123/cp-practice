#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol l;
    cin >> l;
    stack<lol> t;
    t.push(1);
    bool ans = true;
    lol v = 0;
    lol q = powl(2, 32) - 1;
    while (l--)
    {
        string s;
        cin >> s;
        if (ans)
        {
            if (s == "add")
            {

                if (v + t.top() > q)
                    ans = false;
                v += t.top();
            }
            else if (s == "end")
                t.pop();
            else
            {
                cin >> s;
                lol c = stoll(s);
                t.push(min(q + 1, t.top() * 1ll * c));
            }
        }
    }
    if (ans)
        cout << v;
    else
        cout << "OVERFLOW!!!";

    return 0;
}