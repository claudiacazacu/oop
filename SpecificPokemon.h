// SpecificPokemon.h
#pragma once
#include "Pokemon.h"
#include "SpecificMoves.h"

class Charizard : public Pokemon {
public:
    Charizard(int level = 50);
};

class Blastoise : public Pokemon {
public:
    Blastoise(int level = 50);
};

class Venusaur : public Pokemon {
public:
    Venusaur(int level = 50);
};

class Pikachu : public Pokemon {
public:
    Pikachu(int level = 50);
};

class Gengar : public Pokemon {
public:
    Gengar(int level = 50);
};