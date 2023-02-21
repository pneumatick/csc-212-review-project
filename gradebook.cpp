#include "gradebook.h"
#include <fstream>
#include <sstream>
#include <utility>
#include <iostream>

Gradebook::Gradebook(){
    this->assignment_grades_total = 0.0;
    this->exam_grades_total = 0.0;
    this->lab_grades_total = 0.0;
    this->project_grades_total = 0.0;
}

Gradebook::Gradebook(std::string inputFile){
    std::fstream read_file(inputFile);
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
    } else {
        std::cout << "Unable to open file." << std::endl;
        this->assignment_grades_total = 0.0;
        this->exam_grades_total = 0.0;
        this->lab_grades_total = 0.0;
        this->project_grades_total = 0.0;    
    }

    read_file.close();
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
    double total_grade = 0;
    //Multiplies each category total by its value in regards to the final grade (ex: assignments are 20%).
    total_grade = (Get_Assignment_Grade() * 0.2) + (Get_Exam_Grade() * 0.1) + (Get_Lab_Grade() * 0.2) + (Get_Projects_Grade() * 0.5);
    return total_grade;
}

// Manually add a new grade to the respective category
void Gradebook::add_grade(std::string category,std::string name, double grade){

}

// Create/update the grades file upon termination of the program
void Gradebook::close(std::string filename){
    std::ofstream file;
    file.open(filename);

    // Ensure the file has opened. Return if false.
    if (!file.is_open()) {
	std::cout << "Error opening file!" << std::endl;
	return;
    }

    for (unsigned long int i = 0; i < this->labs.size(); i++) {
	file << "lab " << this->labs[i].first << " " << this->labs[i].second << "\n";
    }

    for (unsigned long int i = 0; i < this->assignments.size(); i++) {
	file << "assignment " << this->assignments[i].first << " " << this->assignments[i].second << "\n";
    }
    
    for (unsigned long int i = 0; i < this->projects.size(); i++) {
	file << "project " << this->projects[i].first << " " << this->projects[i].second << "\n";
    }

    for (unsigned long int i = 0; i < this->exams.size(); i++) {
	file << "exam " << this->exams[i].first << " " << this->exams[i].second << "\n";
    }

    file.close();

    return;
}
