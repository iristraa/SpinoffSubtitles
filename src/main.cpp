#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace geode::prelude;


class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		std::vector<CCSprite*> theChosenList {};

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

		switch (Mod::get()->getSettingValue<int64_t>("subtext-type"))
		{
		case 0:
			// none
			break;
		case 1:
			// lite
			// liteSprite->setPosition({100, 100});
			liteSprite->setPositionX(titlePos.x + 150.5);
			liteSprite->setPositionY(titlePos.y - 30);
			liteSprite->setScale(0.8);
			liteSprite->setZOrder(10);
			this->addChild(liteSprite);
			liteSprite->setID("lite-title");
			break;
		case 2:
			// meltdown
			// meltdownSprite->setPosition({ 100, 100 });
			meltdownSprite->setPositionX(titlePos.x + 140);
			meltdownSprite->setPositionY(titlePos.y - 44);
			meltdownSprite->setZOrder(10);
			this->addChild(meltdownSprite);
			meltdownSprite->setID("meltdown-title");
			break;
		case 3:
			// world
			// worldSprite->setPosition({ 100, 100 });
			worldSprite->setPositionX(titlePos.x + 120);
			worldSprite->setPositionY(titlePos.y - 44);
			worldSprite->setZOrder(10);
			this->addChild(worldSprite);
			worldSprite->setID("world-title");
			break;
		case 4:
			// subzero
			// subzeroSprite->setPosition({ 100, 100 });
			subzeroSprite->setPositionX(titlePos.x + 120);
			subzeroSprite->setPositionY(titlePos.y - 44);
			subzeroSprite->setZOrder(10);
			this->addChild(subzeroSprite);
			subzeroSprite->setID("subzero-title");
			break;
		case 5:
			// 2.2
			// twopointtwoSprite->setPosition({ 100, 100 });
			twopointtwoSprite->setPositionX(titlePos.x + 120);
			twopointtwoSprite->setPositionY(titlePos.y - 44);
			twopointtwoSprite->setZOrder(10);
			this->addChild(twopointtwoSprite);
			twopointtwoSprite->setID("twopointtwo-title");
			break;
		case -1:
			if (Mod::get()->getSettingValue<bool>("subtext-lite")) {
				// liteSprite->setPosition({100, 100});
				liteSprite->setPositionX(titlePos.x + 150.5);
				liteSprite->setPositionY(titlePos.y - 30);
				liteSprite->setScale(0.8);
				liteSprite->setZOrder(10);
				liteSprite->setID("lite-title");
				theChosenList.emplace_back(liteSprite);
				//liteSprite->setID("lite-title");
			}
	
			if (Mod::get()->getSettingValue<bool>("subtext-meltdown")) {
				/// meltdownSprite->setPosition({ 100, 100 });
				meltdownSprite->setPositionX(titlePos.x + 140);
				meltdownSprite->setPositionY(titlePos.y - 44);
				meltdownSprite->setZOrder(10);
				meltdownSprite->setID("meltdown-title");
				theChosenList.emplace_back(meltdownSprite);
				//meltdownSprite->setID("meltdown-title");
			}
	
			if (Mod::get()->getSettingValue<bool>("subtext-world")) {
				// worldSprite->setPosition({ 100, 100 });
				worldSprite->setPositionX(titlePos.x + 120);
				worldSprite->setPositionY(titlePos.y - 44);
				worldSprite->setZOrder(10);
				worldSprite->setID("world-title");
				theChosenList.emplace_back(worldSprite);
				//worldSprite->setID("world-title");
			}
	
			if (Mod::get()->getSettingValue<bool>("subtext-subzero")) {
				// subzeroSprite->setPosition({ 100, 100 });
				subzeroSprite->setPositionX(titlePos.x + 120);
				subzeroSprite->setPositionY(titlePos.y - 44);
				subzeroSprite->setZOrder(10);
				subzeroSprite->setID("subzero-title");
				theChosenList.emplace_back(subzeroSprite);
				//subzeroSprite->setID("subzero-title");
			}
	
			if (Mod::get()->getSettingValue<bool>("subtext-2point2")) {
				// twopointtwoSprite->setPosition({ 100, 100 });
				twopointtwoSprite->setPositionX(titlePos.x + 120);
				twopointtwoSprite->setPositionY(titlePos.y - 44);
				twopointtwoSprite->setZOrder(10);
				twopointtwoSprite->setID("twopointtwo-title");
				theChosenList.emplace_back(twopointtwoSprite);
				//twopointtwoSprite->setID("twopointtwo-title");
			}
			std::string result;
			auto theCount = 0;
	    		for (const auto& element : theChosenList) {
				theCount += 1;
				if (theCount == 1 || theCount == 0) result += " " + element->getID(); else result += ", " + element->getID();
	    		}
			log::info("The selected texts:{}",result);
	
			// todo: have a random thingy selected choose one and make id efewhaufioea->setID("spinoff-title");
			if (theCount == 0) break;
			// if (theCount == 1) break;
			this->addChild(theChosenList[rand() % theCount]);
			break;
		}
		
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
