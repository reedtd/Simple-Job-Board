#ifndef NODE_HPP
#define NODE_HPP
#include <string>
class Node{
	private:
		std::string jobName; // title of posted job
		std::string jobDes; //description of posted job
		char jobStatus; //job status n->new, i-> in progress c->complete
		std::string jobOwner;//who takes the job, used in feed
		Node* nextJob; //tail pointer
		Node* prevJob; //head pointer
	public:
		Node();
		Node(std::string jobName, std::string jobDes); //parameterized constructor; takes job name and job desciption
		//AddJob helper for deque class
		void AddJob(Node* currentJob, Node* newJob);
		//data
		std::string GetJobName(); //return name of job
		void SetJobName(std::string jobName); //set name of job
		std::string GetJobDes(); //return job desciption
		void SetJobDes(std::string jobDes); //set job description
		char GetJobStatus();
		void SetJobStatus(char jobStatus);
		std::string GetJobOwner();
		void SetJobOwner(std::string jobOwner);
		//pointers
		Node* GetNextJob(); //return next job (tail pointer)
		Node* GetPrevJob(); //return previous job (head pointer)
		void SetNextJob(Node* nextJob); //set tail pointer
		void SetPrevJob(Node* prevJob); //set head pointer
		//calls from other classes
		std::string ListJob();

};
#endif
