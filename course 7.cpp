

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
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
//#20/3 Plaindrome Number
bool IsPlaindromeMatrix(int arr[3][3],int row,int col) {
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col/2;j++) {
			if (arr[i][j]!=arr[i][col-1-j]) {
				return false;
			}
		}
	}
	return true;
}
//=====================================
//=====================================
//#21/3 Fibonacci Series 
void FibonacciSeries(int Num) {
	int prev1 = 1; // p1 = 1   p2 = 0   fib= 1 
					// p1=0    p2=1    fib=1
					//p1=1     p2=1    fib =2.....
	int prev2 = 0;
	int FibNumber = 0;
	for (int i = 0; i < Num;i++) {
		FibNumber = prev1 + prev2;
		cout << FibNumber<<"	";
		prev1 = prev2;
		prev2 = FibNumber;
	}
}
//=====================================
//=====================================
//#22/3 Fibonacci Series with recersion
void FibnacciSeriesWithRecursion(int Num,int prev1,int prev2) {
	int FibNumber = 0;
	if (Num>0) {
		FibNumber = prev2 + prev1;
		prev2 = prev1;
		prev1 = FibNumber;
		cout << FibNumber << "	";
		FibnacciSeriesWithRecursion(Num-1,prev1,prev2);
	}
}
//=====================================
//=====================================
//#23/3 Print First Letter of Each Word 
string ReadString() {
	string s;
	cout << "Enter Text:\n";
	getline(cin, s);
	return s;
}
void PrintFirstLetterOfEachWord(string Word){
	bool FirstLetter = true;
	for (int i = 0; i < Word.length();i++) {
		if (Word[i] !=' ' && FirstLetter) {
			cout << Word[i] << "	";
		}
		FirstLetter = (Word[i] == ' ' ? true : false);
	}
}
//=====================================
//=====================================
//#24/3 Upper First Letter of Each Word
string UpperFirstLetter(string Word) {
	bool FirstLetter = true;
	for (int i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ' && FirstLetter) {
			Word[i] = toupper(Word[i]);
		}
		FirstLetter = (Word[i] == ' ' ?true:false);
	}
	return Word;
}
//=====================================
//=====================================
//#25/3 Lower First Letter of Each Word
string LowerFirstLetter(string Word) {
	bool FirstLetter = true;
	for (int i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ' && FirstLetter) {
			Word[i] = tolower(Word[i]);
		}
		FirstLetter = (Word[i] == ' ' ? true : false);
	}
	return Word;
}
//=====================================
//=====================================
//#26/3 Upper/Lower all Letter of String
string UpperAllLetterOfString(string Word) {
	for (int i = 0; i < Word.length(); i++) {
			Word[i] = toupper(Word[i]);
	}
	return Word;
}
string LowerAllLetterOfString(string Word) {
	for (int i = 0; i < Word.length(); i++) {
		Word[i] = tolower(Word[i]);
	}
	return Word;
}
//=====================================
//=====================================
//#27/3 Invert Charcter Case 
char ReadChar() {
	char c;
	cout << "Enter Char :\n";
	cin >> c;
	return c;
}
char InverCharcterCase(char c) {
	return (islower(c) ? toupper(c) : tolower(c));
}
//=====================================
//=====================================
//#28/3  Invert All Letter Case 
string InvertAllLetterCase(string Word) {
	for (int i = 0; i < Word.length();i++) {
		Word[i]=InverCharcterCase(Word[i]);
	}
	return Word;
}
//=====================================
//=====================================
//#29/3 Count Small and Capial Letters
int CountSmallLetter(string Word) {
	int CountsmallLetter = 0;
	for (int i = 0; i < Word.length(); i++) {
		if (islower(Word[i])) {
			CountsmallLetter++;
		}
	}
	return CountsmallLetter;
}
int CountCapitalLetter(string Word) {
	int CountCapital = 0;
	for (int i = 0; i < Word.length(); i++) {
		if (isupper(Word[i])) {
			CountCapital++;
		}
	}
	return CountCapital;
}
//Count small-capital Letters Another Way solution
enum enWhatToCont {Small=1 , Capital=2, All=3};
short CountSmallAndCapitalLetters(string Word, enWhatToCont WhatToCount=enWhatToCont::All) {
	short counter = 0;
	if (WhatToCount==enWhatToCont::All) {
		return Word.length();
	}
	for (int i = 0; i < Word.length(); i++) {
		if (WhatToCount==enWhatToCont::Small && islower(Word[i])) {
			counter++;
		}
		if (WhatToCount==enWhatToCont::Capital && isupper(Word[i])) {
			counter++;
		}
	}
	return counter;
}
//=====================================
//=====================================
//#30/3 Count Letters
int CountLetters(string Word,char c) {
	int count = 0;
	for (int i = 0; i < Word.length(); i++) {
		if (Word[i]==c) {
			count++;
		}
	}
	return count;
}
//=====================================
//=====================================
//#31/3 Count Letters (Match Case)
short CountLettersCase(string Word,char C,bool MatchCase=true) {
	short counter = 0;
	for (int i = 0; i < Word.length();i++) {
		if (MatchCase) {
			if (Word[i]==C) {
				counter++;
			}
		}
		else {
			if (towlower(Word[i])==tolower(C)) {
				counter++;
			}
		}
	}
	return counter;
}
//=====================================
//=====================================
//#32/3 Is Vowel ? 
bool IsVowel(char c) {
	c = tolower(c);
	return ((c == 'a') || (c == 'e') ||(c == 'i') || (c == 'o') || (c == 'u'));
}
//=====================================
//=====================================
//#33/3 Count Vowel
short CountVowel(string Word) {
	short counter = 0;
	for (int i = 0; i < Word.length(); i++) {
		if (IsVowel(Word[i])) {
			counter++;
		}
	}
	return counter;
}
//=====================================
//=====================================
//#34/3 Print ALl Vowels In String
void PrintAllVowelsInString(string Word) {
	for (int i = 0; i < Word.length(); i++) {
		if (IsVowel(Word[i])) {
			cout << Word[i] << "	";
		}
	}
}
//=====================================
//=====================================
//#35/3 Print Each Word In String
void PrintEachWordInString(string S1) {
	string delim = " ";
	short pos = 0;
	string sWord;
	while ((pos=S1.find(delim)) != std::string::npos) {
		sWord = S1.substr(0,pos);
		if (sWord!="") {
			cout << sWord << endl;
		}
		S1.erase(0, pos + delim.length());
	}
	if (S1!="") {
		cout << S1 << endl;
	}
}
//=====================================
//=====================================
//#36/3  Count Each Word In S{tring
short CountEachWordInString(string S1) {
	string delim = " ";
	short pos = 0;
	string sWord;
	short count = 0;
	while ((pos=S1.find(delim)) != std::string::npos ) {
		sWord = S1.substr(0,pos);
		if (sWord!="") {
			count++;
		}
		S1.erase(0,pos+delim.length());
	}	
	if (S1 != "") {
		count++;
	}
	return count;
}
//=====================================
//=====================================
//#37/3 Split String 
vector<string> SplitString(string S1 , string delim=" ") {
	vector <string> Snew;
	short pos=0;
	short token=0;
	string sWord;
	
	while ((pos = S1.find(delim)) != std::string::npos) {
		sWord = S1.substr(0,pos);
		if (sWord!="") {
			Snew.push_back(sWord);
		}
		S1.erase(0,pos+delim.length());
	}
	if (S1 != "") {
		Snew.push_back(S1);
	}
	return Snew;
}
void PrintSplitString(vector<string>S) {
	for (string &news : S) {
		cout << news << endl;
	}
}
//=====================================
//=====================================
//#38/3 Trim Left , Trim Right ,Trim
string TrimRight(string S1) {//012345nabeh012345
	for (int i = S1.length()-1; i >=0;i--) {//nabeh012345
		if( S1[i] != ' ') {
		return S1.substr(0,i+1);
		}
	}
	return "";
}
string TrimLeft(string S1) {//0123nabeh
	for (int i = 0; i < S1.length(); i++) {//i=4 
		if (S1[i] != ' ') {
		return S1.substr(i,S1.length()-i);
		}
	}
	return "";
}
string Trim(string S1) {
	return (TrimRight(TrimLeft(S1)));
}
//=====================================
//=====================================
//39/3 Join String
string JoinString(vector<string>vString, string delim = "/") {
	string S1 = "";
	for (string& s : vString) {
		S1 = S1 + s + delim;
	}
	return S1.substr(0,S1.length() - delim.length() );
}
//=====================================
//=====================================
//40/3 Join String (Over Loading)
string JoinString(string arr[],short length,string delim="/") {
	string sWord = "";
	for (int i = 0; i < length;i++) {
		sWord = sWord + arr[i] + delim;
	}
	return sWord.substr(0,sWord.length()-delim.length());
}
//=====================================
//=====================================
//#41/3 Reverse Word
string ReversWordsInString(string S1) {
	vector<string> vString=SplitString(S1," ");
	string S2 = "";
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin()) {
		--iter;
		S2 = S2 + *iter + " ";
	}
	S2 = S2.substr(0,S2.length()-1);
	return S2;
}
//=====================================
//=====================================
//#42/3 Replace Word
string ReplaceWord(string S1 , string sToReplace,string ReplaceTo) { //Nabeh  >- mhmd
	short pos = S1.find(sToReplace);
	while (pos != std::string::npos) {
		S1.replace(pos , sToReplace.length(), ReplaceTo);
		pos = S1.find(sToReplace);
	}
	return S1;
}
//=====================================
//=====================================
//#43/3 Replace Word (Custom)
string ReplaceWordCustom(string S1 , string StringToReplace, string ReplaceTo,bool MatchCase=true) {

	vector<string> vString = SplitString(S1," ");

	for (string& Vs : vString) {
		if (MatchCase) {
				if (Vs == StringToReplace) {
					Vs = ReplaceTo;
				}
		}
		else {
				if (LowerAllLetterOfString(Vs)==LowerAllLetterOfString(StringToReplace)) {
				Vs = ReplaceTo;
				}
			}
	}
	return JoinString(vString," ");
}
//=====================================
//=====================================
//#44/3 Remove Punctuations
string RemovePunctuation(string S1) {
	string S2 = "";
	for (int i = 0; i < S1.length();i++) {
		if (!ispunct(S1[i])) {
			S2 += S1[i];
		}
	}
	return S2;
}
//=====================================
//=====================================
//#45/3 Convert Record To Line 
const string ClientsFileName = "Client.txt";
struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};
stClient ReadNewClient() {
	stClient C1;
	cout << "Please Enter Client Data:\n\n";
	cout << "Enter Account Number ? ";
	getline(cin, C1.AccountNumber);
	cout << "Enter PinCode ? ";
	getline(cin, C1.PinCode);
	cout << "Enter Name ? ";
	getline(cin,C1.Name);
	cout << "Enter Phone ? ";
	getline(cin,C1.Phone);
	cout << "Enter AccountBalance ? ";
	cin >> C1.AccountBalance;
	return C1;
}
string ConvertRecordToLine(stClient C1 , string seperator) {
	string stClientRecord = "";
	stClientRecord += C1.AccountNumber + seperator;
	stClientRecord += C1.PinCode + seperator;
	stClientRecord += C1.Name + seperator;
	stClientRecord += C1.Phone + seperator;
	stClientRecord += to_string(C1.AccountBalance);

	return stClientRecord;
}
//=====================================
//=====================================
//#46/3 Convert Line Data to Record
stClient ConvertLineToRecord(string line , string seperator="#//#") {	
	stClient Client;
	vector<string> vClientData;
	vClientData = SplitString(line,seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1]; 
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); //cast string to double
	
	return Client;
}
void PrintClientRecord(stClient CLient) {
	cout << "\n\nThe following is the extracted client record :\n";
	cout << "Account Number : " << CLient.AccountNumber << endl;
	cout << "PinCode : " << CLient.PinCode << endl;
	cout << "Name : " << CLient.Name << endl;
	cout << "Phone : " << CLient.Phone << endl;
	cout << "Account Ballance : " << CLient.AccountBalance << endl;
}
//=====================================
//=====================================
//#47/3 Add Client To File
void AddDataLineToFile(string FileName, string line) {
	fstream Myfile;
	Myfile.open(FileName,ios::out | ios::app);

	if (Myfile.is_open()) {
		Myfile << line << endl;

		Myfile.close();
	}
}
void AddNewClient() {
	stClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client,"#//#"));
}
void AddClients() {
	char y='y';
	do {
		system("cls");
		cout << "Adding New Client : \n";
		AddNewClient();
		cout << "\nClient Added Successfully , do you want add more clients (y/n)?";
		cin >> y; 
	} while (y=='y'||y=='Y');
}
//=====================================
//=====================================
//#48/3 Show ALl Clients 

//=====================================
//=====================================
//#49/3
//=====================================
//=====================================
//#50/3
//=====================================
//=====================================
//#51/3
int main()
{
	srand((unsigned)time(NULL));

	//stClient C1=ReadNewClient();

	AddNewClient();

	system("pause>0");
	
}

