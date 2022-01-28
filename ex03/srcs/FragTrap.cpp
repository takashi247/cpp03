#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap():
	ClapTrap()
{
	this->setHitpoints(HITPOINTS_FT);
	this->setEnergyPoints(ENERGY_POINTS_FT);
	this->setAttackDamage(ATTACK_DAMAGE_FT);
	if (this->getName() != "")
		std::cout << "FragTrap " << this->getName() << " was constructed" << std::endl;
	else
		std::cout << "FragTrap without a name was constructed" << std::endl;
}

FragTrap::FragTrap(const std::string name):
	ClapTrap(name)
{
	this->setHitpoints(HITPOINTS_FT);
	this->setEnergyPoints(ENERGY_POINTS_FT);
	this->setAttackDamage(ATTACK_DAMAGE_FT);
	std::cout << "FragTrap " << this->getName() << " was constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap " << other.getName() << " was copied" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " was destructed" << std::endl;
}

FragTrap
	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitpoints(other.getHitpoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

void
	FragTrap::attack(std::string const &target)
{
	unsigned int	attack_damage = this->getAttackDamage();
	std::cout << "FragTrap " << this->getName() << " attack " << target \
	<< ", causing " << attack_damage;
	if (attack_damage == 1)
		std::cout << " point of damage!" << std::endl;
	else
		std::cout << " points of damage!" << std::endl;
}

void
	FragTrap::takeDamage(unsigned int amount)
{
	std::string		my_name = this->getName();
	unsigned int	current_hp = this->getHitpoints();
	if (current_hp == 0)
		std::cout << "FragTrap " << my_name << " has already been destroyed..." << std::endl;
	else
	{
		std::cout << "FragTrap " << my_name << " get attacked, taking " \
		<< amount;
		if (amount == 1)
			std::cout << " point of damage!" << std::endl;
		else
			std::cout << " points of damage!" << std::endl;
		if (current_hp > amount)
			this->setHitpoints(current_hp - amount);
		else
		{
			std::cout << "FragTrap " << my_name << " was destroyed..." << std::endl;
			this->setHitpoints(0);
		}
	}
}

void
	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap " << this->getName() << " get repaired, recovering " \
	<< amount;
	if (amount == 1)
		std::cout << " point of hitpoints!" << std::endl;
	else
		std::cout << " points of hitpoints!" << std::endl;
	this->setHitpoints(this->getHitpoints() + amount);
}

void
	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " requested a positive high fives" << std::endl;
}

