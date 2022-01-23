#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		virtual ~FragTrap();
		FragTrap	&operator=(const FragTrap &other);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		highFivesGuys();
	private:
		static const unsigned int	HITPOINTS_FT = 100;
		static const unsigned int	ENERGY_POINTS_FT = 100;
		static const unsigned int	ATTACK_DAMAGE_FT = 30;
};

#endif