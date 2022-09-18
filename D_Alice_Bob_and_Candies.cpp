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
        lol n;
        cin >> n;
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol s = 0, e = n - 1;
        lol a = 0, b = 0;
        lol la = 0, lb = 0;
        lol tggle = 1;
        lol moves = 0;
        s = 1;
        a = c[0];
        la = c[0];
        moves = 1;

        while (s <= e)
        {
            if (tggle)
            {
                lol sum = 0;
                while (sum <= la)
                {
                    sum += c[e];
                    e--;
                    if (e < s)
                        break;
                } 
                b += sum;
                lb = sum;
                moves++;
                tggle = 0; 
                
            }
            else
            {
                lol sum = 0;
                while (sum <= lb)
                {
                    sum += c[s];
                    s++;
                    if (e < s)
                        break;
                }
                a += sum;
                la = sum;
                moves++;
                tggle = 1;
            }
        }
        cout << moves << " " << a << " " << b << endl;
    }

    return 0;
}