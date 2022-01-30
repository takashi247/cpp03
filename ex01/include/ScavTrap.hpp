#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		explicit ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &copy);
		virtual ~ScavTrap();
		ScavTrap					&operator=(const ScavTrap &copy);
		void						attack(std::string const &target);
		void						guardGate();
		static const unsigned int	HITPOINTS_ST = 100;
		static const unsigned int	ENERGY_POINTS_ST = 50;
		static const unsigned int	ATTACK_DAMAGE_ST = 20;
};

#endif
