#include "../include/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap():
	ClapTrap()
{
	hitpoints = HITPOINTS_FT;
	energy_points = ENERGY_POINTS_FT;
	attack_damage = ATTACK_DAMAGE_FT;
	std::cout << "FragTrap without a name was constructed" << std::endl;
}

FragTrap::FragTrap(const std::string name):
	ClapTrap(name)
{
	hitpoints = HITPOINTS_FT;
	energy_points = ENERGY_POINTS_FT;
	attack_damage = ATTACK_DAMAGE_FT;
	std::cout << "FragTrap " << this->getName() << " was constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap " << copy.getName() << " was copied" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " was destructed" << std::endl;
}

FragTrap
	&FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		name = copy.getName();
		hitpoints = copy.getHitpoints();
		energy_points = copy.getEnergyPoints();
		attack_damage = copy.getAttackDamage();
	}
	return (*this);
}

void
	FragTrap::attack(std::string const &target)
{
	unsigned int	attack_damage_value = this->getAttackDamage();
	std::cout << "FragTrap " << this->getName() << " attack " << target \
	<< ", causing " << attack_damage_value;
	if (attack_damage_value == 1)
		std::cout << " point of damage!" << std::endl;
	else
		std::cout << " points of damage!" << std::endl;
}


void
	FragTrap::highFivesGuys()
{
	std::cout << this->getName() << " requested a positive high fives" << std::endl;
}
