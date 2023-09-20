#include "Minions.h"

Minions::Minions(const int cardLevel)
{
	m_id = 3;
	m_unlockedInTrophies = 0;
	m_elixirCost = 3;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::MINIONS));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { MINIONS_UPGRADE_COST_1, MINIONS_UPGRADE_COST_2, MINIONS_UPGRADE_COST_3, MINIONS_UPGRADE_COST_4, MINIONS_UPGRADE_COST_5 };

	m_level = cardLevel;

}


int Minions::getPriority() const
{
	return PRIORITY1;
}