#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int M = 1e5 + 10;
struct TnT
{
    int l, r, num, pos;
} song[M], person[M], gg[M];
bool cmp(TnT a, TnT b)
{
    return a.l < b.l;
}
int ans[M];
set<pair<int, int>> se;
int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &song[i].l, &song[i].r);
        song[i].pos = i, ans[i + 1] = 0;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &person[i].l, &person[i].r, &person[i].num);
        person[i].pos = i;
        gg[i].num = person[i].num;
    }
    sort(song + 1, song + n + 1, cmp);
    sort(person + 1, person + m + 1, cmp);
    int temp = 0, flag = 0;
    for (int i = 1; i <= n; i++)
    {
        while (temp <= m && person[temp].l <= song[i].l)
        {
            se.insert(make_pair(person[temp].r, person[temp].pos));
            temp++;
        }
        set<pair<int, int>>::iterator it;
        it = se.lower_bound(make_pair(song[i].r, 0));
        if (it == se.end())
        {
            flag = 1;
            break;
        }
        else
        {
            if (it->first >= song[i].r)
            {
                ans[song[i].pos] = it->second;
                gg[it->second].num--;
                if (gg[it->second].num == 0)
                {
                    se.erase(it);
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
