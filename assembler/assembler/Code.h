#pragma once
#include <iostream>
using namespace std;

// convert dest, comp and jump to binary code
class Code
{
public:
	string dest(string s);
	string comp(string s);
	string jump(string s);
};

string Code::dest(string s)
{
	if (s == "M") return "001";
	else if (s == "D") return "010";
	else if (s == "MD") return "011";
	else if (s == "A") return "100";
	else if (s == "AM") return "101";
	else if (s == "AD") return "110";
	else if (s == "AMD") return "111";
	else return "000";
}

string Code::comp(string s)
{
	if (s == "0") return "0101010";
	else if (s == "1") return "0111111";
	else if (s == "-1") return "0111010";
	else if (s == "D") return "0001100";
	else if (s == "A") return "0110000";
	else if (s == "M") return "1110000";
	else if (s == "!D") return "0001101";
	else if (s == "!A") return "0110001";
	else if (s == "!M") return "1110001";
	else if (s == "-D") return "0001111";
	else if (s == "-A") return "0110011";
	else if (s == "-M") return "1110011";
	else if (s == "D+1") return "0011111";
	else if (s == "A+1") return "0110111";
	else if (s == "M+1") return "1110111";
	else if (s == "D-1") return "0001110";
	else if (s == "A-1") return "0110010";
	else if (s == "M-1") return "1110010";
	else if (s == "D+A") return "0000010";
	else if (s == "D+M") return "1000010";
	else if (s == "D-A") return "0010011";
	else if (s == "D-M") return "1010011";
	else if (s == "A-D") return "0000111";
	else if (s == "M-D") return "1000111";
	else if (s == "D&A") return "0000000";
	else if (s == "D&M") return "1000000";
	else if (s == "D|A") return "0010101";
	else if (s == "D|M") return "1010101";
}

string Code::jump(string s)
{
	if (s == "JGT") return "001";
	else if (s == "JEQ") return "010";
	else if (s == "JGE") return "011";
	else if (s == "JLT") return "100";
	else if (s == "JNE") return "101";
	else if (s == "JLE") return "110";
	else if (s == "JMP") return "111";
	else return "000";
}