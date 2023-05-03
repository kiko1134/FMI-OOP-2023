#ifndef WEEK7_QUEUE_H
#define WEEK7_QUEUE_H

#include "Ticket.h"

class Queue{
private:
    Ticket * queue;
    int size;
    int capacity;
public:
    Queue(int capacity);
    unsigned int getTicket(const char *name, const char* phone);
    bool empty();
    int getSize() const;
    Ticket next();
    int getCapacity() const;
    Ticket& operator[](unsigned int index);
    ~Queue();

};

#endif //WEEK7_QUEUE_H
