// Pokemon.h
#pragma once
#include "Types.h"
#include "Move.h"
#include "StatusEffect.h"
#include <string>
#include <vector>
#include <memory>
#include <map>

class Pokemon {
protected:
    std::string name;
    PokemonType primaryType;
    PokemonType secondaryType;
    int level;
    int maxHP;
    int currentHP;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;
    std::vector<std::shared_ptr<Move>> moves;
    std::vector<std::shared_ptr<StatusEffect>> statusEffects;

public:
    static std::map<PokemonType, std::map<PokemonType, float>> typeEffectiveness;

    Pokemon(std::string name, PokemonType primary, PokemonType secondary,
            int hp, int atk, int def, int spAtk, int spDef, int spd);
    virtual ~Pokemon() = default;

    // Battle mechanics
    float calculateDamage(const Move& move, const Pokemon& target) const;
    void takeDamage(int damage);
    void heal(int amount);
    void useMove(int moveIndex, Pokemon& target);

    // Status effects
    void addStatusEffect(std::shared_ptr<StatusEffect> effect);
    void updateStatusEffects();
    bool hasStatusEffect(const std::string& effectName) const;
    void removeStatusEffect(const std::string& effectName);
    const std::vector<std::shared_ptr<StatusEffect>>& getStatusEffects() const;

    // Getters
    std::string getName() const;
    PokemonType getPrimaryType() const;
    PokemonType getSecondaryType() const;
    int getLevel() const;
    int getCurrentHP() const;
    int getMaxHP() const;
    int getAttack() const;
    int getDefense() const;
    int getSpAttack() const;
    int getSpDefense() const;
    int getSpeed() const;
    const std::vector<std::shared_ptr<Move>>& getMoves() const;

    bool isFainted() const;

    // Type effectiveness
    static float getTypeEffectiveness(PokemonType attackType, PokemonType defenseType);
    std::string getTypeEffectivenessMessage(float effectiveness) const;

protected:
    // Helper pentru calcularea statisticilor bazate pe nivel
    int calculateStat(int baseStat) const;
};