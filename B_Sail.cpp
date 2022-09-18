#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    string a;
    cin >> a;
    char lr;
    char ud;
    if (sx <= ex)
        lr = 'E';
    else
        lr = 'W';
    if (sy <= ey)
        ud = 'N';
    else
        ud = 'S';
    lol h = abs(sx - ex), v = abs(sy - ey);
    if (h == 0 && v == 0)
        cout << 0;
    else
    {
        lol i;
        for (i = 0; i < t; i++)
        {
            if (a[i] == lr&&h!=0)
            {
                h--;
            }
            if (a[i] == ud&&v!=0)
            {
                v--;
            }
            if (h == 0 && v == 0)
                break;
        } 
        if(i==t)
        cout<<-1;
        else
        cout<<i+1;
    }

    return 0;
}