#pragma once
#include "scene.h"
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
using namespace glm;

class Game : public Scene
{
public:
	
	Game();
	Game(float angle,float relationWH,float near, float far);
	void Init();
	void Update(const glm::mat4 &MVP,const glm::mat4 &Model,const int  shaderIndx);
	void ControlPointUpdate();
	void WhenRotate();
	void WhenTranslate();
	void Motion();
	void initCube(vector<vector<vector<int>*>*>* BigCube);
	void right_pressed();
	void up_pressed();
	void down_pressed();
	void left_pressed();
	void doR();
	void func();
	void doU();
	void L_pressed();
	void D_pressed();
	void B_pressed();
	void F_pressed();
	void space_pressed();
	void Z_pressed();
	void A_pressed();
	void updateSecondCube();
	enum lastAction {UP, DOWN, LEFT, RIGHT, R, L, U, D, B, F, NOTHING };
	lastAction lastAct = NOTHING;
	vector<vector<vector<pair<int,int>>>> myCube;
	unordered_map<int, int>* map = new unordered_map<int, int>;
	int rotAngle = 45;
	int currentAngle = 0;
	bool clockWise = true;
	~Game(void);
};

