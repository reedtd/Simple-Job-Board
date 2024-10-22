#ifndef TUI_HPP
#define TUI_HPP
#include "job_board.hpp"
#include <iomanip>

class TUI{
	private:
		Job_Board* j;

	public:
		void Run();
		void PrintMenu();
		void clearScn();
};
#endif
