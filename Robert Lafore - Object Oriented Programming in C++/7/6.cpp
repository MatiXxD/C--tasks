#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PLAYERS = 4;
const int CARDS = 52;

enum Suit { clubs, diamonds, hearts, spades };
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card {

private:
    int number;
    Suit suit;

public:
    card() { }

    void set(int n, Suit s) {
        suit = s; number = n;
    }

    void display();

};

void card::display() {

    if (number >= 2 && number <= 10)
        cout << number;
    else
        switch (number) {
        case jack:  cout << "J"; break;
        case queen: cout << "Q"; break;
        case king:  cout << "K"; break;
        case ace:   cout << "A"; break;
        }

    switch (suit){
    case clubs:    cout << static_cast<char>(5); break;
    case diamonds: cout << static_cast<char>(4); break;
    case hearts:   cout << static_cast<char>(3); break;
    case spades:   cout << static_cast<char>(6); break;
    }
}

void shuffleDeck(card deck[]) {

    for (int j = 0; j < 52; j++) {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    for (int j = 0; j < 52; j++) {
        int k = rand() % 52;
        card temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
}

void displayPlayers(card players[PLAYERS][CARDS / PLAYERS]) {

    for (int i = 0; i < PLAYERS; i++) {
        cout << "Player " << i + 1 << endl;
        for (int j = 0; j < CARDS / PLAYERS; j++) {
            players[i][j].display();
            cout << ' ';
        }
        cout << endl;
    }

}

int main() {

    card deck[CARDS];
    card players[PLAYERS][CARDS / PLAYERS];
    int j;

    srand(time(NULL));
    shuffleDeck(deck);

    for (int i = 0; i < PLAYERS; i++)
        for (int j = 0; j < CARDS / PLAYERS; j++)
            players[i][j] = deck[i * (CARDS / PLAYERS) + j];

    displayPlayers(players);

    return 0;
}  
