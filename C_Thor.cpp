#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <iomanip>
#include <cmath>
#include <bitset>
#define mst(ss, b) memset((ss), (b), sizeof(ss))
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef long double ld;
#define INF (1ll << 60) - 1
#define Max 1e9
using namespace std;
int n, q, t, x;
list<pair<int, int>> anw;
int pre[300100], num[300100];
int main()
{
    int cnt = 0;
    scanf("%d%d", &n, &q);
    int ans = 0, L = 1;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &t, &x);
        if (t == 1)
        {
            anw.push_back(make_pair(++cnt, x));
            ans++;
            num[x]++;
        }
        else if (t == 2)
        {
            ans -= num[x];
            pre[x] = cnt;
            num[x] = 0;
        }
        else
        {
            list<pair<int, int>>::iterator it;
            for (it = anw.begin(); it != anw.end();)
            {
                if (it->first > x)
                    break;
                if (it->first > pre[it->second])
                {
                    ans--;
                    num[it->second]--;
                }
                anw.erase(it++);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}