#include <bits/stdc++.h>
using namespace std;

struct var
{
    lol n;
    char cur_rod;
    char target_rod;
    char help_rod;
    bool type;
};

void towerOfHanoi(lol n, char cur_rod,
                  char target_rod, char help_rod)
{
    lol mx = INT_MIN;
    var q;
    q.n = n;
    q.cur_rod = cur_rod;
    q.help_rod = help_rod;
    q.target_rod = target_rod;
    q.type = true;

    stack<var> x; 
    x.push(q);
    while (!x.empty())
    {

        n = x.top().n;
        cur_rod = x.top().cur_rod;
        help_rod = x.top().help_rod;
        target_rod = x.top().target_rod;
        bool f = x.top().type;
        x.pop();
        if (f)
        {

            if (n == 0)
            {
            }
            else
            {
                q.n = n - 1;
                q.cur_rod = help_rod;
                q.target_rod = target_rod;
                q.help_rod = cur_rod;
                q.type = true;
                x.push(q);
                q.n = n;
                q.cur_rod = cur_rod;
                q.target_rod = target_rod;
                q.help_rod = help_rod;
                q.type = false;
                x.push(q);
                q.n = n - 1;
                q.cur_rod = cur_rod;
                q.target_rod = help_rod;
                q.help_rod = target_rod;
                q.type = true;
                x.push(q);
            }
        }
        else
        {

            cout << "Move disk " << n << " from rod " << cur_rod << " to rod " << target_rod << endl;
        }
    }
}

int main()
{
    lol n;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
