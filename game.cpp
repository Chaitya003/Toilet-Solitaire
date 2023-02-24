#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include"card.h"

using namespace std;

class Game{
    private:
    int gameRule;
    int cnt;
    // vector<Card*> deck, hand;
    
    public:
    // vector<Card*> deck, hand;
    Deck* newDeck = new Deck();

    // public:
    // Game(vector<Card*> deck){
    //     this->deck = deck;
    // }


    public:
    int selectGameRule(){
        cout<<"Decide the Rule you want to play \n";
        cout<<"1. Basic: 1st & 4th same Suit --> remove middle two, 1st & 4th same rank --> remove all 4"<<endl;
        cout<<"2. Intermediate: Neighbors are same rank --> remove pair"<<endl;
        cout<<"3. House Rule: 1st & 4th same Suit AND 3rd & 4th same rank --> remove last 3"<<endl;
        cin>>gameRule;

        return gameRule;
    }

    vector<Card*> removeCards(vector<Card*> deck, vector<Card*> waste, int numCards[], bool flag=false){
        vector<Card*>::iterator removeCard;
        removeCard = deck.begin();
        if(flag){
            deck.erase(removeCard + (deck.size() - 4) + numCards[0], removeCard + (deck.size() - 4) + (numCards[1] + 1));
        }
        else{
            if(deck.size()>numCards[1]){
                deck.erase(removeCard + numCards[0], removeCard + (numCards[1] + 1));
            }
            else{
                // cout<<"Vector Clear"<<endl;
                deck.clear();
            }
        }
        // }
        return deck;
    }

    vector<Card*> drawCards(vector<Card*> deck, vector<Card*> hand, int numDrawCards){
        // int numDrawCards = 4 - hand.size();
        // cout<<hand.size()<<"Hand Size"<<endl;
        // if(numDrawCards>0){
        // cout<<deck.size()<<" Deck Size"<<endl;
        for(int i=0; i<numDrawCards; i++){
            if(!deck.empty()){
                hand.push_back(deck[i]);
            }
            else{
            /* Add the logic for rotation of hand*/
                cnt+=1;
                rotate(hand.begin(), hand.begin()+1, hand.end());
            }
        }
        // }
        // else{
        //     hand.push_back(deck[0]);
        // }

        return hand;
    }

    void printHand(vector<Card*> hand){
        vector<Card*>::const_iterator first = hand.begin() + (hand.size() - 4);
        vector<Card*>::const_iterator last = hand.begin() + (hand.size());
        vector<Card*> newVec(first, last);

        for(auto i: newVec){
            cout<<i->name()<<',';
        }
    }

    bool checkWin(vector<Card*> deck, vector<Card*> hand){
        int score = deck.size() + hand.size();
        cout<<"Your Current Score is "<<score<<endl;
        if(deck.empty() && hand.size()==cnt){
            if(score==0){
                cout<<"Super Win....."<<endl;
                cout<<"Your final Score is "<<score<<endl;
            }
            else if(score<5){
                cout<<"Congratulations You Won..."<<endl;
                cout<<"Your final Score is "<<score<<endl;
            }
            else if(score>=5){
                cout<<"Sorry You Lost Better luck next time."<<endl;
                cout<<"Your final Score is "<<score<<endl;
            }
            return false;
        }
        else{
            return true;
        }
    }

