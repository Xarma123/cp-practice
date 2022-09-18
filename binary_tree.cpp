#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    lol key;
    node *left;
    node *right;
    node(lol k)
    {
        key = k;
        left = right = NULL;
    }
};
node *build()
{
    lol d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *a = new node(d);
    a->left = build();
    a->right = build();

    return a;
} //    if(a==NULL)
//    {return ;}
//     cout<<a->key;
//     prlol(a->left);
//     prlol(a->right);
//     return;
void levelprlol(node *root, lol k)
{
    if (root == NULL)
        return;
    else if (k == 1)
    {
        cout << root->key << ' ';
        return;
    }
    else
    {
        levelprlol(root->left, k - 1);
        levelprlol(root->right, k - 1);
        return;
    }
}
void prlol(node *a)
{

    if (a == NULL)
        return;
    stack<node *> b;
    b.push(a);
    while (b.empty() == false)
    {
        node *x = b.top();
        if (x->left == NULL && x->right == NULL)
        {
            cout << x->key << " ";
            b.pop();
            cout << b.top()->key << " ";
            b.pop();
        }
        if (x->left != NULL && x->right == NULL)
        {
            b.push(x->left);
        }
        if (x->left == NULL && x->right != NULL)
        {
            cout << x->key << " ";
            b.pop();
            b.push(x->right);
        }
        if (x->left != NULL && x->right != NULL)
        {
            b.pop();
            b.push(x->right);
            b.push(x);
            b.push(x->left);
        }
    }
}
lol h(node *root)
{
    if (root == NULL)
        return 0;
    lol ls = h(root->left);
    lol rs = h(root->right);
    return max(ls, rs) + 1;
}
lol size(node *root)
{
    if (root == NULL)
        return 0;

    return size(root->left) + size(root->right) + 1;
}
lol maxi(node *root)
{
    if (root == NULL)
    {
        return INT16_MIN;
    }
    lol c = max(maxi(root->left), maxi(root->right));
    return max(root->key, c);
}
bool childsum(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    lol sum = 0;
    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;

    return (sum == root->key && childsum(root->right) && childsum(root->left));
}
lol search(lol a[], lol is, lol ie, lol x)
{
    for (lol i = is; i <= ie; i++)
    {
        if (a[i] == x)
            return i;
    }
}
lol k = 0;
node *bt(lol in[], lol pre[], lol is, lol ie)
{
    if (is > ie)
    {
        return NULL;
    }
    node *c = new node(pre[k++]);
    lol index;
    for (lol i = is; i <= ie; i++)
    {
        if (in[i] == c->key)
        {
            index = i;
            break;
        }
    }

    c->left = bt(in, pre, is, index - 1);
    c->right = bt(in, pre, index + 1, is);
    return c;
}
void treeprlol(node *r)
{
    if (r == NULL)
        return;
    deque<node *> q;
    q.push_back(r);
    lol l = 0;
    while (!q.empty())
    {
        lol n;
        n = q.size();
        stack<node *> x;
        for (lol i = 0; i < n; i++)
        {
            node *c = q.front();
            q.pop_front();
            if (l%2==0)
            {
                cout << c->key<<" ";
            }
            else
            {
                x.push(c);
            } 

            if (c->left != NULL)
                q.push_back(c->left);
            if (c->right != NULL)
                q.push_back(c->right);
        } 
        while (!x.empty())
        {
            cout<<x.top()->key<<" ";
             x.pop();
        }
         cout<<endl;
        l++;
    }
}  lol m=INT_MIN;
lol in(node * r)
{  if(r!=NULL)
   { lol lt = in(r->left);
     lol rt = in(r->right);
      
       m= max(m,lt+rt+1);
       return max(lt,rt)+1;
         
   }
   return 0 ;

} 
node * ansc(lol a , lol b,node *r)
{
     if(r==NULL)
     return NULL;
     if(r->key==a||r->key==b)
      return r;
      node * ls= ansc( a ,  b,r->left);
      node * rs= ansc( a ,  b,r->right);
      if(ls!=NULL&&rs!=NULL)
      {
          return r;
      }
      if(ls!=NULL)
      {
          return ls;
      }
      else 
      return rs;

  
}

int main()
{
    node *a = build(); 
    ansc(80,30,a);
}