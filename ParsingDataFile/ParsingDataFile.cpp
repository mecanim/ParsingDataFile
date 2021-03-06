// ParsingDataFile.cpp: определяет точку входа для консольного приложения.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using	namespace std;

struct Employee
{
	string LastName;
	string FirstName;
	double Salary;
};

int main()
{
	ifstream infile("data.csv");
	string strLine;
	
	vector<Employee> empArray;
	string delimiter = ",";
	size_t pos;

	if (infile.is_open())
	{
		while (getline(infile, strLine))
		{
			Employee emp;
			pos = 0;
			if ((pos = strLine.find(delimiter)) != string::npos)
			{
				emp.LastName = strLine.substr(0, pos);
				strLine.erase(0, pos + delimiter.length());
			}

			if ((pos = strLine.find(delimiter)) != string::npos)
			{
				emp.FirstName = strLine.substr(0, pos);
				strLine.erase(0, pos + delimiter.length());
			}

			emp.Salary = stod(strLine.substr(0, strLine.length()));

			empArray.push_back(emp);
		}
	}

	for (Employee emp : empArray)
		cout << emp.LastName << ", " << emp.FirstName << ", " << emp.Salary << endl;



	system("pause>nul");
    return 0;
}

