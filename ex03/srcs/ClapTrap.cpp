#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():
	name(""),
	hitpoints(HITPOINTS_CT),
	energy_points(ENERGY_POINTS_CT),
	attack_damage(ATTACK_DAMAGE_CT)
{
	std::cout << "ClapTrap without a name was constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string name):
	name(name),
	hitpoints(HITPOINTS_CT),
	energy_points(ENERGY_POINTS_CT),
	attack_damage(ATTACK_DAMAGE_CT)
{
	std::cout << "ClapTrap " << name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap " << copy.getName() << " was copied" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << " was destructed" << std::endl;
}

ClapTrap
	&ClapTrap::operator=(const ClapTrap &copy)
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

const std::string
	&ClapTrap::getName() const
{
	return (this->name);
}

void
	ClapTrap::setName(std::string const new_name)
{
	this->name = new_name;
}

const unsigned int
	&ClapTrap::getHitpoints() const
{
	return (this->hitpoints);
}

void
	ClapTrap::setHitpoints(unsigned int value)
{
	this->hitpoints = value;
}

const unsigned int
	&ClapTrap::getEnergyPoints() const
{
	return (this->energy_points);
}

void
	ClapTrap::setEnergyPoints(unsigned int value)
{
	this->energy_points = value;
}

const unsigned int
	&ClapTrap::getAttackDamage() const
{
	return (this->attack_damage);
}

void
	ClapTrap::setAttackDamage(unsigned int value)
{
	this->attack_damage = value;
}

void
	ClapTrap::attack(std::string const &target)
{
	unsigned int	attack_damage_value = this->getAttackDamage();
	std::cout << "ClapTrap " << this->getName() << " attack " << target \
	<< ", causing " << attack_damage_value;
	if (attack_damage_value == 1)
		std::cout << " point of damage!" << std::endl;
	else
		std::cout << " points of damage!" << std::endl;
}

void
	ClapTrap::takeDamage(unsigned int amount)
{
	std::string		my_name = this->getName();
	unsigned int	current_hp = this->getHitpoints();
	if (current_hp == 0)
		std::cout << "ClapTrap " << my_name << " has already been destroyed..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << my_name << " get attacked, taking " \
		<< amount;
		if (amount == 1)
			std::cout << " point of damage!" << std::endl;
		else
			std::cout << " points of damage!" << std::endl;
		if (current_hp > amount)
			this->setHitpoints(current_hp - amount);
		else
		{
			std::cout << "ClapTrap " << my_name << " was destroyed..." << std::endl;
			this->setHitpoints(0);
		}
	}
}

void
	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << " get repaired, recovering " \
	<< amount;
	if (amount == 1)
		std::cout << " point of hitpoints!" << std::endl;
	else
		std::cout << " points of hitpoints!" << std::endl;
	this->setHitpoints(this->getHitpoints() + amount);
}
