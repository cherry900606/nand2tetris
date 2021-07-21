#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"
using namespace std;

// convert decimal number to binary fixed-length string
string decToBinary(int n)
{
	string s = "";
	while (n > 0)
	{
		s = to_string(n % 2) + s;
		n /= 2;
	}
	while (s.size() < 15)
		s = "0" + s;
	return s;
}
int main()
{
	// initialization
	string path = "../../projects/06/Pong/Pong.asm"; // path and fileName have to be changed by hand
	string fileName = "../../projects/06/Pong/Pong.hack";
	Parser parser;
	Code code;
	SymbolTable symbolTable;

	// first pass
	string line;
	ifstream infile;
	infile.open(path);
	while (getline(infile, line))
	{
		parser.advance(line);
		if (parser.commandType() == L_COMMAND)
		{
			parser.counter--; // don't count label
			if (!symbolTable.contains(parser.symbol())) // if not exist, add to table
			{
				symbolTable.addEntry(parser.symbol(), parser.counter);
			}
		}
	}
	infile.clear();
	infile.seekg(0, infile.beg);
	infile.close();

	// test symbolTable
	/*for (auto it : symbolTable.table)
		cout << it.first << " " << it.second << endl;*/

	// main loop
	parser.counter = 0;
	int n = 16;
	infile.open(path);
	ofstream output;
	output.open(fileName);
	while (getline(infile, line))
	{
		string binaryCode = "";
		if (line.empty()) // skip space
			continue;

		parser.advance(line);
		if (parser.commandType() != OTHERS)
		{
			if (parser.commandType() == L_COMMAND || parser.counter == 0)
				continue;
			cout << parser.counter << " " << parser.current_command << endl;
			if (parser.commandType() == A_COMMAND && !isdigit(parser.symbol()[0])) // @symbol
			{
				if (symbolTable.contains(parser.symbol())) // symbol exists in table
				{
					binaryCode = "0" + decToBinary(symbolTable.getAddress(parser.symbol()));
				}
				else // symbol not exists
				{
					symbolTable.addEntry(parser.symbol(), n);
					binaryCode = "0" + decToBinary(n);
					n++;
				}
			}
			else if (parser.commandType() == A_COMMAND) //@value
			{
				binaryCode = "0" + decToBinary(stoi(parser.symbol()));
			}
			else if (parser.commandType() == C_COMMAND)
			{
				binaryCode = "111";
				binaryCode += code.comp(parser.comp());
				binaryCode += code.dest(parser.dest());
				binaryCode += code.jump(parser.jump());
			}
			cout << binaryCode << endl;
			output << binaryCode << endl; // write file
		}
	}
	infile.close();
	return 0;
}