// Move.h
#pragma once
#include "Types.h"
#include <string>

class Pokemon; // Forward declaration

class Move {
protected:
    std::string name;
    PokemonType type;
    MoveCategory category;
    int power;
    int accuracy;
    int maxPP;
    int currentPP;

public:
    Move(std::string name, PokemonType type, MoveCategory category,
         int power, int accuracy, int pp);
    virtual ~Move() = default;

    virtual void use(Pokemon& user, Pokemon& target) = 0;
    virtual bool canUse() const;

    std::string getName() const;
    PokemonType getType() const;
    MoveCategory getCategory() const;
    int getPower() const;
    int getAccuracy() const;
    int getCurrentPP() const;
    int getMaxPP() const;

    void decrementPP();
    void restorePP();
};