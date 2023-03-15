#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int octalToDecimal(string oct) {
    int decimal = 0;
    int power = 0;
    for (int i = oct.length() - 1; i >= 0; i--) {
        decimal += (int(oct[i] - '0') * pow(8, power));
        power++;
    }
    return decimal;
}

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    stringstream ss(binary);
    char binaryDigit;
    while (ss >> binaryDigit) {
        decimal += (int(binaryDigit - '0') * pow(2, power));
        power++;
    }
    return decimal;
}

string decimalToHexadecimal(int decimal) {
    string hexadecimal = "";
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal = char(remainder + '0') + hexadecimal;
        } else {
            hexadecimal = char(remainder - 10 + 'A') + hexadecimal;
        }
        decimal /= 16;
    }
    return hexadecimal;
}

string octalToBinary(string oct) {
    int decimal = octalToDecimal(oct);
    string binary = "";
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary = char(remainder + '0') + binary;
        decimal /= 2;
    }
    return binary;
}

string binaryToHexadecimal(string binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToHexadecimal(decimal);
}

int main() {
    string number;
    cout << "Enter a number in base 8 or 2: ";
    cin >> number;

    if (number.find(".") == string::npos) {
        // number is an integer
        if (number.find("8") != string::npos || number.find("9") != string::npos) {
            // input is not a valid octal number
            cout << "Invalid input. Please enter a valid octal number." << endl;
            return 0;
        }
        if (number.find("2") != string::npos && number.find("0") != string::npos) {
            // input is not a valid binary number
            cout << "Invalid input. Please enter a valid binary number." << endl;
            return 0;
        }

        if (number.find("2") == string::npos) {
            // number is in base 8, convert to binary and hexadecimal
            string binary = octalToBinary(number);
            cout << "Binary: " << binary << endl;
            cout << "Hexadecimal: " << binaryToHexadecimal(binary) << endl;
        } else {
            // number is in base 2, convert to hexadecimal and binary
            cout << "Hexadecimal: " << binaryToHexadecimal(number) << endl;
            cout << "Binary: " << number << endl;
        }

    } else {
        // number is a fraction
        string integerPart = number.substr(0, number.find("."));
        string fractionalPart = number.substr(number.find(".") + 1);

        if (integerPart.find("8") != string::npos || integerPart.find("9") != string::npos ||
            fractionalPart.find("8") != string::npos || fractionalPart.find("9") != string::npos) {
            // input is not a valid octal number
            cout << "Invalid input. Please enter a valid octal number." << endl;
            return 0;
        }
        if (integerPart.find("2") != string::npos && integerPart.find("0") != string::npos ||
            fractionalPart.find("2") != string::npos && fractionalPart.find("0") != string::npos) {
            // input is not a valid binary number
            cout << "Invalid input. Please enter a valid binary number." << endl;
            return 0;
        }

        string binaryIntegerPart = octalToBinary(integerPart);
        string binaryFractionalPart = "";

        if (fractionalPart != "0") {
            // convert fractional part to binary
            double fractional = stod("0." + fractionalPart);
            for (int i = 0; i < 10; i++) {
                fractional *= 2;
                binaryFractionalPart += to_string(int(fractional));
                fractional -= int(fractional);
            }
        }

        cout << "Binary: " << binaryIntegerPart << "." << binaryFractionalPart << endl;
        string binary = binaryIntegerPart + "." + binaryFractionalPart;
        cout << "Hexadecimal: " << binaryToHexadecimal(binary) << endl;
    }

    return 0;
}
