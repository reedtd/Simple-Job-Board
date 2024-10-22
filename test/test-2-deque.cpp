#include "catch/catch.hpp"
#include "../deque.hpp"

TEST_CASE("Test Deque"){
	Deque d;
	d.CreateJob("Job 1", "Example Description 1");
	d.CreateJob("Job 2", "Example Description 2");
	d.CreateJob("Job 3", "Example Description 3");
	d.CreateJob("Job 4", "Example Description 4");
	d.CreateJob("Job 5", "Example Description 5");
	CHECK(d.ListAll() == "Job Name: Job 1\nJob Name: Job 2\nJob Name: Job 3\nJob Name: Job 4\nJob Name: Job 5\n");
	d.CreateJob("Job 6", "Example Description 6");
	CHECK(d.ListAll() == "Job Name: Job 1\nJob Name: Job 2\nJob Name: Job 3\nJob Name: Job 4\nJob Name: Job 5\nJob Name: Job 6\n");
	d.DeleteJob(d.FindJob("Job 4"));
	CHECK(d.ListAll() == "Job Name: Job 1\nJob Name: Job 2\nJob Name: Job 3\nJob Name: Job 5\nJob Name: Job 6\n");
}
