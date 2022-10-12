#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <time.h>
using namespace std;

int main()
{
    int xc, yc, r, x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    cout << "Enter the centre co-ordinates of the circle: ";
    cin >> xc >> yc;
    cout << "Enter radius of circle:";
    cin >> r;
    circle(xc, yc, r);
    cout << "Enter the coordinates of a point: ";
    cin >> x >> y;
    setcolor(RED);
    putpixel(x, y, WHITE);
    clock_t begin = clock();
    int fx = (((x - xc) * (x - xc)) + ((y - yc) * (y - yc)) - r * r);
    if (fx == 0)
    {
        cout << "Point is on the circle!";
    }
    else if (fx > 0)
    {
        cout << "Point is outside the circle!";
    }
    else
        cout << "Point is inside the circle!";
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\nExecution time: " << time_spent << "sec\n";
    getch();
    return 0;
}
