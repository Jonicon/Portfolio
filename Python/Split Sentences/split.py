# split up a paragraph into sentences
# using regular expressions


def splitParagraphIntoSentences(paragraph):
    ''' break a paragraph into sentences
        and return a list '''
    import re
    # to split by multile characters

    #   regular expressions are easiest (and fastest)
    sentenceEnders = re.compile('[.!?][\s]{1,2}(?=[A-Z])')
    sentenceList = sentenceEnders.split(paragraph)
    return sentenceList

# """This is a sentence.  This is an excited sentence! And do you think this is a question?"""
if __name__ == '__main__':

    
    p = open("text.txt", "r").read()

    sentences = splitParagraphIntoSentences(p)
    array=[]
    for s in sentences:
        s = s.replace('_', '\"')
        s = s.lstrip()
        s = s.capitalize()
        s = s.rstrip('\n')
        s = s + "."
        array.append(s)
        # print (s)

    while True:
        try:
            print("\nPrint out line (0 -", array.__len__() -1 , end=")\n")
            choice = int(input("Which line do you wish to see?:   "))
            if choice < 0 or choice > len(array):
                print("No choices above", len(array), "!")
                continue
        except ValueError as e:
            print(e)
            continue
        print(array[choice])








            
