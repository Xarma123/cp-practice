#include <iostream>
using namespace std;

bool rat(char a[10][10], lol sol[10][10], lol x, lol y)
{
    if (x == 3 && y == 3)
    {
        sol[x][y] = 1;
        for (lol i = 0; i < 4; i++)
        {
            for (lol j = 0; j < 4; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }  cout<<endl;
        return true;
    }
    if (x > 3 || y > 3)
        return false;
    if (a[x][y] == 'x')
    {
        return false;
    }

    sol[x][y] = 1;
    bool right = rat(a, sol, x, y + 1);
    bool down = rat(a, sol, x + 1, y);
    sol[x][y]=0;
    if (right||down)
    {
        return true;
    } 
    return false;
    
}
int main()
{
    char maze[10][10] = {
        "0000",
        "00x0",
        "000x",
        "0x00",
    };
    lol a[10][10]={0};

    rat(maze, a, 0, 0);
    return 0;
}