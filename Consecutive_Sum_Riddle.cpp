#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long j = 1;
        long long i;
        while (1)
        {
            i = 8 * n + (j * j);

            long long c = sqrt(i);
            if (i == c * c)
            {
                break;
            }

            j += 2;
        }

        long long l1, l2, r1, r2, l, r;

        l1 = (1 - sqrt(i - 8 * n)) / 2;
        l2 = (1 + sqrt(i - 8 * n)) / 2;

        r1 = (sqrt(1 - 4 * l1 + 4 * l1 * l1 + 8 * n) - 1) / 2;
        r2 = (sqrt(1 - 4 * l2 + 4 * l2 * l2 + 8 * n) - 1) / 2;

        long long q = r1 * r1 - l1 * l1 + l1 + r1;
        if (q == 2 * n)
        {
            l = l1;
            r = r1;
        }
        else
        {
            l = l2;
            r = r2;
        }

        cout << l << " " << r << endl;
    }

    return 0;
}