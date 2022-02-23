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

// my own functions to keep my code dry
int hex_char_to_int(char);
string int_to_hex_char(int);
// assigned functions to complete
int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);  
string dec_to_hex(int);  


int main() 
{
	cout << "Binary to Decimal: \n";
	cout<<"\n00110000 binary = "<<bin_to_dec("00110000")<<" decimal\n"; 
	cout<<"10000010 binary = "<<bin_to_dec("10000010")<<" decimal\n"; 
	cout<<"11111000 binary = "<<bin_to_dec("11111000")<<" decimal\n"; 
	cout<<"1111011000010101 binary = "<<bin_to_dec("1111011000010101")<<" decimal\n"; 
	cout<<"0010001010011011 binary = "<<bin_to_dec("0010001010011011")<<" decimal\n\n";

	cout << "Decimal to Binary: \n";
	cout<<"4692 decimal = "<<dec_to_bin(4692)<<" binary\n"; 
	cout<<"26 decimal = "<<dec_to_bin(26)<<" binary\n";
	cout<<"2011 decimal = "<<dec_to_bin(2011)<<" binary\n"; 
	cout<<"7653452 decimal = "<<dec_to_bin(7653452)<<" binary\n";
	cout<<"801 decimal = "<<dec_to_bin(801)<<" binary\n\n"; 

	cout << "Hex to Decimal: \n";
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; 
	cout<<"F5 hexadecimal = "<<hex_to_dec("F5")<<" decimal\n"; 
	cout<<"1234 hexadecimal = "<<hex_to_dec("1234")<<" decimal\n";
	cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n"; 
	cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n\n"; 

	cout << "Decimal to Hex: \n";
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n";
	cout<<"5000 decimal = "<<dec_to_hex(5000)<<" hexadecimal\n"; 
	cout<<"900000 decimal = "<<dec_to_hex(900000)<<" hexadecimal\n";
	cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n"; 
	cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n\n"; 

	
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
	// continue until the quotient is 0
	while(quotient != 0) {
		bin.insert(0, to_string(bit));
		bit = quotient % 2;
		quotient = quotient / 2;
	}
	// insert the last bit
	bin.insert(0, to_string(bit));
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
			toAdd = pow(16, bitPosition) * hex_char_to_int(s[i]);
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
		// initialize return value
	string hex = "";
	// get the first quotient of the number / 2
	int quotient = n/16;
	// set LSB to quotient mod 2
	int bit = n % 16;
	// continue until the quotient is 0
	while(quotient != 0) {
		// add the bit to the return string
		// cout << "\nbit : " << bit;
		// cout << "\nbit hex : " << int_to_hex_char(bit) << endl;
		hex.insert(0, int_to_hex_char(bit));
		// perform the calculations for the next bit
		bit = quotient % 16;
		quotient = quotient / 16;
	}
	// inser the LSH symbol after the quotient is zero
	hex.insert(0, int_to_hex_char(bit));
	return hex;
}


// my own functions to keep my code dry
int hex_char_to_int(char c) {
	if (c == 'A') { return 10; }
	if (c == 'B') { return 11; }
	if (c == 'C') { return 12; }
	if (c == 'D') { return 13; }
	if (c == 'E') { return 14; }
	if (c == 'F') { return 15; }
	else { return -1; }
}

string int_to_hex_char(int v) {
	// if v is < 11, return v as char
	if (v < 10) { return to_string(v); }
	// otherwise, figure out what symbol it should be
	else {
		if (v == 10) { return "A"; }
		if (v == 11) { return "B"; }
		if (v == 12) { return "C"; }
		if (v == 13) { return "D"; }
		if (v == 14) { return "E"; }
		if (v == 15) { return "F"; }
		else { return "Argument received is an invalid hex character"; }
	}
}
