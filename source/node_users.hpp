#ifndef NODE_USERS_HPP
#define NODE_USERS_HPP
#include <string>
class Node_Users{

	private:
		std::string name;
		bool admin;
		bool user;
	public:
		Node_Users();
		Node_Users(std::string name);

		void SetUserName(std::string userName);
		std::string GetUserName();

		void SetAdmin(std::string userName);
		bool IsAdmin();
		void SetUser(std::string username);
		bool IsUser();
};
#endif
