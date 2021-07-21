#pragma once
#include <iostream>
using namespace std;

enum COMMAND_TYPE
{
	A_COMMAND, // @xxx
	C_COMMAND, // dest = comp; jump
	L_COMMAND, // (xxx)
	OTHERS
};

class Parser
{
public:
	string current_command; // record current command
	int counter; // record lines
	Parser() { current_command = "", counter = 0; }
	void advance(string s); // pre-processing
	int commandType(); // get command type
	string symbol(); // get symbol from @symbol or (symbol)
	string dest(); // get dest part
	string comp(); // get comp part
	string jump(); // get jump part
};

void Parser::advance(string s)
{
	int position = s.find_first_of("//"); // erase comment parts
	s = s.substr(0, position);
	while (s[0] == ' ') // erase front space
		s.erase(0, 1);
	position = s.find_first_of(" "); // erase back space
	s = s.substr(0, position);
	if (!s.empty()) // if s is not an empty string after pre-processing, then read it
	{
		//cout <<counter<<" "<< s << endl;
		current_command = s;
		counter++;
	}
}

int Parser::commandType()
{
	if (current_command[0] == '@')
		return A_COMMAND;
	else if (current_command[0] == '(')
		return L_COMMAND;
	else if (current_command.empty())
		return OTHERS;
	else
		return C_COMMAND;
}

string Parser::symbol()
{
	string symbol = "";
	if (current_command[0] == '@')
	{
		symbol = current_command.substr(1, current_command.size() - 1);
	}
	else if (current_command[0] == '(')
	{
		symbol = current_command.substr(1, current_command.size() - 2);
	}
	return symbol;
}

string Parser::dest()
{
	int position = current_command.find_first_of("=");
	if (position == -1)
		return "";
	else
		return current_command.substr(0, position);
}

string Parser::comp()
{
	string comp = current_command;
	if (comp.find("=") != -1)
		comp = comp.erase(0, comp.find("=") + 1);
	if (comp.find(";") != -1)
		comp = comp.substr(0, comp.find(";"));
	return comp;
}

string Parser::jump()
{
	string jump = current_command;
	if (jump.find(";") == -1)
		return "";
	else
	{
		jump.erase(0, jump.find(";") + 1);
		return jump;
	}
}