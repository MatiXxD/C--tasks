#include <fstream>
#include <iostream>
#include <string>

class Dofile {

private:
    std::string name;
    std::fstream file;

public:
    class Error {
    private:
        std::string reason;
    public:
        Error(std::string reason_in) : reason(reason_in) { }
        std::string getReason() { return reason; }
    };

    Dofile(std::string name_in) : name(name_in) {
        file.open(name, std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
        if (!file) throw Error("Could not open output file.");
    }

    ~Dofile() {
        file.close();
    }

    void writeData(int* data, int size) {
        file.write(reinterpret_cast<char*>(data), size * sizeof(int));
        if (!file) throw Error("Could not write to file");
    }

    void readData(int* data, int size) {
        file.read(reinterpret_cast<char*>(data), size * sizeof(int));
        if (!file) throw Error("Could not read from file");
    }

    void fromStart() {
        file.seekg(std::ios_base::beg);
    }

};

int main() {

    const int MAX = 1000;
    int buff[MAX];
    for (int j = 0; j < MAX; j++)
        buff[j] = j;

    try {

        Dofile file("edata.dat");
        std::cout << "Writing...\n";
        file.writeData(buff, MAX);

        for (int j = 0; j < MAX; j++)
            buff[j] = 0;

        std::cout << "Reading...\n";
        file.fromStart(); file.readData(buff, MAX);

    }
    catch (Dofile::Error err) {
        std::cout << err.getReason() << std::endl;
    }

    for (int j = 0; j < MAX; j++)
        if (buff[j] != j) {
            std::cerr << "\nData is incorrect\n"; exit(1);
        }
    std::cout << "Data is correct\n";

    return 0;

}
