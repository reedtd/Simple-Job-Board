#include "users.hpp"
#include <iostream>
Users::Users(){

	this->numUsers = 0;

	std::string stream = "";

	std::ifstream iss;
	iss.open("../data/users.txt", std::ios::in);

	while(getline(iss, stream)){
		std::string accType;
		std::string userName;

		std::stringstream iss(stream);

		std::getline(iss, accType, ':');
		std::getline(iss, userName);

		Node_Users* newUser = new Node_Users(userName);

		//assign account type, only need to check if admin since all accounts are
		//part of the "Users" group
		if(accType == "Admin"){
			newUser->SetAdmin(userName);
		}

		users.push_back(newUser);

		++numUsers;
	}
}

Users::~Users(){
	while(users.size() > 0){
		//debugging
		std::cout << "Deleting: " << users.back()->GetUserName() << std::endl;

		delete users.back();
		users.pop_back();
	}
}

std::vector<Node_Users*> Users::GetAllUsers(){
	for(int i = 0; i < this->numUsers; ++i){
		std::cout << "User " << i << ": " << users.at(i)->GetUserName() <<std::endl;
	}

	return this->users;
}

Node_Users* Users::GetUser(std::string userName){
	for(int i = 0; i < this->numUsers; ++i){
		if(users.at(i)->GetUserName() == userName){
			return users.at(i);
		}
	}
	return nullptr;
}
