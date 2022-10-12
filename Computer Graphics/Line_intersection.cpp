#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <graphics.h>
using namespace std;

#define paired pair<double, double>
#define db double

void displayPoint(paired P)
{
    cout << "(" << P.first << ", " << P.second << ")" << endl;
}

paired findIntersection(paired A, paired B, paired C, paired D)
{
    db a1 = B.second - A.second;
    db b1 = A.first - B.first;
    db c1 = a1 * (A.first) + b1 * (A.second);

    db a2 = D.second - C.second;
    db b2 = C.first - D.first;
    db c2 = a2 * (C.first) + b2 * (C.second);

    db determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        db x = (b2 * c1 - b1 * c2) / determinant;
        db y = (a1 * c2 - a2 * c1) / determinant;
        return make_pair(x, y);
    }
}

int main()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)" ");
    int x1, y1, x2, y2;
    cout << "Enter coordinates of point A on line L1 (x,y): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of point B on line L1 (x,y): ";
    cin >> x2 >> y2;
    paired A = make_pair(x1, y1);
    paired B = make_pair(x2, y2);
    line(x1, y1, x2, y2);
    int x3, y3, x4, y4;
    cout << "Enter coordinates of point C on line L2 (x,y): ";
    cin >> x3 >> y3;
    cout << "Enter coordinates of point D on line L2 (x,y): ";
    cin >> x4 >> y4;
    paired C = make_pair(x3, y3);
    paired D = make_pair(x4, y4);
    paired intersection = findIntersection(A, B, C, D);
    line(x3, y3, x4, y4);
    if (intersection.first == FLT_MAX && intersection.second == FLT_MAX)
    {
        cout << "The given lines AB and CD are parallel.\n";
    }
    else
    {
        cout << "The intersection of the given lines AB and CD is: ";
        displayPoint(intersection);
        circle(intersection.first, intersection.second, 10);
    }
    getch();
    closegraph();
}
