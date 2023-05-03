//
// Created by ChristianVasikov on 4/29/2023.
//

#ifndef WEEK7_TICKET_H
#define WEEK7_TICKET_H

class Ticket{
private:
    char *name;
    char *phoneNumber;
    unsigned int id;

public:
    Ticket();
    Ticket(const char * username, const char * phone);

    char *getName() const;

    char *getPhoneNumber() const;

    unsigned int getId() const;

    virtual ~Ticket();
};

#endif //WEEK7_TICKET_H
