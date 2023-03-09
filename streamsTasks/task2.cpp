#include <iostream>
#include<fstream>

struct Student {
    int facNum;
    char name[100];
    double avgGrade;

    void write(std::ofstream &output) {
        if (!output.is_open()) {
            std::cout << "File didn't open" << std::endl;
        }
        output << this->facNum << " " << this->name << " " << this->avgGrade << '\n';
    }
};

void writeStudents(std::ofstream &output, Student *students, int size) {
    if (!output.is_open()) {
        std::cout << "File didn't open" << std::endl;
    }
    int count = 0;
    while (size > 0) {
        output << students[count].facNum << " " << students[count].name << " " << students[count].avgGrade << '\n';
        --size;
        ++count;
    }
}

void readStudents(std::ifstream &input) {
    if (!input.is_open()) {
        std::cout << "File didn't open" << std::endl;
    }
    while (!input.eof()) {
        int facNum;
        char name[100];
        double avgGrade;
        input >> facNum >> name >> avgGrade;
        std::cout << facNum << " " << name << " " << avgGrade << std::endl;
    }
}

int main() {
    std::ifstream inputFile("file.txt");
    if (!inputFile.is_open()) {
        std::cout << "File not opened!" << std::endl;
    }
    readStudents(inputFile);
    inputFile.close();

    std::ofstream outputFile("file.txt");
    if (!outputFile.is_open()) {
        std::cout << "File not opened!" << std::endl;
    }
    Student s1{145, "Ivan", 4.80};
    s1.write(outputFile);

    Student students[5] = {
            {145, "Ivan",  4.80},
            {123, "Kris",  5.20},
            {113, "Vasil", 5.30}
    };

    writeStudents(outputFile, students, 3);
    outputFile.close();
}
