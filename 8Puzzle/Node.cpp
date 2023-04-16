#include "Node.h"
#include <string>
#include <iostream>

#define MOVE(i , l , r) for(int i = l ; i <= r ; i++)
#define MOVED(i , l , r) for(int i = l ; i >= r ; i--)
#define MOVES(i , l , r) for(int i = l ; i < r ; i++)
using namespace std;

Node::Node(int a[3][3], string way, moveWay canMove, int x, int y, int z) {
		this->Move = way;
		this->canMove = canMove;
		this->x = x;
		this->y = y;
		this->z = z;

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
		// 7,8, ]
	}
	return Value;
}

