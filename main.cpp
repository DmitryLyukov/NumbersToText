#include <iostream>
#include <string>
#include <clocale>

#include "numtotext.hpp"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    std::string N = "";
    while (true) {
        std::cout << "N = ";
        std::getline(cin, N);
        std::cout << textize(N) << endl << endl;
    }
    return 0;
}
