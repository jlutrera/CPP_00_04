#ifndef HUMANB_HPP
#  define HUMANB_HPP

#  include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB( std::string name);
		HumanB();
		void setWeapon(Weapon& w);
		void attack( void );
};

#endif