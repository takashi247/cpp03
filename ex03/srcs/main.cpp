#include "DiamondTrap.hpp"
#include <iostream>

void
	show_status(const ClapTrap &ct)
{
	std::cout << std::endl;
	std::cout << "---Current status of " << ct.getName() << "---" << std::endl;
	std::cout << "Hitpoints: " << ct.getHitpoints() << std::endl;
	std::cout << "Energy points: " << ct.getEnergyPoints() << std::endl;
	std::cout << "Attack damages: " << ct.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

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
	std::cout << std::endl;
	dt_1.attack("dt_2");
	dt_2.takeDamage(dt_1.getAttackDamage());
	show_status(dt_2);
	dt_3.attack("dt_2");
	dt_2.takeDamage(dt_3.getAttackDamage());
	show_status(dt_2);
	ct_1->attack("ft_1");
	ft_1->takeDamage(ct_1->getAttackDamage());
	show_status(*ft_1);
	ft_1->highFivesGuys();
	st_1->guardGate();
	dt_1.guardGate();
	dt_1.highFivesGuys();
	std::cout << std::endl;
	delete ct_1;
	delete ft_1;
	delete st_1;
}
