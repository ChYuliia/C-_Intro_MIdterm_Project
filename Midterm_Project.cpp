// Yuliia Chernysheva
// 03/08/2025
// Foreign Currency Converter
// This program allows users to convert an amount from one currency to another using predefined exchange rates. 
// The user selects the source currency, enters the amount, and then selects the target currency. 
// The program calculates and displays the converted amount based on the exchange rate.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Convert string value to uppercase
string getUpperString(string str) {	
	for (char& c : str) {
		c = toupper(c);
	}
	return str;
}

// Convert two currency codes (input as strings) into unique numerical values
int getCurrencyNumber(string iRow, string iCol) {

	int row = 0, col = 0;

	iRow = getUpperString(iRow);
	iCol = getUpperString(iCol);	

	// Assign numerical values to row
	if (iRow == "USD" || iRow == "1") row = 1;
	if (iRow == "EUR" || iRow == "2") row = 2;
	if (iRow == "GBP" || iRow == "3") row = 3;
	if (iRow == "MXN" || iRow == "4") row = 4;
	if (iRow == "UAH" || iRow == "5") row = 5;
	if (iRow == "RUB" || iRow == "6") row = 6;

	// Assign numerical values to col
	if (iCol == "USD" || iCol == "1") col = 1;
	if (iCol == "EUR" || iCol == "2") col = 2;
	if (iCol == "GBP" || iCol == "3") col = 3;
	if (iCol == "MXN" || iCol == "4") col = 4;
	if (iCol == "UAH" || iCol == "5") col = 5;
	if (iCol == "RUB" || iCol == "6") col = 6;

	return row * 10 + col;
}

// Function to display conversion rates
void displayConversion(string from, string to, double rate) {
	cout << fixed << setprecision(4);
	cout << "\nCurrent rates:";
	cout << endl << string(24, '-');
	cout << setw(5) << left << "\n| 1 " << from << " = " << setw(8) << right << rate << " " << setw(4) << left << to << "|";
	cout << setw(5) << left << "\n| 1 " << to << " = " << setw(8) << right << (1 / rate) << " " << setw(4) << left << from << "|";
	cout << endl << string(24, '-');
	cout << "\n\nYour operation " << from << " to " << to;
	cout << endl << string(47, '-');
	cout << fixed << setprecision(2);
}

