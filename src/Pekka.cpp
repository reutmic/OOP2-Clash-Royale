#include "Pekka.h"

Pekka::Pekka(const int cardLevel)
{
	m_id = 10;
	m_unlockedInTrophies = 110;
	//m_unlockedInTrophies = 0;
	m_elixirCost = 7;
	m_cardImgSprite.setTexture(Resources::instance().getCard(Resources::PEKKA));
	m_cardImgSprite.setScale(m_cardImgScale);

	m_upgradesCosts = { PEKKA_UPGRADE_COST_1, PEKKA_UPGRADE_COST_2, PEKKA_UPGRADE_COST_3, PEKKA_UPGRADE_COST_4, PEKKA_UPGRADE_COST_5 };

	m_level = cardLevel;

}

int Pekka::getPriority() const
{
	return PRIORITY2;
}
