#include "DartGoblin.h"

DartGoblin::DartGoblin(const int cardLevel)
{
	m_id = 8;
	m_unlockedInTrophies = 52;
	m_elixirCost = 3;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::DART_GOBLIN));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { DART_GOBLIN_UPGRADE_COST_1, DART_GOBLIN_UPGRADE_COST_2, DART_GOBLIN_UPGRADE_COST_3, DART_GOBLIN_UPGRADE_COST_4, DART_GOBLIN_UPGRADE_COST_5 };

	m_level = cardLevel;
}


int DartGoblin::getPriority() const
{
	return PRIORITY3;
}