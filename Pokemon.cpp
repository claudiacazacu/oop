// Pokemon.cpp
#include "Pokemon.h"
#include <algorithm>
#include <iostream>
#include <cmath>

std::map<PokemonType, std::map<PokemonType, float>> Pokemon::typeEffectiveness;

Pokemon::Pokemon(std::string name, PokemonType primary, PokemonType secondary,
                int hp, int atk, int def, int spAtk, int spDef, int spd)
    : name(name), primaryType(primary), secondaryType(secondary), level(1),
      maxHP(hp), currentHP(hp), attack(atk), defense(def),
      spAttack(spAtk), spDefense(spDef), speed(spd) {}

float Pokemon::calculateDamage(const Move& move, const Pokemon& target) const {
    float stab = (move.getType() == primaryType || move.getType() == secondaryType) ? 1.5f : 1.0f;

    float typeEffect = getTypeEffectiveness(move.getType(), target.getPrimaryType());
    if (target.getSecondaryType() != target.getPrimaryType()) {
        typeEffect *= getTypeEffectiveness(move.getType(), target.getSecondaryType());
    }

    float random = (float)(rand() % 16 + 85) / 100.0f;

    int attackStat = (move.getCategory() == MoveCategory::PHYSICAL) ? attack : spAttack;
    int defenseStat = (move.getCategory() == MoveCategory::PHYSICAL) ? target.defense : target.spDefense;

    float damage = (((2.0f * level + 10.0f) / 250.0f) *
                   (float)attackStat / (float)defenseStat *
                   move.getPower() + 2) *
                   stab * typeEffect * random;

    if (typeEffect > 1.0f) {
        std::cout << "It's super effective!\n";
    } else if (typeEffect < 1.0f && typeEffect > 0.0f) {
        std::cout << "It's not very effective...\n";
    } else if (typeEffect == 0.0f) {
        std::cout << "It has no effect...\n";
    }

    return damage;
}

void Pokemon::takeDamage(int damage) {
    currentHP = std::max(0, currentHP - damage);
    if (isFainted()) {
        std::cout << name << " fainted!\n";
    }
}

void Pokemon::heal(int amount) {
    currentHP = std::min(maxHP, currentHP + amount);
    std::cout << name << " restored health!\n";
}

void Pokemon::useMove(int moveIndex, Pokemon& target) {
    if (moveIndex >= 0 && moveIndex < moves.size()) {
        if (moves[moveIndex]->canUse()) {
            moves[moveIndex]->use(*this, target);
        } else {
            std::cout << "No PP left for this move!\n";
        }
    }
}

void Pokemon::addStatusEffect(std::shared_ptr<StatusEffect> effect) {
    if (effect->canApply(*this)) {
        // Verificăm dacă Pokemon-ul are deja acest tip de status
        for (auto it = statusEffects.begin(); it != statusEffects.end(); ++it) {
            if ((*it)->getType() == effect->getType()) {
                statusEffects.erase(it);
                break;
            }
        }
        statusEffects.push_back(effect);
        std::cout << name << " was affected by " << effect->getName() << "!\n";
    }
}

void Pokemon::updateStatusEffects() {
    for (auto it = statusEffects.begin(); it != statusEffects.end();) {
        (*it)->apply(*this);
        if ((*it)->isDone()) {
            std::cout << name << " is no longer " << (*it)->getName() << "!\n";
            it = statusEffects.erase(it);
        } else {
            ++it;
        }
    }
}

bool Pokemon::hasStatusEffect(const std::string& effectName) const {
    return std::any_of(statusEffects.begin(), statusEffects.end(),
                      [&effectName](const auto& effect) {
                          return effect->getName() == effectName;
                      });
}

void Pokemon::removeStatusEffect(const std::string& effectName) {
    statusEffects.erase(
        std::remove_if(statusEffects.begin(), statusEffects.end(),
                      [&effectName](const auto& effect) {
                          return effect->getName() == effectName;
                      }),
        statusEffects.end());
}

const std::vector<std::shared_ptr<StatusEffect>>& Pokemon::getStatusEffects() const {
    return statusEffects;
}

// Getters implementation
std::string Pokemon::getName() const { return name; }
PokemonType Pokemon::getPrimaryType() const { return primaryType; }
PokemonType Pokemon::getSecondaryType() const { return secondaryType; }
int Pokemon::getLevel() const { return level; }
int Pokemon::getCurrentHP() const { return currentHP; }
int Pokemon::getMaxHP() const { return maxHP; }
int Pokemon::getAttack() const { return attack; }
int Pokemon::getDefense() const { return defense; }
int Pokemon::getSpAttack() const { return spAttack; }
int Pokemon::getSpDefense() const { return spDefense; }
int Pokemon::getSpeed() const { return speed; }
const std::vector<std::shared_ptr<Move>>& Pokemon::getMoves() const { return moves; }
bool Pokemon::isFainted() const { return currentHP <= 0; }

float Pokemon::getTypeEffectiveness(PokemonType attackType, PokemonType defenseType) {
    auto it = typeEffectiveness.find(attackType);
    if (it != typeEffectiveness.end()) {
        auto defenseIt = it->second.find(defenseType);
        if (defenseIt != it->second.end()) {
            return defenseIt->second;
        }
    }
    return 1.0f;
}

std::string Pokemon::getTypeEffectivenessMessage(float effectiveness) const {
    if (effectiveness > 2.0f) return "It's super effective!";
    if (effectiveness < 1.0f && effectiveness > 0.0f) return "It's not very effective...";
    if (effectiveness == 0.0f) return "It has no effect...";
    return "";
}

int Pokemon::calculateStat(int baseStat) const {
    return ((2 * baseStat + 31 + (85/4)) * level / 100) + 5;
}