#include <iostream>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
	const int ROWS = 4;  
	
	
	int testArray[ROWS][COLS] =
					{ 
						{ 5, 7, 6, 3, 2 },
						{ 17, 32, 53, 23, 42 },
						{ 12, 37, 67, 82, 13 },
						{ 1, 0, 59, 92, 10 } 
					};
   
	
	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;
   
	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;


	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;

	
	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;

    
	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;

	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;
        
    system("PAUSE");

	return 0;
}


int getTotal(int array[][COLS], int rows)
{
	// initialize the return value
	int sum = 0;
	// traverse the array by row
	for (int i = 0; i < rows; i++) {
		// iterate through each element in the row and then move on to the next one
		for (int j = 0; j < COLS; j++) {
			sum += array[i][j];
		}
	}
	return sum;
}


double getAverage(int array[][COLS], int rows)
{
	// get the sum of all values in the array
	int sum = getTotal(array, rows);
	// return the total / number of elements
  return sum / (static_cast<float>(rows) * COLS);
}


int getRowTotal(int array[][COLS], int rowToTotal)
{
	// initialize return value
	int rowTotal = 0;
	// traverse the specified row and add all the values into sum
	for (int i = 0; i < COLS; i++) {
		rowTotal += array[rowToTotal][i];
	}
	return rowTotal;
}


int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
	// initialize return value
	int colTotal = 0;
	// traverse the specified column and add all the values into sum
	for (int i = 0; i < rows; i++) {
		colTotal += array[i][colToTotal];
	}
	return colTotal;
}


int getHighestInRow(int array[][COLS], int rowToSearch)
{
	// initialize return value to minimum possible integer value
	int high = INT_MIN;
	// traverse the specified row and reassign return value when a higher number is found
	for (int i = 0; i < COLS; i++) {
		// reassign return value when a higher number is found
		if (array[rowToSearch][i] > high) {
			high = array[rowToSearch][i];
		}
		// otherwise, keep looking
	}
	return high;
}


int getLowestInRow(int array[][COLS], int rowToSearch)
{
	// initialize return value to minimum possible integer value
	int low = INT_MAX;
	// traverse the specified row
	for (int i = 0; i < COLS; i++) {
		// reassign return value when a lower number is found
		if (array[rowToSearch][i] < low) {
			low = array[rowToSearch][i];
		}
		// otherwise, keep looking
	}
	return low;
}

