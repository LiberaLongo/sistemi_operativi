import turtle
import sys

rows,cols=4,4
buttonsize=50
topdisplay=2*buttonsize

stack=[0]
fresh=True

def num(x):
        global fresh,stack
        if fresh:
                stack[:0]=[x]
                fresh=False
        else:
                stack[0]=stack[0]*10+x

enter,add,sub,mul,div=0,int.__add__,int.__sub__,int.__mul__,int.__floordiv__

def op(x):
        global fresh,stack
        if x!=enter and len(stack)>1:
                stack=[x(stack[1],stack[0])]+stack[2:]
        fresh=True

def off(x):
        sys.exit(0)

buttons={ 
        (0,0):('0',num,0), (1,0):('1',num,1), (1,1):('2',num,2), (1,2):('3',num,3), (2,0):('4',num,4), 
        (2,1):('5',num,5), (2,2):('6',num,6), (3,0):('7',num,7), (3,1):('8',num,8), (3,2):('9',num,9), 
        (3,3):('+',op,add), (2,3):('-',op,sub), (1,3):('*',op,mul), (0,3):('/',op,div),
        (0,2):('ent',op,enter), (0,1):('off',off,0)}

def click(x,y):
        col=x//buttonsize
        row=y//buttonsize
        if (row,col) in buttons:
                label,op,val=buttons[row,col]
                op(val)
                drawcalc()

def drawcalc():
        def drawbutton(col,row,label):
                turtle.setpos(row*buttonsize,col*buttonsize)
                turtle.pendown()
                for _ in range(4):
                        turtle.forward(buttonsize)
                        turtle.left(90)
                turtle.penup()
                turtle.setpos(row*buttonsize+buttonsize//2,col*buttonsize+buttonsize//2)
                turtle.write(label,align="center")
        turtle.clear()
        turtle.penup()
        for row,col in buttons:
                drawbutton(row,col,buttons[row,col][0])
        turtle.setpos(row*buttonsize*(rows-1),col*buttonsize*(cols+1))
        turtle.write(str(stack[0]),align="right")
        turtle.update()

turtle.screensize(cols*buttonsize+1, rows*buttonsize+topdisplay+1)
turtle.setup(cols*buttonsize+1, rows*buttonsize+topdisplay+1)
turtle.setworldcoordinates(0,0,cols*buttonsize, rows*buttonsize+topdisplay)
turtle.hideturtle()
turtle.speed(10)
turtle.tracer(0)
drawcalc()
turtle.onscreenclick(click)
turtle.listen()
turtle.mainloop()
