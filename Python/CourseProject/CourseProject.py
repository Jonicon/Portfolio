import os
from sys import exit
import sys

fileContent = []
fileList = []
fileName = ""

def createList():
    fileList.append( input("File name:  ") )
    getFileContent()

def addToList():
    printList()
    fileContent.append( str(input("Add to list:   ")) )
    saveToFile()

def removeFromList():
    for i in fileContent:
        print("\t" + i)

    if len(fileContent > 1):
        fileContent.pop( input("Which item do you wish to delete [1 - ", len(fileContent), end="]:  ") )
        saveToFile()
    else:
        print("The list is empty...")

def saveToFile():
    f = open(fileName, "w")
    f.write(fileContent)
    f.close()

def deleteList():
    viewLists()
    try:
        os.remove( getFileName() )
    except OSError:
        pass

def SwitchList():
    try:
        fileList = open("listOfFiles.txt", "r").read()
    except IOError as e:
        print(e)
    
    for i in fileList:
        print("\t" + i)

    fileName = input("Choose a list:   ")
    

def getFileContent():
    fileContent = open( getFileName(), "r" ).read()

def getFileName():
    return fileName

def printList():
    for i in fileContent:
        print("\t" + i)

def viewLists():
    try:
        fileList = open("listOfFiles.txt", "r").read()
    except IOError as e:
        print(e)
    
    for i in fileList:
        print("\t" + i)


def printStartMenu():
    print("""       1: View lists
       2: Create new list
       3: Delete a list
       4: Exit""")

  

def printSubMenu():
    while True:
        print( "Current file:  " + getFileName() )
        print("""           1: View list
      2: Add to list
      3: Delete from list
      4: Back  """)

        choice = input("What do you wish to do:   ")
        if choice == 1:
            printList()
        elif choice == 2:
            addToList()
        elif choice == 3:
            removeFromList()
        elif choice == 4:
            break
    

if __name__ == "__main__":
    while True:
        printStartMenu()

        choice = int(input("What do you wish to do:   "))
        if choice == 1:
            viewLists()
        elif choice == 2:
            createList()
        elif choice == 3:
            deleteList()
        elif choice == 4:
            sys.exit()

