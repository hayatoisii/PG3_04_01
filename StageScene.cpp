#include "StageScene.h"

void StageScene::Initialize() {
    posX = 50;
    posY = 300;
    speed = 4;
    supeedtama = 0;
    syotto = 0;
    X = 50;
    Y = 300;
    A = 640;
    B = 100;
    speed3 = 4;
    taima = 120;
    num2 = 0;
    num3 = 0;
}

void StageScene::Update(char* keys, char* preKeys) {
    if (keys[DIK_W]) {
        posY -= speed;
    }
    if (keys[DIK_S]) {
        posY += speed;
    }
    if (keys[DIK_A]) {
        posX -= speed;
    }
    if (keys[DIK_D]) {
        posX += speed;
    }

    if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
        syotto = 1;
    }

    if (syotto == 1) {
        if (Y >= 0) {
            supeedtama = -10;
        }
    }

    Y += supeedtama;

    if (Y <= 0) {
        syotto = 0;
    }

    if (syotto == 0) {
        X = posX;
        Y = posY;
    }

    if (posX >= 1250) {
        posX = 1250 - speed;
    }
    if (posX <= 30) {
        posX = 30 + speed;
    }
    if (posY >= 697) {
        posY = 697 - speed;
    }
    if (posY <= 23) {
        posY = 23 + speed;
    }


    if (num2 == 0) {
        if ((A - X) * (A - X) + (B - Y) * (B - Y) <= 900) {
            syotto = 0;
            num2 = 1;
        }
    }

    // シーン遷移
    if (num2 == 1) {
        SetSceneNo(CLEAR);
    }
}

void StageScene::Draw() {
    Novice::ScreenPrintf(0, 0, "Stage Scene");
    Novice::DrawEllipse(posX, posY, 30, 30, 0.0f, WHITE, kFillModeSolid);
    Novice::DrawEllipse(A, B, 30, 30, 0.0f, WHITE, kFillModeSolid);
    if (syotto == 1) {
        Novice::DrawTriangle(X, Y - 10, X - 10, Y + 10, X + 10, Y + 10, BLUE, kFillModeSolid);
    }
}

