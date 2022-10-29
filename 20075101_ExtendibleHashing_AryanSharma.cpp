#include <bits/stdc++.h>
using namespace std;
class Bucket
{
public:
    int Bucketdepth;
    int bucketSize;
    vector<int> val;
    Bucket(int Size_bucket)
    {
        Bucketdepth = 0;
        bucketSize = Size_bucket;
    }
    Bucket(int Size_bucket, int _Bucketdepth)
    {
        Bucketdepth = _Bucketdepth;
        bucketSize = Size_bucket;
    }
    void print()
    {
        for (auto i : val)
            cout << i << " ";
        cout << endl;
    }
    bool Full()
    {
        return ((int)val.size() == bucketSize);
    }

    void insert(int v)
    {
        val.push_back(v);
    }
    bool findkey(int v)
    {
        for (auto i : val)
        {
            if (i == v)
                return 1;
        }
        return 0;
    }

    void erase(int v)
    {
        val.erase(find(val.begin(), val.end(), v));
    }
};
class Directory
{
public:
    int globalDepth, bucketSize;
    vector<Bucket *> direc;
    Directory(int Size_bucket)
    {
        globalDepth = 0;
        bucketSize = Size_bucket;
        Bucket *b = new Bucket(bucketSize);
        direc.push_back(b);
    }
    int getHash(int val)
    {
        int hash = val;
        return hash;
    }
    int Kbitsequence(int x, int k)
    {
        int y = ((1 << k) - 1) & x;
        return y;
    }
    int DirNo(int val)
    {
        int hash = getHash(val);
        int dirNo = Kbitsequence(hash, globalDepth);
        return dirNo;
    }
    int MatchingPair(Bucket *b, int dirNo)
    {
        int k = b->Bucketdepth;
        int No_bucket = Kbitsequence(dirNo, k);
        int matchingPair = No_bucket ^ (1 << (k - 1));
        return matchingPair;
    }
    void print()
    {

        for (int i = 0; i < (int)direc.size(); i++)
        {
            Bucket *b = direc[i];
            if (i >> (b->Bucketdepth) == 0)
            {
                cout << i << ": ";
                b->print();
                cout << endl;
            }
            else
            {
                cout << i << "Points to ->";
                cout << Kbitsequence(i, b->Bucketdepth);
                cout << endl;
            }
        }
    }

    void split(Bucket *b, int dirNo)
    {
        if (b->Bucketdepth == globalDepth)
        {

            direc.resize((1 << globalDepth) * 2);
            for (int i = 0; i < (1 << globalDepth); i++)
            {
                direc[i ^ (1 << globalDepth)] = direc[i];
            }
            globalDepth++;
        }
        int ld = b->Bucketdepth;
        int No_bucket = Kbitsequence(dirNo, ld);
        int No_bucket1 = Kbitsequence(dirNo, ld + 1);
        int No_bucket2 = ((1 << ld) ^ No_bucket1);
        b->Bucketdepth++;
        direc[No_bucket2] = new Bucket(bucketSize,
                                       b->Bucketdepth);
        for (int i = 0; i < (1 << (globalDepth - ld)); i++)
        {
            int j = (i << ld) + No_bucket;
            if (direc[j] == b)
            {
                if (Kbitsequence(j, ld + 1) == No_bucket1)
                    direc[j] = direc[No_bucket1];
                else
                    direc[j] = direc[No_bucket2];
            }
        }
        vector<int> values;
        for (int val : b->val)
        {
            values.push_back(val);
        }
        b->val.clear();
        for (int val : values)
        {
            Bucket *bucket = direc[DirNo(val)];
            bucket->insert(val);
        }
    }
    bool findkey(int val)
    {
        int dirNo = DirNo(val);
        Bucket *b = direc[dirNo];
        return b->findkey(val);
    }
    int insert(int val)
    {
        if (findkey(val))
            return 0;
        int dirNo = DirNo(val);
        Bucket *b = direc[dirNo];
        if (!b->Full())
        {
            b->insert(val);
        }
        else
        {
            split(b, dirNo);
            insert(val);
        }
        return 1;
    }
    void half()
    {
        int c = 0;
        for (int i = 0; i < (1 << globalDepth); i++)
        {
            if (direc[i]->Bucketdepth < globalDepth)
            {
                c++;
            }
        }
        if (c == (1 << globalDepth))
        {
            globalDepth--;
            direc.resize(1 << globalDepth);
        }
    }
    void merge(int dirNo)
    {
        Bucket *b = direc[dirNo];
        int ld = b->Bucketdepth;
        if (ld == 0)
            return;
        int No_bucket2 = MatchingPair(b, dirNo);
        Bucket *b2 = direc[No_bucket2];
        if ((int)(b->val).size() + (int)(b2->val).size() <=
                bucketSize &&
            b2->Bucketdepth == ld)
        {
            for (auto val : b2->val)
            {
                (b->val).push_back(val);
            }
            for (int i = 0; i < (1 << (globalDepth - ld)); i++)
            {
                int j = ((i << ld) + No_bucket2);
                if (direc[j] == b2)
                    direc[j] = b;
            }
            b->Bucketdepth--;
            delete b2;
            half();
            merge(Kbitsequence(dirNo,
                               b->Bucketdepth));
        }
    }
    int erase(int val)
    {
        int dirNo = DirNo(val);
        Bucket *b = direc[dirNo];
        if (!b->findkey(val))
            return 0;
        b->erase(val);
        merge(dirNo);
        return 1;
    }
};
int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Enter bucket size: " << endl;
    int bucketSize;
    cin >> bucketSize;
    while (bucketSize <= 0)
    {
        cout << "size must be positive" << endl;
        cout << "Enter the bucket size: " << endl;
        cin >> bucketSize;
    }
    Directory hash(bucketSize);
    cout << "Options Available :" << endl;

    cout << "insert x" << endl;

    cout << "delete x" << endl;

    cout << "findkey x" << endl;

    cout << "print" << endl;

    cout << "exit" << endl;

    while (true)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int x;
            cin >> x;
            if (hash.insert(x))
                cout << x << " inserted successfully" << endl;
            else
                cout << x << " already found" << endl;
        }
        else if (s == "delete")
        {
            int x;
            cin >> x;
            if (hash.erase(x))
                cout << x << " deleted successfully" << endl;
            else
                cout << x << " not found" << endl;
        }
        else if (s == "findkey")
        {
            int x;
            cin >> x;
            if (hash.findkey(x))
                cout << x << " found in directory number" << hash.DirNo(x) << endl;
            else
                cout << x << " not found" << endl;
        }
        else if (s == "print")
        {
            hash.print();
        }
        else if (s == "exit")
        {
            break;
        }
        else
        {
            cout << "Invalid !" << endl;
        }
    }
    return 0;
}