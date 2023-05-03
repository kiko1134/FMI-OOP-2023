#include <iostream>
#include "Task 0/Temperature.h"
#include "Task1/Forecast.h"
#include "Task2/Ticket.h"
#include "Task2/Queue.h"
#include "Task3/Item.h"
#include "Task3/Backpack.h"

using namespace std;

int main() {
//    Ticket t1("Kris Vassikov", "0885540690");
//    Ticket t2("Ivan Petrov", "0884414430");
//    Ticket t3("Valeri Bojinov", "0887890234");
//    cout<<t1.getName()<<endl;
//    cout<<t1.getPhoneNumber()<<endl;
//    cout<<t1.getId()<<endl;

//    Queue queue(2);
//    queue.getTicket(t1.getName(),t1.getPhoneNumber());
//    queue.getTicket(t2.getName(),t2.getPhoneNumber());
//
//    Ticket last = queue.next();
//    cout<<last.getName()<<endl;
//    cout<<last.getPhoneNumber()<<endl;
//    cout<<last.getId()<<endl;

    Item i1("bottle of water",0.2,1);
    Item i2("sweets",0.3,2);

    Backpack backpack(15,7);
    backpack.add(i1);
    backpack.add(i2);

    Item curr = backpack[1];
    cout<<curr.getWeight()<<curr.getVolume()<<endl;
    cout<<backpack.leftWeight()<<backpack.leftVolume()<<endl;


}
