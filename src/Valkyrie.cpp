#include "Valkyrie.h"

Valkyrie::Valkyrie(const int cardLevel)
{
	m_id = 7;
	m_unlockedInTrophies = 26;
	//m_unlockedInTrophies = 0;
	m_elixirCost = 4;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::VALKYRIE));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { VALKYRIE_UPGRADE_COST_1, VALKYRIE_UPGRADE_COST_2, VALKYRIE_UPGRADE_COST_3, VALKYRIE_UPGRADE_COST_4, VALKYRIE_UPGRADE_COST_5 };

	m_level = cardLevel;

}


int Valkyrie::getPriority() const
{
	return PRIORITY2;
}