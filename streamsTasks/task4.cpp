#include <iostream>
#include <fstream>

void removeSpacesFromFile(std::ifstream &input, std::ofstream &output) {
    if (!input.is_open() && !output.is_open()) {
        std::cout << "Unable to open file." << std::endl;
    }
    char ch;
    while (input.get(ch)) {
        if (ch != ' ') {
            output << ch;
        }
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    removeSpacesFromFile(input,output);
    input.close();
    output.close();

}
