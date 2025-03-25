#include "game.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "RubiksCube.h"
#include <iostream>
#include <utility>

using namespace std;
using namespace glm;

void Game::A_pressed() {
	if (abs(rotAngle) == 180)
		return;
	rotAngle = 2 * rotAngle;
}
void Game::Z_pressed() {
	if (abs(rotAngle) == 45)
		return;
	rotAngle = rotAngle / 2;
}

void Game::space_pressed() {
	rotAngle = -rotAngle;
}

void Game::down_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != DOWN && lastAct != UP) {
			return;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int currentCubeIndex = myCube[i][j][k].second;

				mat4 rotation = (shapes)[currentCubeIndex]->getRot();
				mat3 rotationMatrix = mat3(rotation);
				mat3 TransposeMatrix = transpose(rotationMatrix);

				vec3 newVec = TransposeMatrix * vec3(1, 0, 0);
				(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
			}
		}
	}
	
		updateSecondCube();
		if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
			currentAngle = 0;
		}
		else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
			currentAngle = 45;
		}
		else if (abs(currentAngle) != 45) {
			currentAngle = rotAngle;
		}
		lastAct = DOWN;

}


void Game::up_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != UP && lastAct != DOWN) {
			return;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int currentCubeIndex = myCube[i][j][k].second;

				mat4 rotation = (shapes)[currentCubeIndex]->getRot();
				mat3 rotationMatrix = mat3(rotation);
				mat3 TransposeMatrix = transpose(rotationMatrix);

				vec3 newVec = TransposeMatrix * vec3(1, 0, 0);
				(shapes)[currentCubeIndex]->MyRotate(-rotAngle, newVec, 0);

			}
		}
	}
	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = UP;
}
void Game::right_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != RIGHT && lastAct != LEFT) {
			return;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int currentCubeIndex = myCube[i][j][k].second;

				mat4 rotation = (shapes)[currentCubeIndex]->getRot();
				mat3 rotationMatrix = mat3(rotation);
				mat3 TransposeMatrix = transpose(rotationMatrix);

				vec3 newVec = TransposeMatrix * vec3(0, 1, 0);
				(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);

			}
		}
	}
	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = RIGHT;
}
void Game::left_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != LEFT && lastAct != RIGHT) {
			return;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int currentCubeIndex = myCube[i][j][k].second;

				mat4 rotation = (shapes)[currentCubeIndex]->getRot();
				mat3 rotationMatrix = mat3(rotation);
				mat3 TransposeMatrix = transpose(rotationMatrix);

				vec3 newVec = TransposeMatrix * vec3(0, 1, 0);
				(shapes)[currentCubeIndex]->MyRotate(-rotAngle, newVec, 0);

			}
		}
	}

	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = LEFT;
}
void Game::F_pressed() {
	
	if (abs(currentAngle) == 45) {
		if (lastAct != F) {
			return;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int currentCubeIndex = myCube[i][j][2].second;

			mat4 rotation = (shapes)[currentCubeIndex]->getRot();
			mat3 rotationMatrix = mat3(rotation);
			mat3 TransposeMatrix = transpose(rotationMatrix);

			vec3 newVec = TransposeMatrix * vec3(0, 0, 1);
			(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
		}
	}
	
	
	updateSecondCube();
		if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
			currentAngle = 0;
		}
		else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
			currentAngle = 45;
		}
		else if (abs(currentAngle) != 45) {
			currentAngle = rotAngle;
		}
		lastAct = F;
}
void Game::B_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != B) {
			return;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int currentCubeIndex = myCube[i][j][0].second;

			mat4 rotation = (shapes)[currentCubeIndex]->getRot();
			mat3 rotationMatrix = mat3(rotation);
			mat3 TransposeMatrix = transpose(rotationMatrix);

			vec3 newVec = TransposeMatrix * vec3(0, 0, 1);
			(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
		}
	}

	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = B;
}
void Game::D_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != D) {
			return;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			int currentCubeIndex = myCube[i][0][k].second;

			mat4 rotation = (shapes)[currentCubeIndex]->getRot();
			mat3 rotationMatrix = mat3(rotation);
			mat3 TransposeMatrix = transpose(rotationMatrix);

			vec3 newVec = TransposeMatrix * vec3(0, 1, 0);
			(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
		}
	}

	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = D;
}
void Game::L_pressed() {
	if (abs(currentAngle) == 45) {
		if (lastAct != L) {
			return;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			int currentCubeIndex = myCube[0][j][k].second;

			mat4 rotation = (shapes)[currentCubeIndex]->getRot();
			mat3 rotationMatrix = mat3(rotation);
			mat3 TransposeMatrix = transpose(rotationMatrix);

			vec3 newVec = TransposeMatrix * vec3(1, 0, 0);
			(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
		}
	}

	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = L;
}
void Game::doU() {
	if (abs(currentAngle) == 45) {
		if (lastAct != U) {
			return;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			int currentCubeIndex = myCube[i][2][k].second;

			mat4 rotation = (shapes)[currentCubeIndex]->getRot();
			mat3 rotationMatrix = mat3(rotation);
			mat3 TransposeMatrix = transpose(rotationMatrix);

			vec3 newVec = TransposeMatrix * vec3(0, 1, 0);
			(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
		}
	}

	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = U;
}


void Game::doR() {
	if (abs(currentAngle) == 45) {
		if (lastAct != R) {
			return;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			int currentCubeIndex = myCube[2][j][k].second;

			mat4 rotation = (shapes)[currentCubeIndex]->getRot();
			mat3 rotationMatrix = mat3(rotation);
			mat3 TransposeMatrix = transpose(rotationMatrix);

			vec3 newVec = TransposeMatrix * vec3(1, 0, 0);
			(shapes)[currentCubeIndex]->MyRotate(rotAngle, newVec, 0);
		}
	}
	updateSecondCube();
	if (abs(currentAngle) == 45 && abs(rotAngle) == 45) {
		currentAngle = 0;
	}
	else if (abs(currentAngle) == 45 && abs(rotAngle) != 45) {
		currentAngle = 45;
	}
	else if (abs(currentAngle) != 45) {
		currentAngle = rotAngle;
	}
	lastAct = R;
}
void Game::initCube(vector<vector<vector<int>*>*>* BigCube) {
	
	AddTexture("../res/textures/plane.png",false);
	int size = 3;
	float distance = 1;
	int index = 0;

	for (float i = -distance; i <= distance; i ++)
	{
		vector<vector<pair<int,int>>> wall;
		for (float j = -distance; j <= distance; j ++)
		{
			vector<pair<int, int>> row;
			for (float k = -distance; k <= distance; k ++)
			{
				this->map->emplace(index, index);
				row.push_back(pair<int,int>(index, index));
				AddShape(Scene::Cube, -1, Scene::TRIANGLES);
				SetShapeTex(index, 0);
				shapes[index]->MyTranslate(glm::vec3(i, j, k), 0);
				shapes[index]->MyScale(glm::vec3(0.5, 0.5, 0.5));
				index++;
			}
			wall.push_back(row);
		}
		this->myCube.push_back(wall);

	}

}

void Game::updateSecondCube() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				
				int originalCubeIndex = myCube[i][j][k].first;

				vec3 originalTrans = vec3((shapes)[originalCubeIndex]->getTrans()[3]);
				mat4 originalRotation = (shapes)[originalCubeIndex]->getRot();
				mat3 rotationMatrix = mat3(originalRotation);

				vec3 newVec = round(rotationMatrix * originalTrans - originalTrans);
				int newX = i + newVec.x;
				int newY = j + newVec.y;
				int newZ = k + newVec.z;
				vec3 updateNewVec = vec3(newX, newY, newZ);
				
				myCube[updateNewVec.x][updateNewVec.y][updateNewVec.z].second = originalCubeIndex;
			}
		}
	}
}

