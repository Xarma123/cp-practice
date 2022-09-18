
#include <bits/stdc++.h>
using namespace std;

void swap(lol *a, lol *b)
{

    lol t = *a;

    *a = *b;

    *b = t;
}

lol partition(lol arr[], lol l, lol h)
{

    lol x = arr[h];

    lol i = (l - 1);

    for (lol j = l; j <= h - 1; j++)
    {

        if (arr[j] <= x)
        {

            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[h]);

    return (i + 1);
}

void quickSort(lol arr[], lol l, lol h)

{

    stack<pair<lol, lol>> s;

    s.push(make_pair(l, h));

    while (!s.empty())
    {

        h = s.top().second;

        l = s.top().first;

        s.pop();

        lol p = partition(arr, l, h);

        if (p - 1 > l)
        {

            s.push(make_pair(l, p - 1));
        }

        if (p + 1 < h)
        {

            s.push(make_pair(p + 1, h));
        }
    }
}

int main()

{

    lol n;
    cin >> n;
    lol arr[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    for (lol i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
