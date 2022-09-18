#include <stdio.h>
lol prod(lol);
int main()
{
    lol a;
    scanf("%d", &a);
    prlolf("%d", prod(a));
}
lol prod(lol a)
{

    static lol sum = 1, count = 0;
    if (a != 0)
    {
        sum *= a % 10;
        count++;
        prod(a / 10);
    }
    else if (count == 0)
        return 0;
    else
        return sum;
}