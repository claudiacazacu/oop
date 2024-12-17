// Game.cpp
#include "Game.h"
#include "SpecificPokemon.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <iomanip>

Game::Game() {}

void Game::clearScreen() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::displayMainMenu() const {
    clearScreen();
    std::cout << "\n+====================================+\n";
    std::cout << "|     POKEMON BATTLE SIMULATOR        |\n";
    std::cout << "+====================================+\n";
    std::cout << "| 1. Create New Team                 |\n";
    std::cout << "| 2. Show Team Stats                 |\n";
    std::cout << "| 3. Start Battle                    |\n";
    std::cout << "| 4. Exit                            |\n";
    std::cout << "+====================================+\n";
    std::cout << "\nEnter your choice (1-4): ";
}

void Game::displayPokemonSelection() const {
    clearScreen();
    std::cout << "\n+============= Available Pokemon =============+\n\n";

    // Format: Name | Type | Base Stats
    std::cout << std::left
              << std::setw(20) << "Pokemon"
              << std::setw(15) << "Type"
              << "Base Stats\n";
    std::cout << std::string(50, '-') << "\n";

    std::cout << "1. " << std::left
              << std::setw(17) << "Charizard"
              << std::setw(15) << "Fire/Flying"
              << "HP:78 ATK:84 DEF:78\n";

    std::cout << "2. " << std::left
              << std::setw(17) << "Blastoise"
              << std::setw(15) << "Water"
              << "HP:79 ATK:83 DEF:100\n";

    std::cout << "3. " << std::left
              << std::setw(17) << "Venusaur"
              << std::setw(15) << "Grass/Poison"
              << "HP:80 ATK:82 DEF:83\n";

    std::cout << "4. " << std::left
              << std::setw(17) << "Pikachu"
              << std::setw(15) << "Electric"
              << "HP:35 ATK:55 DEF:40\n";

    std::cout << "5. " << std::left
              << std::setw(17) << "Gengar"
              << std::setw(15) << "Ghost/Poison"
              << "HP:60 ATK:65 DEF:60\n";

    std::cout << "\n+===========================================+\n";
}

