#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << (a[0] - '0') + (a[2] - '0') << endl;
    }

    return 0;
}