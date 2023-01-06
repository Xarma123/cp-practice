#include <bits/stdc++.h>
#define LLL long long
using namespace std;
int main()
{
    LLL t;
    cin >> t;
    while (t--)
    {
        LLL n;
        cin >> n;
        vector<LLL> a(n), p(n), q(n);
        set<LLL> paval, qaval;
        map<LLL, vector<LLL>> wowman;
        LLL i = n;
        while (i--)
        {
            cin >> a[n - 1 - i];
            wowman[a[n - 1 - i]].push_back(n - 1 - i);
        }
        i = n;
        while (i--)
        {
            paval.insert(n - 1 - i + 1);
            qaval.insert(n - 1 - i + 1);
        }
        bool checker = true;
        for (auto e : wowman)
        {
            if (!checker)
                break;
            for (auto c : e.second)
            {
                if (!checker)
                    break;
                if (paval.find(e.first) != paval.end() && !qaval.empty() && (*qaval.begin()) <= e.first)
                {
                    paval.erase(e.first);

                    p[c] = e.first;

                    q[c] = (*qaval.begin());

                    qaval.erase(qaval.begin());
                }
                else if (qaval.find(e.first) != paval.end() && !paval.empty() && (*paval.begin()) <= e.first)
                {
                    qaval.erase(e.first);

                    q[c] = e.first;

                    p[c] = (*paval.begin());

                    paval.erase(paval.begin());
                }
                else
                    checker = false;
            }
        }
        if (!checker)
            cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            i = n;
            while (i--)
            {
                cout << p[n - 1 - i] << " ";
            }
            cout << '\n';
            i = n;
            while (i--)
            {
                cout << q[n - 1 - i] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}