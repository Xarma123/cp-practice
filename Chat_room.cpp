#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    string b = "hello";
    lol c = 0; lol i;
    for ( i = 0; i < a.size(); i++)
    {
        if (a[i] == b[c])
        {
            c++;
        }
        if (b[c] == '\0')
        {
            cout << "YES";
            break;
        }
    }
    if (i == a.size())
        cout << "NO";
}