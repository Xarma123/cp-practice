#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    while (cin >> n)
    {
        cin.ignore();
        string a[n], b[n];
        string q;
        for (lol i = 0; i < n; i++)
        {
            getline(cin, q);
            stringstream qq(q);
            qq >> a[i];
            qq >> b[i];
        }
       
    }

    return 0;
}