#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int
	main()
{
	ClapTrap	c1("Clap First");
	ClapTrap	*c2 = new ScavTrap("Clap Second"); // initiate ScavTrap as ClapTrap
	ScavTrap	s1("Scav First");
	ScavTrap	s2(s1);
	ScavTrap	s3;
	s3 = s2;

	std::cout << std::endl;
	s1.attack("Clap First");
	c1.takeDamage(s1.getAttackDamage());
	c1.beRepaired(50);
	c2->beRepaired(1);
	c2->attack("Clap First");
	c1.takeDamage(c2->getAttackDamage());
	s2.attack("Scav First");
	s1.takeDamage(s2.getAttackDamage());
	s1.beRepaired(10);
	// c2->guardGate(); // c2 can't use guardGate() as it's constructed as ClapTrap
	s1.guardGate();
	s2.guardGate();
	s3.guardGate();
	std::cout << std::endl;
	delete c2; // test if destructor of ScavTrap is called properly
}
