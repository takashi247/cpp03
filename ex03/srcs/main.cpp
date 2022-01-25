#include "DiamondTrap.hpp"

int
	main()
{
	DiamondTrap	dt_1("dt_1");
	DiamondTrap	dt_2("dt_2");
	DiamondTrap	dt_3(dt_1);
	DiamondTrap	dt_4 = dt_2;

	dt_1.whoAmI();
	dt_2.whoAmI();
	dt_3.whoAmI();
	dt_4.whoAmI();
	dt_1.attack("dt_2");
	dt_2.takeDamage(dt_1.getAttackDamage());
	dt_4.attack("dt_2");
	dt_3.takeDamage(dt_4.getAttackDamage());
}
