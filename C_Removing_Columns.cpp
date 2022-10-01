#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
set<lol> avoid;
string a[105];
bool check()
{
    for (lol i = 1; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (!avoid.count(j))
            {
                if (a[i][j] > a[i - 1][j])
                {
                    break;
                }
                else if (a[i][j] < a[i - 1][j])
                {
                    
                    avoid.insert(j);
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (!check())
        ;
    cout << avoid.size();

    return 0;
}