static void printMat(const glm::mat4 mat)
{
	std::cout<<" matrix:"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			std::cout<< mat[j][i]<<" ";
		std::cout<<std::endl;
	}
}

Game::Game() : Scene()
{
}

Game::Game(float angle ,float relationWH, float near1, float far1) : Scene(angle,relationWH,near1,far1)
{ 	
}

void Game::Init()
{		

	AddShader("../res/shaders/pickingShader");	
	AddShader("../res/shaders/basicShader");
	
	
	pickedShape = 0;
	
	//SetShapeTex(0,0);
	MoveCamera(0, zTranslate, 10);

	pickedShape = -1;
	
	//ReadPixel(); //uncomment when you are reading from the z-buffer
}

void Game::Update(const glm::mat4 &MVP,const glm::mat4 &Model,const int  shaderIndx)
{
	Shader *s = shaders[shaderIndx];
	int r = ((pickedShape+1) & 0x000000FF) >>  0;
	int g = ((pickedShape+1) & 0x0000FF00) >>  8;
	int b = ((pickedShape+1) & 0x00FF0000) >> 16;
	s->Bind();
	s->SetUniformMat4f("MVP", MVP);
	s->SetUniformMat4f("Normal",Model);
	s->SetUniform4f("lightDirection", 0.0f , 0.0f, -1.0f, 0.0f);
	if(shaderIndx == 0)
		s->SetUniform4f("lightColor",r/255.0f, g/255.0f, b/255.0f,1.0f);
	else 
		s->SetUniform4f("lightColor",0.7f,0.8f,0.1f,1.0f);
	s->Unbind();
}

void Game::WhenRotate()
{
}

void Game::WhenTranslate()
{
}

void Game::Motion()
{
	if(isActive)
	{
	}
}

Game::~Game(void)
{
}
