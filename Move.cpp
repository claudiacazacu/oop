// Move.cpp
#include "Move.h"

Move::Move(std::string name, PokemonType type, MoveCategory category,
           int power, int accuracy, int pp)
    : name(name), type(type), category(category),
      power(power), accuracy(accuracy), maxPP(pp), currentPP(pp) {}

bool Move::canUse() const {
    return currentPP > 0;
}

std::string Move::getName() const {
    return name;
}

PokemonType Move::getType() const {
    return type;
}

MoveCategory Move::getCategory() const {
    return category;
}

int Move::getPower() const {
    return power;
}

int Move::getAccuracy() const {
    return accuracy;
}

int Move::getCurrentPP() const {
    return currentPP;
}

int Move::getMaxPP() const {
    return maxPP;
}

void Move::decrementPP() {
    if (currentPP > 0) {
        currentPP--;
    }
}

void Move::restorePP() {
    currentPP = maxPP;
}