
#include "Zombie.hpp"

void Zombie::setName( std::string name )
{
	this->_name = name;
}

void Zombie::announce( void )
{
	std::cout << "\t" << this->_name
			  << " : " << "BraiiiiiiinnnzzzZ..."
			  << std::endl;
}