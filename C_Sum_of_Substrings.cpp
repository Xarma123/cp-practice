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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol st = -1, e = -1;
        for (lol i = 1; i < n-1; i++)
        {
            if (s[i] == '1')
            {
                st = i;
                break;
            }
        }
        for (lol i = n - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                e = i;
                break;
            }
        }

        if(st!=-1||e!=-1)
        {
            if(s[n-1]!='1'&&(n-1)-e<=k)
            {
                swap(s[n-1],s[e]);
                k-=(n-1)-e; 
                if(st==e) 
                {
                    st=k+2;
                }

            } 
            if(s[0]!='1'&&st<=k)
            {
                swap(s[0],s[st]);
            }
        } 
        lol ans=0; 
        for (lol i = 1; i < n-1; i++)
        {
            if(s[i]=='1')
            ans+=11;
        } 
        if(s[0]=='1')
        ans+=10;
        if(s[n-1]=='1')
        ans++;
        cout<<ans<<endl;
        

    }

    return 0;
}