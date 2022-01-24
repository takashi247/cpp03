#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual ~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &other);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		guardGate();
	private:
		static const unsigned int	HITPOINTS_ST = 100;
		static const unsigned int	ENERGY_POINTS_ST = 50;
		static const unsigned int	ATTACK_DAMAGE_ST = 20;
};

#endif