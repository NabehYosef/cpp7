

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomNumber(int From , int To) {
	int random= rand() % (To - From + 1) + From; 
	return random;
}
//#1/3 Random matrix 
void FillMatrixWithRandomNumbers(int arr[3][3] , short Rows,short Columns) {
	for (int i = 0; i < Rows;i++) {
		for (int j = 0; j < Columns;j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Columns) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Columns; j++) {
			cout <<setw(3)<< arr[i][j];
		}
		cout << endl;
	}
}
//=====================================
//=====================================
//#2/3 Sum Each Row in Matrix	
int SumEachRowInMatrix(int arr[3][3],int Rows,int Columns) {
	int sumeachrow = 0;
	for (int j = 0; j < Columns;j++) {
		sumeachrow += arr[Rows][j];
	}
	return sumeachrow;
}
void PrintEachRowSum(int arr[3][3],int row,int col) {
	cout << "The Following are the sum of each row in the matrix : \n";
	for (int i = 0; i < row;i++) {
		cout <<"Row "<<i+1<<" Sum = "<< SumEachRowInMatrix(arr, i, col) << endl;
	}
}
//=====================================
//=====================================
//#3/3 Sum Each Row in matrix in Array
void SumMatixRowsInArry(int arr[3][3],int arrSum[3],int row,int col) {
	for (int i = 0; i < row;i++) {
		arrSum[i] = SumEachRowInMatrix(arr, i, col);
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << endl;
	PrintEachRowSum(arr, 3, 3);

	
}

