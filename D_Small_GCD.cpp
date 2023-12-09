#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int p, q;
    cin >> p >> q;
    sort(arr, arr + n);
    vector<int> v;
    v.push_back(p);
    v.push_back(q);
    for (int i = 0; i < n; i++)
    {
        v.push_back(arr[i]);
        v.push_back(arr[i] - 1);
        v.push_back(arr[i] + 1);
        if (i)
        {
            int d = arr[i] - arr[i - 1];
            d /= 2;
            v.push_back(d + 1 + arr[i - 1]);
            v.push_back(d - 1 + arr[i - 1]);
            v.push_back(d + arr[i - 1]);
        }
    }
    sort(v.begin(), v.end());
    int mx = INT_MIN;
    int ans;
    for (auto e : v)
    {
        if (e < p || e > q)
            continue;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mn = min(mn, (int)abs(e - arr[i]));
        }
        if (mn > mx)
        {
            mx = mn;
            ans = e;
        }
    }
    cout << ans;

    return 0;
}