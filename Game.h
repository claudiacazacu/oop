// Game.h
#pragma once
#include "BattleSystem.h"
#include <vector>
#include <memory>

class Game {
private:
    std::vector<std::shared_ptr<Pokemon>> playerTeam;
    std::unique_ptr<BattleSystem> battleSystem;

    void displayMainMenu() const;
    void displayPokemonSelection() const;
    void displayBattleMenu(const Pokemon& pokemon) const;
    void createTeam();
    void startBattle();
    void showTeamStats() const;
    void clearScreen() const;
    void displayAnimatedText(const std::string& text, int delayMs = 30) const;
    std::shared_ptr<Pokemon> createPokemon(int choice, int level);

public:
    Game();
    void run();
};