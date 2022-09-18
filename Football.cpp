#include <bits/stdc++.h>

using namespace std;
int main()
{
    lol n;
    string b;
    cin >> n;
    string a;
    cin >> a;
    lol a1 = 1, a2 = 0, k = 1;
    for (lol i = 1; i < n; i++)
    {
        if (k)
        {
            cin >> b;
            if (b != a)
             {   k = 0; 
                 a2++;
             }
            else
            {
                a1++;
            }
        }
        else
        {

            string c;
            cin >> c;
            if (c == a)
                a1++;
            else
            {
                a2++;
            }
        }
    }
    if (a1 > a2)
        cout << a;
    else
    {
        cout << b;
    }
}