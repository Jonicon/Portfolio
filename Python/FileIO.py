"""
Read and write from a file, can also delete the file
"""


def readFile():
    s=""
    try:
        f = open(getFile(), "r")
        s = str(f.read())
        print(s)
        f.close()
    except IOError as e:
        print(e)


def writeFile():
    userStr = input("Write to file: ")
    try:
        fileName = getFile()
        f = open(fileName, "r")
        s = str(f.read())+ "\n"
        f.close()
        f = open(fileName, "a")
        userStr = str(s) + userStr
        f.write(userStr)
        f.close()
    
    except IOError as e:
        print(e)
        

def deleteFile():
    delFile = open(getFile(), "w")
    delFile.close()

def getFile():
    f = input("Give filename: ")
    return f


def main():

    
    while True:
        print("""
        [1] Read from file
        [2] Write to file
        [3] Delete file
        [e] Save and quit""")
    
        userInput = int(input("\tMake a choice [1-3, or e]:  "))

        if userInput == 1:
              readFile()
        elif userInput == 2:
              writeFile()
        elif userInput == 3:
              deleteFile()
        elif userInput == 4:
              break
        else:
            break

if __name__ == "__main__":
              main()
