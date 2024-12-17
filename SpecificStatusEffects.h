// SpecificStatusEffects.h
#pragma once
#include "StatusEffect.h"
#include "Pokemon.h"

class BurnEffect : public StatusEffect {
public:
    BurnEffect();
    void apply(Pokemon& target) override;
    bool canApply(const Pokemon& target) const override;
};

class ParalysisEffect : public StatusEffect {
public:
    ParalysisEffect();
    void apply(Pokemon& target) override;
    bool canApply(const Pokemon& target) const override;
};

class PoisonEffect : public StatusEffect {
public:
    PoisonEffect();
    void apply(Pokemon& target) override;
    bool canApply(const Pokemon& target) const override;
};

class BadlyPoisonEffect : public StatusEffect {
private:
    int turnCount;
public:
    BadlyPoisonEffect();
    void apply(Pokemon& target) override;
    bool canApply(const Pokemon& target) const override;
};

class SleepEffect : public StatusEffect {
public:
    SleepEffect();
    void apply(Pokemon& target) override;
    bool canApply(const Pokemon& target) const override;
};

class FreezeEffect : public StatusEffect {
public:
    FreezeEffect();
    void apply(Pokemon& target) override;
    bool canApply(const Pokemon& target) const override;
};