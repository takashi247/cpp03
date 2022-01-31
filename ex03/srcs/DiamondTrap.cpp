#include "DiamondTrap.hpp"
#include <iostream>

const std::string	DiamondTrap::CLAP_NAME_SUFFIX = "_clap_name";

DiamondTrap::DiamondTrap():
	ClapTrap(), FragTrap(), ScavTrap(), name("")
{
	hitpoints = FragTrap::HITPOINTS_FT;
	energy_points = ScavTrap::ENERGY_POINTS_ST;
	attack_damage = FragTrap::ATTACK_DAMAGE_FT;
	std::cout << "DiamondTrap without a name was constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name):
	ClapTrap(name + CLAP_NAME_SUFFIX), FragTrap(), ScavTrap(), name(name)
{
	hitpoints = FragTrap::HITPOINTS_FT;
	energy_points = ScavTrap::ENERGY_POINTS_ST;
	attack_damage = FragTrap::ATTACK_DAMAGE_FT;
	std::cout << "DiamondTrap " << this->DiamondTrap::getName() << " was constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap " << copy.DiamondTrap::getName() << " was copied" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->DiamondTrap::getName() << " was destructed" << std::endl;
}

DiamondTrap
	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.DiamondTrap::getName();
		this->ClapTrap::name = copy.ClapTrap::getName();
		hitpoints = copy.getHitpoints();
		energy_points = copy.getEnergyPoints();
		attack_damage = copy.getAttackDamage();
	}
	return (*this);
}

void
	DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void
	DiamondTrap::whoAmI()
{
	std::cout << "My name is DiamondTrap " << this->DiamondTrap::getName() << \
	" and my ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}

const std::string
	&DiamondTrap::getName() const
{
	return (this->name);
}

void
	DiamondTrap::setName(std::string const new_name)
{
	this->name = new_name;
}
