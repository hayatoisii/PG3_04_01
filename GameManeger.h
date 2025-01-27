#pragma once
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include <memory>

class GameManager {
public:
    GameManager();
    ~GameManager();
    int Run();

private:
    // シーン配列
    std::unique_ptr<IScene> sceneArr_[3];
    // 現在のシーン番号
    int currentSceneNo_;
    int prevSceneNo_;
};
