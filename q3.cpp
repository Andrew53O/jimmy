#include<iostream>
#include<string.h>
#include<string>
using namespace std;

class TwoD
{
public:
	TwoD();
	TwoD(int _row, int _col);
	TwoD(TwoD&);
	~TwoD();
	int** getArr();
	int getRow();
	int getCol();
	void setArr(int **arr);
	void setRow(int row);
	void setCol(int col);
	void setValue(int r,int c, int value);
	TwoD& operator =(TwoD& arr2);
	TwoD& operator +(TwoD& arr2);
	
	
	
private:
	int **arr;
	int row;
	int col;
};



int main()
{
	int row1, col1;
	int row2, col2;
	int value;
	int **arr;
	TwoD matrix3;
	
	cout << "Enter the row and column dimensions of the array" << endl;
	cin >> row1 >> col1;
	// matrix1 has the pointer after this code
	TwoD matrix1(row1, col1);
	
	cout << "Enter " << row1 << " of " << col1 << " integer each" << endl;
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<col1;j++)
		{
			cin >> value;
			matrix1.setValue(i ,j ,value);
		}
	}
	
	cout << "Enter the row and column dimensions of the array" << endl;
	cin >> row2 >> col2;
	
	// matrix2 has the pointer after this code
	TwoD matrix2(row2, col2);	
	
	cout << "Enter " << row2 << " of " << col2 << " integer each" << endl;
	for(int i=0;i<row2;i++)
	{
		for(int j=0;j<col2;j++)
		{
			cin >> value;
			matrix2.setValue(i ,j ,value);
		}
	}
	cout << endl;

	// testing matrix1 and matrix 2

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			cout <<" testing  code " <<matrix1.getArr()[i][j] << " ";
		}
		cout << endl;
	}

	// until this no problem
	
	cout << "matrix3 = matrix2" << endl;
	matrix3 = matrix2;
	cout << "matrix3 = " << endl;
	arr = matrix3.getArr();
	
	for(int i=0;i<matrix3.getRow();i++)
	{
		for(int j=0;j<matrix3.getCol();j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "matrix3 = matrix1 + matrix2" << endl;
	
	matrix3 = matrix1 + matrix2;
	cout << "matrix3 = " << endl;
	arr = matrix3.getArr();
	
	for(int i=0;i<matrix3.getRow();i++)
	{
		for(int j=0;j<matrix3.getCol();j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}	
	
	
	
}

TwoD& TwoD:: operator +(TwoD& arr2)
{
	/*TwoD tempArr(row, col);
	int** tArr = new int*[col];
	for(int i=0;i<row;i++)
		tArr[i] = new int [row];*/

	cout << "(1)" << endl; 
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout << "(11)" << endl;
			arr[i][j] += arr2.arr[i][j];
			//tArr[i][j] = arr[i][j] + arr2.arr[i][j];
			//tempArr.setRow(row + arr2.row);
			//tempArr.setCol(col + arr2.col);
		}
	}
	//tempArr.setArr(tArr);
	return *this;
}

TwoD& TwoD:: operator =(TwoD& arr2)
{
	row = arr2.row;
	col = arr2.col;
	// problem 1, no pointee (no thing that can be pointed by the calling object)
	
	// make the pointee
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	cout << "(0)" << endl;

	cout << "(1)" << endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			arr[i][j] = arr2.arr[i][j];
		}
	}
	return *this;
}

TwoD:: TwoD()
{
	
}

TwoD:: TwoD(int _row, int _col)
{
	row = _row;
	col = _col;
	arr = new int*[col];
	for(int i=0;i<row;i++)
		arr[i] = new int [row];
}

//copy constructor
TwoD:: TwoD(TwoD& arr2)
{
	int **tempArr = arr2.getArr();
	row = arr2.getRow();
	col = arr2.getCol();
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			arr[i][j] = tempArr[i][j];
		}
	}
}

TwoD:: ~TwoD()
{
	for(int i=0;i<row;i++)
		delete [] arr[i];
	delete [] arr;	
}

int** TwoD:: getArr()
{
	return arr;
}

int TwoD:: getRow()
{
	return row;
}

int TwoD:: getCol()
{
	return col;
}

void TwoD:: setArr(int **arr)
{
	this -> arr = arr; 
}

void TwoD:: setRow(int row)
{
	this -> row = row;
}

void TwoD:: setCol(int col)
{
	this -> col = col;
}

void TwoD:: setValue(int r, int c, int value)
{
	arr[r][c] = value;
}
