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
    vector<lol> q(n + 5, 0);
    lol sum = 0;
    lol l = 0;
    lol c = 1;
    for (lol i = 0; i < n; i++)
    {

        lol t;
        cin >> t;
        if (t == 1)
        {
            lol a;
            lol x;
            cin >> a >> x;
            q[a] += x;
            sum += x * 1ll * a;
        }
        else if (t == 2)
        {
            lol k;
            cin >> k;
            q[c] = q[c] + l - k;
            c++;
            l = k;
            sum += k;
        }
        else
        {
            sum -= l + q[c];
            l = l + q[c] + q[c - 1];
            q[c] = 0;
            c--;
            q[c] = 0;
        }

        cout << setprecision(20);
        cout << (long double)((long double)sum / (long double)c) << endl;
    }

    return 0;
}