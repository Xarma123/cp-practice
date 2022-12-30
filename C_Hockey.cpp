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
    for (lol i = 0; i < n; i++)
    {
        lol q = i;
        for (lol j = i; j < n; j++)
        {
            if (a[q].size() > a[j].size())
            {
                q = j;
            }
        }
        swap(a[i], a[q]);
    }
        

    string s;
    cin >> s;
    char c;
    cin >> c;

    return 0;
}