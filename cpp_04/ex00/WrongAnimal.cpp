/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:29:57 by jutrera-          #+#    #+#             */
/*   Updated: 2023/08/16 17:29:57 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("Unknown wrong animal")
{
	std::cout << "WrongAnimal (unknown) : Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
	std::cout << "WrongAnimal (" << type << ") : Name constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal (" << _type << ") : Destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other.getType())
{
	std::cout << "WrongAnimal (" << _type << ") : Copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal : Overload operator = called." << std::endl;
	if ( this != &other )
		_type = other.getType();
	return *this;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void  WrongAnimal::makeSound( void ) const
{
	std::cout << "I don't know how is my sound." << std::endl;
}
