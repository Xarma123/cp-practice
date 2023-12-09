#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int t;
    cin >> t;
    int l[n];
    int r[n];
    for (int i = 0; i < n; i++)
    {
        l[i] = 1;
        if (i > 0 && s[i - 1] >= s[i])
            l[i] += l[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        r[i] = 1;
        if (i < n - 1 && s[i + 1] >= s[i])
            r[i] += r[i + 1];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (l[i] - 1 >= t && r[i] - 1 >= t)
            ans.push_back(i);
    }
    for (auto e : ans)
        cout << e << " ";
}