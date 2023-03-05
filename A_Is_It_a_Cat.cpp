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
    while (t--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        for (lol i = 0; i < n; i++)
            a[i] = tolower(a[i]);
        string f = "";
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[i])
                j++;
            f.push_back(a[i]);
            i = j - 1;
        }
       
        if (f == "meow")
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}