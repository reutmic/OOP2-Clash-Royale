#include "Giant.h"

Giant::Giant(const int cardLevel)
{
	m_id = 6;
	m_unlockedInTrophies = 0;
	m_elixirCost = 6;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::GIANT));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { GIANT_UPGRADE_COST_1, GIANT_UPGRADE_COST_2, GIANT_UPGRADE_COST_3, GIANT_UPGRADE_COST_4, GIANT_UPGRADE_COST_5 };

	m_level = cardLevel;

}


int Giant::getPriority() const
{
	return PRIORITY2;
}
