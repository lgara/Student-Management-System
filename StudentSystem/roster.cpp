#include "roster.h"
using std::cout;
using std::cerr;

roster::roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

roster::roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new student*[capacity];
}

student* roster::getStudentAt(int index)
{
	return classRosterArray[index];
}

void roster::parseThenAdd(string row)
{
	if (lastIndex < capacity)
	{
		lastIndex++;
		Degree degree;

		if (row[0] == 'N') degree = NETWORKING;
		else if (row[1] == 'E') degree = SECURITY;
		else if (row[1] == 'O') degree = SOFTWARE;
		else
		{
			cerr << "INVALID DEGREE! EXITING! \n";
			exit(-1);
		}

		// Read the id
		int rhs = row.find(",");
		int lhs = rhs + 1;
		string sID = row.substr(lhs, 2);

		// Read first name
		lhs = rhs + 4;
		rhs = row.find(",", lhs);
		string sFirstName = row.substr(lhs, rhs - lhs);

		// Read the last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sLastName = row.substr(lhs, rhs - lhs);

		// Read email address
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sEmail = row.substr(lhs, rhs - lhs);

		// Read age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sAge = stod(row.substr(lhs, rhs - lhs));

		// Read each day to complete
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sDay1 = stod(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sDay2 = stod(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sDay3 = stod(row.substr(lhs, rhs - lhs));

		// Call the add function to create the student
		add(degree, sID, sFirstName, sLastName, sEmail, sAge, sDay1, sDay2, sDay3);
	}
	else
	{
		cerr << "ERROR! LIST HAS EXCEDDED MAXIMUM CAPACITY!\n EXITING NOW!";
		exit(-1);
	}
}

void roster::add(Degree degree, string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sDay1, int sDay2, int sDay3)
{
	// Make an array to get the number of days into the constructor
	int numberOfDays[student::arraySize];
	numberOfDays[0] = sDay1;
	numberOfDays[1] = sDay2;
	numberOfDays[2] = sDay3;
	if (degree == NETWORKING) classRosterArray[lastIndex] = new networkStudent(sID, sFirstName, sLastName, sEmail, sAge, numberOfDays, degree);
	else if (degree == SECURITY) classRosterArray[lastIndex] = new securityStudent(sID, sFirstName, sLastName, sEmail, sAge, numberOfDays, degree);
	else classRosterArray[lastIndex] = new softwareStudent(sID, sFirstName, sLastName, sEmail, sAge, numberOfDays, degree);
}

void roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool roster::remove(string id)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetStudentId() == id)
		{
			found = true;

			delete this->classRosterArray[i];

			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (found == false)
	{
		cout << "Student with id " << id << " was not found.\n";
	}
	return found;
}

void roster::printAverageDaysToComplete(string studentId)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetStudentId() == studentId)
		{
			found = true;
			int* p = classRosterArray[i]->GetNumberOfDaysToComplete();
			cout << "Average number of days to complete classes for student " << studentId << " is " << (p[0] + p[1] + p[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

void roster::printInvalidEmails()
{
	cout << "Displaying invalid email addresses:\n";
	bool any = false;
	for (int i = 0; i < lastIndex - 1; i++)
	{
		any = false;
		string p = classRosterArray[i]->GetEmailAddress();

			if (p.find('@') == string::npos || p.find('.') == string::npos || p.find(' ') != string::npos)
			{
				any = true;
				cout << "Student " << classRosterArray[i]->GetStudentId() << ": ";
				cout << p << " ";
			}
		if (any) cout << "\n";
	}
	if (!any) cout << "NONE";
}

void roster::printByDegreeProgram(Degree d)
{
	cout << "Printing students persuing a degree in " << degreeString[d] << ":\n";
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->GetDegree() == d) this->classRosterArray[i]->print();
	}
}

roster::~roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

int main()
{
	int numStudents = 5;

	string studentData[5] =
	{
		"SECURITY,A1,John,Smith,John1989@gm ail.com,20,30,35,40",
		"NETWORKING,A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40",
		"SOFTWARE,A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33",
		"SECURITY,A4,Erin,Black,Erin.black@comcast.net,22,50,58,40",
		"SOFTWARE,A5,Louis,Gara,lgara@wgu.edu,28,15,20,25"
	};
	cout << "Course Title: Scripting and Programming Applications - C867, Language Used: C++, Student ID: 001120963, Student Name: Louis Gara\n";
	roster* classRoster = new roster(numStudents);
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	classRoster->printAll();
	cout << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	cout << "Printing average number of days to complete course:\n";
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->printAverageDaysToComplete(classRoster->getStudentAt(i)->GetStudentId());
	}

	cout << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");
	cout << endl;
	classRoster->remove("A3");
	
	classRoster->~roster();
	
	system("pause");

	return 0;
}