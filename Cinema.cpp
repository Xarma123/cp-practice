#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
pair<lol, lol> give(pair<lol, lol> &p, vector<vector<char>> &seats, lol l)
{
     if (l == 0)
     {
          if (seats[p.first][p.second] == '\0')
          {
               seats[p.first][p.second] = '-';
               return p;
          }
          else
          {
               pair<lol, lol> x;
               x = give(p, seats, l + 1);
               return x;
          }
     }
     pair<lol, lol> x;

     if ((p.first - l >= 0) && (seats[p.first - l][p.second] == '\0'))
     {
          seats[p.first - l][p.second] = '-';
          x = make_pair(p.first - l, p.second);
          return x;
     }

     if ((p.second - l >= 0) && (seats[p.first][p.second - l] == '\0'))
     {
          seats[p.first][p.second - l] = '-';
          x = make_pair(p.first, p.second - l);
          return x;
     }

     if ((p.second + l < m) && (seats[p.first][p.second + l] == '\0'))
     {
          seats[p.first][p.second + l] = '-';
          x = make_pair(p.first, p.second + l);

          return x;
     }
     if ((p.first + l < n) && (seats[p.first + l][p.second] == '\0'))
     {
          seats[p.first + l][p.second] = '-';
          x = make_pair(p.first + l, p.second);
          return x;
     }
     if ((p.first - l >= 0 && p.second - l >= 0) && (seats[p.first - l][p.second - l] == '\0'))
     {
          seats[p.first - l][p.second - l] = '-';
          x = make_pair(p.first - l, p.second - l);
          return x;
     }
     if ((p.first - l >= 0 && p.second + l < m) && (seats[p.first - l][p.second + l] == '\0'))
     {
          seats[p.first - l][p.second + l] = '-';
          x = make_pair(p.first - l, p.second + l);
          return x;
     }

     if ((p.first + l < n && p.second - l >= 0) && (seats[p.first + l][p.second - l] == '\0'))
     {
          seats[p.first + l][p.second - l] = '-';
          x = make_pair(p.first + l, p.second - l);
          return x;
     }
     if ((p.first + l < n && p.second + l < m) && (seats[p.first + l][p.second + l] == '\0'))
     {
          seats[p.first + l][p.second + l] = '-';
          x = make_pair(p.first + l, p.second + l);
          return x;
     }
     x = give(p, seats, l + 1);
     return x;
}

int main()
{

     cin >> n >> m >> k;

     vector<vector<char>> seats;
     for (lol i = 0; i < n; i++)
     {
          vector<char> v;
          for (lol j = 0; j < m; j++)
          {
               v.push_back('\0');
          }
          seats.push_back(v);
     }
     queue<pair<lol, lol>> person;
     for (lol i = 0; i < k; i++)
     {
          lol a, b;
          cin >> a >> b;
          person.push(make_pair(a - 1, b - 1));
     }
     pair<lol, lol> given, x;
     for (lol i = 0; i < k; i++)
     {
          given = give(person.front(), seats, 0);
          person.pop();
          cout << given.first + 1 << " " << given.second + 1 << endl;
     }

     return 0;
}