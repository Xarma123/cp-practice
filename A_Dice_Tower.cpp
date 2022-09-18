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

    lol x;
    cin >> x;
    lol a, b;
    cin >> a >> b;

    lol q = 7 - x;
    n--;
    bool f = true;
    while (n--)
    {
        cin >> a >> b;
        if (a == q || b == q || 7 - a == q || 7 - b == q)
            f = false;
        else
        {
            q = 7 - q;
        }
    }
    if (f)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}