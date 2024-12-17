// BattleSystem.cpp
#include "BattleSystem.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cstdlib>

BattleSystem::BattleSystem(std::shared_ptr<Pokemon> p1, std::shared_ptr<Pokemon> p2)
    : pokemon1(p1), pokemon2(p2), turnCount(0) {
    isPlayer1Turn = calculateSpeedPriority();
}

void BattleSystem::startBattle() {
    clearScreen();
    displayAnimatedText("\n=== POKEMON BATTLE START ===\n");
    displayAnimatedText(pokemon1->getName() + " VS " + pokemon2->getName() + "\n\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    while (!isBattleOver()) {
        turnCount++;
        displayBattleStatus();

        Pokemon& attacker = isPlayer1Turn ? *pokemon1 : *pokemon2;
        Pokemon& defender = isPlayer1Turn ? *pokemon2 : *pokemon1;

        if (canPokemonMove(attacker)) {
            if (isPlayer1Turn) {
                executeTurn(attacker, defender);
            } else {
                executeAITurn(attacker, defender);
            }
        }

        handleStatusEffects(attacker);
        handleStatusEffects(defender);
        applyWeatherEffects();

        if (!isBattleOver()) {
            isPlayer1Turn = !isPlayer1Turn;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            clearScreen();
        }
    }

    announceWinner();
}

void BattleSystem::executeTurn(Pokemon& attacker, Pokemon& defender) {
    displayBattleMenu(attacker);

    int choice;
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 4) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid choice! Please enter a number between 1 and 4: ";
        std::cin >> choice;
    }

    handlePlayerChoice(choice - 1, attacker, defender);
}

void BattleSystem::executeAITurn(Pokemon& attacker, Pokemon& defender) {
    const auto& moves = attacker.getMoves();
    std::vector<int> availableMoves;

    for (size_t i = 0; i < moves.size(); ++i) {
        if (moves[i]->getCurrentPP() > 0) {
            availableMoves.push_back(i);
        }
    }

    if (availableMoves.empty()) {
        displayAnimatedText(attacker.getName() + " has no moves left!\n");
        return;
    }

    int moveIndex = availableMoves[rand() % availableMoves.size()];
    displayAnimatedText("\nOpponent's " + attacker.getName() + " used " +
                       moves[moveIndex]->getName() + "!\n");

    attacker.useMove(moveIndex, defender);
}

void BattleSystem::handlePlayerChoice(int moveIndex, Pokemon& attacker, Pokemon& defender) {
    const auto& moves = attacker.getMoves();

    if (moveIndex < 0 || moveIndex >= moves.size()) {
        displayAnimatedText("Invalid move! Using first available move.\n");
        moveIndex = 0;
    }

    if (moves[moveIndex]->getCurrentPP() <= 0) {
        displayAnimatedText("No PP left for this move! Choose another move.\n");
        return;
    }

    displayAnimatedText("\nYour " + attacker.getName() + " used " +
                       moves[moveIndex]->getName() + "!\n");

    attacker.useMove(moveIndex, defender);
}

float BattleSystem::calculateSpeedPriority() const {
    int speed1 = pokemon1->getSpeed();
    int speed2 = pokemon2->getSpeed();

    if (pokemon1->hasStatusEffect("Paralysis")) speed1 /= 2;
    if (pokemon2->hasStatusEffect("Paralysis")) speed2 /= 2;

    if (speed1 == speed2) {
        return (rand() % 2 == 0);
    }
    return speed1 > speed2;
}

bool BattleSystem::canPokemonMove(const Pokemon& pokemon) const {
    if (pokemon.hasStatusEffect("Freeze")) {
        std::cout << pokemon.getName() << " is frozen solid!\n";
        if (rand() % 100 < 20) {
            std::cout << pokemon.getName() << " thawed out!\n";
            const_cast<Pokemon&>(pokemon).removeStatusEffect("Freeze");
            return true;
        }
        return false;
    }

    if (pokemon.hasStatusEffect("Sleep")) {
        std::cout << pokemon.getName() << " is fast asleep!\n";
        return false;
    }

    if (pokemon.hasStatusEffect("Paralysis")) {
        if (rand() % 100 < 25) {
            std::cout << pokemon.getName() << " is paralyzed! It can't move!\n";
            return false;
        }
    }

    return true;
}

void BattleSystem::handleStatusEffects(Pokemon& pokemon) {
    if (pokemon.hasStatusEffect("Burn")) {
        int damage = pokemon.getMaxHP() / 16;
        pokemon.takeDamage(damage);
        std::cout << pokemon.getName() << " is hurt by its burn!\n";
    }

    if (pokemon.hasStatusEffect("Poison")) {
        int damage = pokemon.getMaxHP() / 8;
        pokemon.takeDamage(damage);
        std::cout << pokemon.getName() << " is hurt by poison!\n";
    }

    pokemon.updateStatusEffects();
}

