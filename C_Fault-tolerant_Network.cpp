#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol A_(lol a[], lol b[], lol n, lol A)
{
    lol j = lower_bound(b, b + n, A) - b;
    lol v = LONG_LONG_MAX;
    if (j < n)
    {
        v = abs(A - b[j]);
    }
    j--;
    if (j >= 0)
    {
        v = min(v, abs(A - b[j]));
    }
    return v;
}
lol B_(lol a[], lol b[], lol n, lol B)
{
    lol j = lower_bound(a, a + n, B) - a;
    lol v = LONG_LONG_MAX;
    if (j < n)
    {
        v = abs(B - a[j]);
    }
    j--;
    if (j >= 0)
    {
        v = min(v, abs(B - a[j]));
    }
    return v;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol A1, A2;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                A1 = a[i];
            if (i == n - 1)
                A2 = a[i];
        }
        lol b[n];
        lol B1, B2;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (i == 0)
                B1 = b[i];
            if (i == n - 1)
                B2 = b[i];
        }
        lol ans = 0;
        sort(a, a + n);
        sort(b, b + n);
        ans += A_(a, b, n, A1);
        ans += A_(a, b, n, A2);
        ans += B_(a, b, n, B1);
        ans += B_(a, b, n, B2);

        // case A1 B2
        lol ans1 = abs(A1 - B2);
        ans1 += A_(a, b, n, A2);
        ans1 += B_(a, b, n, B1);
        ans = min(ans1, ans);
        // A1 B1
        ans1 = abs(A1 - B1);
        ans1 += A_(a, b, n, A2);
        ans1 += B_(a, b, n, B2);
        ans = min(ans1, ans);
        // a2 b2
        ans1 = abs(A2 - B2);
        ans1 += A_(a, b, n, A1);
        ans1 += B_(a, b, n, B1);
        ans = min(ans1, ans);
        // a2 b1
        ans1 = abs(A2 - B1);
        ans1 += A_(a, b, n, A1);
        ans1 += B_(a, b, n, B2);
        ans = min(ans1, ans);
        // a1 b1 a2 b2
        ans1 = abs(A2 - B2);
        ans1 += abs(A1 - B1);
        ans = min(ans1, ans);
        // a1 b2 a2 b1
        ans1 = abs(A2 - B1);
        ans1 += abs(A1 - B2);
        ans = min(ans1, ans);

        cout << ans << endl;
    }

    return 0;
}