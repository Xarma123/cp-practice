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
        vector<lol> a;
        stack<lol> index;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            a.push_back(t);
            if (t % (i + 2) != 0)
            {
                index.push(i);
            }
        }
        if (a[0] % 2 == 0)
        {
            cout << "NO"<<endl;
        }
        else
        {
            while (!index.empty() && !a.empty())
            {
                lol i = index.top();
                a.erase(a.begin() + i);
                index.pop();
                while (i != a.size())
                {
                    if (a[i] % (i + 2) != 0)
                        index.push(i);
                    i++;
                }
            }
            if (a.empty())
                cout << "YES"<<endl;
            else
                cout << "NO"<<endl;
        }
    }

    return 0;
}