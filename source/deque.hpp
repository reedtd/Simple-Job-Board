#ifndef DEQUE_HPP
#define DEQUE_HPP
#include "node.hpp"
#include <iostream>

class Deque{
	private:
		Node* head;
	public:
		Deque(); //default constructor
		~Deque(); //destructor
		void ClearList();//helper function used by destructor to deallocate memory used by the list
		Node* temp;
		void CreateJob(std::string jobName, std::string jobDes);//seld-explainatory. creates a job
		Node* FindJob(std::string jobName);//find a job based on name
		std::string ListAll(); //list all jobs and first 25 characters of description
		void DeleteJob(Node* job); //remove a job from the deque
		Node* GetHead();//returns head pointer. used in Feed class
};
#endif
