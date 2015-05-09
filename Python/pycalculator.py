import tkinter as tk
from tkinter import *
from math import sqrt

class Window(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.grid()
        self.createWidgets()

    def createWidgets(self):
##        self.quitButton = tk.Button(self, text='Quit', command=self.quit)
##        self.quitButton.grid(row=0, column=0, columnspan=1)
        self.rowconfigure(0, weight=1, pad=1)
        self.rowconfigure(1, weight=1)
        self.rowconfigure(2, weight=1)
        
        ## Create Entry and buttons
        self.string = StringVar()
        self.entry = tk.Entry(self, textvariable=self.string, width=28, justify=RIGHT)
        self.entry.grid(row=0, column=0, columnspan=6)

        

        self.numOne = tk.Button(self, text='1', anchor=CENTER, width=3, command=lambda:self.addNum('1'))
        self.numOne.grid(row=1, column=0)

        self.numTwo = tk.Button(self, text='2', anchor=CENTER, width=3, command=lambda:self.addNum('2'))
        self.numTwo.grid(row=1, column=1,)

        self.numThree = tk.Button(self, text='3', anchor=CENTER, width=3, command=lambda:self.addNum('3'))
        self.numThree.grid(row=1, column=2)

        self.plus = tk.Button(self, text='+', width=3, command=lambda:self.addOp('+'))
        self.plus.grid(row=1, column=3)

        self.numFour = tk.Button(self, text='4', anchor=CENTER, width=3, command=lambda:self.addNum('4'))
        self.numFour.grid(row=2, column=0)

        self.numFive = tk.Button(self, text='5',anchor=CENTER, width=3, command=lambda:self.addNum('5'))
        self.numFive.grid(row= 2, column=1)

        self.numSix = tk.Button(self, text='6',anchor=CENTER, width=3, command=lambda:self.addNum('6'))
        self.numSix.grid(row= 2, column=2)

        self.minus = tk.Button(self, text='-', anchor=CENTER, width=3,  command=lambda:self.addOp('-'))
        self.minus.grid(row=2, column=3)

        self.numSeven = tk.Button(self, text='7',anchor=CENTER, width=3, command=lambda:self.addNum('7'))
        self.numSeven.grid(row=3 , column=0)

        self.numEight = tk.Button(self, text='8', anchor=CENTER, width=3, command=lambda:self.addNum('8'))
        self.numEight.grid(row=3, column=1)

        self.numNine = tk.Button(self, text='9', anchor=CENTER, width=3, command=lambda:self.addNum('9'))
        self.numNine.grid(row=3, column=2)

        self.numDivide = tk.Button(self, text='/', anchor=CENTER, width=3,  command=lambda:self.addOp('/'))
        self.numDivide.grid(row=3, column=3)

        self.numZero = tk.Button(self, text='0', anchor=CENTER, width=8,  command=lambda:self.addNum('0'))
        self.numZero.grid(row=4, column=0, columnspan=2)

        self.numPoint = tk.Button(self, text='.', anchor=CENTER, width=3,  command=lambda:self.addPoint('.'))
        self.numPoint.grid(row=4, column=2)

        self.numTimes = tk.Button(self, text='*', anchor=CENTER, width=3,  command=lambda:self.addOp('*'))
        self.numTimes.grid(row=4, column=3)

        self.sqrt = tk.Button(self, text='sr', width=3,  command=lambda:self.addSqrt())
        self.sqrt.grid(row=1, column=4)

        self.clear = tk.Button(self, text='C', width=3, command=lambda:self.clearScreen())
        self.clear.grid(row=2, column=4)

        self.equals = tk.Button(self, text='=', width=3, height= 3, command=lambda:self.calculate())
        self.equals.grid(row=3, column=4, rowspan=2)

    def clearScreen(self):
        self.entry.delete(0, tk.END)

    def addNum(self, num):
        self.string.set(self.string.get()+str(num))

    def addOp(self, op):
        self.string.set(self.string.get()+ str(op))

    def addSqrt(self):
        self.string.set('sqrt('+self.string.get()+')')

    def addPoint(self, point):
        text=self.string.get()
        notAllowed = '+', '-', '/', '*'
        if self.string.get() == '':
            self.string.set(str('0'+point))
        elif text.endswith(notAllowed):
            self.string.set( str(self.string.get() + '0.') ) 

    def calculate(self):
        self.string.set('=   ' + str(eval(self.string.get())))



app = Window()
app.master.title("Simple Calculator")

app.mainloop()
        
