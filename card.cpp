#include<stdio.h>
#include<iostream>
// #include<bits/stdc++.h>
#include<cmath>
#include<random>
#include<chrono>
#include<tuple>

using namespace std;

class Card{

    private:
    int value;
    int suit;
    char suits_map[4] = {'H', 'D', 'C', 'S'};

    public:
    Card(int value, int suit){
        this->value = value;
        this->suit = suit;
    }

    // public:
    // enum class suits{
    //     hearts = 0,
    //     diamonds,
    //     clubs,
    //     spades

    // };

    // map<int, char> mp;
    // mp[0]='H';
    // mp[1]='D';
    // mp[2]='C';
    // mp[3]='S';

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
        return namedValue()+suits_map[suit];
    }
};

// public:
class Deck{
    vector<Card*> deck;
    int suit, value;
    public:
    vector<Card*> createDeck(){
        for(int i=0; i<52; i++){
            suit = floor(i/13);
            value = i%13+2;
            deck.push_back(new Card(value, suit));
        }

        return deck;
    }

    public:
    void printDeck(vector<Card*> deck){
        int cnt=0;
        for(auto i: deck){
            cout<<i->name()<<',';
            // cout<<i->name()[i->name().size()-1]<<',';
            cnt+=1;
        }
        cout<<cnt;
    }

    public:
    vector<Card*> shuffleDeck(vector<Card*> deck){
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        for (int i = deck.size() - 1; i > 0; --i) {
            uniform_int_distribution<int> dist(0, i);
            int j = dist(rng);
            swap(deck[i], deck[j]);
        }
        return deck;
    }

    public:
    vector<Card*> removeCard(vector<Card*> deck, vector<Card*>::iterator removeCard){
        deck.erase(removeCard);

        return deck;
    }
    
    public:
    tuple<vector<Card*>, vector<Card*> > drawCard(vector<Card*> hand, vector<Card*> newCard){
        removeCard = deck.begin()+(deck.size()-1);
        // hand.push_back(deck[deck.size()-1]);
        hand.push_back(newCard);

        return make_tuple(hand, deck);
    }
};

int main(){
    vector<Card*> b;
    vector<Card*> d;
    vector<Card*>::iterator c;
    Deck* a = new Deck();
    b = a->createDeck();
    b = a->shuffleDeck(b);
    d = a->shuffleDeck(b);
    cout<<d[0]->name()<<endl;
    a->printDeck(b);
    cout<<endl;
    c = b.begin()+1;
    b.erase(c);
    a->printDeck(b);
    cout<<endl;
    a->printDeck(d);
    cout<<endl;
    b.push_back(d[d.size()-1]);
    a->printDeck(b);
    cout<<endl;
    auto [b, d] = a->drawCard(b, d);
    // b = e[0];
    // d = e[1];
    a->printDeck(b);
}