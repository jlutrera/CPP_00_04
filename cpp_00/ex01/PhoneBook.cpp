#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void) const {
	std::cout << "--------------USAGE---------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact(void) {
	static int	i;
	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::printContacts(void) const {
	std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
	for (size_t i = 0; i < 8; i++) {
		this->_contacts[i].view(i);
	}
	std::cout << std::endl << std::flush;
}

int	PhoneBook::_readInput() const {
	int		input = -1;
	bool	valid = false;

	do{
		std::cout << "Please enter the contact index: ";
		std::cin >> input;
		if (std::cin.eof())
			break;
		if (input >= 0 && input <= 8)
			valid = true;
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Invalid index; please re-enter." << std::endl;
		}
	} while (!valid);
	return (input);
}

void	PhoneBook::search(void) const {
	int i = this->_readInput();
	this->_contacts[i].display(i);
}
