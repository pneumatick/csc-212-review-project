#include <iostream>
#include "gradebook.h"

int main(int argc, char*argv[]) {
    bool exit = false;  // Menu exit condition
    std::string value;
    Gradebook grades;
    std::string user_input_category;
    std::string user_input_name;
    std::string user_input_grade;
    std::string filename = "grades.txt";

    // Ensure that the program is run with the correct number of args.
    // Use the correct instructor depending on the given args.
    switch (argc) {
	case 1:
	    grades = Gradebook();
	    break;
	case 2:
	    filename = argv[1];
	    grades = Gradebook(filename);
	    break;
	default:
	    std::cout << "Unexpected number of args: Requires none (create a new gradebook)"
		<< " or one input file name (such as \"grades.txt\")" << std::endl;
	    return 1;
    }

    while (!exit) {
        // Main menu
        std::cout << "Input the number for the menu choice you want executed: " << std::endl;
        std::cout << "1. Get the grade from a specific assignment." << std::endl;
        std::cout << "2. Get the grade for a specific group of assignments " << std::endl;
        std::cout << "3. Get your total grade. " << std::endl;
        std::cout << "4. Add a grade to a specific group of assignments. " << std::endl;
        std::cout << "5. To exit program. " << std::endl;

        std::cin >> value;

        // Handle menu options
        if (value == "1") {   // Grade for single assignment
	    double grade;

            std::cout << "\nInput the category of the assignment you are "
		<< "looking for (lab, assignment, exam, project): ";
            std::cin >> user_input_category;

            std::cout << "\nInput the name of the assignment: ";
            std::cin >> user_input_name;

	    grade = grades.get_assignment_grade(user_input_category, user_input_name);
	    if (grade > 0) {
                std::cout << "\nPoints achieved for assignment \"" 
	            << user_input_name << "\" in category \"" << user_input_category 
		    << "\": " << grade << "\n\n";
	    }
	    else {
	        std::cout << "\nCategory or assignment name not found...\n" << std::endl;
	    }
        }
        else if (value == "2") {  // Grade for entire category
	    double grade;

            std::cout << "\nInput the name of the category you want the total "
		<< "grade for (lab, assignment, exam, project): ";
            std::cin >> user_input_category;

	    grade = grades.get_category_grade(user_input_category);
	    if (grade > 0) {
                std::cout << "\nTotal grade for category \"" 
		    << user_input_category << "\": " << grade << "%\n\n";
	    }
	    else {
		std::cout << "\nCategory name not found...\n" << std::endl;
	    }
        }
        else if (value == "3") { // Grade for overall course
            std::cout << "\nOverall course grade: " << grades.get_total_grade() << "%\n\n";
        }
        else if (value == "4") {  // Add new grade to gradebook
            std::cout << "\nInput the name of the category for the "
		<< "assignment you're adding (lab, assignment, exam, project): ";
            std::cin >> user_input_category;

	    // Esnure that the entered category is valid
	    if (!(user_input_category == LABS || 
		user_input_category == ASSIGNMENTS ||
		user_input_category == PROJECTS ||
		user_input_category == EXAMS)) {
		std::cout << "\nInvalid category name: " 
		    << "Expected lab, assignment, project, or exam\n" << std::endl;
		continue;
	    }

            std::cout << "\nInput the name of the assignment you're adding: ";
            std::cin >> user_input_name;

            std::cout << "\nInput the grade of the assignment you're adding: ";
	    std::cin >> user_input_grade;

            grades.add_grade(user_input_category, user_input_name, std::stod(user_input_grade));

	    std::cout << "\n" + user_input_category + " " + user_input_name 
		+ " with a grade of " + user_input_grade + " added!\n" << std::endl;
        }
        else if (value == "5") {  // Exit program, update grades file
            
            std::cout << "\nWould you like to save this gradebook?\nY/N\n";
            char user_response;
            std::cin >> user_response;
            if (toupper(user_response) == 'Y') {
                std::cout << "\nWould you like to overwrite \"" << filename << "\"?\nY/N\n";
                std::cin >> user_response;
                if (toupper(user_response) == 'N') {
                    std::cout << "\nPlease input a file name using the following format:\nyour_file_name.txt\nEnter file name here:\n";
                    std::cin >> filename;
                }

                grades.close(filename);
                std::cout << "\nGrades saved in file \"" << filename << "\"" << std::endl;
            }
            exit = true;
        }
        else {   // Invalid user input
           std::cout << "Invalid input: Try again" << std::endl;
        }

    }

    return 0;
}
