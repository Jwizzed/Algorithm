//
// Created by Krittin Setdhavanich on 16/5/2023 AD.
//

#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode* next;

    ListNode(valueType val, ListNode* next=0)
            : val(val), next(next) {}
};

class LinkedList
{
private:
    ListNode* header;
    ListNode* tail;
    void free_list();

public:
    LinkedList();
    ~LinkedList();
    void print_list();
    void insert_front(valueType x);
    void append(valueType x);
};

LinkedList::LinkedList()
{
    header = new ListNode(0);
    tail = header;
}

/* To save space, functions ~LinkedList, print_list and free_list are hidden. */


void LinkedList::append(valueType x)
{
    ListNode* newNode = new ListNode(x);
    newNode->next = NULL;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    tail = newNode;

}

void LinkedList::insert_front(valueType x)
{
    ListNode* newNode = new ListNode(x);
    newNode->next = header->next;
    header->next = newNode;

    while(tail->next != NULL){
        tail = tail->next;
    }
}

main()
{
    LinkedList list;
    int t;

    cin >> t;
    for(int i = 0; i < t; i++) {
        int dir, val;
        cin >> dir >> val;
        if(dir == 1) {
            list.insert_front(val);
        } else {
            list.append(val);
        }
    }
    list.print_list();
}