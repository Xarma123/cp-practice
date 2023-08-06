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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        set<lol> x;
        lol l = 0, r = n - 1;
        while (l <= r&&ans)
        {
            if (a[l] < a[r])
            {
                if (x.count(a[l]))
                    ans = false;
                if (x.size() && (*x.rbegin()) >= a[l])
                    ans = false;
                x.insert(a[l]);
                while (l <= r && a[l] == (*x.rbegin()))
                    l++;
            }
            else if (a[l] > a[r])
            {
                if (x.count(a[r]))
                    ans = false;
                if (x.size() && (*x.rbegin()) >= a[r])
                    ans = false;
                x.insert(a[r]);
                while (l <= r && a[r] == (*x.rbegin()))
                    r--;
            }
            else
            {
                if (x.count(a[l]))
                    ans = false;
                if (x.size() && (*x.rbegin()) >= a[l])
                    ans = false;
                x.insert(a[l]);
                while (l <= r && a[l] == (*x.rbegin()))
                    l++;
                while (l <= r && a[r] == (*x.rbegin()))
                    r--;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}