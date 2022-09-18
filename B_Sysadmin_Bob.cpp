#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string a;
    cin >> a;
    if (a[0] == '@' || a[a.size() - 1] == '@')
        cout << "No solution";
    else
    { lol prv = -2;
      bool flag = true; 
      lol count=0;
      string c=",";
        for (lol i = 0; i < a.size(); i++)
        {   
            if (a[i] == '@')
            {   count++;
                if(i-prv<=2)
                {
                     flag=false;
                     break;
                }
                else
                {
                    if(prv<0)
                    {
                        prv=i;
                    }else
                    { 
                      a.insert(prv+2,c);
                      prv=i+1;
                      i++;

                    }
                }

            }
        } 
        if(flag&&count!=0)
        cout<<a;
        else
        cout<<"No solution";
    }

    return 0;
}