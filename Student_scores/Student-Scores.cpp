//============================================================================
// Name        : Student-Scores.cpp
// Author      : Bharathi Vidhya Chandrasekaran
// Version     : 3
// Description : Student Scores
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

typedef int *StudPtr;
typedef StudPtr *ScrPtr;

typedef string *StrPtr;

const string INPUT_FILE_NAME = "students.txt";

/**
 * Read student names and scores
 * @param input input file
 * @param student_count number of students
 */
void read_student_information(ifstream &input, int student_count);

/**
 * Read all the scores of each student
 * @param input input file
 * @param scores 2-D dynamic array of student scores
 * @param index student row #
 * @param score_count number of scores per student
 * @return scores 2-D dynamic array of student scores
 */
ScrPtr read_scores(ifstream &input, ScrPtr scores, int index, int score_count);

/**
 * Prints all the student information
 * @param names dynamic string array of student names
 * @param scores 2-D dynamic array of student scores
 * @param index student row #
 * @param score_count number of scores per student
 */
void print_student_information(StrPtr names, ScrPtr scores, int index, int score_count);

/**
 * Deletes the dynamic arrays, names and scores
 * @param names dynamic string array of student names
 * @param scores 2-D dynamic array of student scores
 * @param row_count total number of students
 * @param score_count number of scores per student
 */
void delete_student_information(StrPtr names, ScrPtr scores, int row_count, int score_count);

/**
 * Main.
 */
int main()
{
    ifstream input;
    string course;
    int count;

    //Read student information.
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
    	//If the file fails to openn return -1.
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    //Extract the course name and student count
    input >> course >> count;

    //Print the first line of the output.
    cout << "STUDENT SCORES for " << course << endl;

    //Function call for reading student information.
    read_student_information(input, count);

    //Close the file after use.
    input.close();

    return 0;
}

void read_student_information(ifstream &input, int student_count)
{

	string first_name, last_name;
	int score_count;

	//Dymamic string array of student names.
	StrPtr  names = new string[student_count];

	//2-D dymamic integer array of student scores.
	ScrPtr scores = new int*[student_count];

	//Read the name and scores of each student incrementally through the file.
	for(int index = 0; index < student_count; index++)
	{
		input >> first_name >> last_name >> score_count;

		//Populate the dynamic array, names, with each studnet's name.
		names[index] = first_name + " " + last_name;

		//Specify the column size(score count) of each student.
		scores[index] = new int[score_count];

		//Function call for reading student scores.
		scores = read_scores(input, scores, index, score_count);

		//Function call for printing student information.
		print_student_information(names, scores, index, score_count);
	}

	//Function call for deleting the dynamic arrays, names and scores.
	delete_student_information(names, scores, student_count, score_count);
}

ScrPtr read_scores(ifstream &input, ScrPtr scores, int index, int score_count)
{
	for(int col = 0; col < score_count; col++)
	{
		//Read the scores of each student.
		input >> scores[index][col];
	}
	return scores;
}

void print_student_information(StrPtr names, ScrPtr scores, int index, int score_count)
{
	cout << endl;

	//Print the student name.
	cout << names[index] << endl;

	//If a student has no scores, print "none".
	if(score_count == 0)	cout << "   (none)";

	else
	{
		for(int col = 0; col < score_count; col++)
			{
				//Print the student scores.
				cout << setw(5) << scores[index][col] << " ";
			}
	}
	cout << endl;
}

void delete_student_information(StrPtr names, ScrPtr scores, int row_count, int score_count)
{
	//Delete the "names" dynamic array.
	delete [] names;
	for(int index = 0; index < row_count; index++)
	{
		//Delete each row of the "scores" dynamic array.
		delete [] scores[index];
	}
	//Delete the pointers to each row.
	delete [] scores;
}
