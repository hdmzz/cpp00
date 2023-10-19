#include <iostream>
#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
		: firstName(first), lastName(last), nickname(nick), phoneNumber(phone), darkestSecret(secret) {}

	void display(int index) const {
		std::cout << "|" << std::right << std::setw(10) << index << "|";
		std::cout << std::right << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
		std::cout << std::right << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
		std::cout << std::right << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|";
		std::cout << std::endl;
	}
};

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook() : contactCount(0) {}

	bool addContact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret) {
		if (contactCount < 8) {
			contacts[contactCount] = Contact(first, last, nick, phone, secret);
			contactCount++;
		} else {
			// Replace the oldest contact
			for (int i = 0; i < 7; i++) {
				contacts[i] = contacts[i + 1];
			}
			contacts[7] = Contact(first, last, nick, phone, secret);
		}
		return true;
	}

	void displayContacts() const {
		std::cout << "|  Index  | First Name| Last Name | Nickname  |" << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		for (int i = 0; i < contactCount; i++) {
			contacts[i].display(i);
		}
	}
};

int main() {
	PhoneBook phoneBook;

	while (true) {
		std::string command;
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD") {
			std::string first, last, nick, phone, secret;
			std::cout << "Enter first name: ";
			std::cin >> first;
			std::cout << "Enter last name: ";
			std::cin >> last;
			std::cout << "Enter nickname: ";
			std::cin >> nick;
			std::cout << "Enter phone number: ";
			std::cin >> phone;
			std::cout << "Enter darkest secret: ";
			std::cin >> secret;

			phoneBook.addContact(first, last, nick, phone, secret);
		} else if (command == "SEARCH") {
			phoneBook.displayContacts();

			int index;
			std::cout << "Enter the index of the contact to display: ";
			if (std::cin >> index && index >= 0 && index < phoneBook.contactCount) {
				const Contact& contact = phoneBook.contacts[index];
				std::cout << "Contact Information:" << std::endl;
				std::cout << "First Name: " << contact.firstName << std::endl;
				std::cout << "Last Name: " << contact.lastName << std::endl;
				std::cout << "Nickname: " << contact.nickname << std::endl;
				std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
				std::cout << "Darkest Secret: " << contact.darkestSecret << std::endl;
			} else {
				std::cout << "Invalid index or format." << std::endl;
			}
		} else if (command == "EXIT") {
			break;
		}
	}

	return 0;
}