#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol s;
    set<lol> x;
    for (lol i = 0; i < 4; i++)
    {
        cin >> s;
        x.insert(s);
    }
    cout << 4 - x.size();

    return 0;
}