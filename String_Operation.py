def In(element, list1):
    return element in list1

def first_appe(string, substring):
    try:
        return string.index(substring)
    except ValueError:
        return -1

def rev(string):
    return string[::-1]

def str_count(str1, char):
    return str1.count(char)

def max_len(splitL):
    global new_str2
    longest_word = max(splitL, key=len)
    new_str2 = longest_word
    return len(longest_word)

def is_palindrome(string):
    return string == string[::-1]

flag = True
while flag:
    print("\n\n-----Menu----\n")
    print("1. Check Palindrome string.")
    print("2. Find the word with the maximum length in a string.")
    print("3. Count occurrences of a specific character.")
    print("4. Find the first appearance of a substring.")
    print("5. Exit")
    choice = int(input("Enter Choice (1 to 5): "))
    
    if choice == 1:
        str1 = input("Enter a string to check if it is a palindrome: ")
        if is_palindrome(str1):
            print("Entered string is a palindrome.")
        else:
            print("Entered string is not a palindrome.")
    
    elif choice == 2:
        str2 = input("Enter a sentence to find the longest word: ")
        words = str2.split()
        print("Max length: ", max_len(words), "Word: ", new_str2)
    
    elif choice == 3:
        str3 = input("Enter a string to count occurrences of a specific character: ")
        ch = input("Enter character: ")
        print("Entered character count is: ", str_count(str3, ch))
    
    elif choice == 4:
        str4 = input("Enter a string to find the first appearance of a substring: ")
        sub_string = input("Enter substring: ")
        index = first_appe(str4, sub_string)
        if index != -1:
            print(f"'{sub_string}' is at index {index}.")
        else:
            print(f"'{sub_string}' is not found in the string.")
    
    elif choice == 5:
        flag = False
        print("Thank you!")
    
    else:
        print("Invalid choice. Please try again.")