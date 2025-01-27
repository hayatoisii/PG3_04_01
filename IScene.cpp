#include "IScene.h"

int IScene::sceneNo = TITLE;

int IScene::GetSceneNo() { return sceneNo; }

void IScene::SetSceneNo(int newSceneNo) { sceneNo = newSceneNo; }
