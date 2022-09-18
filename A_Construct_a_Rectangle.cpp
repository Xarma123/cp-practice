#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        if (l1 < l2)
            swap(l1, l2);
        if (l1 < l3)
            swap(l1, l3);
        if (l1 == l2 + l3)
            cout << "YES" << endl;
        else
        {
            if (l1 == l2)
            {
                if (l3 % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (l3 == l2)
            {
                if (l1 % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (l1 == l3)
            {
                if (l2 % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}