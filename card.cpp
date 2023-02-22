#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<random>
#include<chrono>

using namespace std;

class Card{

    private:
    int value;
    int suit;

    public:
    Card(int value, int suit){
        this->value = value;
        this->suit = suit;
    }

    public:
    enum class suits{
        hearts = 0,
        diamonds,
        clubs,
        spades

    };

    public:
    string namedValue(){
        string name;

        switch(value){
            case 14:
            name='A';
            break;

            case 13:
            name='K';
            break;

            case 12:
            name='Q';
            break;

            case 11:
            name="J";
            break;

            default:
            name=to_string(value);
            break;
        }

        return name;
    }

    public:
    string name(){
        return namedValue()+to_string(suit)+',';
    }
};

// public:
class Deck{
    vector<Card*> deck;
    int suit, value;
    public:
    void createDeck(){
        for(int i=0; i<52; i++){
            suit = floor(i/13);
            value = i%13+2;
            deck.push_back(new Card(value, suit));
        }
    }

    public:
    void printDeck(){
        for(auto i: deck){
            cout<<i->name();
        }
    }

    public:
    void shuffleDeck(){
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        for (int i = deck.size() - 1; i > 0; --i) {
            uniform_int_distribution<int> dist(0, i);
            int j = dist(rng);
            swap(deck[i], deck[j]);
    }
    }
};

int main(){
    Deck* a = new Deck();
    a->createDeck();
    a->shuffleDeck();
    a->printDeck();
}