#include <string>
#include <iostream>

#define MOVE(i , l , r) for(int i = l ; i <= r ; i++)
#define MOVED(i , l , r) for(int i = l ; i >= r ; i--)
#define MOVES(i , l , r) for(int i = l ; i < r ; i++)
using namespace std; 

enum moveWay {
	LEFT, RIGHT, UP, DOWN, STAY

};

// Khởi tạo mảng
class Node
{
public:
	int arr[3][3], x, y, z;
	string Move;
	moveWay canMove;

	Node(int a[3][3], string way, moveWay canMove, int x, int y, int z);

	int defaultCost(int Check, int Value );

	/*bool canMoveLeft();
	bool canMoveRight();
	bool canMoveUp();
	bool canMoveDown();*/
	
};



