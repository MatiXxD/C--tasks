#include <iostream>
#include <string>
#include <fstream>


class Distance {

private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) {  }

    void getdist() {
        std::cout << "Enter feet: ";  std::cin >> feet;
        std::cout << "Enter inches: ";  std::cin >> inches;
    }

    void showdist() {
        std::cout << feet << "\'-" << inches << '\"';
    }

};



int main() {

    std::string name = "data.dat";
    std::fstream f; f.open(name, std::ios::binary | std::ios::out
                                | std::ios::app | std::ios::in);

    Distance d;
    char answer;
    do {

        std::cout << "Entering distance\n";
        d.getdist();
        f.write(reinterpret_cast<char*>(&d), sizeof(Distance));

        std::cout << "Do you want to continue? (y/n) : ";
        std::cin >> answer;

    } while (answer == 'y' || answer == 'Y');

    std::cout << "\bOUTPUT\n";

    int count = 0;
    f.seekg(0); f.read(reinterpret_cast<char*>(&d), sizeof(Distance));
    while (f) {
        std::cout << "Distance " << ++count << ": ";
        d.showdist(); std::cout << std::endl;
        f.read(reinterpret_cast<char*>(&d), sizeof(Distance));
    }

    f.close();

    return 0;

}
