#include <string>
#include <iostream>
#include "Node.h"
#include <vector>

#define REP(i , l , r) for(int i = l ; i <= r ; i++)
#define REPD(i , l , r) for(int i = l ; i >= r ; i--)
#define REPS(i , l , r) for(int i = l ; i < r ; i++)

using namespace std;
typedef long long int ll;

int puzzle[3][3], posX, posY, checkValue, costValue;


bool checkFinish() {
	int counter1 = 0, counter2 = 0, counter3 = 0;
	REP(i, 0, 2) {
		if (puzzle[0][i] == i + 1) counter1++;
	}

	REP(i, 0, 2) {
		if (puzzle[2][i] == 7 - i) counter1++;
	}
	if (puzzle[1][0] == 8) {
		counter1++;
	}
	if (puzzle[1][2] == 4) {
		counter1++;
	}
	if (counter1 == 8) return true;/**/

	/*REP(i, 0, 2) {
		if (puzzle[0][i] == i) counter2++;
		if (puzzle[1][i] == i + 3) counter2++;
		if (puzzle[2][i] == i + 6) counter2++;
	}
	if (counter2 == 8) return true;*/
	
	REP(i, 0, 2) {
		if (puzzle[0][i] == i + 1) counter3++;
		if (puzzle[1][i] == i + 4) counter3++;
		if (puzzle[2][i] == i + 7) counter3++;
		
	}
	if (puzzle[2][3] == 0) counter3++;

	if (counter3 == 8) return true;
	return false;
}

int countStart() {
	int sum = 0;
	REP(q, 0, 8) {
		int row = q / 3;
		int col = q % 3;
		int counter = puzzle[row][col];
		REP(i, 0, 2) {
			REP(j, 0, 2) {
				if ((row < i && puzzle[i][j] < counter && puzzle[i][j] != 0)) {
					sum++;
				}
				else if (row == i && col < j && puzzle[i][j] < counter && puzzle[i][j] != 0) {
					sum++;
				}
			}
		}
	}
	return sum;
}

void prin() {
	REP(i, 0, 2) {
		REP(j, 0, 2) {
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}

void initPuzzle() {
	cout << "Nhap cac gia tri cho puzzle : ";
	cin >> puzzle[0][0] >> puzzle[0][1] >> puzzle[0][2];
	cin >> puzzle[1][0] >> puzzle[1][1] >> puzzle[1][2];
	cin >> puzzle[2][0] >> puzzle[2][1] >> puzzle[2][2];
	costValue = 10000;
	bool checked = true;
	
	int sum = 0;
	REP(i, 0, 2) {
		REP(j, 0, 2) {
			sum += puzzle[i][j];
			if (puzzle[i][j] > 8) {
				checked = false;
				break;
			}
		}
	}
	if (sum != 36 || checked == false) {
		cout << "Nhap sai du lieu vui long nhap lai" << endl;
		return initPuzzle();
	}

	REP(i, 0, 2) {
		REP(j, 0, 2) {
			if (puzzle[i][j] == 0) {
				posX = i;
				posY = j;
				return;
			}
		}
	}
}
void moveLeft() {
	swap(puzzle[posX][posY], puzzle[posX][posY - 1]);
	posY--;
}
void moveRight() {
	swap(puzzle[posX][posY], puzzle[posX][posY + 1]);
	posY++;
}
void moveUp() {
	swap(puzzle[posX][posY], puzzle[posX - 1][posY]);
	posX--;
}
void moveDown() {
	swap(puzzle[posX][posY], puzzle[posX + 1][posY]);
	posX++;
}

int main()
{

	int step = 0;
	ll numOfNode = 0;
	initPuzzle();
	bool check = false;
	string way = "";
	checkValue = countStart() % 2;
	//checkValue = 0;
	Node nd(puzzle, "", STAY, posX, posY, 0, checkValue, costValue);
	vector<Node> vt;
	vt.push_back(nd);
	cout << checkValue <<endl;

	cout << "Trang thai ban dau : " << endl;
	prin();
	cout << "----Start--------" << endl;
	while (!check && vt.size() != 0) {
		vector<Node> open;
		int i = vt.size() - 1;
		if (vt.at(i).checkFinish()) {
			way = vt.at(i).Direction;
			check = true;
			break;
		}
		else {
			if (vt.at(i).checkMoveUp()) {
				Node nd = vt.at(i);
				nd.moveUp();
				open.push_back(nd);
			}
			if (vt.at(i).checkMoveDown()) {
				Node nd = vt.at(i);
				nd.moveDown();
				open.push_back(nd);
			}
			if (vt.at(i).checkMoveRight()) {
				Node nd = vt.at(i);
				nd.moveRight();
				open.push_back(nd);
			}
			if (vt.at(i).checkMoveLeft()) {
				Node nd = vt.at(i);
				nd.moveLeft();
				open.push_back(nd);
			}
		};
		int c = vt.at(i).checkFinish();
		vt.pop_back();
		
		
		REPS(i, 0, open.size()) {
			REPS(j, i + 1, open.size()) {
				if (open.at(i).defaultCost(checkValue, costValue) <= open.at(j).defaultCost(checkValue, costValue)) {
					swap(open.at(i), open.at(j));
				}
			}

		}
		REPS(i, 0, open.size()) {
			if (open.at(i).defaultCost(checkValue, costValue) == open.at(open.size() - 1).defaultCost(checkValue, costValue)) {
				for (int k = 0; k <= 2; k++) {
					for (int j = 0; j <= 2; j++) {
						cout << open.at(i).arr[k][j] << ",";
					};
					cout << endl;
				};
				cout << "------------END---------------" << endl;
				vt.push_back(open.at(i));
			}
		}
		numOfNode++;
	}
	if (!check) {
		cout << "Thuat toan that bai";
		return 0;
	}
	REPS(i, 0, way.length()) {
		if (way[i] == 'l') {
			moveLeft();
			prin();
			cout << "di chuyen sang trai" << endl << endl;
		}
		else if (way[i] == 'r') {
			moveRight();
			prin();
			cout << "di chuyen sang phai" << endl << endl;
		}
		else if (way[i] == 'u') {
			moveUp();
			prin();
			cout << "di chuyen len" << endl << endl;
		}
		else if (way[i] == 'd') {
			moveDown();
			prin();
			cout << "di chuyen xuong" << endl << endl;
		}
	}
	cout << "Thuat toan A sao" << endl;
	cout << "So buoc di = " << way.length() << endl;
	return 0;
}
