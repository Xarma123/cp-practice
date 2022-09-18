#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool isPalindrome(string str)
{
    lol a[30];
    for (lol i = 0; i < 30; i++)
    {
        a[i] = 0;
    }
    for (lol i = 0; i < str.size(); i++)
    {
       a[str[i]-'a']++;
    }  
    lol e=0,o=0;
    for (lol i = 0; i < 30; i++)
    {
        if(a[i]%2!=0)
        o++;
    }
    if(o<=1)
    return true;

    return false;
    
}
int main()
{
    string a;
    cin >> a;
    if (isPalindrome(a))
    {
        cout << "First";
    }
    else
    {
        if (a.size() % 2 == 0)
        {
            cout << "Second";
        }
        else
            cout << "First";
    }

    return 0;
}