#include <iostream>
#include <list>
#include <numeric>          


class airtime {

private:
    int hours;           
    int minutes;          

public:
    
    airtime() : hours(0), minutes(0) {  }
    
    airtime(int h, int m) : hours(h), minutes(m) {  }

    void display() const {
        std::cout << hours << ':' << minutes;
    }

    void get() {
        char dummy;
        std::cout << "\nEnter airtime (format 12:59): ";
        std::cin >> hours >> dummy >> minutes;
    }

    
    airtime operator + (const airtime right) const {

        int temph = hours + right.hours;
        int tempm = minutes + right.minutes;
        if (tempm >= 60) {
            temph++; tempm -= 60;
        }

        return airtime(temph, tempm);

    }
   
    bool operator == (const airtime& at2) const {
        return (hours == at2.hours) &&
            (minutes == at2.minutes);
    }
    
    bool operator < (const airtime& at2) const {
        return (hours < at2.hours) ||
            (hours == at2.hours && minutes < at2.minutes);
    }
    
    bool operator != (const airtime& at2) const {
        return !(*this == at2);
    }
   
    bool operator > (const airtime& at2) const {
        return !(*this < at2) && !(*this == at2);
    }

};  


int main() {

    char answer;
    airtime temp, sum;
    std::list<airtime> airlist;   

    do {                     
        temp.get();
        airlist.push_back(temp);
        std::cout << "Enter another (y/n)? ";
        std::cin >> answer;
    } while (answer != 'n');
    
    sum = accumulate(airlist.begin(), airlist.end(), airtime(0, 0));
    std::cout << "\nsum = "; sum.display(); std::cout << std::endl;

    return 0;
}
