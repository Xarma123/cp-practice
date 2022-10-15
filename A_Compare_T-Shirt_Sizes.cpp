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
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a[0] != b[0])
        {
            if (a[0] == 'L')
                cout << ">" << endl;
            else if (a[0] == 'M')
            {
                if (b[0] == 'L')
                    cout << "<" << endl;
                else
                    cout << ">" << endl;
            }
            else
                cout << "<" << endl;
        }
        else if (a[0] == 'S')
        {
            if (a.size() == b.size())
                cout << "=" << endl;
            else if (a.size() > b.size())
                cout << "<" << endl;
            else
                cout << ">" << endl;
        }
        else if (a[0] == 'M')
            cout << "=" << endl;
        else
        {
            if (a.size() == b.size())
                cout << "=" << endl;
            else if (a.size() < b.size())
                cout << "<" << endl;
            else
                cout << ">" << endl;
        }
    }

    return 0;
}