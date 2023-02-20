#include <iostream>
using namespace std;

struct QueueNode{
    int val;
    QueueNode *prev;
    QueueNode *next;
    QueueNode(int val, QueueNode* prev=nullptr, QueueNode *next = nullptr): val(val),prev(prev), next(next) {}
};

struct BusNode{
    QueueNode *point;
    BusNode *prev;
    BusNode *next;
    BusNode(QueueNode* point, BusNode *prev=nullptr, BusNode *next = nullptr): point(point), prev(prev), next(next) {}
};

class DoublyLinkedList
{
private:
    QueueNode *head;
    QueueNode *tail;
    BusNode *bus_1;
    BusNode *bus_3;
    BusNode *bus_S;
    BusNode *bus_tail;

public:
    DoublyLinkedList();
    void AddPassenger(string l);
    void BoardBus(string l);
    void GetQueue();
};

DoublyLinkedList::DoublyLinkedList() {

    head = new QueueNode(0,nullptr,tail);
    tail = new QueueNode(0,head,nullptr);
    bus_1 = new BusNode(nullptr, nullptr,bus_3);
    bus_3 = new BusNode(nullptr, bus_1,bus_S);
    bus_S = new BusNode(nullptr,bus_3, bus_tail);
    bus_tail = new BusNode(nullptr, bus_S, nullptr);
}


void DoublyLinkedList::AddPassenger(string l) {
    int val;
    if(l=="1") val=1;
    else if(l=="3") val=3;
    else if(l=="S") val=5;

    QueueNode *passenger = new QueueNode(val, tail->prev,tail);
    tail->prev->next = passenger;
    tail->prev = passenger;

    if (l == "1") {
        BusNode *bus_pas = new BusNode(passenger, bus_3->prev, bus_3);
        bus_3->prev->next = bus_pas;
        bus_3->prev = bus_pas;

    } else if (l == "3") {
        BusNode *bus_pas = new BusNode(passenger, bus_S->prev, bus_S);
        bus_S->prev->next = bus_pas;
        bus_S->prev = bus_pas;

    } else if (l == "S") {
        BusNode *bus_pas = new BusNode(passenger, bus_tail->prev, bus_tail);
        bus_tail->next->prev = bus_pas;
        bus_tail->next = bus_pas;

    }
}

void DoublyLinkedList::BoardBus(string l) {
    BusNode *start;
    BusNode *end;
    if(l == "1")
    {
        start = bus_1;
        end = bus_3;
    }
    else if(l == "3")
    {
        start = bus_3;
        end = bus_S;
    }
    else if(l == "S")
    {
        start = bus_S;
        end = bus_tail;
    }
    while(start->next!=end){
        BusNode *BusTemp = start->next;
        start->next = BusTemp->next;
        start->next->prev = start;

        QueueNode *QueueTemp = BusTemp->point;
        QueueTemp->prev->next = QueueTemp->next;
        QueueTemp->next->prev = QueueTemp->prev;

        delete (QueueTemp);
        delete BusTemp;

    }
}

void DoublyLinkedList::GetQueue() {
    QueueNode *passenger = head->next;

    while(passenger != tail){
        if (passenger->val==1 || passenger->val==3 || passenger->val==5){
            if( passenger->val==1) cout << "1" << endl;
            else if (passenger->val==3) cout << "3" << endl;
            else if (passenger->val==5) cout << "S" << endl;
        }
        passenger = passenger->next;
    }
}

int main() {
    DoublyLinkedList* A = new DoublyLinkedList();
    int choice;

    do {
        cout << "What would you like to do?" << endl;
        cout << "1.Add passenger" << endl;
        cout << "2.Board bus" << endl;
        cout << "3.Print queue" << endl;
        cout << "9.Exit Program" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                A->AddPassenger("1");
                cout << "Passenger added" << endl;
                break;
            case 2:
                A->BoardBus("1");
                cout << "Bus boarded" << endl;
                break;
            case 3:
                {
                    A->GetQueue();
                    break;
                }
            case 9:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }while (choice != 9);
    return 0;
}



