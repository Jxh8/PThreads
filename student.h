#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
using namespace std;

class Student{
    public:
        int id;
        int score;
};

double Passed_Percentage(int passed, int vector_size){
    return (passed * 100 /vector_size);
}

class Thread_data{
    public:
        vector<Student>* StudentList;
        int begin = 0;
        int end;
        int passed;
};

void* passed_counter(void* arg){
    Thread_data* data = (Thread_data*)arg;
    int thread_passed = 0;
    for(int i = data->begin; i < data->end; i++){
        if((*data->StudentList)[i].score ==1){
            thread_passed++;
        }
    }
    data->passed = thread_passed;
    pthread_exit(nullptr);
}

#endif 