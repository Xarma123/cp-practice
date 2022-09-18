#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (a[i][j] == 'W' && a[j][i] != 'L')
                f = false;
            else if (a[i][j] == 'L' && a[j][i] != 'W')
                f = false;
            else if (a[i][j] == 'D' && a[j][i] != 'D')
                f = false;
        }
    }
    if (f)
        cout << "correct";
    else
        cout << "incorrect";

    return 0;
}