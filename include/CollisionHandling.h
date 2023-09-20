#pragma once
#include "Object.h"
#include <iostream>
#include <typeinfo>
#include "ArchersObj.h"
#include "Tower.h"
#include "KnightObj.h"
#include "FireballObj.h"
#include "MinionsObj.h"
#include "ValkyrieObj.h"
#include "PekkaObj.h"
#include "DartGoblinObj.h"
#include "PcTerritory.h"
#include "PlayerTerritory.h"
#include "Bullet.h"
#include "GiantObj.h"
#include "PekkaObj.h"
#include "ArrowsObj.h"
#include "FreezeObj.h"

struct UnknownCollision : public std::runtime_error
{
    UnknownCollision(Object& a, Object& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    { }
};

void processCollision(Object& object1, Object& object2);
