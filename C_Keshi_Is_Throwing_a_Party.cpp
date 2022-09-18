#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<pair<lol, lol>> arr;
bool check(lol k)
{
    if (k == 1)
        return true;
    lol a = k - 1;
    lol b = 0;
    lol c = 0;
    for (lol i = 0; i < arr.size(); i++)
    {
        if (arr[i].first >= a && arr[i].second >= b)
        {
            a--;
            b++;
            c++;
        }
    }
    return c >= k;
}

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;

        for (lol i = 0; i < n; i++)
        {
            lol t, b;
            cin >> t >> b;
            arr.push_back(make_pair(t, b));
        }

        lol s = 1;
        lol e = n + 1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;

            if (check(m))
                s = m;

            else
                e = m;
        }
        cout << s << endl; 
        arr.clear();
    }

    return 0;
}