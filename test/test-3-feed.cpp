#include "catch/catch.hpp"
#include "../feed.hpp"

TEST_CASE("Test ReadFile"){
	Feed f;
	//f.ReadFile("jobList.csv");
	CHECK(f.GetDeque()->ListAll() == "Job Name: Job 1\nJob Name: Job 2\nJob Name: Job 3\nJob Name: Job 4\nJob Name: Job 5\nJob Name: Job 6\nJob Name: Job 7\nJob Name: Job 8\n");
}
