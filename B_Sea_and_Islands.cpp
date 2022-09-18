#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    if (n % 2 == 0)
    {
        if (n * 1ll * (n / 2) < k)
            cout << "NO";
        else
        {
            cout << "YES" << endl;
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                char q;
                if (i % 2 == 0)
                    q = 'L';
                else
                    q = 'S';

                for (lol j = 0; j < n; j++)
                {
                    if (q == 'S')
                        q = 'L';
                    else
                        q = 'S';
                    if (q == 'L')
                    {
                        if (c < k)
                        {
                            cout << q;
                            c++;
                        }
                        else
                            cout << 'S';
                    }
                    else
                        cout << q;
                }
                cout << endl;
            }
        }
    }
    else
    {
        if (((n / 2 + 1) * 1ll * (n / 2 + 1) + (n / 2) * 1ll * (n / 2)) < k)
            cout << "NO";
        else
        {
            cout << "YES" << endl;
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                char q;
                if (i % 2 == 0)
                    q = 'S';
                else
                    q = 'L';

                for (lol j = 0; j < n; j++)
                {
                    if (q == 'S')
                        q = 'L';
                    else
                        q = 'S';
                    if (q == 'L')
                    {
                        if (c < k)
                        {
                            cout << q;
                            c++;
                        }
                        else
                            cout << 'S';
                    }
                    else
                        cout << q;
                }
                cout << endl;
            }
        }
    }

    return 0;
}