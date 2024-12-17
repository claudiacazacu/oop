// SpecificStatusEffects.cpp
#include "SpecificStatusEffects.h"
#include <iostream>

BurnEffect::BurnEffect()
    : StatusEffect("Burn", StatusEffectType::BURN) {}

void BurnEffect::apply(Pokemon& target) {
    int damage = target.getMaxHP() / 16;
    target.takeDamage(damage);
    std::cout << target.getName() << " is hurt by its burn!\n";
}

bool BurnEffect::canApply(const Pokemon& target) const {
    return target.getPrimaryType() != PokemonType::FIRE &&
           target.getSecondaryType() != PokemonType::FIRE;
}

ParalysisEffect::ParalysisEffect()
    : StatusEffect("Paralysis", StatusEffectType::PARALYSIS) {}

void ParalysisEffect::apply(Pokemon& target) {
    // Logica de aplicare a paraliziei este gestionată în BattleSystem
    // deoarece afectează șansa de a ataca
}

bool ParalysisEffect::canApply(const Pokemon& target) const {
    return target.getPrimaryType() != PokemonType::ELECTRIC &&
           target.getSecondaryType() != PokemonType::ELECTRIC;
}

PoisonEffect::PoisonEffect()
    : StatusEffect("Poison", StatusEffectType::POISON) {}

void PoisonEffect::apply(Pokemon& target) {
    int damage = target.getMaxHP() / 8;
    target.takeDamage(damage);
    std::cout << target.getName() << " is hurt by poison!\n";
}

bool PoisonEffect::canApply(const Pokemon& target) const {
    return target.getPrimaryType() != PokemonType::POISON &&
           target.getSecondaryType() != PokemonType::POISON &&
           target.getPrimaryType() != PokemonType::STEEL &&
           target.getSecondaryType() != PokemonType::STEEL;
}

BadlyPoisonEffect::BadlyPoisonEffect()
    : StatusEffect("Badly Poison", StatusEffectType::BADLY_POISON), turnCount(1) {}

void BadlyPoisonEffect::apply(Pokemon& target) {
    int damage = (target.getMaxHP() * turnCount) / 16;
    target.takeDamage(damage);
    std::cout << target.getName() << " is hurt by toxic poison!\n";
    turnCount++;
}

bool BadlyPoisonEffect::canApply(const Pokemon& target) const {
    return PoisonEffect().canApply(target);
}

SleepEffect::SleepEffect()
    : StatusEffect("Sleep", StatusEffectType::SLEEP, rand() % 3 + 1) {}

void SleepEffect::apply(Pokemon& target) {
    // Logica de somn este gestionată în BattleSystem
    // deoarece împiedică Pokemon-ul să atace
    decrementDuration();
}

bool SleepEffect::canApply(const Pokemon& target) const {
    return true; // Toate Pokemon-urile pot fi adormite
}

FreezeEffect::FreezeEffect()
    : StatusEffect("Freeze", StatusEffectType::FREEZE) {}

void FreezeEffect::apply(Pokemon& target) {
    // Logica de înghețare este gestionată în BattleSystem
    // deoarece împiedică Pokemon-ul să atace
    if (rand() % 100 < 20) { // 20% șansă de dezghețare
        duration = 0;
        std::cout << target.getName() << " thawed out!\n";
    }
}

bool FreezeEffect::canApply(const Pokemon& target) const {
    return target.getPrimaryType() != PokemonType::ICE &&
           target.getSecondaryType() != PokemonType::ICE;
}
