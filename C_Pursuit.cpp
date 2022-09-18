#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        lol N = n;
        lol st = n - n / 4;
        for (lol i = n - 1 - st; i >= 0; i--)
        {
            a[i] = 100;
        }

        lol pa[n + 1];
        lol pb[n + 1];
        pa[0] = 0;
        pb[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            pa[i] = pa[i - 1] + a[i - 1];
            pb[i] = pb[i - 1] + b[i - 1];
        }
        lol c = 0;
        bool f = true;
        lol score1 = 0, score2 = 0;
        while (1)
        {

            st = n - n / 4;
            if (N - st + c >= N || N - st + c < 0)
                break;

            score1 = pa[N] - pa[N - st + c] + c * 100;
            if (st <= N)
                score2 = pb[N] - pb[N - st];
            else
                score2 = pb[N];

            lol ext = score2 - score1;
            if (ext <= 0)
            {
                cout << n - N << endl;
                f = false;
                break;
            }
            c++;

            n++;
        }

        if (f)
        {

            while (1)
            {
                lol ext = score2 - score1;

                if (ext <= 0)
                {
                    cout << n - N << endl;
                    break;
                }
                if (n - n / 4 != (n + 1) - (n + 1) / 4)
                {
                    score1 += 100;
                }
                n++;
            }
        }
    }

    return 0;
}