#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol a[5];
lol cal(lol op, lol a1, lol b)
{
    if (op == 0)
        return a1 * 1ll * b;
    else if (op == 1)
        return a1 - b;
    else
        return a1 + b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        bool q = false;
        bool end = true;
        for (lol i = 0; i < 5; i++)
        {
            cin >> a[i];
            if (a[i] != 0)
                end = false;
        }
        if (end)
            break;
        for (lol a1 = 0; a1 < 5; a1++)
        {
            for (lol a5 = 0; a5 < 5; a5++)
            {
                for (lol a4 = 0; a4 < 5; a4++)
                {
                    for (lol a3 = 0; a3 < 5; a3++)
                    {
                        for (lol a2 = 0; a2 < 5; a2++)
                        {
                            for (lol op1 = 0; op1 < 3; op1++)
                            {
                                for (lol op2 = 0; op2 < 3; op2++)
                                {
                                    for (lol op3 = 0; op3 < 3; op3++)
                                    {
                                        for (lol op4 = 0; op4 < 3; op4++)
                                        {
                                            lol ans = a[a1];
                                            ans = cal(op1, ans, a[a2]);
                                            ans = cal(op2, ans, a[a3]);
                                            ans = cal(op3, ans, a[a4]);
                                            ans = cal(op4, ans, a[a5]);
                                            if (ans == 23)
                                                q = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (q)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}