    void checkBasicRules(vector<Card*> deck, vector<Card*> hand, int nextMove){
        vector<Card*> waste;
        cout<<nextMove<<"Next Move"<<endl;
        if(nextMove==1){
            char suit_1 = hand[hand.size()-4]->name()[hand[hand.size()-4]->name().size()-1];
            char suit_4 = hand[hand.size()-1]->name()[hand[hand.size()-1]->name().size()-1];
            if(suit_1==suit_4){
                cnt = 0;
                int numRemoveCards[] = {1, 2};
                hand = removeCards(hand, waste, numRemoveCards, true);
                // vector<Card*>::iterator removeCard;
                // removeCard = hand.begin() + 1;
                // hand.erase(removeCard);
                // removeCard = hand.begin() + 2;
                // hand.erase(removeCard);
                int numDrawCards = 2;
                hand = drawCards(deck, hand, numDrawCards);
                if(!deck.empty()){
                    int numRemoveCardsDeck[] = {0, 1};
                    deck = removeCards(deck, waste, numRemoveCardsDeck);
                }
                // else{
                //     cout<<"Deck Empty";
                // }
                // vector<Card*> newCard = deck[deck.size()-1]
                // hand.push_back(newCard);
                // removeCard = deck.begin()
                displayMoves(gameRule, deck, hand);
                // return true;
            }
            else{
                cout<<"Take valid move."<<endl;
                displayMoves(gameRule, deck, hand);
            }
        }
        else if(nextMove==2){
            string rank_1 = hand[hand.size()-4]->name().substr(0, hand[hand.size()-4]->name().size()-1);
            string rank_4 = hand[hand.size()-1]->name().substr(0, hand[hand.size()-1]->name().size()-1);
            if(rank_1==rank_4){
                cnt = 0;
                int numRemoveCards[] = {0, 3};  //{0, 1, 2, 3};
                hand = removeCards(hand, waste, numRemoveCards, true);
                int numDrawCards = 4;
                hand = drawCards(deck, hand, numDrawCards);
                if(!deck.empty()){
                    int numRemoveCardsDeck[] = {0, 3};  //{0, 1, 2, 3};
                    deck = removeCards(deck, waste, numRemoveCardsDeck);
                }
                // else{
                //     cout<<"Deck Empty";
                // }
                displayMoves(gameRule, deck, hand);
                // return true;  
            }
            else{
                cout<<"Take valid move."<<endl;
                displayMoves(gameRule, deck, hand);
            }
        }

        else if(nextMove==8){
            Deck* shuffleDeck = new Deck();
            deck = shuffleDeck->shuffleDeck(deck);
            displayMoves(gameRule, deck, hand);
        }

        else if(nextMove==9){
            int numDrawCards = 1;
            hand = drawCards(deck, hand, numDrawCards);
            int numRemoveCardsDeck[] = {0, 0};
            if(!deck.empty()){
                deck = removeCards(deck, waste, numRemoveCardsDeck);
            }
            displayMoves(gameRule, deck, hand);
        }
        else{
            cout<<"Take valid move."<<endl;
            displayMoves(gameRule, deck, hand);
        }

        /* Draw a new card remaining*/
    }

    void checkIntermediateRules(vector<Card*> deck, vector<Card*> hand, int nextMove){
        vector<Card*> waste;
        if(nextMove==1){
            checkBasicRules(deck, hand, nextMove);
            // return ans;
        }
        else if(nextMove==2){
            checkBasicRules(deck, hand, nextMove);
            // return ans;
        }

        else if(nextMove==3){
            int pairCards[2];
            bool flag=false;
            for(int i=hand.size()-4; i<hand.size()-1; i++){
                if(hand[i]->name().substr(0, hand[i]->name().size()-1)==hand[i+1]->name().substr(0, hand[i+1]->name().size()-1)){
                    // cout<<"Same Pairs"<<endl;
                    flag=true;
                    // cout<<i<<"Pair rank";
                    pairCards[0] = i - (hand.size() - 4);
                    pairCards[1] = (i - (hand.size() - 4)) + 1;
                    break;
                }
            }
            if(flag){
                cnt = 0;
                hand = removeCards(hand, waste, pairCards, true);
                int numDrawCards = 2;
                hand = drawCards(deck, hand, numDrawCards);
                if(!deck.empty()){
                    int numRemoveCardsDeck[] = {0, 1};
                    deck = removeCards(deck, waste, numRemoveCardsDeck);
                }

                displayMoves(gameRule, deck, hand);
            }
            else{
                cout<<"Take valid move."<<endl;
                displayMoves(gameRule, deck, hand);
            }
        }

        else if(nextMove==8){
            checkBasicRules(deck, hand, nextMove);
            // return ans;
        }

        else if(nextMove==9){
            int numDrawCards = 1;
            hand = drawCards(deck, hand, numDrawCards);
            if(!deck.empty()){
                int numRemoveCardsDeck[] = {0, 0};
                deck = removeCards(deck, waste, numRemoveCardsDeck);
            }
            displayMoves(gameRule, deck, hand);
        }
        else{
            cout<<"Take valid move."<<endl;
            displayMoves(gameRule, deck, hand);
        }

        /* Draw a new card remaining*/
    }

