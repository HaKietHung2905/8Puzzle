#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

Node::Node(int a[3][3], string Direction, moveWay canMove, int x, int y, int z, int Check, int Cost) {
		this->Direction = Direction;
		this->canMove = canMove;
		this->x = x;
		this->y = y;
		this->z = z;
		this->Check = Check;
		this->Cost = Cost;
		
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				arr[i][j] = a[i][j];
			}
		}
}

int Node::defaultCost(int Check, int Value) {
	if (Check == 1) {
		if (arr[0][0] != 1) Value++;
		if (arr[0][1] != 2) Value++;
		if (arr[0][2] != 3) Value++;
		if (arr[1][0] != 8) Value++;
		if (arr[1][2] != 4) Value++;
		if (arr[2][0] != 7) Value++;
		if (arr[2][1] != 6) Value++;
		if (arr[2][2] != 5) Value++;

		//[1,2,3
		// 8,0,4
		// 7,6,5]
	}
	//if (Check == 2) {
	//	if (arr[0][1] != 1) Value++;
	//	if (arr[0][2] != 2) Value++;
	//	if (arr[1][0] != 3) Value++;
	//	if (arr[1][1] != 4) Value++;
	//	if (arr[1][2] != 5) Value++;
	//	if (arr[2][0] != 6) Value++;
	//	if (arr[2][1] != 7) Value++;
	//	if (arr[2][2] != 8) Value++;

	//	//[1,2,3
	//	// 4,5,6
	//	// 7,8,0]
	//}
	else {
		if (arr[0][0] != 1) Value++;
		if (arr[0][1] != 2) Value++;
		if (arr[0][2] != 3) Value++;
		if (arr[1][0] != 4) Value++;
		if (arr[1][1] != 5) Value++;
		if (arr[1][2] != 6) Value++;
		if (arr[2][0] != 7) Value++;
		if (arr[2][1] != 8) Value++;
		if (arr[2][2] != 0) Value++;
	}
	return Value + z;
}

/**/
void Node::moveLeft() {
	swap(arr[x][y], arr[x][y - 1]);
	y--;
	canMove = RIGHT;
	Direction += "l";
	z++;
}


void Node::moveRight() {
	swap(arr[x][y], arr[x][y + 1]);
	y++;
	canMove = LEFT;
	Direction += "r";
	z++;
}


void Node::moveUp() {
	swap(arr[x][y], arr[x - 1][y]);
	x--;
	canMove = DOWN;
	Direction += "u";
	z++;
}

void Node::moveDown() {
	swap(arr[x][y], arr[x + 1][y]);
	x++;
	canMove = UP;
	Direction += "d";
	z++;
}


bool Node::checkMoveLeft() {
	defautCost = 0;
	int curCost = defaultCost(Check, defautCost);
	return canMove != LEFT && y > 0 && Cost > curCost;
}
bool Node::checkMoveRight() {
	defautCost = 0;
	int curCost = defaultCost(Check, defautCost);
	return canMove != RIGHT && y < 2 && Cost > curCost;
}
bool Node::checkMoveUp() {
	defautCost = 0;
	int curCost = defaultCost(Check, defautCost);
	return canMove != UP && x > 0 && Cost > curCost;
}
bool Node::checkMoveDown() {
	defautCost = 0;
	int curCost = defaultCost(Check, defautCost);
	return canMove != DOWN && x < 2 && Cost > curCost;
}

bool Node::checkFinish() {
	int counter = 0;
	if (Check == 1) {
		REP(i, 0, 2) {
			if (arr[0][i] != i + 1 || arr[2][i] != 7 - i) return false;
		}
		return arr[1][0] != 8 || arr[1][2] != 4 ? false : true;
	}
	else {
		REP(i, 0, 2) {
			if (arr[0][i] == i + 1) counter++;
			if (arr[1][i] == i + 4) counter++;
			if (arr[2][i] == i + 7) counter++;

		}
		
		if (counter == 8) return true;
		return false;
	}

}