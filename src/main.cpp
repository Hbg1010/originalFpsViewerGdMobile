#include <Geode/Geode.hpp>

using namespace geode::prelude;
#include <Geode/modify/MoreVideoOptionsLayer.hpp>
class $modify(x, MoreVideoOptionsLayer) {
    bool init() {
        if (!MoreVideoOptionsLayer::init()) return false;
        addToggle("Show FPS","0115","Shows frames per second while playing.");

        /*
        For some reason stuff becomes invisible when I addToggle, so this fixes that
        */
        auto menuThing = m_mainLayer->getChildByType<CCMenu>(0);
        CCArrayExt<CCMenuItemSpriteExtra*> coolArray = menuThing->getChildren();
        for (auto* obj : coolArray) {
            if (obj->getTag() == 115) {
                obj->setVisible(true);
            }
        }

        CCArrayExt<CCNode*> textStuff = m_mainLayer->getChildren();
        for (CCNode* obj : textStuff) {
            obj->setVisible(true);
        }
        return true;
    }
};