#include "catch/catch.hpp"
#include "../node.hpp"

TEST_CASE("Test Default"){
	Node n;
	CHECK("" == n.GetJobName());
	CHECK("" == n.GetJobDes());
	CHECK(nullptr == n.GetNextJob());
	CHECK(nullptr == n.GetPrevJob());
}

TEST_CASE("Test non-default Inputs"){
	Node n("Job 1","Job about anything");
	Node * nextJob = new Node("Job 2", "Job about any other thing");
	n.SetNextJob(nextJob);
	CHECK("Job 1" == n.GetJobName());
	CHECK(nextJob == n.GetNextJob());
	CHECK(nullptr == n.GetPrevJob());
}

TEST_CASE("Test AddJob"){
	Node n("Example Job 1", "Example Job Description 1");
	Node * newJob = new Node("Example Job 2", "Example Job Description 2");
	n.AddJob(newJob);
	CHECK(newJob == n.GetNextJob());
	CHECK(nullptr == n.GetPrevJob());
	delete newJob;
}
