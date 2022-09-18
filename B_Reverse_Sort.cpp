#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        stack<lol> in1;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] == '1')
                in1.push(i);
        }
        lol c = 0;
        lol zero = 0;
        lol index;
        vector<set<lol>> sub;
        for (lol i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] == '1' && c == 0)
            {
                if (in1.size() == 0)
                    break;
                in1.pop();
            }
            else
            {   
                if(in1.size()==0) break;
                if (c == 0)
                {
                    index = i;
                }
                c = 1;
                if (a[i] != '1')
                    zero++;
                else
                {
                    if (zero >= in1.size())
                    {
                        set<lol> x;
                        lol t = in1.size();
                        while (!in1.empty())
                        {
                            x.insert(in1.top());
                            in1.pop();
                        }
                        while (t--)
                        {
                            x.insert(index);
                            index--;
                        }
                        sub.push_back(x);
                        break;
                    }
                    else
                    {
                        set<lol> x;
                        lol t = zero;
                        while (t--)
                        {
                            x.insert(index);
                            index--;
                        }
                        t = zero; 
                        in1.pop();
                        t--;
                        while (t--)
                        {
                            x.insert(in1.top());
                            a[in1.top()] = '0';
                            in1.pop();
                            if (in1.empty())
                                break;
                        }

                        sub.push_back(x);
                       
                       c=0;
                       zero=0;
                        if (in1.empty())
                            break;
                    }
                }
            }
        }

        cout << sub.size() << endl;
        for (lol i = 0; i < sub.size(); i++)
        {
            cout << sub[i].size() << " ";
            for (auto j = sub[i].begin(); j != sub[i].end(); j++)
            {
                cout << (*j) + 1 << " ";
            }

            cout << endl;
        }
    }

    return 0;
}