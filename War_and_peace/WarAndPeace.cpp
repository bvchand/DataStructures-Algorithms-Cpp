//============================================================================
// Name        : WarAndPeace.cpp
// Author      : Bharathi Vidhya Chandrasekaran
// Version     : 4
// Copyright   : Your copyright notice
// Description : WarAndPeace in C++
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Names to search for.
const vector<string> NAMES = {"Makar Alexeevich", "Joseph Bazdeev", "Boris Drubetskoy"};

const string INPUT_FILE_NAME = "WarAndPeace.txt";

/**
 * Traverse the file and push individual lines into a vector of strings.
 * @param input	ifstream object.
 * @return lines vector of sentences.
 */
vector<string> fileTraversal(ifstream& input);

/**
 * Finds the last word of a sentence.
 * @param line the sentence.
 * @return last word of the line.
 */
string lastWord(string line);

/**
 * Finds the position of the names in the file.
 * @param lines vector of sentences
 */
void findNames(vector<string> lines);

/**
 * Split entire names into first and last name
 * @param name the name to be found
 */
vector<string> splitName(string name);


/**
 * Prints the line#, position and the names found.
 * @param line#, position and names in each sentence
 */
void printOutput(int lineNumber, size_t position, string name);

int main()
{
    ifstream input;
    vector<string> lines;

    //Open the file WarAndPeace.txt
    input.open(INPUT_FILE_NAME);

    //If the file fails to open:
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    //Print the header of the output.
    cout << " LINE  POSITION  NAME" << endl;

    //Get the individual sentences from the text file.
    lines = fileTraversal(input);
    //Finds the position of the names in the file.
    findNames(lines);

    //Close the file.
    input.close();

    return 0;
}

vector<string> fileTraversal(std::ifstream& input)
{
	string line;
	vector<string> lines;

	//Transfers every line as a string to a vector until the end of the file.
	while(!input.eof())
	{
		getline(input,line);
		lines.push_back(line);
	}

	return lines;
}

string lastWord(string line)
{
    string temp;
    vector<string> words;

    //Object of istringstream to manipulate strings.
    istringstream ss(line);

    //Transfers every word of a string to a vector.
    do
    {
		ss >> temp;
		words.push_back(temp);
    } while (ss);

    //Get the last element of a vector.
    return words.back();
}

vector<string> splitName(string name)
{
    vector<string> Names(2);

    //Object of istringstream to manipulate strings.
    istringstream ss(name);

    //split name into first and last name
    ss >> Names[0] >>  Names[1];

    return Names;
}

void findNames(vector<string> lines)
{
	for(int i = 0; i < lines.size(); i++)
	{
		//For every name in the vector:
		for(int j = 0; j < NAMES.size(); j++)
		{
			//The first and last name could be in he same sentence or they could be split across 2 senteneces.
			if(((lines[i].find(NAMES[j])) != std::string::npos)
					      || ((lastWord(lines[i]) == splitName(NAMES[j])[0]) && (lines[i+1].find(splitName(NAMES[j])[1])) == 0))

				printOutput(i, lines[i].find(splitName(NAMES[j])[0]), NAMES[j]);
		}

	}
}

void printOutput(int lineNumber, size_t position, string name)
{
	//Set a constant width for line number and position columns for a readable output.
	cout<<setw(5)<<lineNumber+1<<setw(10)<<position+1<<"  "<<name<<endl;
}











//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//// Names to search for.
//const string ALEXEEVICH  = "Makar Alexeevich";
//const string BAZDEEV     = "Joseph Bazdeev";
//const string DRUBETSKOY  = "Boris Drubetskoy";
//
//const string INPUT_FILE_NAME = "WarAndPeace.txt";
//
//void fileTraversal(ifstream& input);
//
//void nameCompare(vector<string> lines);
//
//void printOutput(int, size_t ,string);
//
//int main()
//{
//    ifstream input;
//    input.open(INPUT_FILE_NAME);
//    if (input.fail())
//    {
//        cout << "Failed to open " << INPUT_FILE_NAME << endl;
//        return -1;
//    }
//    cout << " LINE  POSITION  NAME" << endl;
//
//    fileTraversal(input);
//    input.close();
//    return 0;
//}
//
//void fileTraversal(std::ifstream& input)
//{
//	string line;
//	vector<string> lines;
//	while(!input.eof())
//	{
//		getline(input,line);
//		lines.push_back(line);
//	}
//	nameCompare(lines);
//}
//
//void nameCompare(vector<string> lines)
//{
//	size_t index;
//	for(int i = 0; i < lines.size(); i++)
//	{
//		if(((index = lines[i].find(ALEXEEVICH)) != std::string::npos)
//				|| (((index = lines[i].find("Makar")) == ((lines[i].length())-5)) && (index = lines[i+1].find("Alexeevich")) == 0))
//
//		{
//			printOutput(i, lines[i].find("Makar"), ALEXEEVICH);
//		}
//		if(((index = lines[i].find(BAZDEEV)) != std::string::npos)
//				|| (((index = lines[i].find("Joseph"))) == ((lines[i].length())-6) && (index = lines[i+1].find("Bazdeev")) == 0))
//
//		{
//			printOutput(i, lines[i].find("Joseph"), BAZDEEV);
//		}
//		if(((index = lines[i].find(DRUBETSKOY)) != std::string::npos)
//				|| (((index = lines[i].find("Boris")) == ((lines[i].length())-5)) && (index = lines[i+1].find("Drubetskoy")) == 0))
//
//		{
//			printOutput(i, lines[i].find("Boris"), DRUBETSKOY);
//		}
//	}
//}
//
//
//void printOutput(int lineCount, size_t position, string name)
//{
//	cout << setw(5) <<lineCount+1 << setw(10) << position+1 << "  " << name << endl;
//}
