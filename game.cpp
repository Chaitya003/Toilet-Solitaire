#pragma once

#include <system/object.h>
#include <cstdint>

class Card : public System::Object
{
    typedef Card ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    enum class Suits
    {
        Hearts = 0,
        Diamonds,
        Clubs,
        Spades
    };
    
    
public:

    int32_t get_Value();
    void set_Value(int32_t value);
    Card::Suits get_Suit();
    void set_Suit(Card::Suits value);
    
    Card();
    
protected:

    #ifdef ASPOSE_GET_SHARED_MEMBERS
    void GetSharedMembers(System::Object::shared_members_type& result) const override;
    #endif
    
    
private:

    int32_t pr_Value;
    Card::Suits pr_Suit;

System::String name = System::String::Empty;
    switch (Value)
    {
        case 14:
            name = u"Ace";
            break;
        
        case 13:
            name = u"King";
            break;
        
        case 12:
            name = u"Queen";
            break;
        
        case 11:
            name = u"Jack";
            break;
        
        default: 
            name = Value->ToString();
            break;
        
    }
    
    return name;
}

System::String Card::get_Name()
{
    return get_NamedValue() + u" of  " + Suite->ToString();
}

Card::Card(int32_t Value, System::SharedPtr<Suits> Suit)
{
    this->Value = Value;
    this->Suit = Suit;
}

{
class String;
} // namespace System

class Card : public System::Object
{
    typedef Card ThisType;
    typedef System::Object BaseType;
    
    typedef ::System::BaseTypesInfo<BaseType> ThisTypeBaseTypesInfo;
    RTTI_INFO_DECL();
    
public:

    System::String get_NamedValue();
    System::String get_Name();
    
    Card(int32_t Value, System::SharedPtr<Suits> Suit);
    
};




 //===============================================
// ARTIFACT: code_snippet.cpp
#include "code_snippet.h"

RTTI_INFO_IMPL_HASH(1568579152u, ::Card, ThisTypeBaseTypesInfo);

int32_t Card::get_Value()
{
    return pr_Value;
}

void Card::set_Value(int32_t value)
{
    pr_Value = value;
}

Card::Suits Card::get_Suit()
{
    return pr_Suit;
}

void Card::set_Suit(Card::Suits value)
{
    pr_Suit = value;
}

Card::Card() : pr_Value(0), pr_Suit(((Card::Suits)0))
{
}

#ifdef ASPOSE_GET_SHARED_MEMBERS
void Card::GetSharedMembers(System::Object::shared_members_type& result) const
{
    System::Object::GetSharedMembers(result);
    
    result.Add("Card::pr_Suit", this->pr_Suit);
}
#endif













    public string NamedValue
    {
        get
        {
            string name = string.Empty;
            switch (Value)
            {
                case (14):
                    name = "Ace";
                    break;
                case (13):
                    name = "King";
                    break;
                case (12):
                    name = "Queen";
                    break;
                case (11):
                    name = "Jack";
                    break;
                default:
                    name = Value.ToString();
                    break;
            }

            return name;
        }
    }

    public string Name
    {
        get
        {
            return NamedValue + " of  " + Suite.ToString();
        }
    }

    public Card(int Value, Suits Suit)
    {
        this.Value = Value;
        this.Suit = Suit;
    }
}

public class Deck
{
    public List<Card> Cards = new List<Card>();
    public void FillDeck()
    {
        public void FillDeck()
        {
            //Can use a single loop utilising the mod operator % and Math.Floor
            //Using divition based on 13 cards in a suited
            for (int i = 0; i < 52; i++)
            {
                Card.Suits suit = (Card.Suits)(Math.Floor((decimal)i / 13));
                //Add 2 to value as a cards start a 2
                int val = i % 13 + 2;
                Cards.Add(new Card(val, suit));
            }
        }
    }

    public void PrintDeck()
    {
        foreach (Card card in this.Cards)
        {
            Console.WriteLine(card.Name);
        }
    }
}