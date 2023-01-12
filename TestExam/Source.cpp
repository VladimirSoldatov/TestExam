#include<iostream>
#include<random>
#include<iomanip>

using namespace std;
random_device dev;
mt19937 rnd(dev());
uniform_int_distribution<> gen(1, 99);

class Cell
{
	int row;
	int column;
	int value;
public:
	Cell(int _column, int _row, int _value) :column{ _column }, row{ _row }, value{ _value } {}
	int Value() { return value; }
	int Column() { return column; }
	int Row() { return row; }
};
typedef vector<Cell> cells;
ostream& operator<<(ostream& ost, vector<cells> temp)
{
	return ost << temp;
 }

class Matrix 
{
	vector<cells> myMap;//vector<vector<Cell>>
	cells line;
	int rows;
	int columns;
public:
	Matrix(int _columns, int _rows)
	{
		columns = _columns;
		rows = _rows;
		for (int i = 0; i < columns; i++)
		{
			
			for (int j = 0; j < rows; j++)
			{
				//cout << "Enter values: ";
				int a = gen(rnd);
				line.push_back(Cell(i, j, a));
			}
			myMap.push_back(line);
			line.clear();
		}
	}
	void push_line(Cell temp) 
	{
		line.push_back(temp);
	}
	void push_stroka(cells temp)
	{
		myMap.push_back(temp);
	}
	friend ostream& operator<<(ostream& ost, Matrix obj)
	{
		return ost << obj.myMap;
	}
	 cells operator[](int index)
	{
		 return myMap[index];
	}
	void print()
	{
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout <<setw(2) <<myMap[i][j].Value() <<" ";
				
			}
			cout << "\n";
		}
	}

};

void insert_values(int** massive, int columns, int rows)
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			massive[i][j] = gen(rnd);
		}
		
	}
}
void print_array(int** massive, int columns, int rows)
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << setw(4) << massive[i][j] << " ";
		}
		cout << "\n\n";
	}
}
void sum_arround(int** massive, int x, int y, int columns, int rows)
{
	int sum = 0;
	for (int i = -1; i< 2; i++)
		for (int j = -1; j < 2; j++)
		{
			int cur_col = x + i;
			int cur_row = y + j;
			bool inLine = (cur_col >= 0
				&& cur_col < columns
				&& cur_row >= 0
				&& cur_row < rows);
			bool isSelf = (cur_col == x && cur_row == y);
			if (!isSelf && inLine)
				sum += massive[cur_col][cur_row];

		}
	cout << "Summa around " << massive[x][y] << " is " << sum << endl;
}
void sum_diag(int** massive, int columns, int rows, int os)
{
	int sum = 0;
	if (os == 1)
		cout << "Second:";
	else
		cout << "First: ";
	for (int i = 0; i < columns; i++)
	{
		
		int cur_col;;
		if (os == 1)
		{
			cur_col = columns - 1 - i;
		
		}
		else
		{
			cur_col = i;
			
		}
		cout << massive[cur_col][i] << " ";
			sum += massive[cur_col][i];
	}
	cout << "\n\n";
	if (os == 0)
		cout << "First diag: " << sum << endl;
	else
		cout << "Second diag: " << sum << endl;


}

int main()
{
/*	int columns = 10;
	int rows = 10;
	int** array = new int* [columns];
	for (int i = 0; i < columns; i++)
	{
		array[i] = new int[rows];
	}
	insert_values(array, columns, rows);
	print_array(array, columns, rows);
	sum_diag(array, columns, rows, 0);
	sum_diag(array, columns, rows, 1);
	sum_arround(array, 5, 5, columns, rows);
	*/
	Matrix m(10, 10);
	m.print();
	int a, b;
	cout << "Enter stolbec: ";
	cin >> a;
	cout << "Enter stroka: ";
	cin >> b;
	m[b][a] = 10;
	return 0;
}