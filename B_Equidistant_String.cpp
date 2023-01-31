#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    lol c = 0;
    for (lol i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            c++;
            if (c % 2)
            {
                if (a[i] == '0')
                    a[i] = '1';
                else
                    a[i] = '0';
            }
        }
    }
    if (c % 2 == 0)
        cout << a;
    else
        cout << "impossible";

    return 0;
}