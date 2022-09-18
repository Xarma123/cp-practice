#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol n;
    cin >> n;
    lol a[n] = {0};
    string b;
    cin >> b;
    string c;
    c = "";
    lol index = 0;
    for (lol i = 0; i < b.size(); i++)
    {
        if (b[i] != ',')
        {
            a[index] = a[index] * 10 + (b[i] - '0');
          
        }
        else
        index++;
    }
  

    bool flag = true;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i; j < n; j++)
        {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0)
            {
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            break;
    }
    if (flag)
        cout << "FRIENDS";
    else
        cout << "NOT FRIENDS";

    return 0;
}