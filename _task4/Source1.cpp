#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

void load(ifstream& in, queue<string>& s) {
	string line;
	while (getline(in, line))
	{
		//cout << line << endl;
		s.push(line);
	}
}

void save(ofstream& out, queue<string>& s)
{
	while (!s.empty())
	{
		out << s.front() << endl;
		s.pop();
	}
}


int main()
{
	string filename;
	cout << "insert file's name : ";
	getline(cin, filename);

	ifstream in(filename);
	ofstream out("rev.txt");
	if (!in || !out)
	{
		cout << "impossible";
		return 1;
	}
	queue <string> s;
	load(in, s);
	in.close();

	save(out, s);
	out.close();
	return 0;
}