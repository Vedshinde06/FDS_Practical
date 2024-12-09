def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        location = i
        for j in range(i+1, n):
            if arr[location] < arr[j]:
                location = j
        arr[i], arr[location] = arr[location], arr[i]
    return arr

def display_top_scores(arr, n=5):
    print("Top 5 scores:")
    for i in range(min(n, len(arr))):
        print(f"{i+1}. {arr[-i-1]}")

percentages = []
num_students = int(input("Enter the number of students: "))
for i in range(num_students):
    percentage = int(input(f"Enter percentage of student {i+1}: "))
    percentages.append(percentage)

flag = True
while flag:
    print("\nMenu:")
    print("1. Sort using Bubble Sort")
    print("2. Sort using Selection Sort")
    print("3. Display Top 5 Scores")
    print("4. Exit")
    
    ch = int(input("Enter your choice (1-4): "))
    if ch == 1:
        print("Before sorting:", percentages)
        sorted_percentages = bubble_sort(percentages.copy())
        print("After sorting (Ascending):", sorted_percentages)
    elif ch == 2:
        print("Before sorting:", percentages)
        sorted_percentages = selection_sort(percentages.copy())
        print("After sorting (Descending):", sorted_percentages)
    elif ch == 3:
        sorted_percentages = bubble_sort(percentages.copy())
        display_top_scores(sorted_percentages, n=5)
    elif ch == 4:
        print("Thank you for using my program!")
        flag = False
    else:
        print("Invalid choice. Please try again.")
