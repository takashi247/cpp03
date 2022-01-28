#include "ClapTrap.hpp"
#include <iostream>

int
	main()
{
	ClapTrap	first("first");
	ClapTrap	second("second");
	ClapTrap	third("third");
	ClapTrap	third_cpy(third);
    ClapTrap    fourth;

    std::cout << std::endl;
    fourth = third;
	first.attack("second");
	second.takeDamage(first.getAttackDamage());
	third.beRepaired(100);
	second.beRepaired(1);
	third_cpy.attack("first");
	first.takeDamage(third_cpy.getAttackDamage());
    fourth.attack("third");
    third.takeDamage(fourth.getAttackDamage());
    std::cout << std::endl;
}

