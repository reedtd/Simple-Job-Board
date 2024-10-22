#include "tui.hpp"


void TUI::Run(){
	std::cout << "Initializing..." << std::endl;

	this->j = new Job_Board();

	while(true){
		std::string userName;

		std::cout << "Please enter a Username: ";
		while(userName.empty()){
			std::getline(std::cin, userName);
		}
		if(userName == "exit" || userName == "Exit"){//user may not to log in
													 //but exit program
			break;
		}

		else{
			j->Logon(userName);
		}

		while(j->GetLogonStatus() == true){
			std::string command;

			PrintMenu();
			std::cout << "Please select an option: ";
			while(command.empty()){
				std::getline(std::cin, command);
			}

			if(command == "List Jobs" || command == "list jobs"){
				clearScn();
				j->ListJobs();
			}
			else if(command == "Accept Job" || command == "accept job"){
				clearScn();
				j->ListJobs();

				std::string selection;
				std::cout << "\nPlease enter the job you would like to take on: ";
				while(selection.empty()){
					std::getline(std::cin, selection);
				}

				j->SelectJob(selection);
			}
			else if(command == "My Jobs" || command == "my jobs"){
				clearScn();
				j->MyJobs();
			}
			else if(command == "Mark Complete" || command == "mark complete"){
				clearScn();
				j->MarkComplete();
			}
			else if(command == "Log Off" || command == "log off"){
				clearScn();
				j->LogOff();
			}
			else if(command == "Create New Job" || command == "create new job"){
				clearScn();
				j->CreateJob();
			}
			else if(command == "Remove Job" || command == "remove job"){
				clearScn();
				j->RemoveJob();
			}
			else if(command == "Exit Program" || command == "exit program"){
				clearScn();
				std::cout << "Are you sure you want to exit? All jobs that have not been marked\n"
						  << "complete and therefore archived will be lost!" << std::endl;
				std::cout << "Enter [y/n]: ";
				std::string response;
				while(response.empty()){
					std::getline(std::cin, response);
				}

				if(response == "y"){
					std::cout << "Exiting...";
					return;
				}
			}
			else{
				std::cout << "Invalid response. Try again";
			}
		}
	}
	delete j;
}

void TUI::PrintMenu(){
	std::cout << "\n" << std::setfill('*') << std::setw(50) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(28) << "Welcome" << std::endl;
	std::cout << std::setfill(' ') << std::setw(34) << "Job Board Options\n" << std::endl;

	if(j->isAdmin() == false){
		std::cout << "User Tasks:\n";
		std::cout << "\tList Jobs - list all available jobs on the board\n";
		std::cout << "\tAccept Job - From the listed jobs, select one to take on\n";
		std::cout << "\tMy Jobs - list all jobs the current user has taken\n";
		std::cout << "\tMark Complete - of the jobs you have taken, mark one as complete\n";
		std::cout << "\tLog off - sign out of the current account\n" << std::endl;
	}
	else{
		std::cout << "User Tasks:\n";
		std::cout << "\tList Jobs - list all available jobs on the board\n";
		std::cout << "\tAccept Job - From the listed jobs, select one to take on\n";
		std::cout << "\tMy Jobs - list all jobs the current user has taken\n";
		std::cout << "\tMark Complete - of the jobs you have taken, mark one as complete\n";
		std::cout << "\tLog off - sign out of the current account\n" << std::endl;
		std::cout << "Administrative Tasks:\n";
		std::cout << "\tCreate New Job - enter in the required information and create a new job on the board\n";
		std::cout << "\tRemove Job - From the jobs available, remove one from the board perminantly" << std::endl;
	}
	std::cout << std::setfill('*') << std::setw(50) << "" << std::endl;
}

void TUI::clearScn(){
	system("cls");
}

