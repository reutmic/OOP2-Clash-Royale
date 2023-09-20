#include "Freeze.h"

Freeze::Freeze(const int cardLevel)
{
	m_id = 9;
	m_unlockedInTrophies = 80;
	m_elixirCost = 4;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::FREEZE));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { FREEZE_UPGRADE_COST_1, FREEZE_UPGRADE_COST_2, FREEZE_UPGRADE_COST_3, FREEZE_UPGRADE_COST_4, FREEZE_UPGRADE_COST_5 };

	m_level = cardLevel;
}


int Freeze::getPriority() const
{
	return PRIORITY5;
}