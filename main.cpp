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
	    std::cout << "Unexpected number of args: Requires none (new gradebook)"
		<< " or one input file name (existing gradebook)" << std::endl;
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
            std::cout << "\nInput the category of the assignment you are "
		<< "looking for (lab, assignment, exam, project): ";
            std::cin >> user_input_category;

            std::cout << "\nInput the name of the assignment: ";
            std::cin >> user_input_name;

            std::cout << "\nPoints achieved for assignment \"" 
		<< user_input_name << "\" in category \"" << user_input_category << "\": " 
		<< grades.get_assignment_grade(user_input_category, user_input_name) 
		<< "\n\n";
        }
        else if (value == "2") {  // Grade for entire category
            std::cout << "\nInput the name of the category you want the total "
		<< "grade for (lab, assignment, exam, project): ";
            std::cin >> user_input_category;

            std::cout << "\nGrade for category \"" << user_input_category << "\": " 
		<< grades.get_category_grade(user_input_category) << "%\n\n";
        }
        else if (value == "3") { // Grade for overall course
            std::cout << "\nOverall course grade: " << grades.get_total_grade() << "%\n\n";
        }
        else if (value == "4") {  // Add new grade to gradebook
            std::cout << "\nInput the name of the category for the "
		<< "assignment you're adding (lab, assignment, exam, project): ";
            std::cin >> user_input_category;

            std::cout << "\nInput the name of the assignment you're adding: ";
            std::cin >> user_input_name;

            std::cout << "\nInput the grade of the assignment you're adding: ";
	    std::cin >> user_input_grade;

            grades.add_grade(user_input_category, user_input_name, std::stod(user_input_grade));

	    std::cout << "\n" + user_input_category + " " + user_input_name 
		+ " with a grade of " + user_input_grade + " added!\n" << std::endl;
        }
        else if (value == "5") {  // Exit program, update grades file
            exit = true;
            grades.close(filename);
        }
        else {   // Invalid user input
           std::cout << "Invalid input: Try again" << std::endl;
        }

    }

    return 0;
}
