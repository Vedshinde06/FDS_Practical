def shellSort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def top_five(arr):
    print("Top five scores are:")
    cnt = len(arr)
    sorted_arr = sorted(arr, reverse=True)  # Sort array in descending order
    for i in range(min(5, cnt)):
        print(f"\t{sorted_arr[i]:.2f}")

def main():
    arr = []
    num = int(input("Enter the number of students: "))
    for i in range(num):
        per = float(input(f"Enter the marks of student {i + 1}: "))
        arr.append(per)

    while True:
        print("\nMenu:")
        print("1. Shell Sort")
        print("2. Insertion Sort")
        print("3. Display Top Five Marks")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            shellSort(arr)
            print("Sorted Array:", arr)
        elif choice == 2:
            insertion_sort(arr)
            print("Sorted Array:", arr)
        elif choice == 3:
            top_five(arr)
        elif choice == 4:
            print("Exiting...")
            break
        else:
            print("Invalid input. Please try again.")

if __name__ == "__main__":
    main()
