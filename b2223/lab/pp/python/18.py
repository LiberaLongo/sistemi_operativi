import turtle
import colorsys
import time

N=6
frompin=list(range(N,0,-1))
auxpin=[]
topin=[]

def rectangle(size, level, pin):
        turtle.penup()
        turtle.setpos(2*N*10*pin,level*10)
        turtle.setheading(0)
        turtle.pendown()
        turtle.fillcolor(colorsys.hls_to_rgb(1.0*(size-1)/N,0.5,1))
        turtle.begin_fill()
        turtle.forward(size*10)
        turtle.left(90)
        turtle.forward(10)
        turtle.left(90)
        turtle.forward(size*20)
        turtle.left(90)
        turtle.forward(10)
        turtle.left(90)
        turtle.forward(size*10)
        turtle.end_fill()

def showhanoi():
        turtle.clear()
        lf,la,lt=map(len,(frompin,auxpin,topin))
        for i in range(lf):
                rectangle(frompin[i], i, -1)
        for i in range(la):
                rectangle(auxpin[i], i, 0)
        for i in range(lt):
                rectangle(topin[i], i, 1)
        turtle.update()
        time.sleep(0.2)

def hanoi(n,f,a,t):
        if n==1:
                t.append(f.pop())
                showhanoi()
        else:
                hanoi(n-1,f,t,a)
                hanoi(1,f,a,t)
                hanoi(n-1,a,f,t)

turtle.hideturtle()
turtle.speed(10)
turtle.tracer(0)
showhanoi()
hanoi(N,frompin,auxpin,topin)
turtle.exitonclick()