int main() {

	// Rates for  USD
	const double USDtoEUR = 0.9230;
	const double USDtoGBP = 0.7740;
	const double USDtoMXN = 20.2514;
	const double USDtoUAH = 41.3874;
	const double USDtoRUB = 89.8585;
	// Rates for EUR
	const double EURtoGBP = 0.8389;
	const double EURtoMXN = 21.9399;
	const double EURtoUAH = 44.8317;
	const double EURtoRUB = 97.4655;
	// Rates for GBP
	const double GBPtoMXN = 26.1636;
	const double GBPtoUAH = 53.4756;
	const double GBPtoRUB = 116.1578;
	// Rates for MXN 
	const double MXNtoUAH = 2.0439;
	const double MXNtoRUB = 4.4397;
	// Rates for UAH
	const double UAHtoRUB = 2.1722;
	// Temp variables for input data
	string tmpInput1, tmpInput2;

	int currencyFromTo;
	double amount;

	// Display a welcome message and a table listing the available currencies, their codes, and descriptions in a structured format
	cout << "\nWelcome to The Foreign Currency Converter! " << endl;

	cout << "\nAvailable currency";
	cout << "\n---------------------------------------------------------";
	cout << setw(5) << left << "\n| #" << setw(17) << "| Currency Code" << setw(35) << "| Currency Description" << "|";
	cout << "\n---------------------------------------------------------";	
	cout << setw(5) << left << "\n| 1" << setw(17) << "| USD" << setw(35) << "| US Dollar" << "|";
	cout << setw(5) << left << "\n| 2" << setw(17) << "| EUR" << setw(35) << "| Euro" << "|";
	cout << setw(5) << left << "\n| 3" << setw(17) << "| GBP" << setw(35) << "| British Pound" << "|";
	cout << setw(5) << left << "\n| 4" << setw(17) << "| MXN" << setw(35) << "| Mexican Peso" << "|";
	cout << setw(5) << left << "\n| 5" << setw(17) << "| UAH" << setw(35) << "| Ukraininan Hryvnia" << "|";
	cout << setw(5) << left << "\n| 6" << setw(17) << "| RUB" << setw(35) << "| Russian Ruble" << "|";
	cout << "\n---------------------------------------------------------";
	cout << endl;

	// Prompts the user to input the currencies they wish to convert from and to. 
	// It allows the user to specify the currency either by its number or its currency code. 
	cout << "\nPlease enter the Currency # or Currency Code to convert from and press Enter: ";
	cin >> tmpInput1;
	cout << "Please enter the Currency # or Currency Code to convert to and press Enter: ";
	cin >> tmpInput2;

	// Convert two currency codes (input as strings) into unique numerical values
	currencyFromTo = getCurrencyNumber(tmpInput1, tmpInput2);

	cout << "Please enter the Amount to be converted: ";
	cin >> amount;

	// build a currency converter with different conversion rates for various currencies
	switch (currencyFromTo) {
		//  USD to USD - branch
		case 11:	
			displayConversion("USD", "USD", 1);	
			cout << "\n" << amount << " US Dollars = " << amount << " US Dollars";
			break;
		// USD to EUR - branch
		case 12:
			displayConversion("USD", "EUR", USDtoEUR);	
			cout << "\n" << amount << " US Dollars = " << (amount * USDtoEUR) << " Euros";
			break;
		// USD to GBP - branch
		case 13:
			displayConversion("USD", "GBP", USDtoGBP);
			cout << "\n" << amount << " US Dollars = " << (amount * USDtoGBP) << " British Pounds";
			break;			
		// USD to MXN - branch
		case 14:
			displayConversion("USD", "MXN", USDtoMXN);
			cout << "\n" << amount << " US Dollars = " << (amount * USDtoMXN) << " Mexican Pesos";
			break;
		// USD to UAH - branch
		case 15:
			displayConversion("USD", "UAH", USDtoUAH);
			cout << "\n" << amount << " US Dollars = " << (amount * USDtoUAH) << " Ukrainian Hryvni";
			break;
		// USD to RUB - branch
		case 16:
			displayConversion("USD", "RUB", USDtoRUB);			
			cout << "\n" << amount << " US Dollars = " << (amount * USDtoRUB) << " Russian Rubles";
			break;	
		// EUR to USD - branch
		case 21:
			displayConversion("EUR", "USD", 1/USDtoEUR);			
			cout << "\n" << amount << " Euros = " << (amount / USDtoEUR) << " US Dollars";
			break;
		// EUR to EUR - branch
		case 22:
			displayConversion("EUR", "EUR", 1);
			cout << "\n" << amount << " Euros = " << amount << " Euros";
			break;
		// EUR to GBP - branch
		case 23:
			displayConversion("EUR", "GBP", EURtoGBP);
			cout << "\n" << amount << " Euros = " << (amount * EURtoGBP) << " British Pounds";
			break;
		// EUR to MXN - branch
		case 24:
			displayConversion("EUR", "MXN", EURtoMXN);
			cout << "\n" << amount << " Euros = " << (amount * EURtoMXN) << " Mexican Pesos";
			break;
		// EUR to UAH - branch		
		case 25:
			displayConversion("EUR", "UAH", EURtoUAH);			
			cout << "\n" << amount << " Euros = " << (amount * EURtoUAH) << " Ukrainian Hryvni";
			break;
		// EUR to RUB
		case 26:
			displayConversion("EUR", "RUB", EURtoRUB);
			cout << "\n" << amount << " Euros = " << (amount * EURtoRUB) << " Russian Rubles";
			break;
		// GBP to USD - branch
		case 31:
			displayConversion("GBP", "USD", 1/USDtoGBP);			
			cout << "\n" << amount << " British Pounds = " << (amount / USDtoGBP) << " US Dollars";
			break;
		// GBP to EUR - branch
		case 32:
			displayConversion("GBP", "EUR", 1/EURtoGBP);			
			cout << "\n" << amount << " British Pounds = " << (amount / EURtoGBP) << " Euros";
			break;
		// GBP to GBP - branch
		case 33:
			displayConversion("GBP", "GBP", 1);			
			cout << "\n" << amount << " British Pounds = " << amount << " British Pounds";
			break;
		// GBP to MXN - branch
		case 34:
			displayConversion("GBP", "MXN", GBPtoMXN);			
			cout << "\n" << amount << " British Pounds = " << (amount * GBPtoMXN) << " Mexican Pesos";
			break;
		// GBP to UAH - branch		
		case 35:
			displayConversion("GBP", "UAH", GBPtoUAH);			
			cout << "\n" << amount << " British Pounds = " << (amount * GBPtoUAH) << " Ukrainian Hryvni";
			break;
		// GBP to RUB - branch
		case 36:
			displayConversion("GBP", "RUB", GBPtoRUB);			
			cout << "\n" << amount << " British Pounds = " << (amount * GBPtoRUB) << " Russian Rubles";
			break;
		// MXN to USD - branch
		case 41:
			displayConversion("MXN", "USD", 1/USDtoMXN);			
			cout << "\n" << amount << " Mexican Pesos = " << (amount / USDtoMXN) << " US Dollars";
			break;
		// MXN to EUR - branch
		case 42:
			displayConversion("MXN", "EUR", 1/EURtoMXN);			
			cout << "\n" << amount << " Mexican Pesos = " << (amount / EURtoMXN) << " Euros";
			break;
		// MXN to GBP - branch
		case 43:
			displayConversion("MXN", "GBP", 1/GBPtoMXN);			
			cout << "\n" << amount << " Mexican Pesos = " << (amount / GBPtoMXN) << " British Pounds";
			break;
		// MXN to MXN - branch
		case 44:
			displayConversion("MXN", "MXN", 1);			
			cout << "\n" << amount << " Mexican Pesos = " << (amount) << " Mexican Pesos";
			break;
		// MXN to UAH - branch		
		case 45:
			displayConversion("MXN", "UAH", MXNtoUAH);			
			cout << "\n" << amount << " Mexican Pesos = " << (amount * MXNtoUAH) << " Ukrainian Hryvni";
			break;
		// MXN to RUB - branch
		case 46:
			displayConversion("MXN", "RUB", MXNtoRUB);			
			cout << "\n" << amount << " Mexican Pesos = " << (amount * MXNtoRUB) << " Russian Rubles";
			break;
		// UAH to USD - branch
		case 51:
			displayConversion("UAH", "USD", 1/USDtoUAH);			
			cout << "\n" << amount << " Ukrainian Hryvni = " << (amount / USDtoUAH) << " US Dollars";
			break;
		// UAH to EUR - branch
		case 52:
			displayConversion("UAH", "EUR", 1/EURtoUAH);			
			cout << "\n" << amount << " Ukrainian Hryvni = " << (amount / EURtoUAH) << " Euros";
			break;
		// UAH to GBP - branch
		case 53:
			displayConversion("UAH", "GBP", 1/GBPtoUAH);			
			cout << "\n" << amount << " Ukrainian Hryvni = " << (amount / GBPtoUAH) << " British Pounds";
			break;
		// UAH to MXN - branch
		case 54:
			displayConversion("UAH", "MXN", 1/MXNtoUAH);			
			cout << "\n" << amount << " Ukrainian Hryvni = " << (amount / MXNtoUAH) << " Mexican Pesos";
			break;
		// UAH to UAH - branch			
		case 55:
			displayConversion("UAH", "UAH", 1);			
			cout << "\n" << amount << " Ukrainian Hryvni = " << (amount) << " Ukrainian Hryvni";
			break;
		// UAH to RUB - branch
		case 56:
			displayConversion("UAH", "RUB", UAHtoRUB);			
			cout << "\n" << amount << " Ukrainian Hryvni = " << (amount * UAHtoRUB) << " Russian Rubles";
			break;
		// RUB to USD - branch
		case 61:
			displayConversion("RUB", "USD", 1/USDtoRUB);			
			cout << "\n" << amount << " Russian Rubles = " << (amount / USDtoRUB) << " US Dollars";
			break;
		// RUB to EUR - branch
		case 62:
			displayConversion("RUB", "EUR", 1/EURtoRUB);			
			cout << "\n" << amount << " Russian Rubles = " << (amount / EURtoRUB) << " Euros";
			break;
		// RUB to GBP - branch
		case 63:
			displayConversion("RUB", "GBP", 1/GBPtoRUB);			
			cout << "\n" << amount << " Russian Rubles = " << (amount / GBPtoRUB) << " British Pounds";
			break;
		// RUB to MXN - branch
		case 64:
			displayConversion("RUB", "MXN", 1/MXNtoRUB);			
			cout << "\n" << amount << " Russian Rubles = " << (amount / MXNtoRUB) << " Mexican Pesos";
			break;
		// RUB to UAH - branch			
		case 65:
			displayConversion("RUB", "UAH", 1/UAHtoRUB);			
			cout << "\n" << amount << " Russian Rubles = " << (amount / UAHtoRUB) << " Ukrainian Hryvni";
			break;
		// RUB to RUB - branch
		case 66:
			displayConversion("RUB", "RUB", 1);			
			cout << "\n" << amount << " Russian Rubles = " << amount << " Russian Rubles";
			break;	
		default: cout << "\nCurrency not supported. Please check the currency codes.";
	}	
	
	cout << endl << string(47, '-');
	cout << endl;

	return 0;
}