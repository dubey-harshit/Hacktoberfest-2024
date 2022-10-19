from graphics import *
import time

def bresenham_line(x1, y1, x2, y2):
    st = time.time()
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    slope = dy/float(dx)
    x, y = x1, y1
    win = GraphWin('Bresenham\'s Line Drawing Algorithm', 600, 480)
    if slope > 1:
        dx, dy = dy, dx
        x, y = y, x
        x1, y1 = y1, x1
        x2, y2 = y2, x2
    p = 2 * dy - dx
    putpixel(win, x, y)
    for k in range(2, dx):
       if p > 0:
           y = y + 1 if y < y2 else y - 1
           p = p + 2*(dy - dx)
       else:
           p = p + 2*dy
       x = x + 1 if x < x2 else x - 1
       putpixel(win, x, y)
    et= time.time()
    elapsed_time = et - st
    print('Execution time:', elapsed_time, 'seconds')
    win.getMouse()
    win.close()
   
def putpixel(win, x, y):  
   pt = Point(x,y)
   pt.draw(win)
  
def main():
   x1 = int(input("Enter Start X: "))
   y1 = int(input("Enter Start Y: "))
   x2 = int(input("Enter End X: "))
   y2 = int(input("Enter End Y: "))
   bresenham_line(x1, y1, x2, y2)
      
if __name__ == "__main__":
   main()
