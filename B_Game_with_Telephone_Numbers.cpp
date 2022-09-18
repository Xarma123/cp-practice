#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol ex = n - 11;
    string s;
    cin >> s;
    lol e = 0;
    for (lol i = 0; i < s.size() - 10; i++)
    {
        if (s[i] == '8')
            e++;
    } 
    if(ex/2>=e)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;

    return 0;
}