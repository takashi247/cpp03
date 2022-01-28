#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap():
	ClapTrap()
{
	this->setHitpoints(HITPOINTS_ST);
	this->setEnergyPoints(ENERGY_POINTS_ST);
	this->setAttackDamage(ATTACK_DAMAGE_ST);
	if (this->getName() != "")
		std::cout << "ScavTrap " << this->getName() << " was constructed" << std::endl;
	else
		std::cout << "ScavTrap without a name was constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string name):
	ClapTrap(name)
{
	this->setHitpoints(HITPOINTS_ST);
	this->setEnergyPoints(ENERGY_POINTS_ST);
	this->setAttackDamage(ATTACK_DAMAGE_ST);
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
		this->setName(copy.getName());
		this->setHitpoints(copy.getHitpoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAttackDamage(copy.getAttackDamage());
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
	ScavTrap::takeDamage(unsigned int amount)
{
	std::string		my_name = this->getName();
	unsigned int	current_hp = this->getHitpoints();
	if (current_hp == 0)
		std::cout << "ScavTrap " << my_name << " has already been destroyed..." << std::endl;
	else
	{
		std::cout << "ScavTrap " << my_name << " get attacked, taking " \
		<< amount;
		if (amount == 1)
			std::cout << " point of damage!" << std::endl;
		else
			std::cout << " points of damage!" << std::endl;
		if (current_hp > amount)
			this->setHitpoints(current_hp - amount);
		else
		{
			std::cout << "ScavTrap " << my_name << " was destroyed..." << std::endl;
			this->setHitpoints(0);
		}
	}
}

void
	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << this->getName() << " get repaired, recovering " \
	<< amount;
	if (amount == 1)
		std::cout << " point of hitpoints!" << std::endl;
	else
		std::cout << " points of hitpoints!" << std::endl;
	this->setHitpoints(this->getHitpoints() + amount);
}

void
	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << std::endl;
}
