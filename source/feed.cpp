#include "feed.hpp"
#include <sstream>//parse
#include <fstream>//input

Feed::Feed(){
	this->d = new Deque();
	this->inFileName = "../data/jobList.csv";
	this->outFileName = "";
	ReadFile(d);
}

Feed::~Feed(){
	delete d;
}

Deque* Feed::GetDeque(){
	return d;
}

std::string Feed:: GetInFileName(){
	return this->inFileName;
}

void Feed::SetInFileName(std::string inFileName){
	this->inFileName = inFileName;
}

std::string Feed::GetOutFileName(){
	if(outFileName.length() < 6){ //".txt" or ".csv" at least requires a file extention. this limit counts for a file
								  //extention plus one character. exp: "1.txt"
		std::string returnMsg = "No filename given. Please enter a file name."; //error message to display for GUI
		return returnMsg;
	}
	else{
		return this->outFileName;
	}
}

void Feed::SetOutFileName(std::string outFileName){
	this->outFileName = outFileName;
}

void Feed::ReadFile(Deque* d){
	std::string stream = "";

	std::ifstream iss;
	iss.open(this->inFileName, std::ios::in);

	while(getline(iss, stream)){
		std::string jobName;//two cars, pass to Deque::CreateJob
		std::string jobDes;//as defined in deque.hpp

		std::stringstream iss(stream);//takes an entire line at a time

		//using a semicolon as the delimiter; allows for the use of
		//commas in desciption part of the job lsting
		getline(iss, jobName, ';');
		getline(iss, jobDes);

		d->CreateJob(jobName, jobDes);//pass two variables over

		stream = "";//refresh stream after line is parsed
	}
}
