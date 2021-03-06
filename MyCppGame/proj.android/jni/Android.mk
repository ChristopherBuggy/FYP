LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
LOCAL_MODULE := cocos2dcpp_shared
LOCAL_MODULE_FILENAME := libcocos2dcpp
LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/src/AppDelegate.cpp \
                   ../../Classes/src/Button.cpp \
				   ../../Classes/src/DPad.cpp \
				   ../../Classes/src/endGame.cpp \
				   ../../Classes/src/FlameEmitter.cpp \
				   ../../Classes/src/GameData.cpp \
				   ../../Classes/src/GameOverScene.cpp \
				   ../../Classes/src/GameScene.cpp \
				   ../../Classes/src/HelloWorldScene.cpp \
				   ../../Classes/src/HUD.cpp \
				   ../../Classes/src/leftButton.cpp \
				   ../../Classes/src/LevelLoader.cpp \
				   ../../Classes/src/levelTwo.cpp \
				   ../../Classes/src/MainMenuScene.cpp \
				   ../../Classes/src/PauseScene.cpp \
				   ../../Classes/src/Platforms.cpp \
				   ../../Classes/src/Player.cpp \
				   ../../Classes/src/player2.cpp \
				   ../../Classes/src/rightButton.cpp \
				   ../../Classes/src/TowerBase.cpp \
				   ../../Classes/src/TowerGun.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes/include

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
