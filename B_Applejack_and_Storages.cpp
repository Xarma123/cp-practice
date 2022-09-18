#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    map<lol, lol> mp1;
    map<lol, lol> mp2;
    map<lol, lol> mp3;
    map<lol, lol> mp4;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if ((*i).second <= 1)
        {
            mp1[(*i).first] = (*i).second;
        }
        else if ((*i).second <= 3)
        {
            mp2[(*i).first] = (*i).second;
        }
        else if ((*i).second < 8)
        {
            mp3[(*i).first] = (*i).second;
        }
        else
        {
            mp4[(*i).first] = (*i).second;
        }
    }

    lol q;
    cin >> q;
    while (q--)
    {
        char a;
        lol no;
        cin >> a >> no;
        if (mp1.count(no))
        {
            if (a == '+')
                mp1[no]++;
            else
                mp1[no]--;
            lol c = mp1[no];
            mp1.erase(no);
            if (c <= 1)
            {
                mp1[no] = c;
            }
            else if (c <= 3)
            {
                mp2[no] = c;
            }
            else if (c < 8)
            {
                mp3[no] = c;
            }
            else
            {
                mp4[no] = c;
            }
        }
        else if (mp2.count(no))
        {
            if (a == '+')
                mp2[no]++;
            else
                mp2[no]--;
            lol c = mp2[no];
            mp2.erase(no);
            if (c <= 1)
            {
                mp1[no] = c;
            }
            else if (c <= 3)
            {
                mp2[no] = c;
            }
            else if (c < 8)
            {
                mp3[no] = c;
            }
            else
            {
                mp4[no] = c;
            }
        }
        else if (mp3.count(no))
        {
            if (a == '+')
                mp3[no]++;
            else
                mp3[no]--;
            lol c = mp3[no];
            mp3.erase(no);
            if (c <= 1)
            {
                mp1[no] = c;
            }
            else if (c <= 3)
            {
                mp2[no] = c;
            }
            else if (c < 8)
            {
                mp3[no] = c;
            }
            else
            {
                mp4[no] = c;
            }
        }
        else if (mp4.count(no))
        {
            if (a == '+')
                mp4[no]++;
            else
                mp4[no]--;
            lol c = mp4[no];
            mp4.erase(no);
            if (c <= 1)
            {
                mp1[no] = c;
            }
            else if (c <= 3)
            {
                mp2[no] = c;
            }
            else if (c < 8)
            {
                mp3[no] = c;
            }
            else
            {
                mp4[no] = c;
            }
        }
        else
        {
            mp1[no]++;
        }
        if (mp4.size() >= 1)
        {
            cout << "YES" << endl;
        }
        else if (mp3.size() >= 2)
        {
            cout << "YES" << endl;
        }
        else if (mp3.size() == 1)
        {
            lol extra = (*mp3.begin()).second - 4;
            if (extra / 2 + mp2.size() >= 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}