// SpecificMoves.cpp
#include "SpecificMoves.h"
#include "SpecificStatusEffects.h"
#include <iostream>

// Fire Moves
Flamethrower::Flamethrower()
    : Move("Flamethrower", PokemonType::FIRE, MoveCategory::SPECIAL, 90, 100, 15) {}

void Flamethrower::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Flamethrower!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 10) {
        target.addStatusEffect(std::make_shared<BurnEffect>());
    }
    decrementPP();
}

FireBlast::FireBlast()
    : Move("Fire Blast", PokemonType::FIRE, MoveCategory::SPECIAL, 110, 85, 5) {}

void FireBlast::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Fire Blast!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 10) {
        target.addStatusEffect(std::make_shared<BurnEffect>());
    }
    decrementPP();
}

// Thunder Moves
Thunder::Thunder()
    : Move("Thunder", PokemonType::ELECTRIC, MoveCategory::SPECIAL, 110, 70, 10) {}

void Thunder::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Thunder!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 30) {
        target.addStatusEffect(std::make_shared<ParalysisEffect>());
    }
    decrementPP();
}

Thunderbolt::Thunderbolt()
    : Move("Thunderbolt", PokemonType::ELECTRIC, MoveCategory::SPECIAL, 90, 100, 15) {}

void Thunderbolt::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Thunderbolt!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 10) {
        target.addStatusEffect(std::make_shared<ParalysisEffect>());
    }
    decrementPP();
}

// Water Moves
HydroPump::HydroPump()
    : Move("Hydro Pump", PokemonType::WATER, MoveCategory::SPECIAL, 110, 80, 5) {}

void HydroPump::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Hydro Pump!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    decrementPP();
}

// Ice Moves
IceBeam::IceBeam()
    : Move("Ice Beam", PokemonType::ICE, MoveCategory::SPECIAL, 90, 100, 10) {}

void IceBeam::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Ice Beam!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 10) {
        target.addStatusEffect(std::make_shared<FreezeEffect>());
    }
    decrementPP();
}

// Flying Moves
AirSlash::AirSlash()
    : Move("Air Slash", PokemonType::FLYING, MoveCategory::SPECIAL, 75, 95, 15) {}

void AirSlash::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Air Slash!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    decrementPP();
}

// Dragon Moves
DragonClaw::DragonClaw()
    : Move("Dragon Claw", PokemonType::DRAGON, MoveCategory::PHYSICAL, 80, 100, 15) {}

void DragonClaw::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Dragon Claw!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    decrementPP();
}

// Grass Moves
SolarBeam::SolarBeam()
    : Move("Solar Beam", PokemonType::GRASS, MoveCategory::SPECIAL, 120, 100, 10) {}

void SolarBeam::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Solar Beam!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    decrementPP();
}

// Steel Moves
FlashCannon::FlashCannon()
    : Move("Flash Cannon", PokemonType::STEEL, MoveCategory::SPECIAL, 80, 100, 10) {}

void FlashCannon::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Flash Cannon!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 10) {
        std::cout << target.getName() << "'s Special Defense fell!\n";
    }
    decrementPP();
}

// Dark Moves
DarkPulse::DarkPulse()
    : Move("Dark Pulse", PokemonType::DARK, MoveCategory::SPECIAL, 80, 100, 15) {}

void DarkPulse::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Dark Pulse!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 20) {
        std::cout << target.getName() << " flinched!\n";
    }
    decrementPP();
}

// Poison Moves
SludgeBomb::SludgeBomb()
    : Move("Sludge Bomb", PokemonType::POISON, MoveCategory::SPECIAL, 90, 100, 10) {}

void SludgeBomb::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Sludge Bomb!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 30) {
        target.addStatusEffect(std::make_shared<PoisonEffect>());
    }
    decrementPP();
}

// Ground Moves
EarthQuake::EarthQuake()
    : Move("Earthquake", PokemonType::GROUND, MoveCategory::PHYSICAL, 100, 100, 10) {}

void EarthQuake::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Earthquake!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    decrementPP();
}

// Status Moves
SleepPowder::SleepPowder()
    : Move("Sleep Powder", PokemonType::GRASS, MoveCategory::STATUS, 0, 75, 15) {}

void SleepPowder::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Sleep Powder!\n";
    if (rand() % 100 < accuracy) {
        target.addStatusEffect(std::make_shared<SleepEffect>());
    } else {
        std::cout << "But it missed!\n";
    }
    decrementPP();
}

// Steel Physical Moves
IronTail::IronTail()
    : Move("Iron Tail", PokemonType::STEEL, MoveCategory::PHYSICAL, 100, 75, 15) {}

void IronTail::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Iron Tail!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 30) {
        std::cout << target.getName() << "'s Defense fell!\n";
    }
    decrementPP();
}

// Normal Moves
QuickAttack::QuickAttack()
    : Move("Quick Attack", PokemonType::NORMAL, MoveCategory::PHYSICAL, 40, 100, 30) {}

void QuickAttack::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Quick Attack!\n";
    std::cout << "It moved first with blazing speed!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    decrementPP();
}

// Ghost Moves
ShadowBall::ShadowBall()
    : Move("Shadow Ball", PokemonType::GHOST, MoveCategory::SPECIAL, 80, 100, 15) {}

void ShadowBall::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Shadow Ball!\n";
    float damage = user.calculateDamage(*this, target);
    target.takeDamage(damage);
    if (rand() % 100 < 20) {
        std::cout << target.getName() << "'s Special Defense fell!\n";
    }
    decrementPP();
}

// Psychic Moves
DreamEater::DreamEater()
    : Move("Dream Eater", PokemonType::PSYCHIC, MoveCategory::SPECIAL, 100, 100, 15) {}

void DreamEater::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Dream Eater!\n";
    if (target.hasStatusEffect("Sleep")) {
        float damage = user.calculateDamage(*this, target);
        target.takeDamage(damage);
        user.heal(damage / 2);
        std::cout << user.getName() << " restored HP!\n";
    } else {
        std::cout << "But it failed!\n";
    }
    decrementPP();
}

// Status Moves
Hypnosis::Hypnosis()
    : Move("Hypnosis", PokemonType::PSYCHIC, MoveCategory::STATUS, 0, 60, 20) {}

void Hypnosis::use(Pokemon& user, Pokemon& target) {
    if (!canUse()) return;
    std::cout << user.getName() << " used Hypnosis!\n";
    if (rand() % 100 < accuracy) {
        target.addStatusEffect(std::make_shared<SleepEffect>());
    } else {
        std::cout << "But it missed!\n";
    }
    decrementPP();
}