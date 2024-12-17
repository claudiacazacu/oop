// main.cpp
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

// Inițializarea tabelului de efectivitate pentru tipurile de Pokemon
void initializeTypeEffectiveness() {
    // Fire relationships
    Pokemon::typeEffectiveness[PokemonType::FIRE][PokemonType::FIRE] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::FIRE][PokemonType::WATER] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::FIRE][PokemonType::GRASS] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::FIRE][PokemonType::ICE] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::FIRE][PokemonType::BUG] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::FIRE][PokemonType::STEEL] = 2.0f;

    // Water relationships
    Pokemon::typeEffectiveness[PokemonType::WATER][PokemonType::FIRE] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::WATER][PokemonType::WATER] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::WATER][PokemonType::GRASS] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::WATER][PokemonType::GROUND] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::WATER][PokemonType::ROCK] = 2.0f;

    // Electric relationships
    Pokemon::typeEffectiveness[PokemonType::ELECTRIC][PokemonType::WATER] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::ELECTRIC][PokemonType::ELECTRIC] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::ELECTRIC][PokemonType::GRASS] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::ELECTRIC][PokemonType::GROUND] = 0.0f;
    Pokemon::typeEffectiveness[PokemonType::ELECTRIC][PokemonType::FLYING] = 2.0f;

    // Grass relationships
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::FIRE] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::WATER] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::GRASS] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::POISON] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::GROUND] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::FLYING] = 0.5f;
    Pokemon::typeEffectiveness[PokemonType::GRASS][PokemonType::BUG] = 0.5f;

    // Ghost relationships
    Pokemon::typeEffectiveness[PokemonType::GHOST][PokemonType::NORMAL] = 0.0f;
    Pokemon::typeEffectiveness[PokemonType::GHOST][PokemonType::GHOST] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::GHOST][PokemonType::PSYCHIC] = 2.0f;
    Pokemon::typeEffectiveness[PokemonType::GHOST][PokemonType::DARK] = 0.5f;

    // Și așa mai departe pentru restul tipurilor...
}

int main() {
    try {
        // Inițializare generator numere aleatoare
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Inițializare tabel de efectivitate
        initializeTypeEffectiveness();

        // Creare și rulare joc
        Game game;
        game.run();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred!" << std::endl;
        return 1;
    }

    return 0;
}