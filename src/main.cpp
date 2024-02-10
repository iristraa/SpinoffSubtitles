#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		auto liteSprite = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");
		auto meltdownSprite = CCSprite::createWithSpriteFrameName("GJ_md_001.png");
		auto worldSprite = CCSprite::createWithSpriteFrameName("gj_worldLogo_001.png");
		auto subzeroSprite = CCSprite::createWithSpriteFrameName("gj_subzeroLogo_001.png");
		auto twopointtwoSprite = CCSprite::create("gj_2point2Logo_001.png"_spr);

		auto title = this->getChildByID("main-title");
		auto titlePos = title->getPosition();

		// auto freeLevels = CCSpriteFrame::createWithTexture("GJ_freeLevelsBtn_001.png");
		// auto fullVersion = CCSpriteFrame::createWithTexture("GJ_fullBtn_001.png");

		auto mainMenu = this->getChildByID("main-menu");
		auto mgMenu = this->getChildByID("more-games-menu");

		if (Mod::get()->getSettingValue<bool>("subtext-lite")) {
			// liteSprite->setPosition({100, 100});
			liteSprite->setPositionX(titlePos.x + 150.5);
			liteSprite->setPositionY(titlePos.y - 30);
			this->addChild(liteSprite);
			liteSprite->setID("lite-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-meltdown")) {
			/// meltdownSprite->setPosition({ 100, 100 });
			meltdownSprite->setPositionX(titlePos.x + 140);
			meltdownSprite->setPositionY(titlePos.y - 44);
			this->addChild(meltdownSprite);
			meltdownSprite->setID("meltdown-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-world")) {
			// worldSprite->setPosition({ 100, 100 });
			worldSprite->setPositionX(titlePos.x + 120);
			worldSprite->setPositionY(titlePos.y - 44);
			this->addChild(worldSprite);
			worldSprite->setID("world-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-subzero")) {
			// subzeroSprite->setPosition({ 100, 100 });
			subzeroSprite->setPositionX(titlePos.x + 120);
			subzeroSprite->setPositionY(titlePos.y - 44);
			this->addChild(subzeroSprite);
			subzeroSprite->setID("subzero-title");
		}

		if (Mod::get()->getSettingValue<bool>("subtext-2point2")) {
			// twopointtwoSprite->setPosition({ 100, 100 });
			twopointtwoSprite->setPositionX(titlePos.x + 120);
			twopointtwoSprite->setPositionY(titlePos.y - 44);
			this->addChild(twopointtwoSprite);
			twopointtwoSprite->setID("twopointtwo-title");
		}

		// this for another day, i'm tired

		//if (Mod::get()->getSettingValue<bool>("full-version")) {
		//	auto editorBtn = mainMenu->getChildByID("editor-button");
		//	// wake me up when there's another way to access this ccsprite inside of this ccmenuitemspriteextra
		//	auto editorBtnSprite = editorBtn->getChildren()->objectAtIndex(0);
		//	editorBtnSprite->setDisplayFrame(fullVersion);
		//}

		return true;
	}
};
