
#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> hull;

int findSide(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) -
              (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

int Dist(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    return abs((p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(pair<int, int> a[], int n, pair<int, int> p1, pair<int, int> p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = Dist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    if (ind == -1)
    {
        for (int i = 0; i < n; i++)
        {

            if (findSide(p1, p2, a[i]) == 0)
            {
                hull.insert(a[i]);
            }
        }
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(pair<int, int> a[], int n)
{

    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }

    quickHull(a, n, a[min_x], a[max_x], 1);

    quickHull(a, n, a[min_x], a[max_x], -1);

    cout << hull.size() << endl;
    while (!hull.empty())
    {
        cout << (*hull.begin()).first << " "
             << (*hull.begin()).second << endl;
        hull.erase(hull.begin());
    }
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    printHull(a, n);
    return 0;
}
