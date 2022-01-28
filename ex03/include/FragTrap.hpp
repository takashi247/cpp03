#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		explicit FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap();
		FragTrap					&operator=(const FragTrap &other);
		void						attack(std::string const &target);
		void						takeDamage(unsigned int amount);
		void						beRepaired(unsigned int amount);
		void						highFivesGuys();
		static const unsigned int	HITPOINTS_FT = 100;
		static const unsigned int	ENERGY_POINTS_FT = 100;
		static const unsigned int	ATTACK_DAMAGE_FT = 30;
};

#endif

