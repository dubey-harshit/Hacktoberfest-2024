#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<time.h>


void drawcircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, RED);
    putpixel(xc + y, yc + x, YELLOW);
    putpixel(xc - x, yc + y, BLUE);
    putpixel(xc - y, yc + x, GREEN);
    putpixel(xc - x, yc - y, GREEN);
    putpixel(xc - y, yc - x, YELLOW);
    putpixel(xc + y, yc - x, RED);
    putpixel(xc + x, yc - y, YELLOW);
}


void circleBres(int xc, int yc, int r)
{   
    clock_t begin=clock();
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x < y)
    {
        drawcircle(xc, yc, x, y);
        x++;
        if (d < 0)
            d = d + 4 * (x) + 6;
        else
        {
            y--;
            d = d + 4 * (x - y) + 10;
            drawcircle(xc, yc, x, y);
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent);
}

int main()
{
    int xc, yc, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    printf("Enter the centre co-ordinates of the circle: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter radius of circle:");
    scanf("%d", &r);
    circleBres(xc, yc, r);
    getch();
    return 0;
}
