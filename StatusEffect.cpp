// StatusEffect.cpp
#include "StatusEffect.h"

StatusEffect::StatusEffect(std::string name, StatusEffectType type, int duration)
    : name(name), type(type), duration(duration) {}

std::string StatusEffect::getName() const {
    return name;
}

StatusEffectType StatusEffect::getType() const {
    return type;
}

bool StatusEffect::isDone() const {
    return duration == 0;
}

void StatusEffect::decrementDuration() {
    if (duration > 0) {
        duration--;
    }
}

int StatusEffect::getDuration() const {
    return duration;
}