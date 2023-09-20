#include "Knight.h"

Knight::Knight(const int cardLevel)
{
	m_id = 1;
	m_unlockedInTrophies = 0;
	m_elixirCost = 4;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::KNIGHT));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { KNIGHT_UPGRADE_COST_1, KNIGHT_UPGRADE_COST_2, KNIGHT_UPGRADE_COST_3, KNIGHT_UPGRADE_COST_4, KNIGHT_UPGRADE_COST_5 };

	m_level = cardLevel;

}


int Knight::getPriority() const
{
	return PRIORITY2;
}