#include <iostream>
#include<fstream>
#include <cstring>

using namespace std;

struct Person {
    char firstname[50];
    char lastname[50];

    void print() {
        cout << firstname << " " << lastname << endl;
    }

    void input(char fn[50], char ln[50]) {
        strcpy(firstname, fn);
        strcpy(lastname, ln);
    }
};

struct Client {
    Person p;
    double bank_account = 0.0;

    void print() {
        cout << p.firstname << " " << p.lastname << " " << bank_account << endl;
    }

    void input(Person client, double account) {
        p = client;
        bank_account = account;
    }
};

struct Product {
    char description[32];  // описание на изделие
    int partNum;           // номер на изделие
    double cost;           // цена на изделие
};


int main() {
    //Task 1
    //a)
    Product p1{"screw-driver",456,5.50};
    Product p2{"hammer",324,8.20};

    //b)
    cout<<p1.description<<" "<<p1.partNum<<" "<<p1.cost<<endl;
    cout<<p2.description<<" "<<p2.partNum<<" "<<p2.cost<<endl;

    //c)

    Product arr[2];

    //d)

    for (auto & i : arr) {
        cin>>i.description>>i.partNum>>i.cost;
    }

    for (auto & i : arr) {
        cout<<i.description<<" "<<i.partNum<<" "<<i.cost<<endl;
    }

    //e)

    Product arr1[5];
    arr1[0] = {"screw-driver",456,5.50};
    arr1[1] = {"hammer",324,8.20};
    arr1[2] = {"socket",458,5.75};
    arr1[3] = {"plier",929,10.50};
    arr1[4] = {"hand-saw",536,7.45};

    for (int i = 0; i < 5; ++i) {
        cout<<arr1[i].description<<" "<<arr1[i].partNum<<" "<<arr1[i].cost<<endl;
    }

////  Task 2
//    Person p[4];
//
//    p[0].input("Kristian", "Yordanov");
//    p[1].input("Maria", "Ilieva");
//    p[2].input("Ivan", "Ivanov");
//    p[3].input("Pesho", "Peshov");
//
//    Client c[4];
//
//    c[0].input(p[0], 12345);
//    c[1].input(p[1], 7654);
//    c[2].input(p[2], 45684);
//    c[3].input(p[3], 24356);
//
//    for (auto &i: c) {
//        i.print();
//    }
//
//    double sum = 0.0;
//    for (auto &i: c) {
//        sum += i.bank_account;
//    }
//
//    cout<<sum<<endl;
}
