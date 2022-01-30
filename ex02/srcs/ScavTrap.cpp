#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	hitpoints = HITPOINTS_ST;
	energy_points = ENERGY_POINTS_ST;
	attack_damage = ATTACK_DAMAGE_ST;
	std::cout << "ScavTrap without a name was constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	hitpoints = HITPOINTS_ST;
	energy_points = ENERGY_POINTS_ST;
	attack_damage = ATTACK_DAMAGE_ST;
	std::cout << "ScavTrap " << this->getName() << " was constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "ScavTrap " << copy.getName() << " was copied" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " was destructed" << std::endl;
}

ScavTrap
	&ScavTrap::operator=(const ScavTrap &copy)
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
	ScavTrap::attack(std::string const &target)
{
	unsigned int	attack_damage = this->getAttackDamage();
	std::cout << "ScavTrap " << this->getName() << " attack " << target \
	<< ", causing " << attack_damage;
	if (attack_damage == 1)
		std::cout << " point of damage!" << std::endl;
	else
		std::cout << " points of damage!" << std::endl;
}

void
	ScavTrap::guardGate()
{
	std::cout << this->getName() << " has entered in Gate keeper mode" << std::endl;
}
