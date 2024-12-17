// BattleSystem.h
#pragma once
#include "Pokemon.h"
#include <memory>
#include <string>

class BattleSystem {
private:
    std::shared_ptr<Pokemon> pokemon1;
    std::shared_ptr<Pokemon> pokemon2;
    bool isPlayer1Turn;
    int turnCount;

    void executeTurn(Pokemon& attacker, Pokemon& defender);
    void executeAITurn(Pokemon& attacker, Pokemon& defender);
    void handlePlayerChoice(int moveIndex, Pokemon& attacker, Pokemon& defender);
    void handleStatusEffects(Pokemon& pokemon);
    float calculateSpeedPriority() const;
    void announceWinner();
    int calculateExperienceGained() const;
    void displayHealthBar(const Pokemon& pokemon) const;
    void displayStatusEffects(const Pokemon& pokemon) const;
    void clearScreen() const;
    std::string getTypeColorCode(PokemonType type) const;  // Adăugat aici
    void displayAnimatedText(const std::string& text, int delayMs = 30) const;
    bool canPokemonMove(const Pokemon& pokemon) const;
    void applyWeatherEffects();

public:
    BattleSystem(std::shared_ptr<Pokemon> p1, std::shared_ptr<Pokemon> p2);

    void startBattle();
    void displayBattleStatus() const;
    bool isBattleOver() const;
    Pokemon* getWinner() const;
    void displayBattleMenu(const Pokemon& pokemon) const;
    static void displayMoveEffectiveness(float effectiveness);
};
