#include "node.hpp"
#include <iostream>

Node::Node(){
	this->jobName = "";
	this->jobDes = "";
	this->jobStatus = 'n';// new job/ not taken
	this->jobOwner = "";//no job owner until someone accepts job
	this->nextJob = nullptr;
	this->prevJob = nullptr;
}

Node::Node(std::string jobName, std::string jobDes){
	this->jobName = jobName;
	this->jobDes = jobDes;
	this->jobStatus = 'n';//new job/ not taken
	this->jobOwner = "";//no job owner until someone accepts job
	this->nextJob = nullptr;
	this->prevJob = nullptr;
}

void Node::AddJob(Node* currentJob, Node* newJob){
	newJob->SetPrevJob(currentJob);
	currentJob->SetNextJob(newJob);
}

std::string Node::GetJobName(){
	return this->jobName;
}

void Node::SetJobName(std::string jobName){
	this->jobName = jobName;
}

std::string Node::GetJobDes(){
	return this->jobDes;
}

void Node::SetJobDes(std::string jobDes){
	this->jobDes = jobDes;
}

char Node::GetJobStatus(){
	return this->jobStatus;
}

void Node::SetJobStatus(char jobStatus){
	this->jobStatus = jobStatus;
}

std::string Node::GetJobOwner(){
	return this->jobOwner;
}

void Node::SetJobOwner(std::string jobOwner){
	this->jobOwner = jobOwner;
}

Node* Node::GetNextJob(){
	if(this->nextJob == nullptr){
		return nullptr;
	}
	else{
		return this->nextJob;
	}
}

Node* Node::GetPrevJob(){
	if(this->prevJob == nullptr){
		return nullptr;
	}
	else{
		return this->prevJob;
	}
}

void Node::SetNextJob(Node* nextJob){
	this->nextJob = nextJob;
}

void Node::SetPrevJob(Node* prevJob){
	this->prevJob = prevJob;
}

std::string Node::ListJob(){
	std::string returnString = "";

	returnString = "Name: " + this->jobName + "\n" + "Description: " + this->jobDes + "\n" + "Status: ";

	if(jobStatus == 'n'){
		returnString += "[New Job]\n";
	}
	else if(jobStatus == 'p'){
		returnString += "[Pending/In Progress]\n";
	}
	else if(jobStatus == 'c'){
		returnString += "[Complete]\n";
	}
	else{
		std::cout << "Invalid Entry";
	}

	returnString += "Owner: ";

	if(this->jobOwner.length() == 0){
		returnString += "[None]\n";
	}
	else{
		returnString += "[" + this->jobOwner + "]\n";
	}

	return returnString;
}
