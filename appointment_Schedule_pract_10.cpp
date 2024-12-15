#include <iostream>
#include <string>
using namespace std;

struct Appointment {
    string time;
    string details;
    Appointment* next;
};

class AppointmentSchedule {
private:
    Appointment* head;
    
    bool isTimeAvailable(const string& time) {
        Appointment* temp = head;
        while (temp) {
            if (temp->time == time) {
                return false; // Time slot already booked
            }
            temp = temp->next;
        }
        return true;
    }

public:
    AppointmentSchedule() : head(nullptr) {}

    void displayFreeSlots(const string slots[], int size) {
        cout << "Free Slots:\n";
        for (int i = 0; i < size; ++i) {
            if (isTimeAvailable(slots[i])) {
                cout << slots[i] << endl;
            }
        }
    }

    void bookAppointment(const string& time, const string& details) {
        if (!isTimeAvailable(time)) {
            cout << "Time slot " << time << " is already booked.\n";
            return;
        }

        Appointment* newAppointment = new Appointment{time, details, nullptr};
        if (!head || time < head->time) {
            newAppointment->next = head;
            head = newAppointment;
        } else {
            Appointment* temp = head;
            while (temp->next && temp->next->time < time) {
                temp = temp->next;
            }
            newAppointment->next = temp->next;
            temp->next = newAppointment;
        }
        cout << "Appointment booked at " << time << ".\n";
    }

    void cancelAppointment(const string& time) {
        if (!head) {
            cout << "No appointments to cancel.\n";
            return;
        }

        if (head->time == time) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
            cout << "Appointment at " << time << " cancelled.\n";
            return;
        }

        Appointment* temp = head;
        while (temp->next && temp->next->time != time) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "No appointment found at " << time << ".\n";
        } else {
            Appointment* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Appointment at " << time << " cancelled.\n";
        }
    }

    void displayAppointments() {
        if (!head) {
            cout << "No appointments scheduled.\n";
            return;
        }

        Appointment* temp = head;
        cout << "Appointment Schedule:\n";
        while (temp) {
            cout << "Time: " << temp->time << ", Details: " << temp->details << endl;
            temp = temp->next;
        }
    }

    ~AppointmentSchedule() {
        while (head) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    AppointmentSchedule schedule;
    string availableSlots[] = {"09:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00"};
    int numSlots = sizeof(availableSlots) / sizeof(availableSlots[0]);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display Appointments\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                schedule.displayFreeSlots(availableSlots, numSlots);
                break;
            case 2: {
                string time, details;
                cout << "Enter time for appointment (HH:MM): ";
                cin >> time;
                cout << "Enter details for appointment: ";
                cin.ignore();
                getline(cin, details);
                schedule.bookAppointment(time, details);
                break;
            }
            case 3: {
                string time;
                cout << "Enter time of appointment to cancel (HH:MM): ";
                cin >> time;
                schedule.cancelAppointment(time);
                break;
            }
            case 4:
                schedule.displayAppointments();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
