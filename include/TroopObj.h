#pragma once
#include <iostream>
#include "Movable.h"

class TroopObj : public Movable
{
public:
	using Movable::Movable;

	TroopObj() : Movable()
	{}

	//void show() override;

private:
};