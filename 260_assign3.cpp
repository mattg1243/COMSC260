// NOTE: The ONLY files that should be #included for this assignment are iostream,  
// cmath (for the pow function), 
// and string
// No other files should be #included

#include <iostream>
#include <cmath>
#include <string>


// NOTE: The ONLY files that should be #included for this assignment are iostream,  
// cmath (for the pow function), 
// and string
// No other files should be #included

using namespace std;

string addbin(string, string);  
string addhex(string, string); 
// adds leading 0s to binary strings to make addition easier
string bitExtension(string, int);


int main()
{
	
	cout<<"binary 1101 + 1000 = "<<addbin("1101", "1000")<<endl;   //you should get 10101
	cout<<"binary 11000 + 1011 = "<<addbin("11000", "1011")<<endl; //you should get 100011
	cout<<"binary 11111111 + 1 = "<<addbin("11111111", "1")<<endl; //you should get 100000000
	cout<<"binary 101010 + 10 = "<<addbin("101010", "10")<<endl<<endl; //you should get 101100
	
	cout<<"hexadecimal A4 + A5 = "<<addhex("A4", "A5")<<endl;  //you should get 149
	cout<<"hexadecimal 2B + C = "<<addhex("2B",  "C")<<endl;    //you should get 37
	cout<<"hexadecimal FABC + 789 = "<<addhex("FABC", "789")<<endl;  //you should get 10245
	cout<<"hexadecimal FFFFFF + FF = "<<addhex("FFFFFF", "FF")<<endl<<endl; //you should get 10000FE 
	

	system("PAUSE");
	return 0;
	
}

// need to implement the bitExtension function to make the args the same length...
string addbin(string bin1, string bin2)
{
	// initialize variables and reutrn value
	int carry = 0;
	int asciiSum = 0;
	int shortestLength = bin1.length() > bin2.length() ? bin2.length() : bin1.length(); 
	cout << "Shortest length test : " << shortestLength << endl;
	string totalSum = "";
	// loop through all bits of the smallest binary string
	for (int i = 0; i < shortestLength; i++) {
		asciiSum += (bin1[i] + bin2[i]);
		// if the sum of the ASCII codes of the chars is 96, the bit = 0
		if (asciiSum == 96) {
			totalSum.insert(0, "0");
		} else if (asciiSum == 97) {
			// sum of 97 means the bit = 1
			totalSum.insert(0, "1");
		} else if (asciiSum == 98) {
			// otherwise, there is a carry to the next bit position
			carry = 1;
			// and a 1 is still put at that bit position
			totalSum.insert(0, "1");
		}
		// if there is a carry, handle it
		if (carry == 1) {
			asciiSum = 1;
		} else {
			// otherwise, reset it to 0
			asciiSum = 0;
		}
	}
	return totalSum;
}

string addhex(string hex1, string hex2)
{
cout << "addhex" << endl;
	
}

// my own functions
// extends a binary strings bits with leading zeros
string bitExtension(string bin, int desiredLength) {
	string strToInsert = "";
	// create a string full of zeros of the rigth length
	for(int i = 0; i < desiredLength - bin.length(); i++) {
		strToInsert.insert(0, "0");
	}
	cout << "bitExtension test: " << strToInsert << endl;
	return strToInsert;
}