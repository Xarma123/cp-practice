#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol r1, r2;
    cin >> r1 >> r2;
    lol c1, c2;
    cin >> c1 >> c2;
    lol d1, d2;
    cin >> d1 >> d2;
    bool f = true;
    for (lol a11 = 1; a11 <= 9; a11++)
    {
        for (lol a12 = 1; a12 <= 9; a12++)
        {
            for (lol a21 = 1; a21 <= 9; a21++)
            {
                for (lol a22 = 1; a22 <= 9; a22++)
                {
                    set<lol> x;
                    x.insert(a11);
                    x.insert(a12);
                    x.insert(a21);
                    x.insert(a22);
                    if (x.size() < 4)
                        continue;
                    if (a11 + a12 != r1)
                        continue;
                    if (a21 + a22 != r2)
                        continue;
                    if (a11 + a21 != c1)
                        continue;
                    if (a12 + a22 != c2)
                        continue;
                    if (a11 + a22 != d1)
                        continue;
                    if (a12 + a21 != d2)
                        continue;
                    f = false;
                    cout << a11 << " " << a12 << endl;
                    cout << a21 << " " << a22;
                    break;
                }
                if (!f)
                    break;
            }
            if (!f)
                break;
        }
        if (!f)
            break;
    }
    if (f)
        cout << -1;

    return 0;
}