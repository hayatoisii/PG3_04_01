#pragma once
#include "IScene.h"
#include <Novice.h>

class StageScene : public IScene {
public:
    void Initialize() override;
    void Update(char* keys, char* preKeys) override;
    void Draw() override;

private:
    int posX, posY, speed, supeedtama, syotto, X, Y, A, B, speed3, taima, num2, num3;
};
