

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
			cout <<setw(3)<< arr[i][j]<<"	";
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
//#3/3 Sum Each Row in matrix in another Array
void SumEachRowInMatrixInArray(int arr[3][3],int arrSum[],int row,int col) {
	int sum = 0;
	for (int i = 0; i < row;i++) {
		arrSum[i] = SumEachRowInMatrix(arr, i, col);
	}
}
void PrintArrRowsSum(int arr[],int row) {
	for (int i = 0; i < row; i++) {
		cout << arr[i] << "	";
	}
}
//=====================================
//=====================================
//#4/3 Sum Each Column in Matrix
int SumEachColumnInMatrix(int arr[3][3],int row,int col) {
	int sum = 0;
	for (int i = 0; i < row;i++) {
		sum+=arr[i][col];
	}
	return sum;
}
void PrintEachSumColumnInMatrix(int arr[3][3],int row,int col) {
	cout << "The Following are the sum of each Column in the matrix : \n";
	for (int j = 0; j < col; j++) {
		cout << "Sum of Column "<<j+1<<" = " << SumEachColumnInMatrix(arr, row,j) << endl;
	}
}
//=====================================
//=====================================
//#5/3 Sum Each Row in matrix in another Array
void SumEachColumnInMatrixInAnotherArray(int arr[3][3],int arrSum[],int row ,int col) {
	for (int j = 0; j < row;j++) {
		arrSum[j] = SumEachColumnInMatrix(arr, row,j);
	}
}
void PrintArrColumnSum(int arr[], int col) {
	for (int j = 0; j < col; j++) {
		cout << arr[j] << "	";
	}
}
//=====================================
//=====================================
//#6/3  3x3 Ordered Matrix
void FillOrderedMatrix(int arr[3][3], int row, int col) {
	int counter= 0;
	for (int i = 0; i < row; i++) { 
		for (int j = i; j < col; j++) {//00  01 02
			counter++;
			arr[i][j] = counter;
		}
	}
}
//=====================================
//=====================================
//#7/3 
int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrsum[3];
	
	cout << "Fill Ordered Matrix : \n";
	FillOrderedMatrix(arr, 3, 3);
	PrintMatrix(arr,3,3);


	
}

