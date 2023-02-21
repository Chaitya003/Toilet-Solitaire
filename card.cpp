#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Card{

    private:
    int value;
    string suit;

    Card(int value, string suit){
        value = value;
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
        switch(value){
            case 14:
            name='A';

        }
    }
};