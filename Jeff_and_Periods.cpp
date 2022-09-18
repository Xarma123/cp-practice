#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<lol, lol>> vect;

    lol n;
    cin >> n;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        vect.push_back(make_pair(t, i));
    }
    sort(vect.begin(), vect.end());
    lol d = 0;    vector<pair<lol,lol>> x;
    x.push_back(make_pair(vect[0].first,0));
   
   
     bool flag = true;
    for (lol i = 1; i < n; i++)
    {  if((vect[i-1].first==vect[i].first)&&flag)
        {
            if(i==1||vect[i-2].first!=vect[i].first)
            {d= vect[i].second-vect[i-1].second;
                 
               x[(x.size()-1)].second=d;
            }
            else
            {
                if(d==vect[i].second-vect[i-1].second)
                 continue;
                 else
                { 
                  x.pop_back();  
                   flag=false;
                }
            }
        }  
        else 
        {    if(vect[i-1].first!=vect[i].first)
             {x.push_back(make_pair(vect[i].first,0));
                flag=true;
             }
            
        }


    } lol c = x.size();
    cout<<c<<endl;
    for (lol i = 0; i < c; i++)
    {
        cout<<x[i].first<<" "<<x[i].second<<endl;
    }
     
    
}