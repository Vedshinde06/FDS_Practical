print("Basic Matrix Operation using Python") 
m1 = [] 
m2 = [] 
res = [[0 for _ in range(5)] for _ in range(5)]
print("For Matrix operation we require some input ") 
row1 = int(input("Enter the number of rows in the first matrix: ")) 
col1 = int(input("Enter the number of columns in the first matrix: ")) 
row2 = int(input("Enter the number of rows in the second matrix: ")) 
col2 = int(input("Enter the number of columns in the second matrix: "))

def main():
    print("\n----- Menu -----")
    print("1. Accept two matrices from user")
    print("2. Show the matrix values")
    print("3. Addition of two matrices")
    print("4. Subtraction of two matrices")
    print("5. Multiplication of two matrices")
    print("6. Transpose of a matrix")
    print("7. Exit")
    ch = int(input("Enter your choice: "))
    
    if ch == 1:
        print("Please enter the values for the first matrix:") 
        accept(m1, row1, col1)
        print("Please enter the values for the second matrix:")
        accept(m2, row2, col2)
        main()
    elif ch == 2:
        print("The values of the first matrix are as follows:")
        show(m1, row1, col1)
        print("The values of the second matrix are as follows:")
        show(m2, row2, col2)
        main()
    elif ch == 3:
        print("The addition of two matrices is as follows:")
        if row1 == row2 and col1 == col2:
            add_mat(m1, m2, row1, col1)
            show(res, row1, col1)
        else:
            print("Sorry! Addition is not possible...")
        main()
    elif ch == 4:
        print("The subtraction of two matrices is as follows:")
        if row1 == row2 and col1 == col2:
            sub_mat(m1, m2, row1, col1)
            show(res, row1, col1)
        else:
            print("Sorry! Subtraction is not possible...")
        main()
    elif ch == 5:
        print("The multiplication of two matrices is as follows:")
        if col1 == row2:
            mul(m1, m2, row1, col2)
            show(res, row1, col2)
        else:
            print("Sorry! Multiplication is not possible...")
        main()
    elif ch == 6:
        print("The transpose of the first matrix is as follows:")
        tran(m1, row1, col1)
        show(res, col1, row1)
        main()
    elif ch == 7:
        print("Exiting. Thank you!")
    else:
        print("Invalid choice. Please try again.")
        main()

def accept(m, row, col):
    for i in range(row):
        c = []
        for j in range(col):
            no = int(input(f"Enter the value of matrix[{i}][{j}]: "))
            c.append(no)
        m.append(c)

def show(m, row, col):
    for i in range(row):
        for j in range(col):
            print(m[i][j], end=" ")
        print()

def add_mat(m1, m2, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] = m1[i][j] + m2[i][j]

def sub_mat(m1, m2, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] = m1[i][j] - m2[i][j]

def mul(m1, m2, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] = 0
            for k in range(len(m2)):
                res[i][j] += m1[i][k] * m2[k][j]

def tran(m1, row, col):
    for i in range(row):
        for j in range(col):
            res[j][i] = m1[i][j]

main()
