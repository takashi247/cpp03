#include "ClapTrap.hpp"

int
	main()
{
	ClapTrap	first("first");
	ClapTrap	second("second");
	ClapTrap	third("third");

	first.attack("second");
	second.takeDamage(first.getAttackDamage());
	third.beRepaired(100);
	second.beRepaired(1);
}
