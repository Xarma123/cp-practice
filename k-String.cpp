#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    lol k;
    cin >> k;
    string s;
    lol a[26] = {0};
    cin >> s;
    lol l = s.size();
    for (lol i = 0; i < l; i++)
    {
        a[s[i] - 97]++;
    }
     string ans;
    ans[0] = '\0';
    bool v = true;
    for (lol i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            if (a[i] % k == 0)
            { 
                 for (lol j = 0; j < a[i]/k ; j++)
                 {
                   char c= char(i+97);
                   ans=ans+c;
                 }
                 
                
            }
            else
            {
                cout << -1;
                v = false;
                break;
            }
        }
    } 
    if(v)
    {  string ans1;ans1[0]='\0';
        for (lol i = 0; i < k; i++)
        {
            ans1=ans +ans1;
        }
         cout<<ans1;
        
    }
}