    void checkHouseRules(vector<Card*> deck, vector<Card*> hand, int nextMove){
        vector<Card*> waste;
        if(nextMove==1){
            checkBasicRules(deck, hand, nextMove);
            // return ans;
        }
        else if(nextMove==2){
            checkBasicRules(deck, hand, nextMove);
            // return ans;
        }

        else if(nextMove==3){
            checkIntermediateRules(deck, hand, nextMove);
            // return ans;
        }

        else if(nextMove==4){
            char suit_1 = hand[hand.size()-4]->name()[hand[hand.size()-4]->name().size()-1];
            char suit_4 = hand[hand.size()-1]->name()[hand[hand.size()-1]->name().size()-1];
            string rank_3 = hand[hand.size()-2]->name().substr(0, hand[hand.size()-2]->name().size()-1);
            string rank_4 = hand[hand.size()-1]->name().substr(0, hand[hand.size()-1]->name().size()-1);
            if(suit_1==suit_4 && rank_3==rank_4){
                cnt = 0;
                int numRemoveCards[] = {1, 3};  //{0, 1, 2, 3}; int numRemoveCards[] = {0, 1, 2};
                hand = removeCards(hand, waste, numRemoveCards, true);
                int numDrawCards = 3;
                hand = drawCards(deck, hand, numDrawCards);
                if(!deck.empty()){
                    int numRemoveCardsDeck[] = {0, 2}; //int numRemoveCardsDeck[] = {0, 1, 2};
                    deck = removeCards(deck, waste, numRemoveCardsDeck);
                }

                displayMoves(gameRule, deck, hand);
            }
            else{
                cout<<"Take valid move."<<endl;
                displayMoves(gameRule, deck, hand);
            }
        }

        else if(nextMove==5){
            char suit_1 = hand[hand.size()-4]->name()[hand[hand.size()-4]->name().size()-1];
            char suit_4 = hand[hand.size()-1]->name()[hand[hand.size()-1]->name().size()-1];
            string rank_1 = hand[hand.size()-4]->name().substr(0, hand[hand.size()-2]->name().size()-1);
            string rank_2 = hand[hand.size()-3]->name().substr(0, hand[hand.size()-1]->name().size()-1);
            if(suit_1==suit_4 && rank_1==rank_2){
                cnt = 0;
                int numRemoveCards[] = {0, 2};  //{0, 1, 2, 3}; int numRemoveCards[] = {0, 1, 2};
                hand = removeCards(hand, waste, numRemoveCards, true);
                int numDrawCards = 3;
                hand = drawCards(deck, hand, numDrawCards);
                if(!deck.empty()){
                    int numRemoveCardsDeck[] = {0, 2}; //int numRemoveCardsDeck[] = {0, 1, 2};
                    deck = removeCards(deck, waste, numRemoveCardsDeck);
                }

                displayMoves(gameRule, deck, hand);
            }
            else{
                cout<<"Take valid move."<<endl;
                displayMoves(gameRule, deck, hand);
            }
        }

        else if(nextMove==8){
            checkBasicRules(deck, hand, nextMove);
            // return ans;
        }

        else if(nextMove==9){
            int numDrawCards = 1;
            hand = drawCards(deck, hand, numDrawCards);
            if(!deck.empty()){
                int numRemoveCardsDeck[] = {0, 0};
                deck = removeCards(deck, waste, numRemoveCardsDeck);
            }
            displayMoves(gameRule, deck, hand);
        }

        else{
            cout<<"Take valid move."<<endl;
            displayMoves(gameRule, deck, hand);
        }

        /* Draw a new card remaining*/
    }

