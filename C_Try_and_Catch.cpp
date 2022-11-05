#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol n;
    cin >> n;
    cin.ignore();
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    map<lol, string> mp;
    lol k = -1;
    string excep = "";
    bool ans = false;
    lol ignore = 0;
    for (lol i = 0; i < n && !ans; i++)
    {
        bool z = false;
        for (lol j = 0; j < a[i].size() && !ans; j++)
        {
            if (((lol)a[i].size() - j >= 5) && a[i].substr(j, 5) == "throw")
            {
                k = j;
                j += 5;
                while (!((a[i][j] >= 'A' && a[i][j] <= 'Z') || (a[i][j] >= 'a' && a[i][j] <= 'z')))
                    j++;
                while ((a[i][j] >= 'A' && a[i][j] <= 'Z') || (a[i][j] >= 'a' && a[i][j] <= 'z'))
                {
                    excep.push_back(a[i][j]);
                    j++;
                }
                break;
            }
            if (((lol)a[i].size() - j >= 3) && a[i].substr(j, 3) == "try")
            {
                if (k != -1)
                    ignore++;
                break;
            }
            if (((lol)a[i].size() - j >= 5) && a[i].substr(j, 5) == "catch")
            {
                if (k != -1)
                {
                    string q = "";
                    if (--ignore < 0)
                    {
                        ignore = 0;
                        k = j;
                        j += 5;
                        while (!((a[i][j] >= 'A' && a[i][j] <= 'Z') || (a[i][j] >= 'a' && a[i][j] <= 'z')))
                            j++;
                        while ((a[i][j] >= 'A' && a[i][j] <= 'Z') || (a[i][j] >= 'a' && a[i][j] <= 'z'))
                        {
                            q.push_back(a[i][j]);
                            j++;
                        }

                        if (q == excep)
                        {
                            while (a[i][j] != '"')
                            {
                                j++;
                            }
                            j++;
                            while (a[i][j] != '"')
                            {
                                cout << a[i][j];
                                j++;
                            }
                            ans = true;
                        }
                    }
                }
                break;
            }
        }
    }
    if (!ans)
    {
        cout << "Unhandled Exception";
    }

    return 0;
}