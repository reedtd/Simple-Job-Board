#ifndef FEED_HPP
#define FEED_HPP
#include "deque.hpp"

class Feed{

	private:
		Deque* d;
		std::string inFileName;
		std::string outFileName;
	public:
		Feed();
		~Feed();

		Deque* GetDeque();//return deque. Job_Board will frequently call this

		std::string GetInFileName();
		void SetInFileName(std::string inFileName);
		std::string GetOutFileName();
		void SetOutFileName(std::string outFileName);//isn't really needed at
													 //the moment, could maybe
													 //implement for the GUI
		//read in files
		void ReadFile(Deque* d);//read file, input data as new nodes onto the
								//deque

};

#endif
