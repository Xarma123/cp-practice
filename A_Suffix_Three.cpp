#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        if (a.size() >= 5 && a.substr(a.size() - 5) == "mnida")
        {
            cout << "KOREAN\n";
        }
        else if (a.size() >= 2 && a.substr(a.size() - 2) == "po")
            cout << "FILIPINO\n";
        else
            cout << "JAPANESE\n";
    }
}