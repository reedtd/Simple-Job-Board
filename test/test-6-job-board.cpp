#include "catch/catch.hpp"
#include "../job_board.hpp"

TEST_CASE("Test Job Board Logon"){
	Job_Board j;
	REQUIRE(j.Logon("Trenten") == true);
	CHECK(j.GetCurrentUser() == "Trenten");

	j.ListJobs();

	j.SelectJob("Job 1");
	j.SelectJob("Job 5");

	j.ListJobs();

	j.MyJobs();

	std::cout << j.GetDate() << std::endl;

	std::cout << j.GetTime() << std::endl;

	j.MarkComplete();
}

