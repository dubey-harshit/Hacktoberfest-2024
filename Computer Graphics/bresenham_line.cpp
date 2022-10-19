#include<stdio.h>  
#include<graphics.h> 
#include <time.h> 

void bresenham_line(int x0, int y0, int x1, int y1)  
{  
    clock_t begin = clock(); 
    int dx, dy,dt,d, x, y,ds;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    dt=2*(dy-dx);
    ds=2*dy;
    d=2*dy-dx;
    putpixel(x,y,WHITE);  
    while(x<x1)  
    {  x++;
        if(d>=0)  
        {   
            y++;  
            d+=dt;  
        }  
        else  
        {  
            d+=ds;  
        }  
        putpixel(x,y,WHITE);
    } 
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent);
} 

int main()  
{  
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;  
    initgraph(&gdriver, &gmode, (char*)"");  
    printf("Enter co-ordinates of first point: ");  
    scanf("%d%d", &x0, &y0);  
    printf("Enter co-ordinates of second point: ");  
    scanf("%d%d", &x1, &y1);  
    bresenham_line(x0, y0, x1, y1);  
    getch();
    closegraph();
    return 0;  
}  