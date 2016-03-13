#include <iostream>

using namespace std;

int numOfQueen = 0;

void Make_Board(int num, int** (&board))
{
	board = new int*[num];
	for (int i = 0; i < num; i++)		// N X N ü���� �迭 ����
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

	bool here = true;					// ���� �ξ �Ǵ��� Ȯ��

	for (int a = 0; a < num; a++)		// ������ �˻�
		if (board[a][j] == 1)
			here = false;

	for (int b = 0; b < num; b++)		// ������ �˻�
		if (board[i][b] == 1)
			here = false;

	int x = i;							// ��;��� i,j �� �ٲ㼭 ���Ŷ� �ӽú���
	int y = j;

	while (1)							// �»� ����
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

	while (1)							// ��� ����
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

	while (1)							// ���� ����
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

	while (1)							// ���� ����
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
	cout << "N X N ü���ǿ� N ���� ������ ���� �������� ���ϰ� ��ġ�մϴ�." << endl << "N �� ����? : ";
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