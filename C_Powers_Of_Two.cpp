#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    map<lol, lol> ans;
    vector<lol> v;
    for (lol i = 0; i <=30; i++)
    {
        if ((n & (1 << i)))
        {
            if (i > 0)
                v.push_back((1 << i));
            ans[1 << i]++;
        }
    }
    if (ans.size() > k)
    {
        cout << "NO";
    }
    else
    {
        lol c = ans.size();
        while (c < k && !v.empty())
        {
            lol z = v.back();
            v.pop_back();
            ans[z]--;
            if(ans[z]==0)
            ans.erase(z);
            ans[z / 2] += 2;
            if (z / 2 > 1)
            {
                v.push_back(z / 2);
                v.push_back(z / 2);
            }
            c++;
        }
        if (c < k)
            cout << "NO";
        else
        {
            cout << "YES" << endl;
            for (auto x : ans)
                for (int i = 0; i < x.second; i++)
                    cout << x.first << " ";
        } 
    }

    return 0;
}