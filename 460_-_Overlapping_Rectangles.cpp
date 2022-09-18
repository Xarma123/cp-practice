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
    bool st = true;
    while (t--)
    {

        st = false;
        lol x1, y1, x2, y2;
        lol x_1, y_1, x_2, y_2;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        bool f = true;
        if (x1 >= x_2 || x2 <= x_1)
            f = false;
        x1 = max(x1, x_1);
        x2 = min(x2, x_2);
        if (y1 >= y_2 || y2 <= y_1)
            f = false;
        y1 = max(y1, y_1);
        y2 = min(y2, y_2);
        if (f)
        {
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        }
        else
            cout << "No Overlap" << endl;
        
    }

    return 0;
}