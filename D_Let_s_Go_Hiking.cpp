#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    lol mx[n];
    lol mxr[n];
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            lol j = i + 1;
            while (j < n && p[j] < p[j - 1])
            {
                j++;
            }
            mx[i] = j - i;
        }
        else if (i == n - 1)
        {
            lol j = i - 1;
            while (j >= 0 && p[j] < p[j + 1])
                j--;
            mx[i] = max((mx[(i - 1)]), ((i) - (j)));
        }
        else
        {
            mx[i] = mx[i - 1];
            if (p[i] > p[i + 1] && p[i] > p[i - 1])
            {
                lol j = i + 1;
                while (j < n && p[j] < p[j - 1])
                {
                    j++;
                }
                mx[i] = max(mx[i], j - i);
                j = i - 1;
                while (j >= 0 && p[j] < p[j + 1])
                    j--;
                mx[i] = max(mx[i], i - j);
            }
        }
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            lol j = i + 1;
            while (j < n && p[j] < p[j - 1])
            {
                j++;
            }
            mxr[i] = max(mxr[i + 1], j - i);
        }
        else if (i == n - 1)
        {
            lol j = i - 1;
            while (j >= 0 && p[j] < p[j + 1])
                j--;
            mxr[i] = i - j;
        }
        else
        {
            mxr[i] = mxr[i + 1];
            if (p[i] > p[i + 1] && p[i] > p[i - 1])
            {
                lol j = i + 1;
                while (j < n && p[j] < p[j - 1])
                {
                    j++;
                }
                mxr[i] = max(mxr[i], j - i);
                j = i - 1;
                while (j >= 0 && p[j] < p[j + 1])
                    j--;
                mxr[i] = max(mxr[i], i - j);
            }
        }
    }
    lol ans = 0;
    for (lol i = 1; i < n - 1; i++)
    {
        if (p[i] > p[i + 1] && p[i] > p[i - 1])
        {
            lol v = max(mx[i - 1], mxr[i + 1]);
            lol j = i + 1;
            while (j < n && p[j] < p[j - 1])
            {
                j++;
            }
            lol l = (j - i);
            j = i - 1;
            while (j >= 0 && p[j] < p[j + 1])
                j--;
            lol r = (i - j);
            if (v - 1 < max(l, r) - 1)
            {
                bool f = true;
                if (l % 2 == 0 && r - 1 <= l - 1)
                {
                    f = false;
                }
                if (l % 2 != 0 && r - 1 <= l - 2)
                {
                    f = false;
                }
                swap(l, r);
                if (l % 2 == 0 && r - 1 <= l - 1)
                {
                    f = false;
                }
                if (l % 2 != 0 && r - 1 <= l - 2)
                {
                    f = false;
                }
                if (f)
                    ans++;
            }
        }
    }
    cout << ans;
}