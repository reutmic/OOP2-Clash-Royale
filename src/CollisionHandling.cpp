#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "CollisionHandling.h"

// ----- This class is responsible for handling all the collisions of object's in the game ---- //

namespace
{
    // ********************** bullet **********************
    void bulletArchers(Object& bullet, Object& archers)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);

        if (archers.getLives() > 0 && bull.getHitAction())
        {
            archers.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletKnight(Object& bullet, Object& knight)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);

        if (knt.getLives() > 0 && bull.getHitAction())
        {
            knt.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletMinions(Object& bullet, Object& minions)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (mns.getLives() > 0 && bull.getHitAction())
        {
            mns.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletGiant(Object& bullet, Object& giant)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);

        if (gnt.getLives() > 0 && bull.getHitAction())
        {
            gnt.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletValkyrie(Object& bullet, Object& valkyrie)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (viki.getLives() > 0 && bull.getHitAction())
        {
            viki.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletPekka(Object& bullet, Object& pekka)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);

        if (pek.getLives() > 0 && bull.getHitAction())
        {
            pek.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletDartGoblin(Object& bullet, Object& dartGoblin)
    {
        Bullet& bull = dynamic_cast<Bullet&>(bullet);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (drt.getLives() > 0 && bull.getHitAction())
        {
            drt.decLives(bull.getAtk());
            bull.setHitAction(false);
        }
    }

    void bulletFireball(Object& bullet, Object& fireball)
    {
        // does nothing
    }

    void bulletArrows(Object& bullet, Object& arrows)
    {

        // does nothing
    }

    void bulletFreeze(Object& bullet, Object& freeze)
    {

        // does nothing
    }


    // ********************** fireball **********************
    void fireballPcTerritory(Object& fireball, Object& territory)
    {}

    void fireballPlayerTerritory(Object& fireball, Object& territory)
    {}

    void fireballTower(Object& fireball, Object& tower)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (fire.getHitAction() && !twr.getHitByFireball())
        {
            twr.decLives(fire.getAtk());
            twr.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            twr.setHitByFireball(false);
        }
    }

    void fireballFireball(Object& fireball1, Object& fireball2)
    {
        // does nothing
    }

    void fireballArchers(Object& fireball, Object& archers)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);

        if (fire.getHitAction() && !arch.getHitByFireball())
        {
            arch.decLives(fire.getAtk());
            arch.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            arch.setHitByFireball(false);
        }
    }

    void fireballKnight(Object& fireball, Object& knight)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);

        if (fire.getHitAction() && !knt.getHitByFireball())
        {
            knt.decLives(fire.getAtk());
            knt.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            knt.setHitByFireball(false);
        }
    }

    void fireballMinions(Object& fireball, Object& minions)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (fire.getHitAction() && !mns.getHitByFireball())
        {
            mns.decLives(fire.getAtk());
            mns.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            mns.setHitByFireball(false);
        }
    }

    void fireballGiant(Object& fireball, Object& giant)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);

        if (fire.getHitAction() && !gnt.getHitByFireball())
        {
            gnt.decLives(fire.getAtk());
            gnt.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            gnt.setHitByFireball(false);
        }
    }


    void fireballPekka(Object& fireball, Object& pekka)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        PekkaObj& pk = dynamic_cast<PekkaObj&>(pekka);

        if (fire.getHitAction() && !pk.getHitByFireball())
        {
            pk.decLives(fire.getAtk());
            pk.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            pk.setHitByFireball(false);
        }
    }

    void fireballDartGoblin(Object& fireball, Object& dartGoblin)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (fire.getHitAction() && !drt.getHitByFireball())
        {
            drt.decLives(fire.getAtk());
            drt.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            drt.setHitByFireball(false);
        }
    }

    void fireballValkyrie(Object& fireball, Object& valkyrie)
    {
        FireballObj& fire = dynamic_cast<FireballObj&>(fireball);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (fire.getHitAction() && !viki.getHitByFireball())
        {
            viki.decLives(fire.getAtk());
            viki.setHitByFireball(true);
        }

        if (!fire.getHitAction())
        {
            viki.setHitByFireball(false);
        }
    }

    void fireballBullet(Object& fireball, Object& bullet)
    {
        bulletFireball(bullet, fireball);
    }

    void fireballArrows(Object& fireball, Object& arrows)
    {
        // does nothing
    }

    void fireballFreeze(Object& fireball, Object& freeze)
    {
        // does nothing
    }


    // ********************** arrows **********************
    void arrowsPcTerritory(Object& arrow, Object& territory)
    {
        // does nothing
    }

    void arrowsPlayerTerritory(Object& arrows, Object& territory)
    {
        // does nothing
    }

    void arrowsArrows(Object& arrows1, Object& arrows2)
    {
        // does nothing
    }

    void arrowsTower(Object& arrows, Object& tower)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (arw.getHitAction() && !twr.getHitByArrows())
        {
            twr.decLives(arw.getAtk());
            twr.setHitByArrows(true);
        }

        if (!arw.getHitAction())
        {
            twr.setHitByArrows(false);
        }
    }

    void arrowsBullet(Object& arrows, Object& bullet)
    {
        bulletArrows(bullet, arrows);
    }

    void arrowsFireball(Object& fireball, Object& arrows)
    {
        fireballArrows(fireball, arrows);
    }

    void arrowsArchers(Object& arrows, Object& archers)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);

        if (arw.getHitAction() && !arch.getHitByArrows())
        {
            arch.decLives(arw.getAtk());
            arw.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            arch.setHitByArrows(false);
        }
    }

    void arrowsKnight(Object& arrows, Object& knight)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);

        if (arw.getHitAction() && !knt.getHitByArrows())
        {
            knt.decLives(arw.getAtk());
            arw.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            knt.setHitByArrows(false);
        }
    }

    void arrowsMinions(Object& arrows, Object& minions)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (arw.getHitAction() && !mns.getHitByArrows())
        {
            mns.decLives(arw.getAtk());
            arw.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            mns.setHitByArrows(false);
        }
    }


    void arrowsGiant(Object& arrows, Object& giant)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);

        if (arw.getHitAction() && !gnt.getHitByArrows())
        {
            gnt.decLives(arw.getAtk());
            arw.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            gnt.setHitByArrows(false);
        }
    }


    void arrowsPekka(Object& arrows, Object& pekka)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        PekkaObj& pk = dynamic_cast<PekkaObj&>(pekka);

        if (arrows.getHitAction() && !pk.getHitByArrows())
        {
            pk.decLives(arrows.getAtk());
            arrows.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            pk.setHitByArrows(false);
        }
    }

    void arrowsDartGoblin(Object& arrows, Object& dartGoblin)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (arw.getHitAction() && !drt.getHitByArrows())
        {
            drt.decLives(arw.getAtk());
            arw.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            drt.setHitByArrows(false);
        }
    }

    void arrowsValkyrie(Object& arrows, Object& valkyrie)
    {
        ArrowsObj& arw = dynamic_cast<ArrowsObj&>(arrows);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (arw.getHitAction() && !viki.getHitByArrows())
        {
            viki.decLives(arw.getAtk());
            arw.setHitAction(false);
        }

        if (!arw.getHitAction())
        {
            viki.setHitByArrows(false);
        }
    }

    void arrowsFreeze(Object& arrows, Object& freeze)
    {
        // does nothing
    }


    // ********************** freeze **********************
    void freezePcTerritory(Object& freeze, Object& territory)
    {}

    void freezePlayerTerritory(Object& freeze, Object& territory)
    {}

    void freezeTower(Object& freeze, Object& tower)
    {
        // does nothing
    }

    void freezeFireball(Object& freeze, Object& fireball)
    {
        // does nothing
    }

    void freezeArchers(Object& freeze, Object& archers)
    {

        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);

        //  if (frz.getHitAction())
        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            arch.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            arch.setFrozenState(false);
            frz.setLives();
        }
    }

    void freezeKnight(Object& freeze, Object& knight)
    {
        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);

        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            knt.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            knt.setFrozenState(false);
            frz.setLives();
        }
    }

    void freezeMinions(Object& freeze, Object& minions)
    {
        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            mns.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            mns.setFrozenState(false);
            frz.setLives();
        }
    }

    void freezeGiant(Object& freeze, Object& giant)
    {
        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);

        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            gnt.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            gnt.setFrozenState(false);
            frz.setLives();
        }
    }


    void freezePekka(Object& freeze, Object& pekka)
    {
        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        PekkaObj& pk = dynamic_cast<PekkaObj&>(pekka);

        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            pk.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            pk.setFrozenState(false);
            frz.setLives();
        }
    }

    void freezeDartGoblin(Object& freeze, Object& dartGoblin)
    {
        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            drt.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            drt.setFrozenState(false);
            frz.setLives();
        }
    }

    void freezeValkyrie(Object& freeze, Object& valkyrie)
    {
        FreezeObj& frz = dynamic_cast<FreezeObj&>(freeze);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (frz.getFrozenAmount() < frz.getMaxAffectedTroops())
        {
            viki.setFrozenState(true);
            frz.addToFrozenAmount();
            //      frz.setHitAction(false);
        }

        if (frz.getFinishedFreezingAction())
        {
            viki.setFrozenState(false);
            frz.setLives();
        }
    }

    void freezeBullet(Object& freeze, Object& bullet)
    {
        bulletFireball(bullet, freeze);
    }

    void freezeArrows(Object& freeze, Object& arrows)
    {
        // does nothing
    }

    void freezeFreeze(Object& freeze1, Object& freeze2)
    {
        // does nothing
    }




    // ********************** archers **********************
    void archersTower(Object& archers, Object& tower)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (arch.getLives() > 0 && twr.getLives() > 0 && arch.getHitAction())
        {
            twr.decLives(archers.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersArchers(Object& archers1, Object& archers2)
    {
        ArchersObj& arch1 = dynamic_cast<ArchersObj&>(archers1);
        ArchersObj& arch2 = dynamic_cast<ArchersObj&>(archers2);

        if (arch1.getLives() > 0 && arch2.getLives() > 0 && arch1.getHitAction())
        {
            arch2.decLives(arch1.getAtk());
            arch1.decLives(arch2.getAtk());
            arch1.setHitAction(false);
        }
    }

    void archersGiant(Object& archers, Object& giant)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);

        if (arch.getLives() > 0 && gnt.getLives() > 0 && arch.getHitAction())
        {
            gnt.decLives(arch.getAtk());
            arch.decLives(gnt.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersKnight(Object& archers, Object& knight)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);

        if (arch.getLives() > 0 && knt.getLives() > 0 && arch.getHitAction())
        {
            knt.decLives(arch.getAtk());
            arch.decLives(knight.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersMinions(Object& archers, Object& minions)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (arch.getLives() > 0 && mns.getLives() > 0 && arch.getHitAction())
        {
            arch.decLives(mns.getAtk());
            mns.decLives(arch.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersPekka(Object& archers, Object& pekka)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);

        if (arch.getLives() > 0 && pek.getLives() > 0 && arch.getHitAction())
        {
            pek.decLives(arch.getAtk());
            arch.decLives(pek.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersValkyrie(Object& archers, Object& valkyrie)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (arch.getLives() > 0 && viki.getLives() > 0 && arch.getHitAction())
        {
            viki.decLives(arch.getAtk());
            arch.decLives(viki.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersDartGoblin(Object& archers, Object& dartGoblin)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (arch.getLives() > 0 && drt.getLives() > 0 && arch.getHitAction())
        {
            drt.decLives(arch.getAtk());
            arch.decLives(drt.getAtk());
            arch.setHitAction(false);
        }
    }

    void archersFireball(Object& archers, Object& fireball)
    {
        fireballArchers(fireball, archers);
    }

    void archersArrows(Object& archers, Object& arrows)
    {
        arrowsArchers(arrows, archers);
    }

    void archersFreeze(Object& archers, Object& freeze)
    {
        freezeArchers(freeze, archers);
    }

    void archersPcTerritory(Object& archers, Object& territory)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        arch.setPcTerritoryCollision(true);
    }

    void archersPlayerTerritory(Object& archers, Object& territory)
    {
        ArchersObj& arch = dynamic_cast<ArchersObj&>(archers);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        arch.setPlayerTerritoryCollision(true);
    }

    void archersBullet(Object& archers, Object& bullet)
    {
        bulletArchers(bullet, archers);
    }


    // ********************** knight **********************
    void knightTower(Object& knight, Object& tower)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (knight.getLives() > 0 && tower.getLives() > 0 && knight.getHitAction())
        {
            tower.decLives(knight.getAtk());
            knight.setHitAction(false);
        }
    }

    void knightKnight(Object& knight1, Object& knight2)
    {
        KnightObj& knt1 = dynamic_cast<KnightObj&>(knight1);
        KnightObj& knt2 = dynamic_cast<KnightObj&>(knight2);

        if (knt1.getLives() > 0 && knt2.getLives() > 0 && knt1.getHitAction())
        {
            knt2.decLives(knt1.getAtk());
            knt1.decLives(knt2.getAtk());
            knt1.setHitAction(false);
        }
    }

    void knightGiant(Object& knight, Object& giant)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);

        if (knt.getLives() > 0 && gnt.getLives() > 0 && knt.getHitAction())
        {
            gnt.decLives(knt.getAtk());
            knt.decLives(gnt.getAtk());
            knt.setHitAction(false);
        }
    }

    void knightArchers(Object& knight, Object& archers)
    {
        archersKnight(archers, knight);
    }

    void knightMinions(Object& knight, Object& minions)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (knt.getLives() > 0 && mns.getLives() > 0 && mns.getHitAction())
        {
            knt.decLives(mns.getAtk());
            mns.setHitAction(false);
        }
    }

    void knightPekka(Object& knight, Object& pekka)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);

        if (knt.getLives() > 0 && pek.getLives() > 0 && knt.getHitAction())
        {
            pek.decLives(knt.getAtk());
            knt.decLives(pek.getAtk());
            knt.setHitAction(false);
        }
    }

    void knightValkyrie(Object& knight, Object& valkyrie)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (knt.getLives() > 0 && viki.getLives() > 0 && knt.getHitAction())
        {
            viki.decLives(knt.getAtk());
            knt.decLives(viki.getAtk());
            knt.setHitAction(false);
        }
    }

    void knightDartGoblin(Object& knight, Object& dartGoblin)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (knt.getLives() > 0 && drt.getLives() > 0 && knt.getHitAction())
        {
            drt.decLives(knt.getAtk());
            knt.decLives(drt.getAtk());
            knt.setHitAction(false);
        }
    }

    void knightFireball(Object& knight, Object& fireball)
    {
        fireballKnight(fireball, knight);
    }

    void knightArrows(Object& knight, Object& arrows)
    {
        arrowsKnight(arrows, knight);
    }

    void knightFreeze(Object& knight, Object& freeze)
    {
        freezeKnight(freeze, knight);
    }

    void knightPcTerritory(Object& knight, Object& territory)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        knt.setPcTerritoryCollision(true);
    }

    void knightPlayerTerritory(Object& knight, Object& territory)
    {
        KnightObj& knt = dynamic_cast<KnightObj&>(knight);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        knt.setPlayerTerritoryCollision(true);
    }

    void knightBullet(Object& knight, Object& bullet)
    {
        bulletKnight(bullet, knight);
    }


    // ********************** giant **********************
    void giantTower(Object& giant, Object& tower)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (giant.getLives() > 0 && tower.getLives() > 0 && giant.getHitAction())
        {
            tower.decLives(giant.getAtk());
            giant.setHitAction(false);
        }
    }

    void giantGiant(Object& giant1, Object& giant2)
    {
        GiantObj& gnt1 = dynamic_cast<GiantObj&>(giant1);
        GiantObj& gnt2 = dynamic_cast<GiantObj&>(giant2);

        if (gnt1.getLives() > 0 && gnt2.getLives() > 0 && gnt1.getHitAction())
        {
            gnt2.decLives(gnt1.getAtk());
            gnt1.decLives(gnt2.getAtk());
            gnt1.setHitAction(false);
        }
    }

    void giantMinions(Object& giant, Object& minions)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);

        if (mns.getLives() > 0 && gnt.getLives() > 0 && mns.getHitAction())
        {
            gnt.decLives(mns.getAtk());
            mns.setHitAction(false);
        }
    }

    void giantArchers(Object& giant, Object& archers)
    {
        archersGiant(archers, giant);
    }

    void giantKnight(Object& giant, Object& knight)
    {
        knightGiant(knight, giant);
    }

    void giantPekka(Object& giant, Object& pekka)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);

        if (gnt.getLives() > 0 && pek.getLives() > 0 && gnt.getHitAction())
        {
            pek.decLives(gnt.getAtk());
            gnt.decLives(pek.getAtk());
            gnt.setHitAction(false);
        }
    }

    void giantValkyrie(Object& giant, Object& valkyrie)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (gnt.getLives() > 0 && viki.getLives() > 0 && gnt.getHitAction())
        {
            viki.decLives(gnt.getAtk());
            gnt.decLives(viki.getAtk());
            gnt.setHitAction(false);
        }
    }

    void giantDartGoblin(Object& giant, Object& dartGoblin)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (gnt.getLives() > 0 && drt.getLives() > 0 && gnt.getHitAction())
        {
            drt.decLives(gnt.getAtk());
            gnt.decLives(drt.getAtk());
            gnt.setHitAction(false);
        }
    }

    void giantFireball(Object& giant, Object& fireball)
    {
        fireballGiant(fireball, giant);
    }

    void giantArrows(Object& giant, Object& arrows)
    {
        arrowsGiant(arrows, giant);
    }

    void giantFreeze(Object& giant, Object& freeze)
    {
        freezeGiant(freeze, giant);
    }

    void giantPcTerritory(Object& giant, Object& territory)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        gnt.setPcTerritoryCollision(true);
    }

    void giantPlayerTerritory(Object& giant, Object& territory)
    {
        GiantObj& gnt = dynamic_cast<GiantObj&>(giant);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        gnt.setPlayerTerritoryCollision(true);
    }

    void giantBullet(Object& giant, Object& bullet)
    {
        bulletGiant(bullet, giant);
    }



    // ********************** minions **********************
    void minionsTower(Object& minions, Object& tower)
    {
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (mns.getLives() > 0 && twr.getLives() > 0 && mns.getHitAction())
        {
            twr.decLives(mns.getAtk());
            mns.setHitAction(false);
        }
    }

    void minionsMinions(Object& minions1, Object& minions2)
    {
        MinionsObj& mns1 = dynamic_cast<MinionsObj&>(minions1);
        MinionsObj& mns2 = dynamic_cast<MinionsObj&>(minions2);

        if (mns1.getLives() > 0 && mns2.getLives() > 0 && mns1.getHitAction())
        {
            mns2.decLives(mns1.getAtk());
            mns1.decLives(mns2.getAtk());
            mns1.setHitAction(false);
        }
    }

    void minionsGiant(Object& minions, Object& giant)
    {
        giantMinions(giant, minions);
    }

    void minionsArchers(Object& minions, Object& archers)
    {
        archersMinions(archers, minions);
    }

    void minionsKnight(Object& minions, Object& knight)
    {
        knightMinions(knight, minions);
    }

    void minionsPekka(Object& minions, Object& pekka)
    {
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);

        if (mns.getLives() > 0 && pek.getLives() > 0 && mns.getHitAction())
        {
            pek.decLives(mns.getAtk());
            mns.setHitAction(false);
        }
    }

    void minionsValkyrie(Object& minions, Object& valkyrie)
    {
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);

        if (mns.getLives() > 0 && viki.getLives() > 0 && mns.getHitAction())
        {
            viki.decLives(mns.getAtk());
            mns.setHitAction(false);
        }
    }

    void minionsDartGoblin(Object& minions, Object& dartGoblin)
    {
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (mns.getLives() > 0 && drt.getLives() > 0 && mns.getHitAction())
        {
            drt.decLives(mns.getAtk());
            mns.decLives(drt.getAtk());
            mns.setHitAction(false);
        }
    }

    void minionsFireball(Object& minions, Object& fireball)
    {
        fireballMinions(fireball, minions);
    }

    void minionsArrows(Object& minions, Object& arrows)
    {
        arrowsMinions(arrows, minions);
    }

    void minionsFreeze(Object& minions, Object& freeze)
    {
        freezeMinions(freeze, minions);
    }

    void minionsPcTerritory(Object& minions, Object& territory)
    {
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        mns.setPcTerritoryCollision(true);
    }

    void minionsPlayerTerritory(Object& minions, Object& territory)
    {
        MinionsObj& mns = dynamic_cast<MinionsObj&>(minions);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        mns.setPlayerTerritoryCollision(true);
    }

    void minionsBullet(Object& minions, Object& bullet)
    {
        bulletMinions(bullet, minions);
    }


    // ********************** valkyrie **********************
    void valkyrieTower(Object& valkyrie, Object& tower)
    {
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (viki.getLives() > 0 && twr.getLives() > 0 && viki.getHitAction())
        {
            twr.decLives(viki.getAtk());
            viki.setHitAction(false);
        }
    }

    void valkyrieValkyrie(Object& valkyrie1, Object& valkyrie2)
    {
        ValkyrieObj& viki1 = dynamic_cast<ValkyrieObj&>(valkyrie1);
        ValkyrieObj& viki2 = dynamic_cast<ValkyrieObj&>(valkyrie2);

        if (viki1.getLives() > 0 && viki2.getLives() > 0 && viki1.getHitAction())
        {
            viki2.decLives(viki1.getAtk());
            viki1.decLives(viki2.getAtk());
            viki1.setHitAction(false);
        }
    }

    void valkyrieGiant(Object& valkyrie, Object& giant)
    {
        giantValkyrie(giant, valkyrie);
    }

    void valkyrieArchers(Object& valkyrie, Object& archers)
    {
        archersValkyrie(archers, valkyrie);
    }

    void valkyrieKnight(Object& valkyrie, Object& knight)
    {
        knightValkyrie(knight, valkyrie);
    }

    void valkyriePekka(Object& valkyrie, Object& pekka)
    {
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);

        if (viki.getLives() > 0 && pek.getLives() > 0 && viki.getHitAction())
        {
            pek.decLives(viki.getAtk());
            viki.decLives(pekka.getAtk());
            viki.setHitAction(false);
        }
    }

    void valkyrieMinions(Object& valkyrie, Object& minions)
    {
        minionsValkyrie(minions, valkyrie);
    }

    void valkyrieFireball(Object& valkyrie, Object& fireball)
    {
        fireballValkyrie(fireball, valkyrie);
    }

    void valkyrieArrows(Object& valkyrie, Object& arrows)
    {
        arrowsValkyrie(arrows, valkyrie);
    }

    void valkyrieFreeze(Object& valkyrie, Object& freeze)
    {
        freezeValkyrie(freeze, valkyrie);
    }

    void valkyrieDartGoblin(Object& valkyrie, Object& dartGoblin)
    {
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (viki.getLives() > 0 && drt.getLives() > 0 && viki.getHitAction())
        {
            drt.decLives(viki.getAtk());
            viki.decLives(drt.getAtk());
            viki.setHitAction(false);
        }
    }

    void valkyriePcTerritory(Object& valkyrie, Object& territory)
    {
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        viki.setPcTerritoryCollision(true);
    }

    void valkyriePlayerTerritory(Object& valkyrie, Object& territory)
    {
        ValkyrieObj& viki = dynamic_cast<ValkyrieObj&>(valkyrie);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        viki.setPlayerTerritoryCollision(true);
    }

    void valkyrieBullet(Object& valkyrie, Object& bullet)
    {
        bulletValkyrie(bullet, valkyrie);
    }


    // ********************** pekka **********************
    void pekkaTower(Object& pekka, Object& tower)
    {
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (pek.getLives() > 0 && twr.getLives() > 0 && pek.getHitAction())
        {
            twr.decLives(pek.getAtk());
            pek.setHitAction(false);
        }
    }

    void pekkaPekka(Object& pekka1, Object& pekka2)
    {
        PekkaObj& pek1 = dynamic_cast<PekkaObj&>(pekka1);
        PekkaObj& pek2 = dynamic_cast<PekkaObj&>(pekka2);

        if (pek1.getLives() > 0 && pek2.getLives() > 0 && pek1.getHitAction())
        {
            pek2.decLives(pek1.getAtk());
            pek1.decLives(pek2.getAtk());
            pek1.setHitAction(false);
        }
    }

    void pekkaGiant(Object& pekka, Object& giant)
    {
        giantPekka(giant, pekka);
    }

    void pekkaArchers(Object& pekka, Object& archers)
    {
        archersPekka(archers, pekka);
    }

    void pekkaKnight(Object& pekka, Object& knight)
    {
        knightPekka(knight, pekka);
    }

    void pekkaValkyrie(Object& pekka, Object& valkyrie)
    {
        valkyriePekka(valkyrie, pekka);
    }

    void pekkaMinions(Object& pekka, Object& minions)
    {
        minionsPekka(minions, pekka);
    }

    void pekkaFireball(Object& pekka, Object& fireball)
    {
        fireballPekka(fireball, pekka);
    }

    void pekkaArrows(Object& pekka, Object& arrows)
    {
        arrowsPekka(arrows, pekka);
    }

    void pekkaFreeze(Object& pekka, Object& freeze)
    {
        freezePekka(freeze, pekka);
    }

    void pekkaDartGoblin(Object& pekka, Object& dartGoblin)
    {
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);

        if (pek.getLives() > 0 && drt.getLives() > 0 && pek.getHitAction())
        {
            drt.decLives(pek.getAtk());
            pek.decLives(drt.getAtk());
            pek.setHitAction(false);
        }
    }

    void pekkaPcTerritory(Object& pekka, Object& territory)
    {
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        pek.setPcTerritoryCollision(true);
    }

    void pekkaPlayerTerritory(Object& pekka, Object& territory)
    {
        PekkaObj& pek = dynamic_cast<PekkaObj&>(pekka);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        pek.setPlayerTerritoryCollision(true);
    }

    void pekkaBullet(Object& pekka, Object& bullet)
    {
        bulletPekka(bullet, pekka);
    }


    // ********************** dart goblin **********************
    void dartGoblinTower(Object& dartGoblin, Object& tower)
    {
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);
        Tower& twr = dynamic_cast<Tower&>(tower);

        if (drt.getLives() > 0 && twr.getLives() > 0 && drt.getHitAction())
        {
            twr.decLives(drt.getAtk());
            drt.setHitAction(false);
        }
    }

    void dartGoblinDartGoblin(Object& dartGoblin1, Object& dartGoblin2)
    {
        DartGoblinObj& drt1 = dynamic_cast<DartGoblinObj&>(dartGoblin1);
        DartGoblinObj& drt2 = dynamic_cast<DartGoblinObj&>(dartGoblin2);

        if (drt1.getLives() > 0 && drt2.getLives() > 0 && drt1.getHitAction())
        {
            drt2.decLives(drt1.getAtk());
            drt1.decLives(drt2.getAtk());
            drt1.setHitAction(false);
        }
    }

    void dartGoblinGiant(Object& dartGoblin, Object& giant)
    {
        giantDartGoblin(giant, dartGoblin);
    }

    void dartGoblinArchers(Object& dartGoblin, Object& archers)
    {
        archersDartGoblin(archers, dartGoblin);
    }

    void dartGoblinKnight(Object& dartGoblin, Object& knight)
    {
        knightDartGoblin(knight, dartGoblin);
    }

    void dartGoblinValkyrie(Object& dartGoblin, Object& valkyrie)
    {
        valkyrieDartGoblin(valkyrie, dartGoblin);
    }

    void dartGoblinMinions(Object& dartGoblin, Object& minions)
    {
        minionsDartGoblin(minions, dartGoblin);
    }

    void dartGoblinPekka(Object& dartGoblin, Object& pekka)
    {
        pekkaDartGoblin(pekka, dartGoblin);
    }

    void dartGoblinFireball(Object& dartGoblin, Object& fireball)
    {
        fireballDartGoblin(fireball, dartGoblin);
    }

    void dartGoblinArrows(Object& dartGoblin, Object& arrows)
    {
        arrowsDartGoblin(arrows, dartGoblin);
    }

    void dartGoblinFreeze(Object& dartGoblin, Object& freeze)
    {
        freezeDartGoblin(freeze, dartGoblin);
    }

    void dartGoblinPcTerritory(Object& dartGoblin, Object& territory)
    {
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);
        PcTerritory& terr = dynamic_cast<PcTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        drt.setPcTerritoryCollision(true);
    }

    void dartGoblinPlayerTerritory(Object& dartGoblin, Object& territory)
    {
        DartGoblinObj& drt = dynamic_cast<DartGoblinObj&>(dartGoblin);
        PlayerTerritory& terr = dynamic_cast<PlayerTerritory&>(territory);

        terr.setCollidedWithTerritory(true);
        drt.setPlayerTerritoryCollision(true);
    }

    void dartGoblinBullet(Object& dartGoblin, Object& bullet)
    {
        bulletDartGoblin(bullet, dartGoblin);
    }


    // ********************** tower **********************
    void towerArchers(Object& tower, Object& archers)
    {
        archersTower(archers, tower);
    }

    void towerKnight(Object& tower, Object& knight)
    {
        knightTower(knight, tower);
    }

    void towerMinions(Object& tower, Object& minions)
    {
        minionsTower(minions, tower);
    }

    void towerGiant(Object& tower, Object& giant)
    {
        giantTower(giant, tower);
    }

    void towerPekka(Object& tower, Object& pekka)
    {
        pekkaTower(pekka, tower);
    }

    void towerFireball(Object& tower, Object& fireball)
    {
        fireballTower(fireball, tower);
    }

    void towerArrows(Object& tower, Object& arrows)
    {
        arrowsTower(arrows, tower);
    }

    void towerDartGoblin(Object& tower, Object& dartGoblin)
    {
        dartGoblinTower(dartGoblin, tower);
    }

    void towerValkyrie(Object& tower, Object& valkyrie)
    {
        valkyrieTower(valkyrie, tower);
    }

    void towerFreeze(Object& tower, Object& freeze)
    {
        freezeTower(freeze, tower);
    }


    // ********************** pcTerritory **********************
    void pcTerritoryArchers(Object& territory, Object& archers)
    {
        archersPcTerritory(archers, territory);
    }

    void pcTerritoryKnight(Object& territory, Object& knight)
    {
        knightPcTerritory(knight, territory);
    }

    void pcTerritoryMinions(Object& territory, Object& minions)
    {
        minionsPcTerritory(minions, territory);
    }

    void pcTerritoryGiant(Object& territory, Object& giant)
    {
        giantPcTerritory(giant, territory);
    }

    void pcTerritoryPekka(Object& territory, Object& pekka)
    {
        pekkaPcTerritory(pekka, territory);
    }

    void pcTerritoryDartGoblin(Object& territory, Object& dartGoblin)
    {
        dartGoblinPcTerritory(dartGoblin, territory);
    }

    void pcTerritoryValkyrie(Object& territory, Object& valkyrie)
    {
        valkyriePcTerritory(valkyrie, territory);
    }

    void pcTerritoryFireball(Object& territory, Object& fireball)
    {
        fireballPcTerritory(fireball, territory);
    }

    void pcTerritoryArrows(Object& territory, Object& arrows)
    {
        arrowsPcTerritory(arrows, territory);
    }

    void pcTerritoryFreeze(Object& territory, Object& freeze)
    {
        freezePcTerritory(freeze, territory);
    }


    // ********************** playerTerritory **********************
    void playerTerritoryArchers(Object& territory, Object& archers)
    {
        archersPlayerTerritory(archers, territory);
    }

    void playerTerritoryKnight(Object& territory, Object& knight)
    {
        knightPlayerTerritory(knight, territory);
    }

    void playerTerritoryMinions(Object& territory, Object& minions)
    {
        minionsPlayerTerritory(minions, territory);
    }

    void playerTerritoryGiant(Object& territory, Object& giant)
    {
        giantPlayerTerritory(giant, territory);
    }

    void playerTerritoryDartGoblin(Object& territory, Object& dartGoblin)
    {
        dartGoblinPlayerTerritory(dartGoblin, territory);
    }

    void playerTerritoryPekka(Object& territory, Object& pekka)
    {
        pekkaPlayerTerritory(pekka, territory);
    }

    void playerTerritoryValkyrie(Object& territory, Object& valkyrie)
    {
        valkyriePlayerTerritory(valkyrie, territory);
    }

    void playerTerritoryFireball(Object& territory, Object& fireball)
    {
        fireballPlayerTerritory(fireball, territory);
    }

    void playerTerritoryArrows(Object& territory, Object& arrows)
    {
        arrowsPlayerTerritory(arrows, territory);
    }

    void playerTerritoryFreeze(Object& territory, Object& freeze)
    {
        freezePlayerTerritory(freeze, territory);
    }


    using HitFunctionPtr = std::function<void(Object&, Object&)>;
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Bullet), typeid(ArchersObj))] = &bulletArchers;
        phm[Key(typeid(Bullet), typeid(KnightObj))] = &bulletKnight;
        phm[Key(typeid(Bullet), typeid(MinionsObj))] = &bulletMinions;
        phm[Key(typeid(Bullet), typeid(GiantObj))] = &bulletGiant;
        phm[Key(typeid(Bullet), typeid(ValkyrieObj))] = &bulletValkyrie;
        phm[Key(typeid(Bullet), typeid(PekkaObj))] = &bulletPekka;
        phm[Key(typeid(Bullet), typeid(DartGoblinObj))] = &bulletDartGoblin;
        phm[Key(typeid(Bullet), typeid(FireballObj))] = &bulletFireball;
        phm[Key(typeid(Bullet), typeid(ArrowsObj))] = &bulletArrows;
        phm[Key(typeid(Bullet), typeid(FreezeObj))] = &bulletFreeze;

        phm[Key(typeid(FireballObj), typeid(FireballObj))] = &fireballFireball;
        phm[Key(typeid(FireballObj), typeid(Tower))] = &fireballTower;
        phm[Key(typeid(FireballObj), typeid(ArchersObj))] = &fireballArchers;
        phm[Key(typeid(FireballObj), typeid(GiantObj))] = &fireballGiant;
        phm[Key(typeid(FireballObj), typeid(KnightObj))] = &fireballKnight;
        phm[Key(typeid(FireballObj), typeid(MinionsObj))] = &fireballMinions;
        phm[Key(typeid(FireballObj), typeid(PekkaObj))] = &fireballPekka;
        phm[Key(typeid(FireballObj), typeid(ValkyrieObj))] = &fireballValkyrie;
        phm[Key(typeid(FireballObj), typeid(DartGoblinObj))] = &fireballDartGoblin;
        phm[Key(typeid(FireballObj), typeid(ArrowsObj))] = &fireballArrows;
        phm[Key(typeid(FireballObj), typeid(FreezeObj))] = &fireballFreeze;
        phm[Key(typeid(FireballObj), typeid(PcTerritory))] = &fireballPcTerritory;
        phm[Key(typeid(FireballObj), typeid(PlayerTerritory))] = &fireballPlayerTerritory;
        phm[Key(typeid(FireballObj), typeid(Bullet))] = &fireballBullet;

        phm[Key(typeid(ArrowsObj), typeid(ArrowsObj))] = &arrowsArrows;
        phm[Key(typeid(ArrowsObj), typeid(FreezeObj))] = &arrowsFreeze;
        phm[Key(typeid(ArrowsObj), typeid(FireballObj))] = &arrowsFireball;
        phm[Key(typeid(ArrowsObj), typeid(Tower))] = &arrowsTower;
        phm[Key(typeid(ArrowsObj), typeid(ArchersObj))] = &arrowsArchers;
        phm[Key(typeid(ArrowsObj), typeid(GiantObj))] = &arrowsGiant;
        phm[Key(typeid(ArrowsObj), typeid(KnightObj))] = &arrowsKnight;
        phm[Key(typeid(ArrowsObj), typeid(MinionsObj))] = &arrowsMinions;
        phm[Key(typeid(ArrowsObj), typeid(PekkaObj))] = &arrowsPekka;
        phm[Key(typeid(ArrowsObj), typeid(ValkyrieObj))] = &arrowsValkyrie;
        phm[Key(typeid(ArrowsObj), typeid(DartGoblinObj))] = &arrowsDartGoblin;
        phm[Key(typeid(ArrowsObj), typeid(PcTerritory))] = &arrowsPcTerritory;
        phm[Key(typeid(ArrowsObj), typeid(PlayerTerritory))] = &arrowsPlayerTerritory;
        phm[Key(typeid(ArrowsObj), typeid(Bullet))] = &arrowsBullet;

        phm[Key(typeid(FreezeObj), typeid(FireballObj))] = &freezeFireball;
        phm[Key(typeid(FreezeObj), typeid(Tower))] = &freezeTower;
        phm[Key(typeid(FreezeObj), typeid(ArchersObj))] = &freezeArchers;
        phm[Key(typeid(FreezeObj), typeid(GiantObj))] = &freezeGiant;
        phm[Key(typeid(FreezeObj), typeid(KnightObj))] = &freezeKnight;
        phm[Key(typeid(FreezeObj), typeid(MinionsObj))] = &freezeMinions;
        phm[Key(typeid(FreezeObj), typeid(PekkaObj))] = &freezePekka;
        phm[Key(typeid(FreezeObj), typeid(ValkyrieObj))] = &freezeValkyrie;
        phm[Key(typeid(FreezeObj), typeid(DartGoblinObj))] = &freezeDartGoblin;
        phm[Key(typeid(FreezeObj), typeid(ArrowsObj))] = &freezeArrows;
        phm[Key(typeid(FreezeObj), typeid(FreezeObj))] = &freezeFreeze;
        phm[Key(typeid(FreezeObj), typeid(PcTerritory))] = &freezePcTerritory;
        phm[Key(typeid(FreezeObj), typeid(PlayerTerritory))] = &freezePlayerTerritory;
        phm[Key(typeid(FreezeObj), typeid(Bullet))] = &freezeBullet;

        phm[Key(typeid(ArchersObj), typeid(Tower))] = &archersTower;
        phm[Key(typeid(ArchersObj), typeid(ArchersObj))] = &archersArchers;
        phm[Key(typeid(ArchersObj), typeid(GiantObj))] = &archersGiant;
        phm[Key(typeid(ArchersObj), typeid(KnightObj))] = &archersKnight;
        phm[Key(typeid(ArchersObj), typeid(MinionsObj))] = &archersMinions;
        phm[Key(typeid(ArchersObj), typeid(PekkaObj))] = &archersPekka;
        phm[Key(typeid(ArchersObj), typeid(ValkyrieObj))] = &archersValkyrie;
        phm[Key(typeid(ArchersObj), typeid(ArrowsObj))] = &archersArrows;
        phm[Key(typeid(ArchersObj), typeid(FreezeObj))] = &archersFreeze;
        phm[Key(typeid(ArchersObj), typeid(FireballObj))] = &archersFireball;
        phm[Key(typeid(ArchersObj), typeid(DartGoblinObj))] = &archersDartGoblin;
        phm[Key(typeid(ArchersObj), typeid(PcTerritory))] = &archersPcTerritory;
        phm[Key(typeid(ArchersObj), typeid(PlayerTerritory))] = &archersPlayerTerritory;
        phm[Key(typeid(ArchersObj), typeid(Bullet))] = &archersBullet;

        phm[Key(typeid(MinionsObj), typeid(Tower))] = &minionsTower;
        phm[Key(typeid(MinionsObj), typeid(MinionsObj))] = &minionsMinions;
        phm[Key(typeid(MinionsObj), typeid(GiantObj))] = &minionsGiant;
        phm[Key(typeid(MinionsObj), typeid(ArchersObj))] = &minionsArchers;
        phm[Key(typeid(MinionsObj), typeid(KnightObj))] = &minionsKnight;
        phm[Key(typeid(MinionsObj), typeid(PekkaObj))] = &minionsPekka;
        phm[Key(typeid(MinionsObj), typeid(ValkyrieObj))] = &minionsValkyrie;
        phm[Key(typeid(MinionsObj), typeid(FireballObj))] = &minionsFireball;
        phm[Key(typeid(MinionsObj), typeid(ArrowsObj))] = &minionsArrows;
        phm[Key(typeid(MinionsObj), typeid(FreezeObj))] = &minionsFreeze;
        phm[Key(typeid(MinionsObj), typeid(DartGoblinObj))] = &minionsDartGoblin;
        phm[Key(typeid(MinionsObj), typeid(PcTerritory))] = &minionsPcTerritory;
        phm[Key(typeid(MinionsObj), typeid(PlayerTerritory))] = &minionsPlayerTerritory;
        phm[Key(typeid(MinionsObj), typeid(Bullet))] = &minionsBullet;

        phm[Key(typeid(KnightObj), typeid(Tower))] = &knightTower;
        phm[Key(typeid(KnightObj), typeid(KnightObj))] = &knightKnight;
        phm[Key(typeid(KnightObj), typeid(GiantObj))] = &knightGiant;
        phm[Key(typeid(KnightObj), typeid(ArchersObj))] = &knightArchers;
        phm[Key(typeid(KnightObj), typeid(MinionsObj))] = &knightMinions;
        phm[Key(typeid(KnightObj), typeid(PekkaObj))] = &knightPekka;
        phm[Key(typeid(KnightObj), typeid(ValkyrieObj))] = &knightValkyrie;
        phm[Key(typeid(KnightObj), typeid(DartGoblinObj))] = &knightDartGoblin;
        phm[Key(typeid(KnightObj), typeid(FireballObj))] = &knightFireball;
        phm[Key(typeid(KnightObj), typeid(ArrowsObj))] = &knightArrows;
        phm[Key(typeid(KnightObj), typeid(FreezeObj))] = &knightFreeze;
        phm[Key(typeid(KnightObj), typeid(PcTerritory))] = &knightPcTerritory;
        phm[Key(typeid(KnightObj), typeid(PlayerTerritory))] = &knightPlayerTerritory;
        phm[Key(typeid(KnightObj), typeid(Bullet))] = &knightBullet;

        phm[Key(typeid(GiantObj), typeid(Tower))] = &giantTower;
        phm[Key(typeid(GiantObj), typeid(GiantObj))] = &giantGiant;
        phm[Key(typeid(GiantObj), typeid(KnightObj))] = &giantKnight;
        phm[Key(typeid(GiantObj), typeid(ArchersObj))] = &giantArchers;
        phm[Key(typeid(GiantObj), typeid(MinionsObj))] = &giantMinions;
        phm[Key(typeid(GiantObj), typeid(PekkaObj))] = &giantPekka;
        phm[Key(typeid(GiantObj), typeid(ValkyrieObj))] = &giantValkyrie;
        phm[Key(typeid(GiantObj), typeid(DartGoblinObj))] = &giantDartGoblin;
        phm[Key(typeid(GiantObj), typeid(FireballObj))] = &giantFireball;
        phm[Key(typeid(GiantObj), typeid(ArrowsObj))] = &giantArrows;
        phm[Key(typeid(GiantObj), typeid(FreezeObj))] = &giantFreeze;
        phm[Key(typeid(GiantObj), typeid(PcTerritory))] = &giantPcTerritory;
        phm[Key(typeid(GiantObj), typeid(PlayerTerritory))] = &giantPlayerTerritory;
        phm[Key(typeid(GiantObj), typeid(Bullet))] = &giantBullet;

        phm[Key(typeid(ValkyrieObj), typeid(Tower))] = &valkyrieTower;
        phm[Key(typeid(ValkyrieObj), typeid(ValkyrieObj))] = &valkyrieValkyrie;
        phm[Key(typeid(ValkyrieObj), typeid(GiantObj))] = &valkyrieGiant;
        phm[Key(typeid(ValkyrieObj), typeid(KnightObj))] = &valkyrieKnight;
        phm[Key(typeid(ValkyrieObj), typeid(ArchersObj))] = &valkyrieArchers;
        phm[Key(typeid(ValkyrieObj), typeid(MinionsObj))] = &valkyrieMinions;
        phm[Key(typeid(ValkyrieObj), typeid(PekkaObj))] = &valkyriePekka;
        phm[Key(typeid(ValkyrieObj), typeid(DartGoblinObj))] = &valkyrieDartGoblin;
        phm[Key(typeid(ValkyrieObj), typeid(FireballObj))] = &valkyrieFireball;
        phm[Key(typeid(ValkyrieObj), typeid(ArrowsObj))] = &valkyrieArrows;
        phm[Key(typeid(ValkyrieObj), typeid(FreezeObj))] = &valkyrieFreeze;
        phm[Key(typeid(ValkyrieObj), typeid(PcTerritory))] = &valkyriePcTerritory;
        phm[Key(typeid(ValkyrieObj), typeid(PlayerTerritory))] = &valkyriePlayerTerritory;
        phm[Key(typeid(ValkyrieObj), typeid(Bullet))] = &valkyrieBullet;

        phm[Key(typeid(PekkaObj), typeid(Tower))] = &pekkaTower;
        phm[Key(typeid(PekkaObj), typeid(PekkaObj))] = &pekkaPekka;
        phm[Key(typeid(PekkaObj), typeid(GiantObj))] = &pekkaGiant;
        phm[Key(typeid(PekkaObj), typeid(KnightObj))] = &pekkaKnight;
        phm[Key(typeid(PekkaObj), typeid(ArchersObj))] = &pekkaArchers;
        phm[Key(typeid(PekkaObj), typeid(MinionsObj))] = &pekkaMinions;
        phm[Key(typeid(PekkaObj), typeid(ValkyrieObj))] = &pekkaValkyrie;
        phm[Key(typeid(PekkaObj), typeid(DartGoblinObj))] = &pekkaDartGoblin;
        phm[Key(typeid(PekkaObj), typeid(FireballObj))] = &pekkaFireball;
        phm[Key(typeid(PekkaObj), typeid(ArrowsObj))] = &pekkaArrows;
        phm[Key(typeid(PekkaObj), typeid(FreezeObj))] = &pekkaFreeze;
        phm[Key(typeid(PekkaObj), typeid(PcTerritory))] = &pekkaPcTerritory;
        phm[Key(typeid(PekkaObj), typeid(PlayerTerritory))] = &pekkaPlayerTerritory;
        phm[Key(typeid(PekkaObj), typeid(Bullet))] = &pekkaBullet;

        phm[Key(typeid(DartGoblinObj), typeid(Tower))] = &dartGoblinTower;
        phm[Key(typeid(DartGoblinObj), typeid(PekkaObj))] = &dartGoblinPekka;
        phm[Key(typeid(DartGoblinObj), typeid(GiantObj))] = &dartGoblinGiant;
        phm[Key(typeid(DartGoblinObj), typeid(KnightObj))] = &dartGoblinKnight;
        phm[Key(typeid(DartGoblinObj), typeid(ArchersObj))] = &dartGoblinArchers;
        phm[Key(typeid(DartGoblinObj), typeid(MinionsObj))] = &dartGoblinMinions;
        phm[Key(typeid(DartGoblinObj), typeid(ValkyrieObj))] = &dartGoblinValkyrie;
        phm[Key(typeid(DartGoblinObj), typeid(DartGoblinObj))] = &dartGoblinDartGoblin;
        phm[Key(typeid(DartGoblinObj), typeid(FireballObj))] = &dartGoblinFireball;
        phm[Key(typeid(DartGoblinObj), typeid(ArrowsObj))] = &dartGoblinArrows;
        phm[Key(typeid(DartGoblinObj), typeid(PcTerritory))] = &dartGoblinPcTerritory;
        phm[Key(typeid(DartGoblinObj), typeid(PlayerTerritory))] = &dartGoblinPlayerTerritory;
        phm[Key(typeid(DartGoblinObj), typeid(Bullet))] = &dartGoblinBullet;
        phm[Key(typeid(DartGoblinObj), typeid(FreezeObj))] = &dartGoblinFreeze;

        phm[Key(typeid(Tower), typeid(ArchersObj))] = &towerArchers;
        phm[Key(typeid(Tower), typeid(KnightObj))] = &towerKnight;
        phm[Key(typeid(Tower), typeid(MinionsObj))] = &towerMinions;
        phm[Key(typeid(Tower), typeid(GiantObj))] = &towerGiant;
        phm[Key(typeid(Tower), typeid(PekkaObj))] = &towerPekka;
        phm[Key(typeid(Tower), typeid(FireballObj))] = &towerFireball;
        phm[Key(typeid(Tower), typeid(ArrowsObj))] = &towerArrows;
        phm[Key(typeid(Tower), typeid(DartGoblinObj))] = &towerDartGoblin;
        phm[Key(typeid(Tower), typeid(FreezeObj))] = &towerFreeze;
        phm[Key(typeid(Tower), typeid(ValkyrieObj))] = &towerValkyrie;

        phm[Key(typeid(PcTerritory), typeid(ArchersObj))] = &pcTerritoryArchers;
        phm[Key(typeid(PcTerritory), typeid(KnightObj))] = &pcTerritoryKnight;
        phm[Key(typeid(PcTerritory), typeid(MinionsObj))] = &pcTerritoryMinions;
        phm[Key(typeid(PcTerritory), typeid(GiantObj))] = &pcTerritoryGiant;
        phm[Key(typeid(PcTerritory), typeid(DartGoblinObj))] = &pcTerritoryDartGoblin;
        phm[Key(typeid(PcTerritory), typeid(PekkaObj))] = &pcTerritoryPekka;
        phm[Key(typeid(PcTerritory), typeid(FireballObj))] = &pcTerritoryFireball;
        phm[Key(typeid(PcTerritory), typeid(ArrowsObj))] = &pcTerritoryArrows;
        phm[Key(typeid(PcTerritory), typeid(FreezeObj))] = &pcTerritoryFreeze;
        phm[Key(typeid(PcTerritory), typeid(ValkyrieObj))] = &pcTerritoryValkyrie;

        phm[Key(typeid(PlayerTerritory), typeid(ArchersObj))] = &playerTerritoryArchers;
        phm[Key(typeid(PlayerTerritory), typeid(KnightObj))] = &playerTerritoryKnight;
        phm[Key(typeid(PlayerTerritory), typeid(GiantObj))] = &playerTerritoryGiant;
        phm[Key(typeid(PlayerTerritory), typeid(PekkaObj))] = &playerTerritoryPekka;
        phm[Key(typeid(PlayerTerritory), typeid(MinionsObj))] = &playerTerritoryMinions;
        phm[Key(typeid(PlayerTerritory), typeid(ValkyrieObj))] = &playerTerritoryValkyrie;
        phm[Key(typeid(PlayerTerritory), typeid(DartGoblinObj))] = &playerTerritoryDartGoblin;
        phm[Key(typeid(PlayerTerritory), typeid(FireballObj))] = &playerTerritoryFireball;
        phm[Key(typeid(PlayerTerritory), typeid(ArrowsObj))] = &playerTerritoryArrows;
        phm[Key(typeid(PlayerTerritory), typeid(FreezeObj))] = &playerTerritoryFreeze;


        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

}

void processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
