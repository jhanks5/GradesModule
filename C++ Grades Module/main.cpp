#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void bookstore(double);
void highest_grade();
void grade_calculator(int, int, int);

int main()
{
    //Display a menu for the user to access different modules
    int choice;
    cout << "Please enter the corresponding number of your desired module." << endl;
    cout << "1. Grade Calculator" << endl;
    cout << "2. Book Store" << endl;
    cout << "3. University's lowest grade" << endl;
    cin >> choice;

    //Branch into different modules based on user selection
    switch (choice)
    {
        //If the user enters a 1
    case 1:
       int cls, stu, score;
       cout << "Enter the number of classrooms (1-2)" << endl;
       cin >> cls;
       cout << "Enter the number of students per classroom (1-2)" << endl;
       cin >> stu;
       cout << "Enter the number of scores per student (1-3)" << endl;
       cin >> score;
       //call the grade_calculator function and use the user input as the arguments
       grade_calculator(cls, stu, score);

    break;

        //If the user enters a 2
    case 2:
        double money;
        cout << "How much money are you willing to spend?";
        cin >> money;
        bookstore(money); //call the bookstore function and run it with user input 'money' as the argument

    break;

        //If the user enters a 3
    case 3:
        highest_grade();
        break;
    }

}

void grade_calculator (int cls, int stu, int score) //case 1
{
double class1_student1[3];						    //create arrays for each student to hold the grades the user inputs
double class1_student2[3];
double class2_student1[3];
double class2_student2[3];

double class1_student1_total = 0;					//initializes
double class1_student2_total = 0;
double class2_student1_total = 0;
double class2_student2_total = 0;

double class1_student1_average = 0;					//set the total for classroom 1 student 1 to 0
double class1_student2_average = 0;
double class2_student1_average = 0;
double class2_student2_average = 0;

double class1_average = 0;						    //set the total classroom average to 0
double class2_average = 0;
double total_average = 0;

cout << "Input grade for test 1 for Student 1 in classroom 1 ";		    //have the user input data into the arrays
cin >> class1_student1[0];                                              //for each student, as seen below
cout << endl;
cout << "Input grade for test 2 for Student 1 in classroom 1 ";
cin >> class1_student1[1];
cout << endl;
cout << "Input grade for test 3 for Student 1 in classroom 1 ";
cin >> class1_student1[2];
cout << endl;

cout << "Input grade for test 1 for Student 2 in classroom 1 ";
cin >> class1_student2[0];
cout << endl;
cout << "Input grade for test 2 for Student 2 in classroom 1 ";
cin >> class1_student2[1];
cout << endl;
cout << "Input grade for test 3 for Student 2 in classroom 1 ";
cin >> class1_student2[2];
cout << endl;

cout << "Input grade for test 1 for Student 1 in classroom 2 ";
cin >> class2_student1[0];
cout << endl;
cout << "Input grade for test 2 for Student 1 in classroom 2 ";
cin >> class2_student1[1];
cout << endl;
cout << "Input grade for test 3 for Student 1 in classroom 2 ";
cin >> class2_student1[2];
cout << endl;

cout << "Input grade for test 1 for Student 2 in classroom 2 ";
cin >> class2_student2[0];
cout << endl;
cout << "Input grade for test 2 for Student 2 in classroom 2 ";
cin >> class2_student2[1];
cout << endl;
cout << "Input grade for test 3 for Student 2 in classroom 2 ";
cin >> class2_student2[2];
cout << endl;

for(int i = 0; i < 3; i++)						                        //for(initialize; test; update)
	{
	   class1_student1_total += class1_student1[i];			            //
	   class1_student2_total += class1_student2[i];
	   class2_student1_total += class2_student1[i];
	   class2_student2_total += class2_student2[i];
	}


class1_student1_average = (class1_student1_total / 3);
class1_student2_average = (class1_student2_total / 3);
class2_student1_average = (class2_student1_total / 3);
class2_student2_average = (class2_student2_total / 3);

cout << "Student 1 classroom 1 average test grade: " << class1_student1_average << endl;
cout << "Student 2 classroom 1 average test grade: " << class1_student2_average << endl;
cout << "Student 1 classroom 2 average test grade: " << class2_student1_average << endl;
cout << "Student 2 classroom 2 average test grade: " << class2_student2_average << endl;

class1_average = (class1_student1_average + class1_student2_average) / 2;
class2_average = (class2_student1_average + class2_student2_average) / 2;

cout << "Classroom 1 average test grade: " << class1_average << endl;
cout << "Classroom 2 average test grade: " << class2_average << endl;

total_average = (class1_average + class2_average) / 2;
cout << "Total School average: " << total_average;
}


void bookstore(double money) //case 2
{
    if (money < 1)
        cout << "You will need more money to make a purchase.";
    else if (money <= 2)
        cout << "With that amount, you can buy a comic for $1.";
    else if (money <= 10)
        cout << "With that amount, you can buy a comic for $1 or a sport journal for $2.";
    else if (money <= 15)
        cout << "With that amount, you can buy a comic for $1, a sport journal for $2, or a novel for up to $10.";
    //Below is a blanket statement for when the value entered for money exceeds 15
    else
        cout << "With that amount, you could buy a comic for $1, a sport journal for $2, a novel for up to $10, or a science book for $15.";
}

void highest_grade()  //case 3
{
    ifstream inputFile;
    inputFile.open("grades.txt");       //Note: the 'grades.txt' file needs to be saved in the same folder as the project
    int grades[12];                    //creates an array named grades and declares that it can store 12 integers

    for(int a = 0; a<=12; a++)         //for(initialize; test; update)
    {
        inputFile >> grades[a];
    }

    sort(grades, grades+11);
    cout << "Your lowest grade is " << grades[0];
    inputFile.close();
}
