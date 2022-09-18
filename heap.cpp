#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Minheap
{

public:
    vector<lol> arr;

    lol left(lol i)
    {
        return (2 * i + 1);
    }
    lol right(lol i)
    {
        return (2 * i + 2);
    }
    lol parent(lol i)
    {
        return (i - 1) / 2;
    }
    void insert(lol x)
    {

        arr.push_back(x);
        for (lol i = arr.size() - 1; i > 0 && (arr[parent(i)] > arr[i]); i = parent(i))
            swap(arr[i], arr[parent(i)]);
    }
    lol getmin()
    {
        if (arr.size() == 0)
            return LONG_LONG_MAX;

        return arr[0];
    }
    void heapify(lol i)
    {
        lol smallest = i;
        lol lt = left(i), rt = right(i);
        if (lt < arr.size())
        {
            if (arr[lt] < arr[smallest])
                smallest = lt;
        }
        if (rt < arr.size())
        {
            if (arr[rt] < arr[smallest])
                smallest = rt;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    lol deletemin()
    {
        if (arr.size() == 0)
            return LONG_LONG_MAX;

        lol t = arr[0];

        swap(arr[0], arr[arr.size() - 1]);

        arr.pop_back();
        if (arr.size() > 0)
            heapify(0);
        return t;
    }
};

int main()
{
    Minheap x;
    x.insert(45);
    x.insert(20);
    x.insert(14);
    x.insert(12);
    x.insert(31);
    x.insert(7);
    x.insert(11);
    x.insert(13);
    x.insert(7);

    for (auto i = 0; i < x.arr.size(); i++)
    {
        cout << x.arr[i] << " ";
    }
    cout << endl;
    while (x.arr.size())
    {
        cout << x.deletemin() << " ";
    }
    cout << endl;
    return 0;
}