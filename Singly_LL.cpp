#include <iostream>
#include <cstring>
using namespace std;

class node {
    friend class list;
    int prnno;
    char name[30];
    node *next;

public:
    node(int d, const char s[]) {
        prnno = d;
        strcpy(name, s);
        next = NULL;
    }
};

class list {
    node *start;

public:
    list() { start = NULL; }

    void display() {
        node *ptr = start;
        if (ptr == NULL) {
            cout << "\nList is empty!\n";
            return;
        }
        cout << "\nInfo is:\n";
        while (ptr != NULL) {
            cout << "\n" << ptr->prnno << "\t" << ptr->name;
            ptr = ptr->next;
        }
    }

    void insertmember();
    void createmember();
    void insertpresident();
    void insertsecretary();
    void deletemember();
    void delete1();
    void deletesecretary();
    void deletepresident();
    void count();
    void reverse(node *);
    void reverse1() { reverse(start); }
    void concatinate(list &s1, list &s2);
};

void list::insertmember() {
    int prnno;
    char name[30];
    node *ptr, *temp;
    cout << "\nEnter PRN number: ";
    cin >> prnno;
    cout << "\nEnter name: ";
    cin >> name;
    temp = new node(prnno, name);
    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void list::insertpresident() {
    int prnno;
    char name[30];
    node *temp;
    cout << "\nEnter PRN number: ";
    cin >> prnno;
    cout << "\nEnter name: ";
    cin >> name;
    temp = new node(prnno, name);
    temp->next = start;
    start = temp;
}

void list::insertsecretary() {
    int prnno;
    char name[30];
    node *ptr, *temp;
    cout << "\nEnter PRN number: ";
    cin >> prnno;
    cout << "\nEnter name: ";
    cin >> name;
    temp = new node(prnno, name);
    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void list::createmember() {
    int ch;
    char ans;
    do {
        cout << "\nChoose:";
        cout << "\n1 - Member\n2 - Secretary\n3 - President\n";
        cin >> ch;
        switch (ch) {
            case 1: insertmember(); break;
            case 2: insertsecretary(); break;
            case 3: insertpresident(); break;
            default: cout << "Invalid choice!"; break;
        }
        cout << "\nInsert more? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
}

void list::delete1() {
    int ch;
    char ans;
    do {
        cout << "\nChoose:";
        cout << "\n1 - Member\n2 - Secretary\n3 - President\n";
        cin >> ch;
        switch (ch) {
            case 1: deletemember(); break;
            case 2: deletesecretary(); break;
            case 3: deletepresident(); break;
            default: cout << "Invalid choice!"; break;
        }
        cout << "\nDelete more? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
}

void list::deletesecretary() {
    if (start == NULL) {
        cout << "\nList is empty!";
        return;
    }
    node *ptr = start, *prev = NULL;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev != NULL) prev->next = NULL;
    delete ptr;
    cout << "\nSecretary deleted";
}

void list::deletepresident() {
    if (start == NULL) {
        cout << "\nList is empty!";
        return;
    }
    node *ptr = start;
    start = start->next;
    delete ptr;
    cout << "\nPresident deleted";
}

void list::deletemember() {
    if (start == NULL) {
        cout << "\nList is empty!";
        return;
    }
    int p;
    cout << "\nEnter PRN number to delete: ";
    cin >> p;
    node *ptr = start, *prev = NULL;

    while (ptr != NULL && ptr->prnno != p) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "\nData not found!";
    } else {
        if (prev == NULL) {
            start = start->next;
        } else {
            prev->next = ptr->next;
        }
        delete ptr;
        cout << "\nMember deleted";
    }
}

void list::count() {
    int cnt = 0;
    node *ptr = start;
    while (ptr != NULL) {
        cnt++;
        ptr = ptr->next;
    }
    cout << "\nTotal number of nodes: " << cnt;
}

void list::reverse(node *ptr) {
    if (ptr == NULL)
        return;
    reverse(ptr->next);
    cout << "\n" << ptr->prnno << "\t" << ptr->name;
}

void list::concatinate(list &s1, list &s2) {
    node *ptr = s1.start;
    if (ptr == NULL) {
        s1.start = s2.start;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = s2.start;
    }
    s1.display();
}

int main() {
    int ch;
    char ans;
    list sll1, sll2;

    do {
        cout << "\nEnter your choice:";
        cout << "\n1 - Create Member\n2 - Display\n3 - Delete Member\n4 - Count Nodes\n5 - Reverse\n6 - Concatenate\n";
        cin >> ch;

        switch (ch) {
            case 1: sll1.createmember(); break;
            case 2: sll1.display(); break;
            case 3: cout << "\nEnter nodes to be deleted in the list: "; sll1.delete1(); break;
            case 4: sll1.count(); break;
            case 5: cout << "\nReversed list:"; sll1.reverse1(); break;
            case 6: sll2.createmember(); sll1.concatinate(sll1, sll2); break;
            default: cout << "\nInvalid choice!"; break;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