    void displayMoves(int gameRule, vector<Card*> deck, vector<Card*> hand){
        int nextMove;
        vector<Card*> waste;
        if(hand.empty()){
            int numDrawCards = 4;
            hand = drawCards(deck, hand, numDrawCards);
            int numRemoveCards[] =  {0, 3};//{0, 1, 2, 3};
            deck = removeCards(deck, waste, numRemoveCards);
            cout<<"Your Hand: ";
            printHand(hand);
            cout<<endl;
            newDeck->printDeck(hand);
            cout<<endl;
            newDeck->printDeck(deck);
            cout<<endl;
        }
        else{
            cout<<"Your Hand: ";
            printHand(hand);
            cout<<endl;
            newDeck->printDeck(hand);
            cout<<endl;
        }

        bool is_win = checkWin(deck, hand);
        if(is_win){
            switch(gameRule){
                case(1):
                cout<<"1. Remove middle two cards"<<endl;
                cout<<"2. Remove all four cards"<<endl;
                cout<<"8. Shuffle Cards"<<endl;
                cout<<"9. Draw a new card."<<endl;
                cin>>nextMove;
                checkBasicRules(deck, hand, nextMove);
                break;

                case(2):
                cout<<"1. Remove middle two cards"<<endl;
                cout<<"2. Remove all four cards"<<endl;
                cout<<"3. Remove neighbouring pair of cards with same rank."<<endl;
                cout<<"8. Shuffle Cards"<<endl;
                cout<<"9. Draw a new card."<<endl;
                cin>>nextMove;
                checkIntermediateRules(deck, hand, nextMove);
                break;

                case(3):
                cout<<"1. Remove middle two cards"<<endl;
                cout<<"2. Remove all four cards"<<endl;
                cout<<"3. Remove pair of cards with same rank."<<endl;
                cout<<"4. Remove last 3 cards."<<endl;
                cout<<"5. Remove first 3 cards."<<endl;
                cout<<"8. Shuffle Cards"<<endl;
                cout<<"9. Draw a new card."<<endl;
                cin>>nextMove;
                checkHouseRules(deck, hand, nextMove);
                break;

                default:
                cout<<"Select valid move"<<endl;
                displayMoves(gameRule, deck, hand);
                break;

            }
        }

    }

};

int main(){
    Deck* newDeck = new Deck();
    vector<Card*> deck, hand, waste;
    deck = newDeck->createDeck();
    deck = newDeck->shuffleDeck(deck);
    int cnt=0;
    newDeck->printDeck(deck);
    cout<<endl;
    Game* newGame = new Game();

    while(true){
        // cout<<gameRule<<endl;
        // if(hand.empty()){
        //     hand = newGame->drawCards(deck, hand);
        //     int numRemoveCards[] = {0, 1, 2, 3};
        // cout<<"Your Hand: ";
        // }
        // hand = newGame->drawCards(deck, hand);
        // newDeck->printDeck(hand);
        // cout<<endl;
        // int numRemoveCards[] = {0, 1, 2, 3};
        // deck = newGame->removeCards(deck, waste, numRemoveCards);
        // newDeck->printDeck(deck);
        // cout<<endl;
        deck = newDeck->shuffleDeck(deck);
        if(cnt==0){
            cnt+=1;
            cout<<"Start the game. Good Luck."<<endl;
            int gameRule = newGame->selectGameRule();
            cout<<endl;
            newGame->displayMoves(gameRule, deck, hand);
        }
        else{
            char gameAgain;
            cout<<"If you want to play game again press P"<<endl;
            cin>>gameAgain;
            if(tolower(gameAgain)=='p'){
                cout<<"Start the game. Good Luck."<<endl;
                int gameRule = newGame->selectGameRule();
                cout<<endl;
                newGame->displayMoves(gameRule, deck, hand);
            }
        }
    }
}