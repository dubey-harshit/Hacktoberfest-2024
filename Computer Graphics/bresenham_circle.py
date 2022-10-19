from graphics import *
import time

def putpixel(win, x, y):
    pt = Point(x,y)
    pt.draw(win)

def drawCircle(xc,yc,x,y,win):
    putpixel(win, xc+x, yc+y )
    putpixel(win, xc-x, yc+y )
    putpixel(win, xc+x, yc-y )
    putpixel(win, xc-x, yc-y )
    putpixel(win, xc+y, yc+x )
    putpixel(win, xc-y, yc+x )
    putpixel(win, xc+y, yc-x )
    putpixel(win, xc-y, yc-x )

def BresenhamCircle(xc,yc,r):
    st = time.time()
    win = GraphWin('Bresenham\'s Line Drawing Algorithm', 600, 480)
    x = 0
    y = r
    d = 3-2*r
    while (y>=x):
        x+=1
        if (d>0):
            y-=1
            d = d+4*(x-y)+10
        else:
            d = d + 4*x + 6
        drawCircle(xc,yc,x,y,win)
    et= time.time()
    elapsed_time = et - st
    print('Execution time:', elapsed_time, 'seconds')
    win.getMouse()
    win.close()
    
def main():
    x1 = int(input("Enter center X: "))
    y1 = int(input("Enter center Y: "))
    r = int(input("Radius: "))
    BresenhamCircle(x1, y1, r)
      
if __name__ == "__main__":
    main()
