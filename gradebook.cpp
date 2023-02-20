#include "gradebook.h"
#include <fstream>
#include <sstream>
#include <utility>
#include <iostream>
#include <iomanip>

Gradebook::Gradebook(){
    this->assignment_grades_total = 0.0;
    this->exam_grades_total = 0.0;
    this->lab_grades_total = 0.0;
    this->project_grades_total = 0.0;
}

Gradebook::Gradebook(std::string inputFile){
    std::ifstream read_file(inputFile);
    std::string line;
    std::string category;
    std::string name;
    double grade;
    // Verify File opened
    if (read_file.is_open()) {
        // Tokenize input data
        while (std::getline(read_file,line)) {
            std::stringstream data_line(line);
            data_line >> category >> name >> grade;
            // Add element to respective category and add to total grade of category
            if (category == LABS) {
                labs.push_back({name, grade});
                this->lab_grades_total+= grade;
            }
            else if (category == ASSIGNMENTS) {
                assignments.push_back({name, grade});
                this->assignment_grades_total+= grade;
            }
            else if (category == PROJECTS) {
                projects.push_back({name, grade});
                this->project_grades_total+= grade;
            }
            else if (category == EXAMS) {
                exams.push_back({name, grade});
                this->exam_grades_total+= grade;
            } else {
                std::cout << "Categroy not found for: " << category << ' ' << name << ' ' << grade << std::endl;
            }
        }
        read_file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
        this->assignment_grades_total = 0.0;
        this->exam_grades_total = 0.0;
        this->lab_grades_total = 0.0;
        this->project_grades_total = 0.0;
    }
}

// Return the student's cumulative grade for all graded labs as a percentage
double Gradebook::Get_Lab_Grade() {
    if (labs.size() == 0) {
        return 100.0;
    }

    return (this->lab_grades_total / (MAX_LAB_GRADE * labs.size())) * 100;
}

// Return the student's cumulative grade for all graded assignments as a
// percentage
double Gradebook::Get_Assignment_Grade() {
    if (assignments.size() == 0) {
        return 100.0;
    }

    return (this->assignment_grades_total / (MAX_ASSIGNMENT_GRADE * assignments.size())) * 100;
}

// Return the student's cumulative grade for all graded exams as a percentage
double Gradebook::Get_Exam_Grade() {
    if (exams.size() == 0) {
        return 100.0;
    }

    return (this->exam_grades_total / (MAX_EXAM_GRADE * exams.size())) * 100;
}

// Return the student's cumulative grade for all graded projects as a
// percentage
double Gradebook::Get_Projects_Grade() {
    if (projects.size() == 0) {
        return 100.0;
    }

    return (this->project_grades_total / (MAX_PROJECT_GRADE * projects.size())) * 100;
}

// Return the grade of a specific assignment.
// Returns -1.0 if the category or assignment isn't found.
double Gradebook::get_assignment_grade(std::string category, std::string name){
    double grade = -1.0;
    std::vector<std::pair<std::string, double>> category_vector;

    if (category == LABS) {
        category_vector = this->labs;
    }
    else if (category == ASSIGNMENTS) {
        category_vector = this->assignments;
    }
    else if (category == PROJECTS) {
        category_vector = this->projects;
    }
    else if (category == EXAMS) {
        category_vector = this->exams;
    }
    else {
        return -1.0;
    }

    for (long unsigned int i = 0; i < category_vector.size(); i++) {
        if (category_vector[i].first == name) {
            grade = category_vector[i].second;
        }
    }

    return grade;
}


// Returns the grade of a category as a percentage
double Gradebook::get_category_grade(std::string category){
    if (category == LABS) {
        return this->Get_Lab_Grade();
    }
    else if (category == ASSIGNMENTS) {
        return this->Get_Assignment_Grade();
    }
    else if (category == PROJECTS) {
        return this->Get_Projects_Grade();
    }
    else if (category == EXAMS) {
        return this->Get_Exam_Grade();
    }
    else {
        return -1.0;
    }
    return 0;
}

// Return the total cumulative grade for the class as a percentage
double Gradebook::get_total_grade(){
    int tot_points = 1000;
    double tot_grade = this->Get_Assignment_Grade()+ this->Get_Exam_Grade() + this->Get_Lab_Grade() + this->Get_Projects_Grade();
    return (tot_grade/tot_points)*100;
}

// Manually add a new grade to the respective category
void Gradebook::add_grade(std::string category,std::string name, double grade,std::string fname){
    if(category == LABS){
        for(int i = 0; i < labs.size();i++){
            if(std::stod(name) < std::stod(labs[i].first)){
                labs.insert(labs.begin()+i,{name,grade});
                i = labs.size();
            }
            else if(i == labs.size()-1){
                labs.push_back({name,grade});
                i = labs.size();
            }
        }
        this->lab_grades_total += grade;
    }
    else if(category == ASSIGNMENTS){
        for(int i = 0; i < assignments.size();i++){
            if(std::stod(name) < std::stod(assignments[i].first)){
                assignments.insert(assignments.begin()+i,{name,grade});
                i = assignments.size();
            }
            else if(i == assignments.size()-1){
                assignments.push_back({name,grade});
                i = assignments.size();
            }
        }
        this->assignment_grades_total+= grade;
    }
    else if(category == PROJECTS){
        for(int i = 0; i < projects.size();i++){
            if(std::stod(name) < std::stod(projects[i].first)){
                projects.insert(projects.begin()+i,{name,grade});
                i = projects.size();
            }
            else if(i == projects.size()-1){
                projects.push_back({name,grade});
                i = projects.size();
            }
        }
        this->project_grades_total += grade;
    }
    else if(category == EXAMS){
        for(int i = 0; i < exams.size();i++){
            if(std::stod(name) < std::stod(exams[i].first)){
                exams.insert(exams.begin()+i,{name,grade});
                i = projects.size();
            }
            else if(i == exams.size()-1){
                exams.push_back({name,grade});
                i = projects.size();
            }
        }
        this->exam_grades_total += grade;
    }
    std::ofstream new_file(fname);
    bool lab_done = false;
    bool assignment_done = false;
    bool proj_done = false;
    bool exam_done = false;
    if(new_file.is_open()){
        while(!exam_done){
            if(!lab_done){
                for(int i = 0; i<labs.size();i++){
                    new_file << "lab "+ labs[i].first + " " + std::to_string(labs[i].second) <<std::endl;
                }
                lab_done = true;
            }
            else if(!assignment_done){
                for(int i = 0; i<assignments.size();i++){
                    new_file << "assignment "+ assignments[i].first + " " + std::to_string(assignments[i].second) <<std::endl;
                }
                assignment_done = true;
            }
            else if(!proj_done){
                for(int i = 0; i<projects.size();i++){
                    new_file << "project "+ projects[i].first + " " + std::to_string(projects[i].second) <<std::endl;
                }
                proj_done = true;
            }
            else if(!exam_done){
                for(int i = 0; i<exams.size();i++){
                    new_file << "exam "+ exams[i].first + " " + std::to_string(exams[i].second) <<std::endl;
                }
                exam_done = true;
            }
        }
    }
    new_file.close();
 }