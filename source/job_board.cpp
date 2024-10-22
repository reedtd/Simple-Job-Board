#include "job_board.hpp"

Job_Board::Job_Board(){
	this->f = new Feed();
	this->u = new Users();
	this->currentUser = nullptr;

	//std::string outFileName = GetDate() + ".txt";
	//this->completedJobs.open(outFileName, std::ios::out | std::ios::app);
}

Job_Board::~Job_Board(){
	delete f;
	delete u;
}

std::string Job_Board::GetCurrentUser(){
	return currentUser->GetUserName();
}

bool Job_Board::Logon(std::string userName){
	int attempts = 0;
	while(attempts < 3){
		currentUser = u->GetUser(userName);

		if(currentUser == nullptr){
			attempts++;
			if(attempts == 3){
				std::cout << "\nLogon Failed!!!" << std::endl;
				logonStatus = false;
				return false;
			}
			else{
				std::cout << "\nUsername does not match records. Please try again. " << (3 - attempts) << " attempts remaining." << std::endl;
			}
		}
		else{
			std::cout << "\nLogon successful!" << std::endl;
			attempts = 3;
			logonStatus = true;
			return true;
		}
	}
	return false;
}

void Job_Board::LogOff(){
	std::cout << "Logging off..." << std::endl;
	this->currentUser = nullptr;
	this->logonStatus = false;
}

bool Job_Board::GetLogonStatus(){
	return this->logonStatus;
}

void Job_Board::ListJobs(){
	Node* currentJob;

	currentJob = f->GetDeque()->GetHead();

	std::cout << "<<<-------------------->>>\n" << std::endl;
	while(currentJob != nullptr){
		std::cout << currentJob->ListJob() << std::endl;

		currentJob = currentJob->GetNextJob();
	}
	std::cout << "<<<-------------------->>>" << std::endl;
}

void Job_Board::SelectJob(std::string jobName){
	Deque* list = f->GetDeque();

	Node* currentJob = list->FindJob(jobName);

	if(currentJob == nullptr){
		std::cout << "No job found. Try again.";
		return;
	}
	else if(isTaken(currentJob) == true){
		std::cout << "Job is already taken. Exiting." << std::endl;
		return;
	}
	else{
		currentJob->SetJobStatus('p');
		currentJob->SetJobOwner(currentUser->GetUserName());

		std::string temp = currentJob->ListJob();
		std::cout << "<<<-------------------->>>\n" << "Confirming....\n" << temp
			<< "<<<-------------------->>>" << std::endl;
	}
}

void Job_Board::MyJobs(){
	Node* currentJob = f->GetDeque()->GetHead();

	std::cout << "<<<-------------------->>>" << std::endl;

	while(currentJob != nullptr){
		if(currentJob->GetJobOwner() == currentUser->GetUserName()){
			std::cout << currentJob->ListJob() << std::endl;
			currentJob = currentJob->GetNextJob();
		}
		else{
			currentJob = currentJob->GetNextJob();
		}
	}

	std::cout << "<<<-------------------->>>" << std::endl;
}

void Job_Board::MarkComplete(){
	std::string outputFileName = "../data/archive/" + GetDate() + ".txt";
	this->completedJobs.open(outputFileName, std::ios::out | std::ios::app);

	Node* currentJob;
	//list all current jobs of User
	MyJobs();

	std::string selection;
	std::string returnstr;

	std::cout << "Please Enter the job you'd like to make complete: ";
	while (selection.empty()){
		std::getline(std::cin, selection);
	}
	
	if(f->GetDeque()->FindJob(selection) == nullptr){
		std::cout << "Invalid entry. Exiting" << std::endl;
		return;
	}
	else{
		currentJob = f->GetDeque()->FindJob(selection);
		currentJob->SetJobStatus('c');
	}

	std::cout << "removing from list... ";

	if(completedJobs.is_open()){
		returnstr = currentJob->ListJob();
		std::cout << "\n\n" << returnstr << "\n" << std::endl;
		this->completedJobs << returnstr;
		std::string completedTime = "Completed at: " + GetTime();
		this->completedJobs << completedTime;
		completedJobs << "\n";
		f->GetDeque()->DeleteJob(currentJob);
		std::cout << selection << " has been removed!" << std::endl;
		this->completedJobs.close();
	}
	else{
		std::cout << "Error! Output file is not open! Exiting." << std::endl;
		return;
	}
}

void Job_Board::CreateJob(){
	Deque* dll = f->GetDeque();
	std::string tempName, tempDes;

	std::cout << "Please enter the job name: ";
	while(tempName.empty()){
		std::getline(std::cin, tempName);
	}

	std::cout << "Please enter the job description: ";
	while(tempDes.empty()){
		std::getline(std::cin, tempDes);
	}

	dll->CreateJob(tempName, tempDes);

	std::cout << tempName << " has been created!" << std::endl;

}

void Job_Board::RemoveJob(){
	Deque* dll = f->GetDeque();
	std::string tempName;

	std::cout << "Please select a job from the list below" << std::endl;
	dll->ListAll();
	std::cout << "Enter job name here: ";

	while(tempName.empty()){
		std::getline(std::cin, tempName);
	}

	//check if job exists
	if(dll->FindJob(tempName) == nullptr){
		std::cout << "No job found. Exiting." <<std::endl;
		return;
	}
	else{
		dll->DeleteJob(dll->FindJob(tempName));
	}
}

bool Job_Board::isTaken(Node* jobName){
	if(jobName->GetJobStatus() != 'n'){
		return true;
	}
	return false;
}

bool Job_Board::isAdmin(){
	if(currentUser->IsAdmin() == true){
		return true;
	}
	return false;
}

std::time_t Job_Board::GetSystemTime(){
	using std::chrono::system_clock;

	system_clock::time_point time = system_clock::now();
	std::time_t tm = system_clock::to_time_t(time);

	return tm;
}

std::string Job_Board::GetTime(){
	std::time_t tm = GetSystemTime();

	char* systemTime = ctime(&tm);
	std::istringstream parsedSystemTime(systemTime);
	std::vector<std::string> pT;//parsedTime
	std::string t;

	while(parsedSystemTime >> t){
		pT.push_back(t);
	}

	std::string returnString = pT.at(3);

	return returnString;
}

std::string Job_Board::GetDate(){
	std::time_t tm = GetSystemTime();

	char* systemTime = ctime(&tm);
	std::istringstream parsedSystemTime(systemTime);
	std::vector<std::string> pT;
	std::string t;

	while(parsedSystemTime >> t){
		pT.push_back(t);
	}

	std::string returnString = pT.at(0) + "-" + pT.at(1) + "-" + pT.at(2) + "-" + pT.at(4);

	return returnString;
}
