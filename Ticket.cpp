#include <iostream>
#include <string>
using namespace std;

class node {
public:
    node* next;
    node* prev;
    int seat;
    string id;
    int status;
};

class cinemax {
    node *head, *tail, *temp;

public:
    cinemax() { head = NULL; }
    void create_list();
    void display();
    void book();
    void cancel();
    void avail();
};

void cinemax::create_list() {
    head = new node;
    head->seat = 1;
    head->status = 0;
    head->id = "null";
    tail = head;

    for (int i = 2; i <= 70; i++) {
        node* newNode = new node;
        newNode->seat = i;
        newNode->status = 0;
        newNode->id = "null";
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    tail->next = head;
    head->prev = tail;
}

void cinemax::display() {
    int count = 0;
    node* temp = head;

    cout << "\n Screen this way \n";
    cout << "------------------------------------------------------------------------------------\n";

    do {
        if (temp->seat < 10)
            cout << "S0" << temp->seat << " :";
        else
            cout << "S" << temp->seat << " :";

        if (temp->status == 0)
            cout << "|___| ";
        else
            cout << "|_B_| ";

        count++;
        if (count % 7 == 0)
            cout << endl;

        temp = temp->next;
    } while (temp != head);

    cout << "\n------------------------------------------------------------------------------------\n";
}

void cinemax::book() {
    int seatNumber;
    string userId;

    cout << "\nEnter seat number to book (1-70): ";
    cin >> seatNumber;
    cout << "Enter your ID number: ";
    cin >> userId;

    if (seatNumber < 1 || seatNumber > 70) {
        cout << "Invalid seat number! Please choose a seat between 1 and 70.\n";
        return;
    }

    temp = head;
    do {
        if (temp->seat == seatNumber) {
            if (temp->status == 1) {
                cout << "Seat already booked!\n";
            } else {
                temp->status = 1;
                temp->id = userId;
                cout << "Seat " << seatNumber << " booked successfully!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void cinemax::cancel() {
    int seatNumber;
    string userId;

    cout << "\nEnter seat number to cancel (1-70): ";
    cin >> seatNumber;
    cout << "Enter your ID: ";
    cin >> userId;

    if (seatNumber < 1 || seatNumber > 70) {
        cout << "Invalid seat number! Please choose a seat between 1 and 70.\n";
        return;
    }

    temp = head;
    do {
        if (temp->seat == seatNumber) {
            if (temp->status == 0) {
                cout << "Seat not booked yet!\n";
            } else if (temp->id == userId) {
                temp->status = 0;
                temp->id = "null";
                cout << "Seat " << seatNumber << " cancelled successfully!\n";
            } else {
                cout << "Wrong ID! Seat cannot be cancelled.\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void cinemax::avail() {
    int count = 0;
    node* temp = head;

    cout << "\nAvailable Seats:\n";
    cout << "------------------------------------------------------------------------------------\n";

    do {
        // Display available seats only
        if (temp->status == 0) {
            if (temp->seat < 10)
                cout << "S0" << temp->seat << " :|___| ";
            else
                cout << "S" << temp->seat << " :|___| ";
        }

        count++;
        if (count % 7 == 0)
            cout << endl;

        temp = temp->next;
    } while (temp != head);

    cout << "\n------------------------------------------------------------------------------------\n";
}

int main() {
    cinemax obj;
    obj.create_list();
    int choice;
    char continueChoice = 'y';

    while (continueChoice == 'y') {
        cout << "\n*********************************************\n";
        cout << " CINEMAX MOVIE THEATRE\n";
        cout << "*********************************************\n";
        cout << "\nEnter your choice:\n";
        cout << "1. Current Seat Status\n";
        cout << "2. Book Seat\n";
        cout << "3. Available Seats\n";
        cout << "4. Cancel Seat\n";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.display();
                break;
            case 2:
                obj.book();
                break;
            case 3:
                obj.avail();
                break;
            case 4:
                obj.cancel();
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << "\nDo you want to perform any other operation? (y/n): ";
        cin >> continueChoice;
    }

    return 0;
}
