from graphics import *
import time

def putpixel(win,x, y):  
   pt = Point(x,y)
   pt.draw(win)

def drawcircle(win,xc,yc,x,y):
    putpixel(win,xc + x, yc + y)
    putpixel(win,xc - x, yc + y)
    putpixel(win,xc + x, yc - y)
    putpixel(win,xc - x, yc - y)
    putpixel(win,xc + y, yc + x)
    putpixel(win,xc - y, yc + x)
    putpixel(win,xc + y, yc - x)
    putpixel(win,xc - y, yc - x)

def circlemidpoint(xc, yc, r):
    st = time.time()
    x=0
    y=r
    p=1-r
    win = GraphWin('Bresenham\'s Line Drawing Algorithm', 600, 480)
    while x<y:
        drawcircle(win,xc, yc, x, y)
        x+=1
        if p < 0:
            p = p + 2 * x + 1
        else:
            y-=1
            p = p + 2 * (x - y) + 1
        drawcircle(win,xc, yc, x, y)

    et= time.time()
    elapsed_time = et - st
    print('Execution time:', elapsed_time, 'seconds')
    win.getMouse()
    win.close()
  
def main():
    x1 = int(input("Enter center X: "))
    y1 = int(input("Enter center Y: "))
    r = int(input("Radius: "))
    circlemidpoint(x1, y1, r)
      
if __name__ == "__main__":
   main()
