#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <memory>
////////////////////////////////////////////////////////////
/// \brief A class that stores gameplay data
/// 
////////////////////////////////////////////////////////////


class GameData {
private:
	//Constructor
	GameData();

	static std::weak_ptr<GameData> m_instance;

	friend std::weak_ptr < GameData >;
	friend std::shared_ptr < GameData >;
public:
	//Get instance of singleton
	static std::shared_ptr<GameData> sharedGameData();

	std::string m_backgroundTextureFile;
	std::string m_textureAtlasImageFile;
	std::string m_textureAtlasPlistFile;
	// Tower base and tower related fields.
	std::string m_towerBaseFile;
	std::string m_hiddenPlatFile;
	std::string m_endGameArea;
	std::string m_towerGunFile;
	//Button stuff loaded from json file
	std::string m_buttonUnpressed;
	std::string m_buttonPressed;
	//Level Two stuff within the json file being loaded here.
	std::string m_levelTwoPlatforms;
	std::string m_flameImitPic;

	int m_towerWidth;
	int m_towerHeight;
	int m_firingDelay;
	int m_towerRotationSpeed;
	float m_towerRotationOriginX;
	float m_towerRotationOriginY;
	int m_numberOfTowerBases;
	int m_numberOfHiddenPlatforms;
	int m_numberOfTraps;
	int m_numEndGame;
	int m_numButton;
	int m_numberOfLevelTwoPlats;
	int m_buttonsLvlTwo;
	int m_flameImt;

	float m_towerBaseX[52];
	float m_towerBaseY[52];

	float m_hiddenPlatsX[2];
	float m_hiddenPlatsY[2];

	float m_trapX[2];
	float m_trapY[2];

	float m_endGameX[1];
	float m_endGameY[1];

	float m_ButtonsX[2];
	float m_ButtonsY[2];

	float m_levelTwoPlatformsX[189];
	float m_levelTwoPlatformsY[189];

	float m_fireEmittersX[20];
	float m_fireEmittersY[20];

	// Projectile related fields.
	std::string m_projectileFile;
	float m_projectileCentreX;
	float m_projectileCentreY;
	int m_maxNumProjectiles;
	int m_ttl;
	float m_velocity;

	// AI related fields.
	std::string m_aiImageFile;
	std::string m_aiPlistFile;
	int m_maxNumAI;
	int m_spawnInterval;
	float m_aiScale;
	float m_aiVelocity;
	int m_aiTimeDelay;
	int m_aiStartX;
	int m_aiStartY;
	// AI sprite sheet.
	int m_aiRows;
	int m_aiColumns;
	int m_aiWidth;
	int m_aiHeight;
	// AI Waypoints.
	int m_numWaypoints;
	float m_aiWPX[12];
	float m_aiWPY[12];
};

#endif