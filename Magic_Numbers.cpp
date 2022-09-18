#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    string a;
    cin >> a;
    lol s = a.size() ; lol i = 0;
     for (i = 0; i < s; i++)
    {
        if (i == 0)
        {
            if (a[i] != '1')
           {     cout << "NO";
            break; }
        }
        else if (a[i] == '1' || a[i] == '4')
        {
            if (a[i] == '4')
            {
                if (a[i - 1] == '1')
                {
                    continue;
                }
                else
                {
                    if (a[i - 2] != '1')
                    {
                        cout << "NO";
                        break;
                    }
                }
            }  
            if(a[i]=='1') continue;
        }
        else
        {
            cout << "NO";
            break;
        }
    } 
    if (i==s)
    {  cout<<"YES";
    }
    
}