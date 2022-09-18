#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    string a, b;
    lol ans = 0;
    bool flag = true;
    vector<string> x;
    for (lol i = 0; i < n; i++)
    {
        cin >> a;   flag=true;
        for (char c : a)
        {
            if (c == '0')
            {
                x.push_back(a);
                ans++; flag=false;
                break;
            }
           
        }  
        if(flag)
        {
            b=a;
        }

    }
    if (ans < n)
    {
        cout << ans + 1 << endl;

        cout << b << " ";
    }
    else
        cout << ans<<endl;
    while (!x.empty())
    {
        cout << x.back() << " ";
        x.pop_back();
    }

    return 0;
}