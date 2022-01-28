#include "DiamondTrap.hpp"
#include <iostream>

int
	main()
{
	DiamondTrap	dt_1("dt_1");
	DiamondTrap	dt_2(dt_1);
	DiamondTrap	dt_3;
	ClapTrap	*ct_1 = new DiamondTrap("ct_1");
	FragTrap	*ft_1 = new DiamondTrap("ft_1");
	ScavTrap	*st_1 = new DiamondTrap("st_1");

	std::cout << std::endl;
	dt_3 = dt_2;
	dt_1.whoAmI();
	dt_2.whoAmI();
	dt_3.whoAmI();
	dt_1.attack("dt_2");
	dt_2.takeDamage(dt_1.getAttackDamage());
	dt_3.attack("dt_2");
	dt_2.takeDamage(dt_3.getAttackDamage());
	ct_1->attack("ft_1");
	ft_1->takeDamage(ct_1->getAttackDamage());
	ft_1->highFivesGuys();
	st_1->guardGate();
	std::cout << std::endl;
	delete ct_1;
	delete ft_1;
	delete st_1;
}
