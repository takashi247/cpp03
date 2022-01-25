#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		explicit DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &other);
		virtual ~DiamondTrap();
		DiamondTrap			&operator=(const DiamondTrap &other);
		void				attack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				whoAmI();
		const std::string	&getName() const;
		void				setName(std::string const name);
	private:
		std::string					name;
		static const std::string	CLAP_NAME_SUFFIX;
};

#endif