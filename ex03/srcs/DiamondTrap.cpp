#include "DiamondTrap.hpp"
#include <iostream>

const std::string	DiamondTrap::CLAP_NAME_SUFFIX = "_clap_name";

DiamondTrap::DiamondTrap():
	ClapTrap(), FragTrap(), ScavTrap(), name("")
{
	this->ClapTrap::setName(this->getName() + CLAP_NAME_SUFFIX);
	this->setHitpoints(FragTrap::HITPOINTS_FT);
	this->setEnergyPoints(ScavTrap::ENERGY_POINTS_ST);
	this->ScavTrap::setAttackDamage(FragTrap::ATTACK_DAMAGE_FT);
	std::cout << "DiamondTrap without a name was constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name):
	ClapTrap(name + CLAP_NAME_SUFFIX), FragTrap(), ScavTrap(), name(name)
{
	this->setHitpoints(FragTrap::HITPOINTS_FT);
	this->setEnergyPoints(ScavTrap::ENERGY_POINTS_ST);
	this->ScavTrap::setAttackDamage(FragTrap::ATTACK_DAMAGE_FT);
	std::cout << "DiamondTrap " << this->getName() << " was constructed" << std::endl;
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
		this->DiamondTrap::setName(copy.DiamondTrap::getName());
		this->ClapTrap::setName(copy.ClapTrap::getName());
		this->setHitpoints(copy.getHitpoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAttackDamage(copy.getAttackDamage());
	}
	return (*this);
}

void
	DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void
	DiamondTrap::takeDamage(unsigned int amount)
{
	std::string		my_name = this->getName();
	unsigned int	current_hp = this->getHitpoints();
	if (current_hp == 0)
		std::cout << "DiamondTrap " << my_name << " has already been destroyed..." << std::endl;
	else
	{
		std::cout << "DiamondTrap " << my_name << " get attacked, taking " \
		<< amount;
		if (amount == 1)
			std::cout << " point of damage!" << std::endl;
		else
			std::cout << " points of damage!" << std::endl;
		if (current_hp > amount)
			this->setHitpoints(current_hp - amount);
		else
		{
			std::cout << "DiamondTrap " << my_name << " was destroyed..." << std::endl;
			this->setHitpoints(0);
		}
	}
}

void
	DiamondTrap::beRepaired(unsigned int amount)
{
	std::cout << "DiamondTrap " << this->getName() << " get repaired, recovering " \
	<< amount;
	if (amount == 1)
		std::cout << " point of hitpoints!" << std::endl;
	else
		std::cout << " points of hitpoints!" << std::endl;
	this->setHitpoints(this->getHitpoints() + amount);
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
