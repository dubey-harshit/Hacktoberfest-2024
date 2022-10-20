from graphics import *
import time
from math import cos, sin

win = GraphWin('Rotation Algorithm', 600, 480)

def putpixel(x, y):
    pt = Point(x,y)
    pt.draw(win)

def triangle(x, y):
    tr = Polygon(Point(x[0], y[0]), Point(x[1], y[1]), Point(x[2], y[2]))
    tr.draw(win)

def mul(ar1, ar2):
    if (len(ar1[0]) != len(ar2)):
        print("{} {}".format(len(ar1[0]), len(ar2)))
        print("Multiplication not possible")
        exit()

    mult = []
    mult.append([0,0,0])
    mult.append([0,0,0])
    mult.append([0,0,0])
    for i in range(0, len(ar1)):
        for j in range(0, len(ar2[0])):
            for k in range(0, len(ar1[0])):
                #print("{}, {}, {}".format(mult[i][j], ar1[i][k], ar2[k][j]))
                mult[i][j] += ar1[i][k] * ar2[k][j]
    return mult
    
def rotate_mat(vert_mat):
    angle = int(input("Angle: "))
    angle = (-angle * 3.14)/180
    rot_mat = []
    rot_mat.append([cos(angle), -1*sin(angle), 0])
    rot_mat.append([sin(angle), cos(angle), 0])
    rot_mat.append([0,0,1])

    transl_mat = []
    transl_mat.append([1,0,-vert_mat[0][0]])
    transl_mat.append([0,1,-vert_mat[1][0]])
    transl_mat.append([0,0,1])

    transl_mat2 = []
    transl_mat2.append([1,0,vert_mat[0][0]])
    transl_mat2.append([0,1,vert_mat[1][0]])
    transl_mat2.append([0,0,1])

    trans1 = mul(rot_mat, transl_mat)
    trans2 = mul(transl_mat2, trans1)
    transformed = mul(trans2, vert_mat)
    return transformed

def main():
    x1,y1 = (int(s) for s  in input("Enter the 1st point for the triangle: ").split(" "))
    x2,y2 = (int(s) for s  in input("Enter the 2nd point for the triangle: ").split(" "))
    x3,y3 = (int(s) for s  in input("Enter the 3rd point for the triangle: ").split(" "))

    vert_mat = []
    X = [x1, x2, x3]
    Y = [y1, y2, y3]
    vert_mat.append(X)
    vert_mat.append(Y)
    vert_mat.append([1,1,1])
    triangle(X, Y)
    print(X, Y)
    st= time.time()
    tf = rotate_mat(vert_mat)
    et= time.time()
    elapsed_time = et - st
    print('Execution time:', elapsed_time, 'seconds')
    triangle(tf[0], tf[1])
    win.getMouse()
    win.close()

if __name__ == "__main__":
    main()
