#include "node_users.hpp"
#include <sstream>//parse
#include <fstream>//input users

Node_Users::Node_Users(){
	this->name = "Trenten";
	this->admin = true;
	this->user = true;
}

Node_Users::Node_Users(std::string name){
	this->name = name;
	this->admin = false;
	this->user = true;
}

void Node_Users::SetUserName(std::string userName){
	this->name = userName;
}

std::string Node_Users::GetUserName(){
	return this->name;
}

void Node_Users::SetAdmin(std::string userName){
	//similar to computer account management, admins get permissions of both base users and admins
	this->admin = true;
	this->user = true;
}

bool Node_Users::IsAdmin(){
	if(this->admin == false){
		return false;
	}
	else{
		return true;
	}
}

void Node_Users::SetUser(std::string userName){
	this->user = true;
}

bool Node_Users::IsUser(){
	if(this->user == false){
		return false;
	}
	else{
		return true;
	}
}
