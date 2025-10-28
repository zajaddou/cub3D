#include <stdio.h>


typedef struct hola
{
    int x;
}hhola;


hhola *test(void)
{
    static hhola ss;
    return (&ss);
}

int main(void)
{
    hhola *p = test();
    p->x = 10;
    test()->x += 10;
    printf("*p %d \n",  test()->x);

}