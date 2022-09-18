#include <stdio.h>
lol factors(lol);
int main()
{
    lol a;
    scanf("%d", &a);
    factors(a);
}
lol factors(lol a)
{
    static lol b = 1;
    if (b <= a)
    {
        if (a % b == 0)
        {
            prlolf(" %d", b);
        }
        b++;
        factors(a);
    }
    else
        return 0;
}