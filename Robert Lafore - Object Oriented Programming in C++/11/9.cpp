#include "msoftcon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int CPF = 5;
const int maxHorses = 7;
class Track;
class Horse;
class Comhorse;


class Horses {

protected:
    const Track* ptrTrack;
    const int horse_number;
    float finish_time;
    float distance_run;

public:
    Horses(const int n, const Track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0) {  }

    float getDistance() { return distance_run; }
    virtual void display_horse(const float)=0;


};

class Horse : public Horses {

public:
    Horse(const int n, const Track* ptrT, float distance) : Horses::Horses(n, ptrT) {
        distance_run = distance;
    }
    ~Horse() { }

    void display_horse(const float elapsed_time);

};

class Comhorse : public Horses {

public:
    Comhorse(const int n, const Track* ptrT, float distance) : Horses::Horses(n, ptrT) {
        distance_run = distance;
    }
    ~Comhorse() { }

    void display_horse(const float elapsed_time);

};


class Track {

private:
    Horses* hArray[maxHorses];
    int total_horses;
    int horse_count;
    int comhorse_id;
    const float track_length;
    float elapsed_time;

public:
    Track(float lenT, int nH);
    ~Track();

    void display_track();
    void run();
    void checkHorses();
    float get_track_len() const;

};


void Horse::display_horse(float elapsed_time) {

    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
    set_color(static_cast<color>(cBLUE + horse_number));
    char horse_char = '0' + static_cast<char>(horse_number);
    _putch(' '); _putch('\xDB'); _putch(horse_char); _putch('\xDB');

    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        if (rand() % 3)
            distance_run += 0.2F;
        finish_time = elapsed_time;
    }
    else {
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        cout << " Time=" << mins << ":" << secs;
    }

}

void Comhorse::display_horse(float elapsed_time) {

    set_cursor_pos(1 + int(distance_run * CPF), 2 + horse_number * 2);
    set_color(static_cast<color>(cBLUE + horse_number));
    char horse_char = '0' + static_cast<char>(horse_number);
    _putch(' '); _putch('\xDB'); _putch(horse_char); _putch('\xDB');

    if (distance_run < ptrTrack->get_track_len() + 1.0 / CPF) {
        if (rand() % 5)
            distance_run += 0.4F;
        finish_time = elapsed_time;
    }
    else {
        int mins = int(finish_time) / 60;
        int secs = int(finish_time) - mins * 60;
        cout << " Time=" << mins << ":" << secs;
    }

}

Track::Track(float lenT, int nH) : track_length(lenT), total_horses(nH), comhorse_id(-1),
                                   horse_count(0), elapsed_time(0.0) {
    init_graphics();
    total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
    for (int j = 0; j < total_horses; j++)
        hArray[j] = new Horse(horse_count++, this, 0.0F);

    time_t aTime;
    srand(static_cast<unsigned>(time(&aTime)));
    display_track();

}

Track::~Track() {
    for (int j = 0; j < total_horses; j++)
        delete hArray[j];
}

void Track::display_track() {

    clear_screen();

    for (int f = 0; f <= track_length; f++)
        for (int r = 1; r <= total_horses * 2 + 1; r++) {
            set_cursor_pos(f * CPF + 5, r);
            if (f == 0 || f == track_length)
                cout << '\xDE';
            else
                cout << '\xB3';
        }
}

void Track::checkHorses() {

    int leader = 0;
    for(int i = 0 ; i < total_horses ; i++)
        if (hArray[i]->getDistance() > hArray[leader]->getDistance()) {
            leader = i;
        }

    if (hArray[leader]->getDistance() < track_length / 2.0) return;

    bool check = true;
    for (int i = 0; i < total_horses; i++) {
        if (i == leader || (hArray[leader] - hArray[i] >= 0.1)) continue;
        else {
            check = false;
            break;
        }
    }

    if (check) {

        Horses* temp = hArray[leader];
        hArray[leader] = new Comhorse(leader, this, hArray[leader]->getDistance());
        delete temp;

        if (comhorse_id != -1) {
            temp = hArray[comhorse_id];
            hArray[comhorse_id] = new Horse(comhorse_id, this, hArray[leader]->getDistance());
            delete temp;
        }

        comhorse_id = leader;

    }

}

void Track::run() {

    while (!_kbhit()) {
        elapsed_time += 1.75;
        for (int j = 0; j < total_horses; j++) {
            hArray[j]->display_horse(elapsed_time);
            this->checkHorses();
        }
        wait(500);
    }
    _getch();
    cout << endl;

}

float Track::get_track_len() const {
    return track_length;
}



int main() {

    float length;
    int total;

    cout << "Enter track length (furlongs; 1 to 12): ";
    cin >> length;
    cout << "Enter number of horses (1 to 7): ";
    cin >> total;
    cout << "\n\n";

    Track theTrack(length, total);
    theTrack.run();

    return 0;
    
}
