#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        long long a;
        bool c = true, s = true, arr[n];
        cin >> a;
        arr[0] = a;
        for (long long i = 1; i < n; i++)
        {
            long long t;
            cin >> t;
            arr[i] = t;
            if (c)
            {
                if (t >= a)
                {
                    a = t;
                    continue;
                }
                else
                {
                    c = false;
                    s = false;
                }
            }
        }
        if (s)
        {
            cout << "YES" << endl;
        }
        else if (x < n)
        {
            if (x < n / 2)
            {
                cout << "YES" << endl;
                continue;
            }
            if (n % 2 == 0 && x == n / 2)
            {
                cout << "YES" << endl;
                continue;
            }
            bool q = is_sorted(arr + n - 1 - x, arr + x );
            if (!q)
            {
                cout << "NO" << endl;
                continue;
            }
            bool q2 = true, q3 = true;
            for (long long i = 0; i <= n - 1 - x; i++)
            {
                if (arr[i] > arr[(n - x)])
                {
                    q2 = false;
                    break;
                }
            }
            if (!q2)
            {
                cout << "NO" << endl;
                continue;
            }

            for (long long i = x; i < n; i++)
            {
                if (arr[i] < arr[(x - 1)])
                {
                    q2 = false;
                    break;
                }
            }
            if (!q2)
            {
                cout << "NO" << endl;
                continue;
            }

            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}