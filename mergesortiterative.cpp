#include <bits/stdc++.h>
using namespace std;

void merge(lol arr[], lol l, lol m, lol r);

void mergeSort(lol arr[], lol n)
{
    lol size;
    lol left_start;

    for (size = 1; size <= n - 1; size = 2 * size)
    {

        for (left_start = 0; left_start < n - 1; left_start += 2 * size)
        {

            lol mid = min(left_start + size - 1, n - 1);

            lol right_end = min(left_start + 2 * size - 1, n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

void merge(lol arr[], lol l, lol m, lol r)
{
    lol i, j, k;
    lol n1 = m - l + 1;
    lol n2 = r - m;

    lol L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
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

    mergeSort(arr, n);
    for (lol i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
