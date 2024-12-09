#include <iostream>
using namespace std;
#define SIZE 5

class Pizza
{
    int porder[SIZE];
    int front, rear;

public:
    Pizza()
    {
        front = rear = -1;
    }

    int qfull()
    {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
            return 1;
        return 0;
    }

    int qempty()
    {
        if (front == -1)
            return 1;
        return 0;
    }

    void accept_order(int);
    void make_payment(int);
    void order_in_queue();
};

void Pizza::accept_order(int item)
{
    if (qfull())
        cout << "\nVery Sorry !!!! No more orders....\n";
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        porder[rear] = item;
    }
}

void Pizza::make_payment(int n)
{
    int item;
    if (qempty())
        cout << "\nSorry !!! No order is there...\n";
    else
    {
        cout << "\nDelivered orders as follows...\n";
        for (int i = 0; i < n; i++)
        {
            item = porder[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
            cout << "\t" << item;
        }
        cout << "\nTotal amount to pay: " << n * 100;
        cout << "\nThank you! Visit again....\n";
    }
}

void Pizza::order_in_queue()
{
    int temp;
    if (qempty())
    {
        cout << "\nSorry !! There is no pending order...\n";
    }
    else
    {
        temp = front;
        cout << "\nPending orders as follows..\n";
        while (temp != rear)
        {
            cout << "\t" << porder[temp];
            temp = (temp + 1) % SIZE;
        }
        cout << "\t" << porder[temp];
    }
}

int main()
{
    Pizza p1;
    int ch, k, n;
    do
    {
        cout << "\n\t***** Welcome To Pizza Parlor *******\n";
        cout << "\n1. Accept order\n2. Make payment\n3. Pending Orders\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nWhich Pizza do you like most....\n";
            cout << "\n1. Veg Soya Pizza\n2. Veg Butter Pizza\n3. Egg Pizza";
            cout << "\nPlease enter your order: ";
            cin >> k;
            p1.accept_order(k);
            break;
        case 2:
            cout << "\nHow many pizzas? ";
            cin >> n;
            p1.make_payment(n);
            break;
        case 3:
            cout << "\nFollowing orders are in queue to deliver....\n";
            p1.order_in_queue();
            break;
        }
    } while (ch != 4);
    return 0;
}