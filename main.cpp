#include <iostream>

int main() {
    bool exit = false;
    std::string value;

    while(!exit){
        std::cout<<"Input the number for the menu choice you want executed: "<<std::endl;
        std::cout<<"1. Get the grade from a specific assignment."<<std::endl;
        std::cout<<"2. Get the grade for a specific group of assignments "<<std::endl;
        std::cout<<"3. Get your total grade. "<<std::endl;
        std::cout<<"4. Add a grade to a specific group of assignments. "<<std::endl;
        std::cout<<"5. To exit program. "<<std::endl;

        std::cin>>value;

        if(value == "1"){

        }
        else if(value == "2"){

        }
        else if (value == "3"){

        }
        else if(value == "4"){

        }
        else if(value == "5"){
            exit = true;
        }
        else{
           std::cout<<"Invalid input try again" <<std::endl;
        }

    }
    return 0;
}
