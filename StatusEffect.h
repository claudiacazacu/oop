// StatusEffect.h
#pragma once
#include <string>

class Pokemon; // Forward declaration

enum class StatusEffectType {
    BURN,
    FREEZE,
    PARALYSIS,
    POISON,
    BADLY_POISON,
    SLEEP,
    CONFUSION
};

class StatusEffect {
protected:
    std::string name;
    StatusEffectType type;
    int duration;

public:
    StatusEffect(std::string name, StatusEffectType type, int duration = -1);
    virtual ~StatusEffect() = default;

    virtual void apply(Pokemon& target) = 0;
    virtual bool canApply(const Pokemon& target) const = 0;

    std::string getName() const;
    StatusEffectType getType() const;
    bool isDone() const;
    void decrementDuration();
    int getDuration() const;
};