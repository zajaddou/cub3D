
#include <stdio.h>


// https://qiao.github.io/PathFinding.js/visual/

// 1 = wall
// 2 = visit
// 3 = exit

int init[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void algo(int x,int y)
{
    if (init[x][y] == 1 || init[x][y] == 2)
        return;

    if (init[x][y] == 3)
        printf(" Found in (%d,%d)\n", x, y);

    init[x][y] = 2;

    algo(x, y+1);
    algo(x, y-1);
    algo(x+1, y);
    algo(x-1, y);
}

int main()
{
    algo(1, 1);
}
