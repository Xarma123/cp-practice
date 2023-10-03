#include <bits/stdc++.h>
using namespace std;
#define lol long long
int ans(vector<int> a, int k)
{
    sort(a.begin(), a.end());
    map<int, int> x;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int j = i + 1;
        while (j < a.size() && a[j] == a[i])
            j++;
        if (x.count(k - a[i]))
            ans++;
        mp[a[i]] = j - i;
        i = j - 1;
    }
    if (k % 2 == 0 && mp[k / 2] > 1)
        ans++;
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}