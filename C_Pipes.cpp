#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        string a[2];
        cin >> a[0] >> a[1];
        bool s = true;
        lol i = 1, j = n - 1;
        bool ans = true;
        while (i < 2 && i >= 0 && j < n && j >= 0)
        {

            if (s)
            {
                if (a[i][j] == '1' || a[i][j] == '2')
                {
                    j--;
                }
                else
                {
                    s = false;
                    if (i == 1)
                    {
                        i--;
                    }
                    else
                        i++;
                }
            }
            else
            {
                if (a[i][j] == '1' || a[i][j] == '2')
                {   
                    ans = false;
                    break;
                }
                else
                {
                    j--;
                    s = true;
                }
            }
        }
       
        if (!ans)
            cout << "NO" << endl;
        else
        {
            if (s && i == 0 && j == -1)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}