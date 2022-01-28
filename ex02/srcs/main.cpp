#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int
	main()
{
	ClapTrap	c1("Clap First");
	ClapTrap	*c2 = new FragTrap("Clap Second");
	ScavTrap	s1("Scav First");
	ScavTrap	s2("Scav Second");
	FragTrap	f1("Frag First");
	FragTrap	f2;

	std::cout << std::endl;
	f2 = f1;
	s1.attack("Clap First");
	c1.takeDamage(s1.getAttackDamage());
	c1.beRepaired(50);
	c2->beRepaired(1);
	c2->attack("Clap First");
	c1.takeDamage(c2->getAttackDamage());
	s2.attack("Scav First");
	s1.takeDamage(s2.getAttackDamage());
	s1.beRepaired(10);
	s1.guardGate();
	s2.guardGate();
	f1.attack("Scav First");
	s1.takeDamage(f1.getAttackDamage());
	f2.attack("Scav First");
	s1.takeDamage(f2.getAttackDamage());
	s1.attack("Frag First");
	f1.takeDamage(s1.getAttackDamage());
	f1.highFivesGuys();
	f2.highFivesGuys();
	std::cout << std::endl;
	delete c2;
}

