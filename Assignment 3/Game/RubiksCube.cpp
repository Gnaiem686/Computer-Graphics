#include "game.h"
#include "RubiksCube.h"
#include <vector>
using namespace std;

RubiksCube::RubiksCube(Game* scn) {
	scn->initCube(this->BigCube);
}
