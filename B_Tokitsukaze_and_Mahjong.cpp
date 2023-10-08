#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (c < b)
        swap(b, c);
    if (a > b)
        swap(a, b);

    if (a == b && b == c)
    {
        cout << 0;
        return 0;
    }
    if (a[1] == b[1] && b[1] == c[1])
    {
        if (a[0] == b[0] - 1 && b[0] == c[0] - 1)
        {
            cout << 0;
            return 0;
        }
    }
    if (a == b || a == c || b == c)
    {
        cout << 1;
        return 0;
    }
    if (a[1] == b[1])
    {
        if ((long long)abs((a[0] - '0') - (b[0] - '0')) == 1||(long long)abs((a[0] - '0') - (b[0] - '0')) == 2)
        {
            cout << 1;
            return 0;
        }
    }
    if (a[1] == c[1])
    {
        if ((long long)abs((a[0] - '0') - (c[0] - '0')) == 1||(long long)abs((a[0] - '0') - (c[0] - '0')) == 2)
        {
            cout << 1;
            return 0;
        }
    }
    if (b[1] == c[1])
    {
        if ((long long)abs((b[0] - '0') - (c[0] - '0')) == 1||(long long)abs((b[0] - '0') - (c[0] - '0')) == 2)
        {
            cout << 1;
            return 0;
        }
    }
    
    cout << 2;
    return 0;
}