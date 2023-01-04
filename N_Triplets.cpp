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
        lol x;
        cin >> x;
        lol i = 2;
        vector<lol> div;
        while (i * 1ll * i <= x)
        {
            if (x % i == 0 && x / i != i)
            {
                div.push_back(i);
                div.push_back(x / i);
                break;
            }
            i++;
        }
        if (div.size() == 2)
        {
            cout << 1 << " " << div[0] << " " << div[1] << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}