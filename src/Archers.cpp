#include "Archers.h"

Archers::Archers(const int cardLevel)
{
	m_id = 2;
	m_unlockedInTrophies = 0;
	m_elixirCost = 3;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::ARCHERS));
	m_cardImgSprite.setScale(m_cardImgScale);
	m_upgradesCosts = { ARCHERS_UPGRADE_COST_1, ARCHERS_UPGRADE_COST_2, ARCHERS_UPGRADE_COST_3, ARCHERS_UPGRADE_COST_4, ARCHERS_UPGRADE_COST_5 };
	m_level = cardLevel;
}

int Archers::getPriority() const
{
	return PRIORITY3;
}