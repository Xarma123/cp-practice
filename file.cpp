#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m1, m2, m3, m4;
    cin >> n >> m1 >> m2 >> m3 >> m4;
    vector<string> a[4];
    for (lol i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        lol h;
        cin >> h;
        if (h >= m1 && h < m2)
            a[0].push_back(s);
        else if (h >= m2 && h < m3)
            a[1].push_back(s);
        else if (h >= m3 && h < m4)
            a[2].push_back(s);
        else
            a[3].push_back(s);
    }
    cout << "S:\n";
    for (auto e : a[0])
        cout << e << '\n';
    cout << "M:\n";
    for (auto e : a[1])
        cout << e << '\n';
    cout << "L:\n";
    for (auto e : a[2])
        cout << e << '\n';
    cout << "X:\n";
    for (auto e : a[3])
    {
        cout << e << '\n';
    }
    
}