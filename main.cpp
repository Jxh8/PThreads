#include <iostream>
#include <fstream>
#include <vector>
#include <pthread.h>
#include "student.h"
#include <string>

using namespace std;



int main(){

vector<Student> StudentList;
int id;
int score;
int passed = 0;

//This will open the already existing file that we created.
ifstream infile("listofstudents.txt");
//This error will populate if the existing file cannot be found or name was changed.
if(!infile){
    cerr << "Error, could not locate file." << endl;
    return 1;
}
//Re-iterates through the whole file adding the ID and the score of the student into the vector.
while(infile >> id >> score){
    Student default_student;
    default_student.id = id;
    default_student.score = score;

    StudentList.push_back(default_student);

    if (score == 1){
        passed++;
    }
}
//Closes the File.
infile.close();


//Test--------------------------------------------------------------------------------------------
for (const auto& default_student : StudentList) {
        cout << "ID: " << default_student.id << ", Passed: " << default_student.score << endl;
    }
//Test--------------------------------------------------------------------------------------------


// This is using No Threads, simply using a function to determine the percentage of students who passed.
cout << "Using No Threads, the amount of students that passed the exam was " << Passed_Percentage(passed, StudentList.size()) << "%."<< endl;


Thread_data one_thread;
one_thread.StudentList = &StudentList;
one_thread.end = StudentList.size();
pthread_t one_pthread;

pthread_create(&one_pthread, nullptr, passed_counter, (void*)&one_thread);
pthread_join(one_pthread, nullptr);
// This is using One Thread, using 1 Thread to calculate the percentage of students who passed.
cout << "Using One Threads, the amount of students that passed the exam was " << Passed_Percentage(one_thread.passed, StudentList.size()) << "%." << endl;










return 0;
}
