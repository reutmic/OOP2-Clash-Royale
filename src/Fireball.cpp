#include "Fireball.h"

Fireball::Fireball(const int cardLevel)
{
	m_id = 5;
	m_unlockedInTrophies = 0;
	m_elixirCost = 4;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::FIREBALL));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { FIREBALL_UPGRADE_COST_1, FIREBALL_UPGRADE_COST_2, FIREBALL_UPGRADE_COST_3, FIREBALL_UPGRADE_COST_4, FIREBALL_UPGRADE_COST_5 };

	m_level = cardLevel;

}

int Fireball::getPriority() const
{
	return PRIORITY4;
}