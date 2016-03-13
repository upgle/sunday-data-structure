#include <iostream>
using namespace std;

int numOfQueen = 0;

void Make_Board(int num, int** (&board))
{
	board = new int*[num];
	for (int i = 0; i < num; i++)		// N X N 체스판 배열 생성
		board[i] = new int[num];

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			board[i][j] = 0;
}

void Delete_Board(int** (&board))
{

}

void Queen(int num, int** board, int i, int j)
{
	if (numOfQueen == num)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
				cout << board[i][j] << " ";
			cout << endl;
		}

		cout << endl;
		return;
	}

	if (!(i < num && j < num))
		return;

	bool here = true;					// 퀸을 두어도 되는지 확인

	for (int a = 0; a < num; a++)		// 가로줄 검사
		if (board[a][j] == 1)
			here = false;

	for (int b = 0; b < num; b++)		// 세로줄 검사
		if (board[i][b] == 1)
			here = false;

	int x = i;							// 재귀쓸때 i,j 값 바꿔서 쓸거라 임시변수
	int y = j;

	while (1)							// 좌상 방향
	{
		x -= 1;
		y -= 1;

		if (x < 0 || y < 0)
		{
			x = i;
			y = j;
			break;
		}

		if (board[x][y] == 1)
			here = false;

	}

	while (1)							// 우상 방향
	{
		x += 1;
		y -= 1;

		if (x > num - 1 || y < 0)
		{
			x = i;
			y = j;
			break;
		}

		if (board[x][y] == 1)
			here = false;
	}

	while (1)							// 좌하 방향
	{
		x -= 1;
		y += 1;

		if (x < 0 || y > num - 1)
		{
			x = i;
			y = j;
			break;
		}

		if (board[x][y] == 1)
			here = false;
	}

	while (1)							// 우하 방향
	{
		x += 1;
		y += 1;

		if (x > num - 1 || y > num - 1)
		{
			x = i;
			y = j;
			break;
		}

		if (board[x][y] == 1)
			here = false;
	}

	if (here)
	{
		board[i][j] = 1;
		numOfQueen++;
	}

	if (j == num - 1)
		Queen(num, board, i+1, 0);

	else
		Queen(num, board, i, j+1);

	if (board[i][j] == 1)
	{
		board[i][j] = 0;
		numOfQueen--;

		if (j == num - 1)
			Queen(num, board, i+1, 0);

		else
			Queen(num, board, i, j+1);
	}

	if (i != 0 && j == 0)
	{
		i--;
		j = num - 1;
	}
	else
		j--;

}

void Show_board(int num, int** board)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cout << board[i][j] << " ";

		cout << endl;
	}
}

int main(void)
{
	int num;
	int** board = NULL;
	cout << "N X N 체스판에 N 개의 여왕이 서로 공격하지 못하게 배치합니다." << endl << "N 의 값은? : ";
	cin >> num;

	Make_Board(num, board);
	
	Queen(num, board, 0, 0);
	//for (int i = 0; i < num; i++)
	//{
	//	Queen(num, board, 0, i);
		//Show_board(num, board);
	//	numOfQueen = 0;
	//	for (int a = 0; a < num; a++)
	//		for (int b = 0; b < num; b++)
	//			board[a][b] = 0;
	//}

	for (int i = 0; i < num; i++)
		delete[] board[i];
	delete[] board;

	return 0;
}
