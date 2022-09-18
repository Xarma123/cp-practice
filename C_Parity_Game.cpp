#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if (a == b)
        cout << "YES";
    else
    {
        lol onesa = 0;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] == '1')
                onesa++;
        }

        lol onesb = 0;
        for (lol i = 0; i < b.size(); i++)
        {
            if (b[i] == '1')
                onesb++;
        }
        
            if (onesa % 2 != 0)
            {
                if (onesb <= (onesa + 1))
                    cout << "YES";
                else
                    cout << "NO";
            }
            else
            {
                if (onesb <= onesa)
                    cout << "YES";
                else
                    cout << "NO";
            }
        
    }
    return 0;
}