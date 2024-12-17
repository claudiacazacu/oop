// SpecificMoves.h
#pragma once
#include "Move.h"
#include "Pokemon.h"
#include "StatusEffect.h"
#include <memory>

// Fire Moves
class Flamethrower : public Move {
public:
    Flamethrower();
    void use(Pokemon& user, Pokemon& target) override;
};

class FireBlast : public Move {
public:
    FireBlast();
    void use(Pokemon& user, Pokemon& target) override;
};

// Water Moves
class HydroPump : public Move {
public:
    HydroPump();
    void use(Pokemon& user, Pokemon& target) override;
};

class IceBeam : public Move {
public:
    IceBeam();
    void use(Pokemon& user, Pokemon& target) override;
};

// Electric Moves
class Thunderbolt : public Move {
public:
    Thunderbolt();
    void use(Pokemon& user, Pokemon& target) override;
};

class Thunder : public Move {
public:
    Thunder();
    void use(Pokemon& user, Pokemon& target) override;
};

// Normal Moves
class QuickAttack : public Move {
public:
    QuickAttack();
    void use(Pokemon& user, Pokemon& target) override;
};

class IronTail : public Move {
public:
    IronTail();
    void use(Pokemon& user, Pokemon& target) override;
};

// Ghost Moves
class ShadowBall : public Move {
public:
    ShadowBall();
    void use(Pokemon& user, Pokemon& target) override;
};

// Grass Moves
class SolarBeam : public Move {
public:
    SolarBeam();
    void use(Pokemon& user, Pokemon& target) override;
};

// Dragon Moves
class DragonClaw : public Move {
public:
    DragonClaw();
    void use(Pokemon& user, Pokemon& target) override;
};

// Status Moves
class SleepPowder : public Move {
public:
    SleepPowder();
    void use(Pokemon& user, Pokemon& target) override;
};

class Hypnosis : public Move {
public:
    Hypnosis();
    void use(Pokemon& user, Pokemon& target) override;
};

// Other Moves
class FlashCannon : public Move {
public:
    FlashCannon();
    void use(Pokemon& user, Pokemon& target) override;
};

class DarkPulse : public Move {
public:
    DarkPulse();
    void use(Pokemon& user, Pokemon& target) override;
};

class SludgeBomb : public Move {
public:
    SludgeBomb();
    void use(Pokemon& user, Pokemon& target) override;
};

class EarthQuake : public Move {
public:
    EarthQuake();
    void use(Pokemon& user, Pokemon& target) override;
};

class AirSlash : public Move {
public:
    AirSlash();
    void use(Pokemon& user, Pokemon& target) override;
};

class DreamEater : public Move {
public:
    DreamEater();
    void use(Pokemon& user, Pokemon& target) override;
};