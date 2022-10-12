#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<time.h>

void drawcircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, BLUE);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, RED);
    putpixel(xc + y, yc + x, GREEN);
    putpixel(xc - y, yc + x, YELLOW);
    putpixel(xc + y, yc - x, YELLOW);
    putpixel(xc - y, yc - x, YELLOW);
}

void circlemidpoint(int xc, int yc, int r)
{
    clock_t begin=clock();
    int x = 0, y = r;
    int p = 1 - r;
    while (x < y)
    {
        drawcircle(xc, yc, x, y);
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
        drawcircle(xc, yc, x, y);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent);
}

int  main()
{
    int xc, yc, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*) "");
    printf("Enter center coordinates of the circle: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter radius of the circle: ");
    scanf("%d", &r);
    circlemidpoint(xc, yc, r);
    getch();
    return 0;
}


