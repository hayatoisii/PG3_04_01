#pragma once

enum Scene {
    TITLE,
    STAGE,
    CLEAR
};

class IScene {
public:
    virtual ~IScene() {}
    virtual void Initialize() = 0;
    virtual void Update(char* keys, char* preKeys) = 0;
    virtual void Draw() = 0;
    static int GetSceneNo();
    static void SetSceneNo(int sceneNo);

protected:
    static int sceneNo;

	int posX;
	int posY;
	int speed;
	int supeedtama;
	int syotto;
	int X;
	int Y;
	int A;
	int B;
	int speed3;
	int taima;
	int num2;
	int num3;

};
