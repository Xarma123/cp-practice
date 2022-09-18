#include <iostream>
#include <graphics.h>
using namespace std;
void Plotpoints(int, int);
int r, xcenter, ycenter;
int main()
{

    // Input
    cout << "Enter center of circle";
    cin >> xcenter >> ycenter;
    cout << "Enter radius";
    cin >> r;

    // initialization
    int x, y, p;
    x = 0;
    y = r;
    p = 1 - r;
    Plotpoints(x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        Plotpoints(x, y);
    }
}
void Plotpoints(int x, int y)
{
    putpixel(xcenter + x, ycenter + y, YELLOW);
    putpixel(xcenter - x, ycenter + y, YELLOW);
    putpixel(xcenter + x, ycenter - y, YELLOW);
    putpixel(xcenter - x, ycenter - y, YELLOW);
    putpixel(xcenter + y, ycenter + x, YELLOW);
    putpixel(xcenter - y, ycenter + x, YELLOW);
    putpixel(xcenter + y, ycenter - x, YELLOW);
    putpixel(xcenter - y, ycenter - x, YELLOW);
}
