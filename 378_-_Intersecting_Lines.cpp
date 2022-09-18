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
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while (n--)
    {
        lol x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1))
            cout << "LINE" << endl;
        else if ((y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1))
            cout << "NONE" << endl;
        else
        { 
            
        }
    }

    return 0;
}