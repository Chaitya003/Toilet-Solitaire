#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include"card.h"

using namespace std;

class Game{
    private:
    int gameRule;

    public:
    int selectGameRule(){
        cout<<"Decide the Rule you want to play \n"
        cout<<"1. Basic: 1st & 4th same Suit --> remove middle two, 1st & 4th same rank --> remove all 4"<<endl
        cout<<"2. Intermediate: Neighbors are same rank --> remove pair"<<endl
        cout<<"3. House Rule: 1st & 4th same Suit AND 3rd & 4th same rank --> remove last 3"<<endl
        cin>>gameRule;

        return gameRule
    }

    vector<Card*> removeCards(vector<Card*> deck, int[] numCards){
        for(int i; i<sizeof(numCards); i++){
            vector<Card*>::iterator removeCard;
            removeCard = deck.begin() + numCards[i];
            deck.erase(removeCard);
        }
        return deck;
    }

    vector<Card*> drawCards(vector<Card*> deck, vector<Card*> hand){
        numDrawCards = 4 - hand.size();
        for(int i=0; i<numDrawCards; i++){
            hand.push_back(deck[i])
        }

        return hand;
    }

    bool checkBasicRules(vector<Card*> deck, vector<Card*> hand, int nextMove){
        if(nextMove==1){
            suit_1 = hand[0]->name()[i->name().size()-1];
            suit_4 = hand[hand.size()-1]->name()[i->name().size()-1];
            if(suit_1==suit_4){
                int[] numRemoveCards = {1, 2};
                hand = removeCards(hand, numRemoveCards)
                // vector<Card*>::iterator removeCard;
                // removeCard = hand.begin() + 1;
                // hand.erase(removeCard);
                // removeCard = hand.begin() + 2;
                // hand.erase(removeCard);
                hand = drawCards(deck, hand);
                int[] numRemoveCards = {0, 1};
                deck = removeCards(deck, numRemoveCards)
                // vector<Card*> newCard = deck[deck.size()-1]
                // hand.push_back(newCard);
                // removeCard = deck.begin()
                return true;
            }
            else{
                return false;
            }
        }
        else if(nextMove==2){
            rank_1 = hand[0]->name().substr(0, i->name().size()-1);
            rank_4 = hand[hand.size()-1]->name().substr(0, i->name().size()-1);
            if(rank_1==rank_4){
                int[] numRemoveCards = {0, 1, 2, 3};
                hand = removeCards(hand, numRemoveCards)
                hand = drawCards(deck, hand);
                int[] numRemoveCards = {0, 1, 2, 3};
                deck = removeCards(deck, numRemoveCards)

                return true;  
            }
            else{
                return false;
            }
        }

        /* Draw a new card remaining*/
    }

    bool checkIntermediateRules(vector<Card*> deck, vector<Card*> hand, int nextMove){
        if(nextMove==1){
            checkBasicRules(deck, hand, nextMove);
        }
        else if(nextMove==2){
            checkBasicRules(deck, hand, nextMove);
        }

        else if(nextMove==3){
            int[] pairCards;
            for(int i=0; i<hand.size()-1; i++){
                flag=false;
                if(hand[i]->name().substr(0, i->name().size()-1)==hand[i+1]->name().substr(0, i->name().size()-1)){
                    flag=true;
                    pairCards = {i, i+1}
                    break;
                }
            }
            if(flag){
                int[] numRemoveCards = pairCards;
                hand = removeCards(hand, numRemoveCards)
                hand = drawCards(deck, hand);
                int[] numRemoveCards = {0, 1};
                deck = removeCards(deck, numRemoveCards)

                return true;  
            }
            else{
                return false;
            }
        }

        /* Draw a new card remaining*/
    }

    bool checkHouseRules(vector<Card*> deck, vector<Card*> hand, int nextMove){
        if(nextMove==1){
            checkBasicRules(deck, hand, nextMove);
        }
        else if(nextMove==2){
            checkBasicRules(deck, hand, nextMove);
        }

        else if(nextMove==3){
            checkIntermediateRules(deck, hand, nextMove)
        }

        else if(nextMove==4){
            suit_1 = hand[0]->name()[i->name().size()-1];
            suit_4 = hand[hand.size()-1]->name()[i->name().size()-1];
            rank_3 = hand[hand.size()-2]->name().substr(0, i->name().size()-1);
            rank_4 = hand[hand.size()-1]->name().substr(0, i->name().size()-1);
            if(suit_1==suit_4 && rank_3==rank_4){
                int[] numRemoveCards = {0, 1, 2};
                hand = removeCards(hand, numRemoveCards)
                hand = drawCards(deck, hand);
                int[] numRemoveCards = {0, 1, 2};
                deck = removeCards(deck, numRemoveCards)

                return true;  
            }
            else{
                return false;
            }
        }

        /* Draw a new card remaining*/
    }

    void displayMoves(){
        int nextMove;

        switch(gameRule){
            case(1):
            cout<<"1. Remove middle two cards";
            cout<<"2. Remove all four cards";
            cout<<"9. Draw a new card."
            cin>>nextMove;
            checkBasicRules(nextMove);
            break;

            case(2):
            cout<<"1. Remove middle two cards";
            cout<<"2. Remove all four cards";
            cout<<"3. Remove neighbouring pair of cards with same rank."
            cout<<"9. Draw a new card."
            cin>>nextMove;
            checkIntermediateRules(nextMove);
            break;

            case(3):
            cout<<"1. Remove middle two cards";
            cout<<"2. Remove all four cards";
            cout<<"3. Remove pair of cards with same rank."
            cout<<"4. Remove last 3 cards."
            cout<<"9. Draw a new card."
            cin>>nextMove;
            checkHouseRules(nextMove);
            break;

            default:
            cout<<"Select valid move";
            displayMoves();
            break;

        }

    }

};

int main(){
    Deck* newDeck = new Deck();
    vector<Card*> deck;
    deck = newDeck->createDeck();
    deck = newDeck->shuffleDeck(deck);
    newDeck->printDeck(deck);
}