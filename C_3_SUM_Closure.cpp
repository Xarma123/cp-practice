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
        lol n;
        cin >> n;
        lol a[n];
        lol z = 0;
        vector<lol> nz;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                z++;
            else
            {
                nz.push_back(a[i]);
            }
        }
        if (z)
        {
            if (nz.size() > 2)
                cout << "NO" << endl;
            else if (nz.size() == 2)
            {
                if (nz[0] + nz[1] == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        else
        {
            if (nz.size() > 4)
                cout << "NO" << endl;
            else
            {
                sort(nz.begin(), nz.end());
                if (nz.size() == 4)
                {
                    if (nz[0] + nz[3] == 0 && nz[1] + nz[2] == 0)
                        cout << "YES" << endl;
                    else
                        cout << "NO" << endl;
                }
                else if (nz.size() == 3)
                {
                    if (nz[0] + nz[1] == 0 || nz[0] + nz[2] == 0 || nz[1] + nz[2] == 0)
                        cout << "YES" << endl;
                    else
                        cout << "NO" << endl;
                }
                else
                    cout << "NO" << endl;
            }
        }
    }

    return 0;
}