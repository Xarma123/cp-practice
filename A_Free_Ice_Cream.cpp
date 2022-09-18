#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol d = 0;
    while (n--)
    {
        char c;
        cin >> c;
        lol b;
        cin >> b;
        if (c == '+')
        {
            x += b;
        }
        else
        {
            if (b > x)
            {
                d++;
            }
            else
            {
                x -= b;
            }
        }
    }
    cout << x << " " << d;

    return 0;
}