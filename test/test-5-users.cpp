#include "catch/catch.hpp"
#include "../users.hpp"

TEST_CASE("Test Users"){
	Users u;

	CHECK(u.GetUser("Trenten")->IsUser() == true);
}