void Game::createTeam() {
    clearScreen();
    playerTeam.clear();

    std::cout << "How many Pokemon would you like in your team? (1-6): ";
    int teamSize;
    std::cin >> teamSize;
    teamSize = std::min(6, std::max(1, teamSize));

    for (int i = 0; i < teamSize; ++i) {
        displayPokemonSelection();
        std::cout << "\nChoosing Pokemon " << (i + 1) << " of " << teamSize << "\n";
        std::cout << "\nEnter your choice (1-5): ";

        int choice;
        std::cin >> choice;
        while (choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please enter a number between 1 and 5: ";
            std::cin >> choice;
        }

        std::cout << "Enter level for this Pokemon (1-100): ";
        int level;
        std::cin >> level;
        level = std::min(100, std::max(1, level));

        std::shared_ptr<Pokemon> newPokemon;
        switch (choice) {
            case 1:
                newPokemon = std::make_shared<Charizard>(level);
                break;
            case 2:
                newPokemon = std::make_shared<Blastoise>(level);
                break;
            case 3:
                newPokemon = std::make_shared<Venusaur>(level);
                break;
            case 4:
                newPokemon = std::make_shared<Pikachu>(level);
                break;
            case 5:
                newPokemon = std::make_shared<Gengar>(level);
                break;
            default:
                std::cout << "Invalid choice. Adding Charizard by default.\n";
                newPokemon = std::make_shared<Charizard>(level);
        }

        playerTeam.push_back(newPokemon);
        std::cout << "\n" << newPokemon->getName() << " (Level " << level
                  << ") has been added to your team!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "\nTeam creation complete! Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Game::showTeamStats() const {
    clearScreen();
    if (playerTeam.empty()) {
        std::cout << "\nYou haven't created a team yet!\n";
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return;
    }

    std::cout << "\n+============= Your Team =============+\n";

    for (size_t i = 0; i < playerTeam.size(); ++i) {
        const auto& pokemon = playerTeam[i];
        std::cout << "\nPokemon " << (i + 1) << ": " << pokemon->getName()
                  << " (Level " << pokemon->getLevel() << ")\n";

        std::cout << "+----------------------------------+\n";
        std::cout << "| HP: " << std::setw(3) << pokemon->getCurrentHP()
                  << "/" << std::setw(3) << pokemon->getMaxHP() << std::setw(20) << " |\n";
        std::cout << "| Attack: " << std::setw(3) << pokemon->getAttack()
                  << std::setw(24) << " |\n";
        std::cout << "| Defense: " << std::setw(3) << pokemon->getDefense()
                  << std::setw(23) << " |\n";
        std::cout << "| Sp. Attack: " << std::setw(3) << pokemon->getSpAttack()
                  << std::setw(20) << " |\n";
        std::cout << "| Sp. Defense: " << std::setw(3) << pokemon->getSpDefense()
                  << std::setw(19) << " |\n";
        std::cout << "| Speed: " << std::setw(3) << pokemon->getSpeed()
                  << std::setw(25) << " |\n";

        std::cout << "|             Moves:               |\n";
        const auto& moves = pokemon->getMoves();
        for (const auto& move : moves) {
            std::cout << "| - " << std::left << std::setw(15) << move->getName()
                      << "PP: " << std::setw(2) << move->getCurrentPP()
                      << "/" << std::setw(2) << move->getMaxPP() << " |\n";
        }
        std::cout << "+----------------------------------+\n";
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Game::startBattle() {
    if (playerTeam.empty()) {
        std::cout << "\nYou need to create a team first!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        return;
    }

    clearScreen();
    std::cout << "\n+========== Select Pokemon ==========+\n\n";
    for (size_t i = 0; i < playerTeam.size(); ++i) {
        std::cout << (i + 1) << ". " << playerTeam[i]->getName()
                  << " (Level " << playerTeam[i]->getLevel() << ")\n";
    }

    std::cout << "\nEnter your choice (1-" << playerTeam.size() << "): ";
    size_t choice;
    std::cin >> choice;
    choice = std::min(playerTeam.size(), std::max(size_t(1), choice));

    // Create random opponent
    int opponentLevel = playerTeam[choice-1]->getLevel();
    int randomPokemon = rand() % 5 + 1;
    auto opponent = createPokemon(randomPokemon, opponentLevel);

    clearScreen();
    std::cout << "\nA wild " << opponent->getName() << " (Level "
              << opponentLevel << ") appeared!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    battleSystem = std::make_unique<BattleSystem>(playerTeam[choice-1], opponent);
    battleSystem->startBattle();

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

std::shared_ptr<Pokemon> Game::createPokemon(int choice, int level) {
    switch (choice) {
        case 1: return std::make_shared<Charizard>(level);
        case 2: return std::make_shared<Blastoise>(level);
        case 3: return std::make_shared<Venusaur>(level);
        case 4: return std::make_shared<Pikachu>(level);
        case 5: return std::make_shared<Gengar>(level);
        default: return std::make_shared<Charizard>(level);
    }
}

void Game::run() {
    bool running = true;

    // Display welcome screen
    clearScreen();
    std::cout << "\n+=====================================+\n";
    std::cout << "|    POKEMON BATTLE SIMULATOR v1.0    |\n";
    std::cout << "+=====================================+\n\n";
    std::cout << "Welcome to the Pokemon Battle Simulator!\n";
    std::cout << "Create your team and battle against opponents.\n\n";
    std::cout << "Press Enter to continue...";
    std::cin.get();

    while (running) {
        displayMainMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createTeam();
                break;
            case 2:
                showTeamStats();
                break;
            case 3:
                startBattle();
                break;
            case 4:
                clearScreen();
                std::cout << "\nThanks for playing Pokemon Battle Simulator!\n";
                running = false;
                break;
            default:
                std::cout << "\nInvalid option! Please try again.\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }
    }
}