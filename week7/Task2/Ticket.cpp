#include "Ticket.h"
#include<cstring>
#include <iostream>
#include <random>
#include <cctype>

char *Ticket::getName() const {
    return name;
}

char *Ticket::getPhoneNumber() const {
    return phoneNumber;
}

unsigned int Ticket::getId() const {
    return id;
}

Ticket::~Ticket() {
    delete[] name;
    delete[] phoneNumber;
}

Ticket::Ticket(const char *username, const char *phone) {
    int i = 0;
    while (i < strlen(username)-1) {
        if(!std::isalpha(username[i]) && !std::isspace(username[i]))
            throw std::invalid_argument("The name contains weird symbols");
        i++;
    }
    if (strlen(phone) != 10) throw std::invalid_argument("The phone is invalid");

    name = new char[strlen(username)+1];
    strcpy(name, username);
    phoneNumber = new char[strlen(phone)+1];
    strcpy(phoneNumber, phone);

    std::random_device rd;
    std::mt19937 gen(rd());
    const unsigned int max_value = std::numeric_limits<unsigned int>::max();
    std::uniform_int_distribution<unsigned int> dist(0, max_value);
    unsigned int random_number = dist(gen);
    id = random_number;
}

Ticket::Ticket() {
    name = nullptr;
    phoneNumber = nullptr;
    id = 0;
}
