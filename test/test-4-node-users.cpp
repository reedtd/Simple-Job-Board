#include "catch/catch.hpp"
#include "../node_users.hpp"

TEST_CASE("Test Node_Users"){

	Node_Users n;

	CHECK(n.GetUserName() == "Trenten");
	CHECK(n.IsAdmin() == true);
	CHECK(n.IsUser() == true);

}

TEST_CASE("Test Parameterized Node_Users"){

	Node_Users n("Terriann");

	CHECK(n.GetUserName() == "Terriann");
	CHECK(n.IsAdmin() == false);
	CHECK(n.IsUser() == true);

}
