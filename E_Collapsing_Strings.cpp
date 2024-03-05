#include <bits/stdc++.h>
using namespace std;
#define lol long long
class node
{
public:
    node *a[26];
    int sz;
    int c;
    int e;
    node()
    {
        for (int i = 0; i < 26; i++)
            a[i] = nullptr;
        sz = 0;
        c = 0;
        e = 0;
    }
    ~node()
    {
        for (lol i = 0; i < 26; i++)
        {
            if (a[i] != nullptr)
                delete a[i];
        }
    }
};
class trie
{
public:
    node *root;
    trie()
    {
        root = new node();
    }
    ~trie()
    {
        if (root != nullptr)
            delete root;
    }
    void insert(string s)
    {
        node *p = root;
        for (lol i = 0; i < s.size(); i++)
        {
            lol j = s[i] - 'a';
            if (p->a[j] == nullptr)
            {
                p->a[j] = new node();
            }
            p = p->a[j];
            p->sz += s.size() - i;
            p->c++;
        }
        p->e++;
    }
    lol search(string s)
    {

        node *p = root;
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            lol k = s[i] - 'a';
            for (lol j = 0; j < 26; j++)
            {
                if (j == k)
                    continue;
                if (p->a[j] != nullptr)
                {
                    ans += p->a[j]->sz + ((p->a[j]->c) * 1ll * (s.size() - i));
                }
            }
            if (p->a[k] == nullptr)
            {
                break;
            }
            p = p->a[k];
            ans += (p->e) * 1ll * (s.size() - i - 1);
            if (i == s.size() - 1)
            {
                for (lol j = 0; j < 26; j++)
                {
                    if (p->a[j] != nullptr)
                    {
                        ans += p->a[j]->sz;
                    }
                }
            }
        }
        return ans;
    }
};
lol ans = 0;
void solve1(string a[], lol n)
{
    trie s;
    for (lol i = 0; i < n; i++)
    {
        if (n != 1)
        {
            ans += s.search(a[i]);
            reverse(a[i].begin(), a[i].end());
            s.insert(a[i]);
            reverse(a[i].begin(), a[i].end());
        }
        lol k = a[i].size() - 1;
        lol j = 0;
        while (j <= k)
        {
            if (a[i][j] == a[i][k])
            {

                j++;
                k--;
            }
            else
            {
                ans += k + 1 + a[i].size() - j;
                break;
            }
        }
    }
}
void solve2(string a[], lol n)
{
    trie s;
    for (lol i = 0; i < n; i++)
    {
        reverse(a[i].begin(), a[i].end());
        ans += s.search(a[i]);
        reverse(a[i].begin(), a[i].end());
        s.insert(a[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve1(a, n);
    if (n != 1)
        solve2(a, n);
    cout << ans;

    return 0;
}
