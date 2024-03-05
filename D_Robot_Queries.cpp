#include <bits/stdc++.h>
using namespace std;
#define lol long long
class node
{
public:
    node *a[26];
    lol c;
    lol e;
    node()
    {
        for (int i = 0; i < 26; i++)
            a[i] = nullptr;
        c = 0;
        e = 0;
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
                    ans += (p->a[j]->c) * 1ll * (i);
                }
            }
            if (p->a[k] == nullptr)
            {
                break;
            }
            p = p->a[k];
            ans += (p->e) * 1ll * (i + 1);
            if (i == s.size() - 1)
            {
                for (lol j = 0; j < 26; j++)
                {
                    if (p->a[j] != nullptr)
                    {
                        ans += (p->a[j]->c) * 1ll * (i + 1);
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    trie s1, s2;
    lol ans = 0;
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += sum + a[i].size() * 1ll * i - 2ll * s2.search(a[i]);
        reverse(a[i].begin(), a[i].end());
        ans += sum + a[i].size() * 1ll * i - 2ll * s1.search(a[i]);
        reverse(a[i].begin(), a[i].end());

        s1.insert(a[i]);
        reverse(a[i].begin(), a[i].end());
        s2.insert(a[i]);

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
        cout << ans << " ";
        sum += a[i].size();
    }
    cout << ans;

    return 0;
}