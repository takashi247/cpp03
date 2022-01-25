#include "ClapTrap.hpp"

int
	main()
{
	ClapTrap	first("first");
	ClapTrap	second("second");
	ClapTrap	third("third");
	ClapTrap	third_cpy(third);

	first.attack("second");
	second.takeDamage(first.getAttackDamage());
	third.beRepaired(100);
	second.beRepaired(1);
	third_cpy.attack("first");
	first.takeDamage(third_cpy.getAttackDamage());
}
