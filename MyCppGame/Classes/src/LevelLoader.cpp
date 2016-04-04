#include "LevelLoader.h"

////////////////////////////////////////////////////////////
LevelLoader::LevelLoader(std::string const & filename) 
{
	loadJSONData(filename);
	m_document.Parse<0>(m_JSONData.c_str());	
	loadGameData();
}

////////////////////////////////////////////////////////////
void LevelLoader::loadJSONData(std::string const & filename)
{
	m_JSONData.clear();

	auto fileUtils = cocos2d::FileUtils::getInstance();
	// Loads all the data in the file into a std::string.
	m_JSONData = fileUtils->getStringFromFile(filename);
}


////////////////////////////////////////////////////////////
void LevelLoader::loadGameData()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	Value::ConstMemberIterator it1 = m_document["global_settings"].MemberBegin();
	// Get value of "background_texture" 
	ptr->m_backgroundTextureFile = it1->value.GetString();
	// Get value of "texture_atlas_image_file" 
	it1++;
	ptr->m_textureAtlasImageFile = it1->value.GetString();
	// Get value of "texture_atlas_plist_file"
	it1++;
	ptr->m_textureAtlasPlistFile = it1->value.GetString();
	it1++;
	Value const & tower = it1->value; 
	assert(tower.IsObject());
	// Get the tower properties.
	ptr->m_towerBaseFile = tower["tower_base_file"].GetString();
	//Hidden plats 
	ptr->m_hiddenPlatFile = tower["hidden_plat_file"].GetString();
	//Traps
	ptr->m_towerGunFile = tower["tower_gun_file"].GetString();
	//End game
	ptr->m_endGameArea = tower["end_game_file"].GetString();

	//loading the button both pressed and unpressed.
	//Going to have to change hte button when I contact it. I'll try sort that.
	ptr->m_buttonUnpressed = tower["button_game_file"].GetString();
	ptr->m_buttonPressed = tower["button_pressed_game_file"].GetString();

	ptr->m_towerWidth = tower["tower_width"].GetInt();
	ptr->m_towerHeight = tower["tower_height"].GetInt();
	ptr->m_firingDelay = tower["firing_delay"].GetInt();
	ptr->m_towerRotationSpeed = tower["tower_rotation_speed"].GetInt();

	// The "tower_rotation_origin" element is an object.
	Value const & towerRotationOrigin = tower["tower_rotation_origin"];
	ptr->m_towerRotationOriginX = towerRotationOrigin["x"].GetInt();
	ptr->m_towerRotationOriginY = towerRotationOrigin["y"].GetInt();
	ptr->m_numberOfTowerBases = tower["number_of_tower_bases"].GetInt();
	ptr->m_numberOfHiddenPlatforms = tower["number_of_hidden_platforms"].GetInt();
	ptr->m_numberOfTraps = tower["number_of_traps"].GetInt();
	ptr->m_numEndGame = tower["end_Game"].GetInt();
	ptr->m_numButton = tower["num_Buttons"].GetInt();

	// The "tower_bases" element is an array.
	Value const & towerBases = tower["tower_bases"];
	Value const & traps = tower["traps"];
	Value const & endGame = tower["endGame"];
	Value const & hiddenPlatforms = tower["hiddenPlat"];

	// Iterate through the array.
	for (int i = 0; i < towerBases.Size(); i++) {
		ptr->m_towerBaseX[i] = towerBases[i]["x"].GetInt();
		ptr->m_towerBaseY[i] = towerBases[i]["y"].GetInt();
	}

	//Hidden Platfrom Array
	for (int i = 0; i < hiddenPlatforms.Size(); i++)
	{
		ptr->m_hiddenPlatsX[i] = hiddenPlatforms[i]["x"].GetInt();
		ptr->m_hiddenPlatsY[i] = hiddenPlatforms[i]["y"].GetInt();
	}

	//trap array!
	for (int i = 0; i < traps.Size(); i++) {
		ptr->m_trapX[i] = traps[i]["x"].GetInt();
		ptr->m_trapY[i] = traps[i]["y"].GetInt();
	}

	//endgame Array!
	for (int i = 0; i < endGame.Size(); i++){
		ptr->m_endGameX[i] = endGame[i]["x"].GetInt();
		ptr->m_endGameY[i] = endGame[i]["y"].GetInt();
	}
	// Move to the "projectile" element, which is another object.
	it1++;
	Value const & projectile = it1->value;
	ptr->m_projectileFile = projectile["projectile_file"].GetString();
	// The "projectile_centre" element is an object.	
	Value const & projectileCentre = projectile["projectile_centre"];
	ptr->m_projectileCentreX = projectileCentre["x"].GetInt();
	ptr->m_projectileCentreY = projectileCentre["y"].GetInt();
	// Get the remaining projectile attributes.
	ptr->m_maxNumProjectiles = projectile["max_num_projectiles"].GetInt();
	ptr->m_ttl = projectile["time_to_live"].GetInt();
	ptr->m_velocity = projectile["velocity"].GetInt();

	// Move to the "ai" element
	it1++;
	Value const & ai = it1->value;
	ptr->m_aiImageFile = ai["ai_image_file"].GetString();
	ptr->m_aiPlistFile = ai["ai_plist_file"].GetString();
	ptr->m_maxNumAI = ai["max_num_ai"].GetInt();
	ptr->m_spawnInterval = ai["ai_spawn_interval"].GetInt();
	ptr->m_aiScale = ai["ai_scale"].GetDouble();
	ptr->m_aiVelocity = ai["ai_velocity"].GetDouble();
	ptr->m_aiTimeDelay = ai["ai_time_delay"].GetInt();
	// The "ai_start_position" element is an object.
	Value const & aiStartPosition = ai["ai_start_position"];
	ptr->m_aiStartX = aiStartPosition["x"].GetInt();
	ptr->m_aiStartY = aiStartPosition["y"].GetInt();
	// The "ai_walking_spritesheet" element is an object.
	Value const & aiWalkingSpriteSheet = ai["ai_walking_spritesheet"];
	ptr->m_aiRows = aiWalkingSpriteSheet["rows"].GetInt();
	ptr->m_aiColumns = aiWalkingSpriteSheet["columns"].GetInt();
	ptr->m_aiWidth = aiWalkingSpriteSheet["width"].GetInt();
	ptr->m_aiHeight = aiWalkingSpriteSheet["height"].GetInt();
	// The "ai_waypoints" element is an array.
	Value const & aiWaypoints = ai["ai_waypoints"];
	// Iterate through the array.
	for (int i = 0; i < aiWaypoints.Size(); i++) {
		ptr->m_aiWPX[i] = aiWaypoints[i]["x"].GetInt();
		ptr->m_aiWPY[i] = aiWaypoints[i]["y"].GetInt();
	}
	ptr->m_numWaypoints = aiWaypoints.Size();
}
