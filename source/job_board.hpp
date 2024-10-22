#ifndef JOB_BOARD_HPP
#define JOB_BOARD_HPP
#include "feed.hpp"
#include "users.hpp"
#include <ctime>
#include <chrono>

class Job_Board{

	private:
		Feed* f;
		Users* u;

		Node_Users* currentUser;
		bool logonStatus;

		std::ofstream completedJobs;

	public:
		Job_Board();
		~Job_Board();

		std::string GetCurrentUser();

		//logon -> who takes the job
		bool Logon(std::string userName);
		void LogOff();
		bool GetLogonStatus();
		//commands for base users
		void ListJobs();//job name, desciption, status, and current jobTaker
		void SelectJob(std::string jobName);
		void MyJobs(); //pull any job with owner that matches current
							  //user
		void MarkComplete();//pulls up job user has taken on, user selects which job to mark complete
		//commands for advanced users; all base user functions plus adv func
		void CreateJob();
		void RemoveJob();
		//void Defragment();

		//other func. depends.
		bool isTaken(Node* jobName);
		bool isAdmin();

		std::time_t GetSystemTime();
		std::string GetTime();//used for archiving jobs
		std::string GetDate();//used for naming the archive file
};
#endif
