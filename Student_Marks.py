def average(marks):
    sum=0
    length=0
    for i in marks:
        if (i>0):
            sum=sum+i
            length=length+1
    average=sum/length
    return average
def highest(marks):
    high=0
    for i in marks:
        if (i>high):
            high=i
    return high
def lowest(marks):
    low=100
    for i in marks:
        if (low>i>0):
            low=i
    return low
def absent(marks):
    ab=0
    for i in marks:
        if (i== -1):
            ab=ab+1
    return ab
n=int(input("Enter no of Student in Class:"))
marks=[]
for i in range (0,n):
    print("Enter Marks Of Student: ",i+1)
    lst=int(input())
    marks.append(lst)
flag=1
while flag==1:
    print("\n\n------MENU------\n")
    print("1. Average of Marks")
    print("2. Highest Score in Class")
    print("3. Lowest Score in Class")
    print("4. Number of Absent Student")
    print("5. Exit")
    choice=int(input("Enter your choice from 1 to 5: "))
    if (choice==1):
        average=average(marks)
        print("The Average of marks of all student in class is: ",average)
        a=(input("You want to Continue yes or no: "))
        if (a=='yes'):
            flag=1
        else:
            flag=0
            print(" Thank You ")
    elif choice==2:
        high=highest(marks)
        print("Highest Score in class is: ",high)
        a=(input("You want to comntinue yes or no: "))
        if (a=='yes'):
            flag=1
        else:
            flag=0
            print("Thank You")
    elif (choice==3):
        low=lowest(marks)
        print("lowest Score in class is: ",low)
        a=(input("You want to continue yes or no: "))
        if (a=='yes'):
            flag=1
        else:
            flag=0
            print("Thank You")
    elif (choice==4):
        ab=absent(marks)
        print("Number of absent student is: ",ab)
        
    elif (choice==5):
        print("Thanks")
        flag=0
    else:
        print("You have enter wrong choice.")
        a=(input("You want to continue yes or no:"))
        if (a=='yes'):
            flag=1
        else:
            flag=0
            print("Thank You")