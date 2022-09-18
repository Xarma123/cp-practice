#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(vector<lol> x, vector<lol> y)
{
    return x.size() < y.size();
}
int main()
{
    lol n, k;
    cin >> n >> k;
    vector<vector<lol>> x;

    pair<lol, lol> ar[n];
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        ar[i] = make_pair(t, i);
    }

    sort(ar, ar + n);
    lol i = 0;
    vector<lol> y;
    for (lol j = 0; j < ar[i].first; j++)
    {
        y.push_back(k);
    }
    x.push_back(y);

    bool flag = true;
    k--;

    i++;
    if (n > 1)
    {
        while (1)
        {
           

            if (ar[i].first == ar[i - 1].first)
            {
                vector<lol> y;
                for (lol j = 0; j < ar[i - 1].first; j++)
                {
                    lol t = x[i - 1][j];

                    y.push_back(t);
                }
                x.push_back(y);
            }
            else if (ar[i].first > ar[0].first + 1 + k)
            {
                flag = false;
                break;
            }
            else
            {
                if (ar[i].first == ar[0].first + 1)
                {
                    vector<lol> y;
                    for (lol j = 0; j < ar[0].first + 1; j++)
                    {
                        lol t = x[0][0];

                        y.push_back(t);
                    }
                    x.push_back(y);
                }
                else
                {
                    vector<lol> y;
                 
            
                     lol t=k;
                    for (lol j = 0; j < ar[i].first; j++)
                    {   
                         if( j < ar[0].first + 1)
                        { 
                            lol q = x[0][0];

                        y.push_back(q);

                        } 
                        else
                        {
                            y.push_back(t);
                            t--;
                        }
                       
                       
                    }
                    
                      x.push_back(y);
                }
            }
            i++;

            //    vector<lol> y;
            // for (lol j = 0; j < ar[i-1]; j++)
            // {   lol t = x[i-1][j];

            //     y.push_back(t);
            // }
            //   x.push_back(y);
            // // // memset(&x[i][0] + a, k, x[i].size()-x[i-1].size());
            // for (lol j = 0; j < ar[i]-ar[i-1]; j++)
            // {
            //      x[i].push_back(k);
            // }
            //  if(ar[i-1]!=ar[i])
            // k--;

            // i++;
            if (i >= n)
            {
                break;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        for (lol i = 0; i < n; i++)
        {    lol k=i;
            for ( k = 0; k < n; k++)
            {
                if(ar[k].second==i)
                    break;
            }
            

            for (lol j = 0; j < ar[k].first; j++)
            {
                cout << x[k][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "NO";

    return 0;
}