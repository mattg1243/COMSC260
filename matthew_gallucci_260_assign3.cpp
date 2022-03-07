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
int hex_char_to_int(char);


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
	string extendedArg;
	string untouchedArg;
	// get the length of the longest argument
	int length = bin1.length() > bin2.length() ? bin1.length() : bin2.length();
	// extend the other argument to match the length of the other 
	if (bin1.length() < length) {
		extendedArg = bitExtension(bin1, length);
		untouchedArg = bin2;
	} else {
		extendedArg = bitExtension(bin2, length);
		untouchedArg = bin1;
	}
	string totalSum = "";
	// loop through all bits of the smallest binary string
	for (int i = length - 1; i >= 0; i--) {
		asciiSum += (extendedArg[i] + untouchedArg[i]);
		// if the sum of the ASCII codes of the chars is 96, the bit = 0
		if (asciiSum == 96) {
			totalSum.insert(0, "0");
		} else if (asciiSum == 97) {
			// sum of 97 means the bit = 1
			totalSum.insert(0, "1");
		} else if (asciiSum == 98) {
			// otherwise, there is a carry to the next bit position
			carry = 1;
			// and a 0 is put at that bit position
			totalSum.insert(0, "0");
		}
		// if there is a carry, handle it
		if (carry == 1) {
			asciiSum = 1;
		} else {
			// otherwise, reset it to 0
			asciiSum = 0;
		}
	}
	// check if there is a carry after adding the last bits
	if (asciiSum == 1) {
		totalSum.insert(0, "1");
	}
	cout << "TotalSum: " << totalSum << endl;
	return totalSum;
}

string addhex(string hex1, string hex2)
{
	// initialize variables and reutrn value
	int carry = 0, columnSum = 0;
	string extendedArg, untouchedArg, totalSum = "";
	// get the length of the longest argument and extend the other
	int length = hex1.length() > hex2.length() ? hex1.length() : hex2.length();
	if (hex1.length() < length) {
		extendedArg = bitExtension(hex1, length);
		untouchedArg = hex2;
	} else {
		extendedArg = bitExtension(hex2, length);
		untouchedArg = hex1;
	}
	// iterate through the hex strings starting from the LSB and add
	for (int i = length - 1; i >= 0; i--) {
		columnSum += hex_char_to_int(extendedArg[i]) + hex_char_to_int(untouchedArg[i]);
		// handle the addition of the column
		if (columnSum > 15) {
			totalSum.insert(0, to_string(columnSum % 16));
			carry = 1;
		} else {
			totalSum.insert(0, to_string(columnSum));
		}
		// if theres a carry, add it to the column sum for the next iteration
		if (carry == 1) {
			columnSum = 1;
		} else {
			columnSum = 0;
		}
	}
		// check if there is a carry after adding the last bits
	if (columnSum == 1) {
		totalSum.insert(0, "1");
	}
	return totalSum;
}

// my own functions
// extends a binary strings bits with leading zeros
string bitExtension(string bin, int desiredLength) {
	string strToInsert = bin;
	// create a string full of zeros of the rigth length
	for(int i = 0; i < desiredLength - bin.length(); i++) {
		strToInsert.insert(0, "0");
	}
	return strToInsert;
}
// converts a hex char to its equivalent integer
int hex_char_to_int(char c) {
	// handle the case where function is passed a valid int 0-9
	if (int(c) > 47 && int(c) < 58) {
		// cout << "Integer detected :\n" << c - '0' << endl;
		return c - '0';
	}
	if (c == 'A') { return 10; }
	if (c == 'B') { return 11; }
	if (c == 'C') { return 12; }
	if (c == 'D') { return 13; }
	if (c == 'E') { return 14; }
	if (c == 'F') { return 15; }
	else { return -1; }
}