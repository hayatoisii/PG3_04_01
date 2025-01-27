#include "GameManeger.h"
#include <Novice.h>
#include <cstring>

GameManager::GameManager() {
    sceneArr_[TITLE] = std::make_unique<TitleScene>();
    sceneArr_[STAGE] = std::make_unique<StageScene>();
    sceneArr_[CLEAR] = std::make_unique<ClearScene>();

    currentSceneNo_ = TITLE;
    prevSceneNo_ = -1;
}

GameManager::~GameManager() {}

int GameManager::Run() {
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        prevSceneNo_ = currentSceneNo_;
        currentSceneNo_ = IScene::GetSceneNo();

        if (prevSceneNo_ != currentSceneNo_) {
            sceneArr_[currentSceneNo_]->Initialize();
        }

        sceneArr_[currentSceneNo_]->Update(keys, preKeys);
        sceneArr_[currentSceneNo_]->Draw();

        Novice::EndFrame();

        if (keys[DIK_ESCAPE]) {
            break;
        }
    }

    return 0;
}
