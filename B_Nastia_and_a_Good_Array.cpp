#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct var
{
    lol i;
    lol j;
    lol x;
    lol y;
};
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol mn = -1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mn == -1)
                mn = i;
            if (a[mn] > a[i])
            {
                mn = i;
            }
        }
        vector<var> s;

        if (mn != 0)
        {
            var q;
            q.i = 1;
            q.j = mn + 1;
            q.x = a[mn];
            q.y = a[mn] + mn;
            a[0] = a[mn];
            a[mn] = a[0] + mn;
            s.push_back(q);
        }
        for (lol i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1] + 1)
            {
                var q;
                q.i = 1;
                q.j = i + 1;
                q.x = a[0];
                q.y = a[0] + i;

                a[i] = a[0] + i;
                s.push_back(q);
            }
        }
        cout << s.size() << endl;
        for (lol i = 0; i < s.size(); i++)
        {
            cout << s[i].i << " " << s[i].j << " " << s[i].x << " " << s[i].y << endl;
        }
    }

    return 0;
}