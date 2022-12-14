#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie( std::string _name );
		~Zombie();
		const std::string	&getName();
		void				setName(std::string _name);
		void				announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
