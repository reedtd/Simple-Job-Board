#ifndef USERS_HPP
#define USERS_HPP
#include <sstream>
#include <fstream>
#include <vector>
#include "node_users.hpp"
class Users{

	private:
		std::vector<Node_Users*> users;//array to store users
		int numUsers;
	public:
		Users();//read users.csv first, then add admin priv with admins.csv
		~Users();

		std::vector<Node_Users*> GetAllUsers();//return the array

		Node_Users* GetUser(std::string userName);//return just the user based on username
};
#endif
