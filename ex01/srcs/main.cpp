#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int
	main()
{
	ClapTrap	c1("Clap First");
	ClapTrap	c2("Clap Second");
	ScavTrap	s1("Scav First");
	ScavTrap	s2("Scav Second");

	s1.attack("Clap First");
	c1.takeDamage(s1.getAttackDamage());
	c1.beRepaired(50);
	c2.beRepaired(1);
	s2.attack("Scav First");
	s1.takeDamage(s2.getAttackDamage());
	s1.beRepaired(10);
	s1.guardGate();
	s2.guardGate();
}
