

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
			//printf(" 0%d	",2,arr[i][j]);
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
		for (int j = 0; j < col; j++) {//00  01 02
			counter++;
			arr[i][j] = counter;
		}
	}
}
//=====================================
//=====================================
//#7/3 Traspose Matrix 
void TransposeMatrix(int arr[3][3],int arrTranspose[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arrTranspose[i][j] = arr[j][i];
		}
	}
}
//=====================================
//=====================================
//#8/3 Multiply Two Matrix
void MultiplyMatrix(int arr1[3][3], int arr2[3][3],int Result[3][3], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Result[i][j]=arr1[i][j] * arr2[i][j];
		}
	}
}
//=====================================
//=====================================
//#9/2 Print Middle Row and Column of Matrix 
void PrintMiddleRowInMatrix(int arr[3][3],int row,int col) {
	int middlerow = row / 2;
	for (int j = 0; j < col; j++) {
		cout << arr[middlerow][j]<<"	";
		//printf("0%d	", 2, arr[middlerow][j]);
	}
}
void PrintMiddleColumnInMatrix(int arr[3][3], int row, int col) {
	int middlecol = col / 2;
	for (int i =0; i < row; i++) {
		cout << arr[i][middlecol] << "	";
		//printf("0%d	",2,arr[i][middlecol]);
	}
}
//=====================================
//=====================================
//#10/3 Sum of Matrix 
int SumofMatrix(int arr[3][3],int row,int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
//=====================================
//=====================================
//11/3 Check Matrix Equality 
bool CheckMatrixEquality(int arr1[3][3],int arr2[3][3],int row,int col) {

	return (SumofMatrix(arr1, row, col) == SumofMatrix(arr2, row, col));
	
}
//=====================================
//=====================================
//12/3 Check Typical Matrix 
bool CheckTypicalMatrix(int arr1[3][3], int arr2[3][3], int row, int col){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr1[i][j]!=arr2[i][j]) {
				return false;
			}
		}
	}
	return true;
}
//=====================================
//=====================================
//13/3 Check Identity Matrix
//My Solution
bool CheckIdentityMatrix(int arr1[3][3],int row ,int col) {
	for (int i = 0; i < row; i++) {//0	1  2	 
		for (int j = i; j <= i; j++) {//0	1	2
			if (i==j && arr1[i][j] != 1) {
				return false;
			}
			if (i!=j && arr1[i][j]!=0) {
				return false;
			}
		}
	}
	return true;
}
//=====================================
//=====================================
//#14/3 Check Scalar Matrix 
bool CheckScalarMatrix(int arr1[3][3], int row, int col) {
	int FirstDiagElements = arr1[0][0];
	for (int i = 0; i < row; i++) {//0	1  2	 
		for (int j = i; j <= i; j++) {//0	1	2
			if (i == j && arr1[i][j] != FirstDiagElements) {
				return false;
			}
			if (i != j && arr1[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}
//=====================================
//=====================================
//15/3 Count Number in Matrix
int CountNumberInMatrix(int arr[3][3] ,int row, int col,int Num) {
	int counter = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j]==Num) {
				counter++;
			}
		}
	}
	return counter;
}
//=====================================
//=====================================
//16/3 Check Sparse Matrix
bool IsSparseMatrix(int arr[3][3], int row, int col) {
	int counterNum = 0;
	int counterZero = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0) {
				counterZero++;
			}
			else {
				counterNum++;
			}
		}
	}
	return counterZero > counterNum;
}
//instructor Solution 
bool IsSparseMatrixWay2(int arr[3][3], int row, int col) {
	int MatrixSize = row * col;
	return (CountNumberInMatrix(arr, row, col, 0) >= (MatrixSize / 2));
}
//=====================================
//=====================================
//#17/3 Check Number exist in Matrix
bool CheckNumberInMatrix(int arr[3][3], int row, int col, int Num) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == Num) {
				return true;
			}
		}
	}
	return false;
}
//=====================================
//=====================================
//#18/3 Intersected Numbers  in Matrix
void PrintIntersectedNumbers(int arr1[3][3],int arr2[3][3],int row,int col) {
	int num;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			num = arr1[i][j];	
			if (CheckNumberInMatrix(arr2,row,col,num)) {
				cout << num << "	";
			}
		}
	}
}
//=====================================
//=====================================
//#19/3 Min/Max Numbers  in Matrix
int MaxNumberInMatrix(int arr1[3][3], int row, int col) {
	int MaxNumber = arr1[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr1[i][j] > MaxNumber) {
				MaxNumber = arr1[i][j];
			}
		}
	}
	return MaxNumber;
}
int MinNumberInMatrix(int arr1[3][3], int row, int col) {
	int MinNumber = arr1[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr1[i][j] < MinNumber) {
				MinNumber = arr1[i][j];
			}
		}
	}
	return MinNumber;
}
//=====================================
//=====================================
//#20/3 Plainfrome Number
int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	int arr2[3][3];
	//int arrResult[3][3];
	//int arrsum[3]; 
	//int arrTranspose[3][3];

/*
cout << "Fill Ordered Matrix : \n";
	FillMatrixWithRandomNumbers(arr1, 3, 3);
	cout << "Matrix 1 :\n";
	PrintMatrix(arr1, 3, 3);
	FillMatrixWithRandomNumbers(arr2, 3, 3);
*/	
	int arr[3][3] = {
		1,2,3,
		0,1,8,
		0,0,1
	};
	int arr3[3][3] = { 9,1,1,2,9,3,0,9,8 };
	//FillMatrixWithRandomNumbers(arr1, 3, 3);
	PrintMatrix(arr, 3, 3);
	cout << "================\n";
	PrintMatrix(arr3, 3, 3);
	cout << "================\n";

	cout << "Max Number arr : " << MaxNumberInMatrix(arr,3,3) << endl;
	cout << "Max Number arr3 : " << MaxNumberInMatrix(arr3,3,3) << endl;


	system("pause>0");
	
}