void BattleSystem::displayBattleStatus() const {
    std::cout << "\n+========== Battle Status ==========+\n\n";

    // Display player's Pokemon
    std::cout << "Your " << pokemon1->getName()
              << " (Level " << pokemon1->getLevel() << ")\n";
    displayHealthBar(*pokemon1);
    displayStatusEffects(*pokemon1);

    std::cout << "\n";

    // Display opponent's Pokemon
    std::cout << "Opponent's " << pokemon2->getName()
              << " (Level " << pokemon2->getLevel() << ")\n";
    displayHealthBar(*pokemon2);
    displayStatusEffects(*pokemon2);

    std::cout << "\n+================================+\n";
}

void BattleSystem::displayHealthBar(const Pokemon& pokemon) const {
    const int barWidth = 20;
    float healthPercentage = (float)pokemon.getCurrentHP() / pokemon.getMaxHP();
    int filledWidth = static_cast<int>(healthPercentage * barWidth);

    std::cout << "HP: " << std::setw(3) << pokemon.getCurrentHP() << "/"
              << std::setw(3) << pokemon.getMaxHP() << " [";

    for (int i = 0; i < barWidth; ++i) {
        if (i < filledWidth) {
            if (healthPercentage > 0.5f) std::cout << "=";
            else if (healthPercentage > 0.2f) std::cout << "-";
            else std::cout << ".";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "]\n";
}

void BattleSystem::displayStatusEffects(const Pokemon& pokemon) const {
    std::cout << "Status: ";
    bool hasStatus = false;

    for (const auto& effect : pokemon.getStatusEffects()) {
        std::cout << effect->getName() << " ";
        hasStatus = true;
    }

    if (!hasStatus) {
        std::cout << "Normal";
    }
    std::cout << "\n";
}

void BattleSystem::applyWeatherEffects() {
    // Placeholder pentru efecte de vreme viitoare
}

void BattleSystem::announceWinner() {
    std::cout << "\n+========== Battle Finished! ==========+\n";

    Pokemon* winner = getWinner();
    if (winner) {
        bool isPlayerWinner = (winner == pokemon1.get());
        std::string winnerText = isPlayerWinner ? "Congratulations! Your " : "The opponent's ";
        std::cout << winnerText << winner->getName() << " wins the battle!\n";

        if (isPlayerWinner) {
            int expGained = calculateExperienceGained();
            std::cout << "\nYour " << pokemon1->getName() << " gained "
                      << expGained << " experience points!\n";
        }
    } else {
        std::cout << "The battle ended in a draw!\n";
    }
    std::cout << "+====================================+\n";
}

bool BattleSystem::isBattleOver() const {
    return pokemon1->isFainted() || pokemon2->isFainted();
}

Pokemon* BattleSystem::getWinner() const {
    if (pokemon1->isFainted() && !pokemon2->isFainted()) return pokemon2.get();
    if (!pokemon1->isFainted() && pokemon2->isFainted()) return pokemon1.get();
    return nullptr;
}

void BattleSystem::clearScreen() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void BattleSystem::displayAnimatedText(const std::string& text, int delayMs) const {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

int BattleSystem::calculateExperienceGained() const {
    int baseExp = pokemon2->getLevel() * 2;
    if (pokemon2->isFainted()) {
        baseExp = static_cast<int>(baseExp * 1.5f);
    }
    return baseExp;
}

void BattleSystem::displayBattleMenu(const Pokemon& pokemon) const {
    std::cout << "\n+========== Choose a Move ==========+\n";
    const auto& moves = pokemon.getMoves();
    for (size_t i = 0; i < moves.size(); ++i) {
        std::cout << (i + 1) << ". " << std::left << std::setw(15)
                  << moves[i]->getName()
                  << "PP: " << std::setw(2) << moves[i]->getCurrentPP()
                  << "/" << std::setw(2) << moves[i]->getMaxPP()
                  << " | Type: " << std::setw(8) << getTypeColorCode(moves[i]->getType())
                  << " Power: " << std::setw(3) << moves[i]->getPower() << "\n";
    }
    std::cout << "+================================+\n";
    std::cout << "\nEnter your choice (1-4): ";
}

std::string BattleSystem::getTypeColorCode(PokemonType type) const {
    switch (type) {
        case PokemonType::NORMAL:   return "NORMAL   ";
        case PokemonType::FIRE:     return "FIRE     ";
        case PokemonType::WATER:    return "WATER    ";
        case PokemonType::ELECTRIC: return "ELECTRIC ";
        case PokemonType::GRASS:    return "GRASS    ";
        case PokemonType::ICE:      return "ICE      ";
        case PokemonType::FIGHTING: return "FIGHTING ";
        case PokemonType::POISON:   return "POISON   ";
        case PokemonType::GROUND:   return "GROUND   ";
        case PokemonType::FLYING:   return "FLYING   ";
        case PokemonType::PSYCHIC:  return "PSYCHIC  ";
        case PokemonType::BUG:      return "BUG      ";
        case PokemonType::ROCK:     return "ROCK     ";
        case PokemonType::GHOST:    return "GHOST    ";
        case PokemonType::DRAGON:   return "DRAGON   ";
        case PokemonType::DARK:     return "DARK     ";
        case PokemonType::STEEL:    return "STEEL    ";
        case PokemonType::FAIRY:    return "FAIRY    ";
        default:                    return "UNKNOWN  ";
    }
}