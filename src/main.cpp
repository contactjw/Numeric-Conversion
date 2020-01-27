#include <iostream>
#include <cmath>
using namespace std;

int showMenu();
void decimalToBinary();
void binaryToDecimal();
void decimalToHex();
void hexToDecimal();

int main() {

	int menuChoice;

	do {
		menuChoice = showMenu();
		switch (menuChoice) {
		case 1:
			decimalToBinary();
			break;
		case 2:
			binaryToDecimal();
			break;
		case 3:
			decimalToHex();
			break;
		case 4:
			hexToDecimal();
			break;
		}
	} while (menuChoice != 9);

	cout << "Program ending... have a good day!";
	exit(0);

}

// This function displays the menu and returns a menu selection
int showMenu() {
	cout << endl;
	int tempChoice;
	cout << "1.) Decimal to Binary" << endl;
	cout << "2.) Binary to Decimal" << endl;
	cout << "3.) Decimal to Hexadecimal" << endl;
	cout << "4.) Hexadecimal to Decimal" << endl;
	cout << "9.) Exit Program" << endl;
	cout << "Enter menu choice: ";
	cin >> tempChoice;

	if (tempChoice == 9) {
		return tempChoice;
	}

	while (tempChoice < 1 || tempChoice > 4) {
		cout << "Enter a valid menu choice: ";
		cin >> tempChoice;
	}

	return tempChoice;
}

// This function converts a decimal number into binary
void decimalToBinary() {
	string binNum;
	int decNum;

	cout << "Enter a decimal number: ";
	cin >> decNum;

	//Check for preconditions, if decNum less than 0 return back to menu.
	if (decNum < 0) {
		return;
	}
	// Check for preconditions, if decNum == 0 return binary 0.
	// This line was needed, otherwise if user enters 0, will display nothing.
	if (decNum == 0) {
		cout << "0" << endl;
		return;
	}

	// Append the binary digits to the binNum string.
	while (decNum != 0) {
		binNum += to_string(decNum % 2);
		decNum /= 2;
	}

	// Display the binary string in reverse order, due to being read right to left
	for (int i = binNum.length(); i >= 0; i--) {
		cout << binNum[i];
	}

	cout << endl;
	return;

}

// This function converts a decimal number into binary
void binaryToDecimal() {
	string binNum;
	int decNum = 0;

	// Get user binary number.
	cout << "Enter a binary number: ";
	cin >> binNum;

	// Check if binNum is greater than 8 bits.
	if (binNum.length() > 8) {
		cout << "Error: binary number cannot be greater than 8 bits, try again."
				<< endl;
		return;
	}

	// Check if binNum is an accurate binary number.
	for (int i = 0; i < binNum.length(); i++) {
		if (binNum[i] != '0' && binNum[i] != '1') {
			cout << "Error: binary numbers contain only 1's and 0's, try again."
					<< endl;
			return;
		}
	}

	// Convert the binary digits to decimal and add to decNum.
	for (int j = binNum.length() - 1, k = 0; j >= 0; j--, k++) {
		if (binNum[j] == '1') {
			decNum += pow(2, k);
		}
	}

	cout << decNum << endl;
	return;

}

// This function converts a decimal number into hexadecimal.
void decimalToHex() {
	int decNum;
	string hexString;
	int tempNum = 0;

	cout << "Enter a decimal number: ";
	cin >> decNum;

	//Check for preconditions, if decNum less than 0 return back to menu.
	if (decNum < 0) {
		return;
	}
	// Check for preconditions, if decNum == 0 return hexadecimal 0.
	// This line was needed, otherwise if user enters 0, will display nothing.
	if (decNum == 0) {
		cout << "0" << endl;
		return;
	}

	// Append the hexadecimal characters to the hexString.
	while (decNum != 0) {
		tempNum = decNum % 16;

		if (tempNum < 10)
			hexString += to_string(tempNum);
		else {
			switch (tempNum) {
			case 10:
				hexString += "A";
				break;
			case 11:
				hexString += "B";
				break;
			case 12:
				hexString += "C";
				break;
			case 13:
				hexString += "D";
				break;
			case 14:
				hexString += "E";
				break;
			case 15:
				hexString += "F";
				break;
			}
		}

		decNum /= 16;
	}

	// Display the hexString in reverse order, due to being read right to left
	for (int i = hexString.length(); i >= 0; i--) {
		cout << hexString[i];
	}

	cout << endl;
	return;
}

// This function converts a hexadecimal number into decimal.
void hexToDecimal() {
	string hexString;
	int decNum = 0;

		// Get user hexadecimal number.
		cout << "Enter a hexadecimal number: ";
		cin >> hexString;

		// Check if hexString is greater than 4 chars.
		if (hexString.length() > 4) {
			cout << "Error: hexadecimal number cannot be greater than 4 digits, try again." << endl;
			return;
		}

		// Check if hexString is an accurate hexadecimal number.
		for (int i = 0; i < hexString.length(); i++) {
			if (hexString[i] < '0' || hexString[i] > '9') {
				cout << "Error: hexadecimal number must be 1 through 9, a, b, c, d, e, or f" << endl;
				return;
			}
		}

		// Convert the binary digits to decimal and add to decNum.
		for (int j = hexString.length() - 1, k = 0; j >= 0; j--, k++) {
			if (hexString[j] >= '0' && hexString[j] <= '9')
				decNum += (hexString[j] - '0') * pow(16, k);
		}

		cout << decNum << endl;
		return;

}


