#pragma once
#include <iostream>
#include "Movable.h"

class SpellObj : public Movable
{
public:
	using Movable::Movable;

	SpellObj() : Movable()
	{}

private:
};