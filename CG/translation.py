from graphics import *
import time

win = GraphWin('Translation Algorithm', 600, 480)

def putpixel(win, x, y):
    pt = Point(x,y)
    pt.draw(win)

def rectangle(xmin, ymin, xmax, ymax):
    t_begin = time.time()
    rect = Rectangle(Point(xmin, ymin), Point(xmax, ymax))
    rect.draw(win)
    return time.time() - t_begin

def translate_rectanlge(xmin, ymin, xmax, ymax):
    xf, yf = (int(s) for s  in input().split(" "))
    t_begin = time.time()
    rect = Rectangle(Point(xmin+xf, ymin+yf), Point(xmax+xf, ymax+yf))
    rect.draw(win)
    return time.time() - t_begin

def main():
    xmin, ymin = (int(s) for s in input("Enter starting co-ordinates of rectangle: ").split(" "))
    xmax, ymax = (int(s) for s in input("Enter ending co-ordinates of rectangle: ").split(" "))
    
    t_begin = time.time()
    rectangle(xmin, ymin, xmax, ymax)
    t = time.time()-t_begin
    t += translate_rectanlge(xmin, ymin, xmax, ymax)
    print("Execution Time: {}".format(t))
    win.getMouse()
    win.close()
    
if __name__ == "__main__":
    main()
