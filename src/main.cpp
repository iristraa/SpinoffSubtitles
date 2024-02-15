#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <matjson.hpp>

using namespace geode::prelude;

// Random Code from stack overflow cause why not: https://stackoverflow.com/a/2125908
template < typename Type > std::string tostr (const Type & t)
{
  std::ostringstream os;
  os << t;
  return os.str ();
}
// hello

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		std::list<CCSprite*> theChosenList {};
		auto boxesSelected = 0;

		auto liteSprite = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");
		auto meltdownSprite = CCSprite::createWithSpriteFrameName("GJ_md_001.png");
		auto worldSprite = CCSprite::createWithSpriteFrameName("gj_worldLogo_001.png");
		auto subzeroSprite = CCSprite::createWithSpriteFrameName("gj_subzeroLogo_001.png");
		auto twopointtwoSprite = CCSprite::create("gj_2point2Logo_001.png"_spr);

		auto title = this->getChildByID("main-title");
		auto titlePos = title->getPosition();

		auto freeLevels = CCSprite::createWithSpriteFrameName("GJ_freeLevelsBtn_001.png");
		auto fullVersion = CCSprite::createWithSpriteFrameName("GJ_fullBtn_001.png");
		auto freeChest = CCSprite::createWithSpriteFrameName("GJ_freeChestBtn_001.png");

		auto mainMenu = this->getChildByID("main-menu");
		auto mgMenu = this->getChildByID("more-games-menu");
		auto rightSideMenu = this->getChildByID("right-side-menu");

		if (Mod::get()->getSettingValue<bool>("subtext-lite")) {
			// liteSprite->setPosition({100, 100});
			liteSprite->setPositionX(titlePos.x + 150.5);
			liteSprite->setPositionY(titlePos.y - 30);
			liteSprite->setScale(0.8);
			liteSprite->setZOrder(10);
			liteSprite->setID("lite-title");
			theChosenList.emplace_back(liteSprite);
			boxesSelected = boxesSelected + 1;
			//liteSprite->setID("lite-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-meltdown")) {
			/// meltdownSprite->setPosition({ 100, 100 });
			meltdownSprite->setPositionX(titlePos.x + 140);
			meltdownSprite->setPositionY(titlePos.y - 44);
			meltdownSprite->setZOrder(10);
			meltdownSprite->setID("meltdown-title");
			theChosenList.emplace_back(meltdownSprite);
			boxesSelected = boxesSelected + 1;
			//meltdownSprite->setID("meltdown-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-world")) {
			// worldSprite->setPosition({ 100, 100 });
			worldSprite->setPositionX(titlePos.x + 120);
			worldSprite->setPositionY(titlePos.y - 44);
			worldSprite->setZOrder(10);
			worldSprite->setID("world-title");
			theChosenList.emplace_back(worldSprite);
			boxesSelected = boxesSelected + 1;
			//worldSprite->setID("world-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-subzero")) {
			// subzeroSprite->setPosition({ 100, 100 });
			subzeroSprite->setPositionX(titlePos.x + 120);
			subzeroSprite->setPositionY(titlePos.y - 44);
			subzeroSprite->setZOrder(10);
			subzeroSprite->setID("subzero-title");
			theChosenList.emplace_back(subzeroSprite);
			boxesSelected = boxesSelected + 1;
			//subzeroSprite->setID("subzero-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-2point2")) {
			// twopointtwoSprite->setPosition({ 100, 100 });
			twopointtwoSprite->setPositionX(titlePos.x + 120);
			twopointtwoSprite->setPositionY(titlePos.y - 44);
			twopointtwoSprite->setZOrder(10);
			twopointtwoSprite->setID("twopointtwo-title");
			theChosenList.emplace_back(twopointtwoSprite);
			boxesSelected = boxesSelected + 1;
			//twopointtwoSprite->setID("twopointtwo-title");
		}
		const eee = tostr(theChosenList)
		log::info(eee);

		// todo: have a random thingy selected choose one and make id efewhaufioea->setID("spinoff-title");

		
		if (Mod::get()->getSettingValue<bool>("full-ver-btn")) {
			CCMenuItemSpriteExtra* editBtn = dynamic_cast<CCMenuItemSpriteExtra*>(mainMenu->getChildByID("editor-button"));
			editBtn->setNormalImage(fullVersion);
		}

		if (Mod::get()->getSettingValue<bool>("free-chest-btn")) {
			CCMenuItemSpriteExtra* chestBtn = dynamic_cast<CCMenuItemSpriteExtra*>(rightSideMenu->getChildByID("daily-chest-button"));
			chestBtn->setNormalImage(freeChest);
		}

		if (Mod::get()->getSettingValue<bool>("free-lvls-btn")) {
			CCMenuItemSpriteExtra* mgBtn = dynamic_cast<CCMenuItemSpriteExtra*>(mgMenu->getChildByID("more-games-button"));
			mgBtn->setNormalImage(freeLevels);
		}

		return true;
	}
};
