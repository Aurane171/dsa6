#include <stack>
#include <iostream>
#include <string>
#include <sstream>

using namespace std; 


void input(stack<string>& s)
{
	string cmdline; 
	string cmd; 
	string arg; 
	do
	{
		cout << "command line: "; 
		getline(cin, cmdline); 
		stringstream ss(cmdline); 
		ss >> cmd; 
		ss >> arg; 
		if (cmd == "ADD")
		{
			s.push(arg); 
		}
		else if (cmd == "UNDO")
		{
			if (!s.empty())
				s.pop();
			else
				cout << "empty" << endl; 
		}
		else if (cmd == "EXIT")
		{
			break;
		}

	} while (true);
}

void output(stack<string>& s) 
{
	stack<string> cpy; 
	while (!s.empty())
	{
		cpy.push(s.top()); 
		s.pop(); 
		 
	}
	while (!cpy.empty())
	{
		cout<< cpy.top()<<endl;
		cpy.pop();
	}
}

int main() {
	stack<string> s; 
	input(s); 
	output(s); 
	return 0; 
}