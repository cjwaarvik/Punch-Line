#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayAllLines(ifstream &infile);
void displayLastLine(ifstream &infile);

int main()
{

	ifstream joke("C:\\Users\User\\Desktop\\joke.txt", ios::in);
	ifstream punchline("C:\\Users\\User\\Desktop\\punchline.txt", ios::in);



	if (joke)
		displayAllLines(joke);
	else
		cout << "ERROR: Cannot open file." << endl;

	if (punchline)
		displayLastLine(punchline);
	else
		cout << "ERROR: Cannot open file." << endl;



	joke.close();
	punchline.close();

	cout << endl;
	("pause");
	return 0;
}


void displayAllLines(ifstream &infile)
{
	string line;

	getline(infile, line);

	while (infile)
	{
		cout << line << endl;
		getline(infile, line);
	}
}


void displayLastLine(ifstream &infile)
{
	string line;
	char ch;
	long pos = -1;


	infile.seekg(0L, ios::end);

	infile.seekg(pos, ios::cur);

	infile.get(ch);


	while (ch != '\n')
	{
		pos--;
		infile.seekg(pos, ios::cur);
		infile.get(ch);
	}


	getline(infile, line);

	if (infile)
		cout << line << endl;
}
