#include "deque.hpp"

Deque::Deque(){
	this->head = nullptr;
}

Deque::~Deque(){
	while(this->head != nullptr){
		this->ClearList();
	}
	delete head;
}

void Deque::ClearList(){
	Node* tempHead = this->head;
	if(tempHead != nullptr){
		this->head = tempHead->GetNextJob();
		delete tempHead;
	}
}

void Deque::CreateJob(std::string jobName, std::string jobDes){
	Node* newJob = new Node(jobName, jobDes);
	Node** headByRef = &head;
	Node* temp = *headByRef;

	newJob->SetNextJob(nullptr);

	//Check if list is empty
	if(*headByRef == nullptr){
		newJob->SetPrevJob(nullptr);
		*headByRef = newJob;
		//std::cout << "CreatJob: List is Empty" << std::endl; //DB
		return; //end of function
	}
	while(temp->GetNextJob() != nullptr){//otherwise add new job to end of list
		temp = temp->GetNextJob();
	}

	temp->SetNextJob(newJob);//set next pointer
	newJob->SetPrevJob(temp);//set prev pointer

	/*Debugging
	std::cout << "Created New Job -> " << jobName << std::endl;
	std::cout << "New Job's Prev Job -> " << newJob->GetPrevJob()->GetJobName() << std::endl;*/

	//this->jobStatus = 'n'; //n -> new job
						   	  //p - >pending/in progress
						      //c -> complete
						      //will end up being able to be changed at a later
						      //time --> move to node | base-line data
}

std::string Deque::ListAll(){
	std::string list = "";//string to return; maybe do stringstream instead of outputting? could be useful for archiving

	Node** headByRef = &head;

	Node* temp = *headByRef;

	while(temp->GetNextJob() != nullptr){
		list = list + "Job Name: " + temp->GetJobName() + "\n";
		temp = temp->GetNextJob();
	}

	list = list + "Job Name: " + temp->GetJobName() + "\n";

	return list;
}

Node* Deque::FindJob(std::string jobName){
	Node** headByRef = &head;
	Node* temp = *headByRef;

	while(temp != nullptr){
		if(temp->GetJobName() == jobName){
			std::cout << "Found Job: " << temp->GetJobName() << "!" << std::endl;
			return temp;
		}
		else{
			temp = temp->GetNextJob();
		}
	}
	return nullptr;
}

void Deque::DeleteJob(Node* job){
	//visualization before
	//             ->   ->   ->   -> (next pointers)
	//nullptr    A    B    C    D    nullptr
	//        <-   <-   <-   <-      (prev pointers)

	//visualization after
	//             ->   ------>   -> (next pointers)
	//nullptr    A    B    X    D    nullptr
	//        <-   <-   <------      (prev pointers)

	//std::cout << "Delete Job Function" << std::endl;//DB
	if(job == nullptr){
		std::cout << "Job passed was a nullptr! Exiting!";
		return;
	}
	//check is node is head
	else if(job->GetPrevJob() == nullptr){
		//std::cout << "Node is head" << std::endl;//DB
		this->head = job->GetNextJob();
		job->GetNextJob()->SetPrevJob(nullptr);
		delete job;
	}
	//check if node is tail
	else if(job->GetNextJob() == nullptr){
		//std::cout << "Node is tail" << std::endl;//DB
		job->GetPrevJob()->SetNextJob(nullptr);
		delete job;

	}
	else{
	//create temp pointers of node
	Node* temp = job;
	Node* tempNext = job->GetNextJob();
	Node* tempPrev = job->GetPrevJob();
	//rewrite next pointer
	tempPrev->SetNextJob(temp->GetNextJob());
	//rewrite prev pointer
	tempNext->SetPrevJob(temp->GetPrevJob());
	//delete node
	delete job;
	}
}

Node* Deque::GetHead(){
	return this->head;
}
