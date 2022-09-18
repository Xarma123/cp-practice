#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol p[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (lol i = 0; i < n; i++)
        {
            if (p[i] != i + 1)
            {
                lol j = i + 1;
                if (j < n)
                {
                    while (p[j] != i + 1)
                    {
                        j++;
                    }
                    while (i < j)
                    {
                        swap(p[i], p[j]);
                        i++;
                        j--;
                    }
                    break;
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << p[i] << " ";
        } 
        cout<<endl;
    }

    return 0;
}