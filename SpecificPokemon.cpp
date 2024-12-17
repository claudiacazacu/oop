// SpecificPokemon.cpp
#include "SpecificPokemon.h"

Charizard::Charizard(int level)
    : Pokemon("Charizard", PokemonType::FIRE, PokemonType::FLYING,
              78, 84, 78, 109, 85, 100) {
    this->level = level;

    // Calcularea statisticilor bazate pe nivel
    maxHP = ((2 * 78 + 31 + 85/4) * level / 100) + level + 10;
    currentHP = maxHP;
    attack = calculateStat(84);
    defense = calculateStat(78);
    spAttack = calculateStat(109);
    spDefense = calculateStat(85);
    speed = calculateStat(100);

    // Adăugarea mișcărilor
    moves.push_back(std::make_shared<Flamethrower>());
    moves.push_back(std::make_shared<AirSlash>());
    moves.push_back(std::make_shared<DragonClaw>());
    moves.push_back(std::make_shared<SolarBeam>());
}

Blastoise::Blastoise(int level)
    : Pokemon("Blastoise", PokemonType::WATER, PokemonType::WATER,
              79, 83, 100, 85, 105, 78) {
    this->level = level;

    maxHP = ((2 * 79 + 31 + 85/4) * level / 100) + level + 10;
    currentHP = maxHP;
    attack = calculateStat(83);
    defense = calculateStat(100);
    spAttack = calculateStat(85);
    spDefense = calculateStat(105);
    speed = calculateStat(78);

    moves.push_back(std::make_shared<HydroPump>());
    moves.push_back(std::make_shared<IceBeam>());
    moves.push_back(std::make_shared<FlashCannon>());
    moves.push_back(std::make_shared<DarkPulse>());
}

Venusaur::Venusaur(int level)
    : Pokemon("Venusaur", PokemonType::GRASS, PokemonType::POISON,
              80, 82, 83, 100, 100, 80) {
    this->level = level;

    maxHP = ((2 * 80 + 31 + 85/4) * level / 100) + level + 10;
    currentHP = maxHP;
    attack = calculateStat(82);
    defense = calculateStat(83);
    spAttack = calculateStat(100);
    spDefense = calculateStat(100);
    speed = calculateStat(80);

    moves.push_back(std::make_shared<SolarBeam>());
    moves.push_back(std::make_shared<SludgeBomb>());
    moves.push_back(std::make_shared<EarthQuake>());
    moves.push_back(std::make_shared<SleepPowder>());
}

Pikachu::Pikachu(int level)
    : Pokemon("Pikachu", PokemonType::ELECTRIC, PokemonType::ELECTRIC,
              35, 55, 40, 50, 50, 90) {
    this->level = level;

    maxHP = ((2 * 35 + 31 + 85/4) * level / 100) + level + 10;
    currentHP = maxHP;
    attack = calculateStat(55);
    defense = calculateStat(40);
    spAttack = calculateStat(50);
    spDefense = calculateStat(50);
    speed = calculateStat(90);

    moves.push_back(std::make_shared<Thunderbolt>());
    moves.push_back(std::make_shared<IronTail>());
    moves.push_back(std::make_shared<QuickAttack>());
    moves.push_back(std::make_shared<Thunder>());
}

Gengar::Gengar(int level)
: Pokemon("Gengar", PokemonType::GHOST, PokemonType:: POISON,
          60, 65, 60, 130, 75, 110) {
    this->level = level;

    maxHP = ((2 * 60 + 31 + 85/4) * level / 100) + level + 10;
    currentHP = maxHP;
    attack = calculateStat(65);
    defense = calculateStat(60);
    spAttack = calculateStat(130);
    spDefense = calculateStat(75);
    speed = calculateStat(110);

    moves.push_back(std::make_shared<ShadowBall>());
    moves.push_back(std::make_shared<SludgeBomb>());
    moves.push_back(std::make_shared<DreamEater>());
    moves.push_back(std::make_shared<Hypnosis>());
}