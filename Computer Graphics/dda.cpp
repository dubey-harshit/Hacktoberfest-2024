#include <stdio.h>
#include <graphics.h>
#include<time.h>

void lineDDA (int xa, int ya, int xb, int yb)
{
float dx =(float)(xb-xa), dy=(float)(yb-ya),x,y,steps; 
if(abs(dx) >= abs(dy)) steps = abs(dx) ;
else steps = abs(dy);
dx= dx/steps;
dy= dy/steps;
x=xa;y=ya;
for (int k=1; k<=steps; k++) {
 putpixel(x, y, RED);  
 x += dx;  
 y += dy;  
}
}

int main(int argc, char const *argv[]){
    int x1,y1,x2,y2;
    int gd=DETECT, gm;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter the x1 coordinate of line: ");
    scanf("%d",&x1);
    printf("Enter the y1 coordinate of line: ");
    scanf("%d",&y1);
    printf("Enter the x2 coordinate of line: ");
    scanf("%d",&x2);
    printf("Enter the y2 coordinate of line: ");
    scanf("%d",&y2);
    clock_t begin=clock();
    lineDDA(x1,y1,x2,y2);
    clock_t end = clock();
	long double time_spent = (long double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nExecution time: %llf sec\n",&time_spent);
    getch();
    closegraph();
    return 0;
}