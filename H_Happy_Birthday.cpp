#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a[10];
        for (lol i = 0; i < 10; i++)
        {
            cin >> a[i];
        }
        string up = "";
        for (lol i = 0; i < 10; i++)
        {
            string no = "";
            a[i]++;
            if (i == 0)
                no = no + "1";
            while (a[i]--)
            {
                no = no + to_string(i);
            }
            if (up == "")
                up = no;
            else
            {
                if (no.size() < up.size())
                    up = no;
                else if (no.size() == up.size() && no < up)
                    up = no;
            }
        }
        cout << up << endl;
    }

    return 0;
}