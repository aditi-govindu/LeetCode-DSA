'''
Question from Indian National Olympiad (INOI), 2007

Description:
Before smartphones and touch keypads were invented, button phones were used. 
Every button or key in the phone had 2 or more letters associated with that number. 
That is, every number from 0-9 had a uniques combination of alphabets from a to z assigned to them. This mapping is illustrated below: 
Number Letters associated 2 {a, b, c} 3 {d, e, f} 4 {g, h, i} 5 {j, k, l} 6 {m, n, o} 7 {p, q, r, s} 8 {t, u, v} 9 {w, x, y, z}
'''

words=list()
word_num={}

#Map every letter to a number based on given list
def Mapping(n):
    for i in range(n):
        i=input()
        #Convert user entered word to lower case by default
        i=i.lower()
        words.append(i)

    for element in words:
        i=0
        #number is a string that contains the numeric equivalent of word
        number=''

        for i in range(len(element)):
            #If letter is a,b,c: number 2 is assigned
            if(element[i] == 'a' or element[i]=='b' or element[i]=='c'):
                number=number+str(2)
                i=i+1
            #If letter is d,e,f: number 3 is assigned
            elif(element[i] == 'd' or element[i]=='e' or element[i]=='f'):
                number=number+str(3)
                i=i+1
            #If letter is g,h,i: number 4 is assigned
            elif(element[i] == 'g' or element[i]=='h' or element[i]=='i'):
                number=number+str(4)
                i=i+1
            #If letter is j,k,l: number 5 is assigned
            elif(element[i] == 'j' or element[i]=='k' or element[i]=='l'):
                number=number+str(5)
                i=i+1
            #If letter is m,n,o: number 6 is assigned
            elif(element[i] == 'm' or element[i]=='n' or element[i]=='o'):
                number=number+str(6)
                i=i+1
            #If letter is p,q,r,s: number 7 is assigned
            elif(element[i] == 'p' or element[i]=='q' or element[i]=='r' or element[i]=='s'):
                number=number+str(7)
                i=i+1
            #If letter is t,u,v: number 8 is assigned
            elif(element[i] == 't' or element[i]=='u' or element[i]=='v'):
                number=number+str(8)
                i=i+1
            #If letter is w,x,y,z: number 9 is assigned
            elif(element[i] == 'w' or element[i]=='x' or element[i]=='y' or element[i]=='z'):
                number=number+str(9)
                i=i+1
            #If character is not a letter, no assignment
            #Index is moved by 1
            else:
                i=i+1
        if(int(number) in word_num):
            #If key is in dictionary, increase count by 1
            word_num[int(number)]=word_num[int(number)]+1
        else:
            #Add key to dictionary
            word_num[int(number)]=1
    #Print key with maximum value or maximum count
    print(max(word_num, key=word_num.get))

#Driver code
n=int(input())
Mapping(n)
