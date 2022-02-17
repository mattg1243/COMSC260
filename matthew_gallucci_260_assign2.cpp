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

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);  
string dec_to_hex(int);  


int main() 
{
	
	cout<<"10000011 binary = "<<bin_to_dec("10000011")<<" decimal\n"; // you should get 131
	cout<<"01010101 binary = "<<bin_to_dec("01010101")<<" decimal\n"; // you should get 85
	cout<<"1111111111111111 binary = "<<bin_to_dec("1111111111111111")<<" decimal\n"; // you should get 65,535
	cout<<"0111111111111111 binary = "<<bin_to_dec("0111111111111111")<<" decimal\n\n"; // you should get 32,767
	
	cout<<"255 decimal = "<<dec_to_bin(255)<<" binary\n"; //you should get 11111111
	cout<<"65532 decimal = "<<dec_to_bin(65532)<<" binary\n"; //you should get 1111111111111100
	cout<<"12 decimal = "<<dec_to_bin(12)<<" binary\n"; //you should get 1100
	cout<<"1000000 decimal = "<<dec_to_bin(1000000)<<" binary\n\n"; //you should get 11110100001001000000
	
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"F5 hexadecimal = "<<hex_to_dec("F5")<<" decimal\n"; //you should get 245
	cout<<"1234 hexadecimal = "<<hex_to_dec("1234")<<" decimal\n"; //you should get 4,660
	cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n\n"; //you should get 1,040,075
	/*
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout<<"5000 decimal = "<<dec_to_hex(5000)<<" hexadecimal\n"; //you should get 1388
	cout<<"900000 decimal = "<<dec_to_hex(900000)<<" hexadecimal\n"; //you should get DBBA0
	cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n\n"; //you should get FFF5
	*/
	
	system("PAUSE");
	return 0;

}

// Converts any UNsigned binary number to decimal

int bin_to_dec(string s) 
{
	// initialize return value
	int decimal = 0;
	// index for bit position to traverse the string
	int bitPosition = s.length() - 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			// add 2^bitPostion to decimal
			decimal += pow(2, bitPosition);
		}
		// decrement bitPosition with every iteration
		bitPosition--;
	}
	return decimal;
}	

//Converts any non-negative decimal number to binary

string dec_to_bin(int n)  
{
	// initialize return value
	string bin = "";
	// get the first quotient of the number / 2
	int quotient = n/2;
	// set LSB to quotient mod 2
	int bit = n % 2;
	bin.insert(0, to_string(bit)); 
	// continue until the quotient is 0
	while(quotient != 0) {
		bit = quotient % 2;
		bin.insert(0, to_string(bit));
		quotient = quotient / 2;
	}
	return bin;
}


//Converts any UNsigned hexadecimal number to decimal

int hex_to_dec(string s) 
{
	// initialize return value
	int decimal = 0;
	// variable to add every iteration
	int toAdd;
	// index for bit position to traverse the string
	int bitPosition = s.length() - 1;
	for (int i = 0; i < s.length(); i++) {
		// figure out what the character is representing numerically
		if (isdigit(s[i])) {
			// already a number
			toAdd = pow(16, bitPosition) * (int)s[i];
		} else {
			if (s[i] == 'A')
			{
				toAdd = pow(16, bitPosition) * 10;
			} else if (s[i] == 'B') {
				toAdd = pow(16, bitPosition) * 11;
			} else if (s[i] == 'C') {
				toAdd = pow(16, bitPosition) * 12;
			} else if (s[i] == 'D') {
				toAdd = pow(16, bitPosition) * 13;
			} else if (s[i] == 'E') {
				toAdd = pow(16, bitPosition) * 14;
			} else if (s[i] == 'F') {
				toAdd = pow(16, bitPosition) * 15;
			}
		}
		// decrement bitPosition with every iteration
		decimal += toAdd;
		bitPosition--;
	}
	return decimal;
}	


//Converts any non-negative decimal number to hexadecimalConverts any non-negative decimal number to hexadecimal

string dec_to_hex(int n)  
{
	return "not yet implemented";
}



