#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();
		ClapTrap 			&operator=(const ClapTrap &other);
		const std::string	&getName() const;
		void				setName(std::string const name);
		const unsigned int	&getHitpoints() const;
		void				setHitpoints(unsigned int value);
		const unsigned int	&getEnergyPoints() const;
		void				setEnergyPoints(unsigned int value);
		const unsigned int	&getAttackDamage() const;
		void				setAttackDamage(unsigned int value);
		void				attack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
	private:
		std::string		name;
		unsigned int	hitpoints;
		unsigned int	energy_points;
		unsigned int	attack_damage;
};

#endif