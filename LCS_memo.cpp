#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol mono[1001][1001] = {-1};

lol lcs(string a, string b, lol n, lol m)
{
    if (n == 0 || m == 0)
        return 0;


    if (mono[n][m] == -1)

    {
        if (a[n - 1] == b[m - 1])
            mono[n][m] = lcs(a, b, n - 1, m - 1) + 1;
        else
            mono[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    } 

    return mono[n][m];
}
int main()
{
    string a, b;
    cin >> a >> b;
memset(mono,-1,sizeof(mono));
    cout << lcs(a, b, a.size(), b.size());
    return 0;
}