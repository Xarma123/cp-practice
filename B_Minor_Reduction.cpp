#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        lol mx = 0;
        for (lol i = 0; i < x.size() - 1; i++)
        {

            if (x[i] - '0' + x[i + 1] - '0' >= 10)
                mx = i;
        }
        if (x[mx] - '0' + x[mx + 1] - '0' < 10)
        {
            cout << x[0] - '0' + x[1] - '0';
            cout << x.substr(2);
            cout << endl;
        }
        else
        {
            for (lol i = 0; i < x.size(); i++)
            {
                if (i != mx)
                    cout << x[i];
                else
                {
                    cout << x[mx] - '0' + x[mx + 1] - '0';
                    i++;
                }
            }
            cout << endl;
        }
    }

    return 0;
}