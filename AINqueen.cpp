#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long lol
#define pb push_back
const ll n = 8;
const ll inf = 1e18;
void assign(lol chess[][n], lol value)
{
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            chess[i][j] = value;
        }
    }
}
lol func_counter(lol chess[][n], lol *current)
{
    lol move = 0;
    lol a, b;
    for (lol i = 0; i < n; i++)
    {
        a = current[i], b = i - 1;
        while (b >= 0 && chess[a][b] != 1)
        {
            b--;
        }
        if (b >= 0 && chess[a][b] == 1)
        {
            move++;
        }
        a = current[i], b = i + 1;
        while (b < n && chess[a][b] != 1)
        {
            b++;
        }
        if (b < n && chess[a][b] == 1)
        {
            move++;
        }
        a = current[i] - 1, b = i - 1;
        while (b >= 0 && a >= 0 && chess[a][b] != 1)
        {
            b--;
            a--;
        }
        if (b >= 0 && a >= 0 && chess[a][b] == 1)
        {
            move++;
        }
        a = current[i] + 1, b = i + 1;
        while (b < n && a < n && chess[a][b] != 1)
        {
            b++;
            a++;
        }
        if (b < n && a < n && chess[a][b] == 1)
        {
            move++;
        }
        a = current[i] + 1, b = i - 1;
        while (b >= 0 && a < n && chess[a][b] != 1)
        {
            b--;
            a++;
        }
        if (b >= 0 && a < n && chess[a][b] == 1)
        {
            move++;
        }
        a = current[i] - 1, b = i + 1;
        while (b < n && a >= 0 && chess[a][b] != 1)
        {
            b++;
            a--;
        }
        if (b < n && a >= 0 && chess[a][b] == 1)
        {
            move++;
        }
    }
    lol curr = move / 2;
    return curr;
}
void asking_about_neighbours(lol chess[][n], lol *current)
{
    lol board2[n][n];
    lol board2_stat[n];
    for (lol i = 0; i < n; i++)
    {
        board2_stat[i] = current[i];
    }
    assign(board2, 0);
    for (lol i = 0; i < n; i++)
    {
        board2[board2_stat[i]][i] = 1;
    }
    lol obj2 = func_counter(board2, board2_stat);
    lol board_around[n][n];
    lol board_around_state[n];
    for (lol i = 0; i < n; i++)
    {
        board_around_state[i] = current[i];
    }
    assign(board_around, 0);
    for (lol i = 0; i < n; i++)
    {
        board_around[board_around_state[i]][i] = 1;
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (j != current[i])
            {
                board_around_state[i] = j;
                board_around[board_around_state[i]][i] = 1;
                board_around[current[i]][i] = 0;
                lol temp = func_counter(board_around, board_around_state);
                if (temp <= obj2)
                {
                    obj2 = temp;
                    for (lol i = 0; i < n; i++)
                    {
                        board2_stat[i] = board_around_state[i];
                    }
                    assign(board2, 0);
                    for (lol i = 0; i < n; i++)
                    {
                        board2[board2_stat[i]][i] = 1;
                    }
                }
                board_around[board_around_state[i]][i] = 0;
                board_around_state[i] = current[i];
                board_around[current[i]][i] = 1;
            }
        }
    }
    for (lol i = 0; i < n; i++)
    {
        current[i] = board2_stat[i];
    }
    assign(chess, 0);
    for (lol i = 0; i < n; i++)
    {
        chess[current[i]][i] = 1;
    }
}
void hillclimbing(lol chess[][n], lol *current)
{
    lol board_around[n][n] = {{0}};
    lol board_around_state[n];
    for (lol i = 0; i < n; i++)
    {
        board_around_state[i] = current[i];
    }
    assign(board_around, 0);
    for (lol i = 0; i < n; i++)
    {
        board_around[board_around_state[i]][i] = 1;
    }
    do
    {
        for (lol i = 0; i < n; i++)
        {
            current[i] = board_around_state[i];
        }
        assign(chess, 0);
        for (lol i = 0; i < n; i++)
        {
            chess[current[i]][i] = 1;
        }
        asking_about_neighbours(board_around, board_around_state);
        bool cmp = true;
        for (lol i = 0; i < n; i++)
        {
            if (current[i] != board_around_state[i])
            {
                cmp = false;
                break;
            }
        }
        if (cmp)
        {
            for (lol i = 0; i < n; i++)
            {
                cout << " ";
                for (lol j = 0; j < n; j++)
                {
                    cout << chess[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        else if (func_counter(chess, current) == func_counter(board_around,
                                                              board_around_state))
        {
            board_around_state[rand() % n] = rand() % n;
            assign(board_around, 0);
            for (lol i = 0; i < n; i++)
            {
                board_around[board_around_state[i]][i] = 1;
            }
        }
    } while (true);
}
void solve()
{
    lol current[n] = {0};
    lol chess[n][n] = {{0}};
    for (lol i = 0; i < n; i++)
    {
        current[i] = rand() % n;
        chess[current[i]][i] = 1;
    }
    hillclimbing(chess, current);
}
int main()
{

    ll t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}