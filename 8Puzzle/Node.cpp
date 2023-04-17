#include "Node.h"
#include <string>
#include <iostream>

#define MOVE(i , l , r) for(int i = l ; i <= r ; i++)
#define MOVED(i , l , r) for(int i = l ; i >= r ; i--)
#define MOVES(i , l , r) for(int i = l ; i < r ; i++)
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
	else {
		if (arr[0][1] != 1) Value++;
		if (arr[0][2] != 2) Value++;
		if (arr[1][0] != 3) Value++;
		if (arr[1][1] != 4) Value++;
		if (arr[1][2] != 5) Value++;
		if (arr[2][0] != 6) Value++;
		if (arr[2][1] != 7) Value++;
		if (arr[2][2] != 8) Value++;

		//[1,2,3
		// 4,5,6
		// 7,8,0]
	}
	return Value;
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
	y++;
	canMove = DOWN;
	Direction += "r";
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
	return canMove != LEFT && y > 0 && Cost > defaultCost(Check, defautCost);
}
bool Node::checkMoveRight() {
	defautCost = 0;
	return canMove != RIGHT && y < 2 && Cost > defaultCost(Check, defautCost);
}
bool Node::checkMoveUp() {
	defautCost = 0;
	return canMove != UP && x > 0 && Cost > defaultCost(Check, defautCost);
}
bool Node::checkMoveDown() {
	defautCost = 0;
	return canMove != DOWN && x < 2 && Cost > defaultCost(Check, defautCost);
}

bool Node::checkFinish() {
	if (Check == 1) {
		REP(i, 0, 2) {
			if (arr[0][i] != i + 1 || arr[2][i] != 7 - i) return false;;
		}
		return arr[1][0] != 8 || arr[1][2] != 4 ? false : true;
	}
	else {
		REP(i, 0, 2) {
			if (arr[0][i] != i || arr[1][i] != i + 3 || arr[2][i] != i + 6) return false;
		}
		return true;
	}

}