﻿#include "TitleScene.h"

void TitleScene::Initialize() {}

void TitleScene::Update(char* keys, char* preKeys) {
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        SetSceneNo(STAGE);
    }
}

void TitleScene::Draw() {
    Novice::ScreenPrintf(0, 0, "Title Scene");
    Novice::ScreenPrintf(0, 30, "Press SPACE to Start");
}
