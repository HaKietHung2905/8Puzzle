#include <string>
#include <iostream>

#define MOVE(i , l , r) for(int i = l ; i <= r ; i++)
#define MOVED(i , l , r) for(int i = l ; i >= r ; i--)
#define MOVES(i , l , r) for(int i = l ; i < r ; i++)
#define REP(i , l , r) for(int i = l ; i <= r ; i++)
#define REPD(i , l , r) for(int i = l ; i >= r ; i--)
#define REPS(i , l , r) for(int i = l ; i < r ; i++)
using namespace std; 

enum moveWay {
	LEFT, RIGHT, UP, DOWN, STAY

};
//int puzzle[3][3], posX, posY, Check, Cost, defautCost;
// Khởi tạo mảng
class Node
{
public:
	int arr[3][3], x, y, z, Check, Cost, defautCost;
	string Direction;
	moveWay canMove;

	Node(int a[3][3], string Direction, moveWay canMove, int x, int y, int z, int Check, int Cost);

	int defaultCost(int Check, int Value );

	bool checkMoveLeft();
	bool checkMoveRight();
	bool checkMoveUp();
	bool checkMoveDown();
	bool checkFinish();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	/*bool canMoveRight();
	bool canMoveUp();
	bool canMoveDown();*/
	
};



