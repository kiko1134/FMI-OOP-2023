#include "Queue.h"
#include "Ticket.h"
#include <iostream>

Queue::Queue(int capacity) {
    size = 0;
    this->capacity = capacity;
    queue = new Ticket[capacity];
}

unsigned int Queue::getTicket(const char *name, const char *phone) {
    if (size >= capacity) {
        capacity = 2 * capacity + 1;
        Ticket *newArr = new Ticket[capacity];
        memcpy(newArr, queue, size * sizeof(Ticket));
        delete[] queue;
        queue = newArr;
    }
    Ticket currTicket(name, phone);
    ++size;
    queue[size - 1] = currTicket;
    return currTicket.getId();
}
Ticket &Queue::operator[](unsigned int index) {
    bool flag = true;
    int i = 0;
    while (i < size) {
        if (queue[i].getId() == index) {
            flag = false;
        }
        i++;
    }
    if (flag) throw std::invalid_argument("There is no such element with the selected index");
    else return queue[i];
}

bool Queue::empty() {
    return size == 0;
}

int Queue::getSize() const {
    return size;
}

Ticket Queue::next() {
    int newSize = size-1;
    Ticket lastElement = queue[newSize];
    Ticket *newArr = new Ticket[newSize];
    for (int i = 0; i <  newSize; ++i) {
        newArr[i] = queue[i];
    }
    delete[] queue;
    queue = newArr;
    return lastElement;
}

int Queue::getCapacity() const {
    return capacity;
}
Queue::~Queue() {
    delete[] queue;
}
