#include "Arrows.h"

Arrows::Arrows(const int cardLevel)
{
	m_id = 4;
	m_unlockedInTrophies = 0;
	m_elixirCost = 3;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::ARROWS));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { ARROWS_UPGRADE_COST_1, ARROWS_UPGRADE_COST_2, ARROWS_UPGRADE_COST_3, ARROWS_UPGRADE_COST_4, ARROWS_UPGRADE_COST_5 };

	m_level = cardLevel;

}


int Arrows::getPriority() const
{
	return PRIORITY4;
}

