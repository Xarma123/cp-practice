#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol size[20];
lol parent[20];
lol find(lol a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}
void unio(lol a, lol b)
{

    a = find(a);
    b = find(b);

    if (a == b)
        return;
    if (size[a] <= size[b])
    {
        parent[a] = b;
        size[b] += size[a];
    }
    else
    {
        parent[b] = a;
        size[a] += size[b];
    }
}
bool check(vector<lol> &a, vector<lol> &b)
{
    if (a[0] > a[2])
    {
        swap(a[0], a[2]);
        swap(a[1], a[3]);
    }
    if (b[0] > b[2])
    {
        swap(b[0], b[2]);
        swap(b[1], b[3]);
    }
    lol x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
    lol x3 = b[0], y3 = b[1], x4 = b[2], y4 = b[3];
    if (x1 > x4 || x2 < x3)
        return false;
    if (min(y2, y1) > max(y3, y4) || max(y2, y1) < min(y3, y4))
        return false;

    if ((a[3] - a[1]) * 1ll * (b[2] - b[0]) == (a[2] - a[0]) * 1ll * (b[3] - b[1]))
    {

        if ((x4 - x3) * (y1 * (x2 - x1) - x1 * (y2 - y1)) == (x2 - x1) * (y3 * (x4 - x3) - x3 * (y4 - y3)))
            return true;
        else
            return false;
    }

    if (x1 == x3 && y1 == y3)
        return true;
    if (x2 == x4 && y2 == y4)
        return true;

    if (((y3 * (x2 - x1) - x3 * (y2 - y1) - y1 * (x2 - x1) + x1 * (y2 - y1)) > 0) != ((y4 * (x2 - x1) - x4 * (y2 - y1) - y1 * (x2 - x1) + x1 * (y2 - y1)) > 0))
        return true;
    else
        return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        // cin.ignore();
        lol n;
        cin >> n;
        vector<vector<lol>> p;
        for (lol i = 0; i < n; i++)
        {
            lol x, y, xx, yy;
            cin >> x >> y >> xx >> yy;
            p.push_back({x, y, xx, yy});
        }

        for (lol k = 0; k < n; k++)
        {
            parent[k] = k;
        }

        for (lol k = 0; k < n; k++)
        {
            size[k] = 1;
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = i + 1; j < n; j++)
            {
                if (check(p[i], p[j])&&check(p[j],p[i]))
                {
                    unio(i, j);

                    cout << i << " " << j << endl;
                    for (lol k = 0; k < n; k++)
                    {
                        cout << parent[k] << " ";
                    }
                    cout << endl;
                    for (lol k = 0; k < n; k++)
                    {
                        cout << size[k] << " ";
                    }
                    cout << endl;
                }
            }
        }
        lol a, b;
        while (1)
        {
            cin >> a >> b;

            if (a == b && a == 0)
                break;
            a--;
            b--;
            if (find(a) == find(b))
                cout << "CONNECTED" << endl;
            else
                cout << "NOT CONNECTED" << endl;
        }
    }

    return 0;
}