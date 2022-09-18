#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool isPalindrome(string str)
{
    lol l = 0;
    lol h = str.size() - 1;

    while (h > l)
    {
        if (str[l++] != str[h--])
        {

            return false;
        }
    }
    return true;
}

int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];

        map<lol, lol> x;
        string b = "";
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x[a[i]]++;
            b = b + to_string(a[i]);
        }
        lol c = 0;
        vector<lol> y;
        for (auto i = x.begin(); i != x.end(); i++)
        {
            if ((*i).second % 2 != 0)
            {
                c++;
                y.push_back((*i).first);
            }
        }
        if (c == 0)
        {
            if (isPalindrome(b))
            {
                cout << "YES" << endl;
            }
            else
            {
                if (x.size() <= 2)
                {
                    cout << "YES" << endl;
                }
                else
                    cout << "NO" << endl;
            }
        }
        else if (c == 1)
        {
            if (isPalindrome(b))
            {
                cout << "YES" << endl;
            }
            else
            {
                string q = "";
                for (lol i = 0; i < n; i++)
                {
                    if (a[i] != y[0])
                    {
                        q = q + to_string(a[i]);
                    }
                }
                if (isPalindrome(q))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
        else if (c == 2)
        {

            bool f = false;
            lol g = 2;
            while (g--)
            { cout<<g;
                string q = "";
                for (lol i = 0; i < n; i++)
                {   
                    if (a[i] != y[g])
                    {
                        q = q + to_string(a[i]);
                    }
                }
                if (isPalindrome(q))
                {
                    f = true;
                    break;
                }
            }
            if (f)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}