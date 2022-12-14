#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << getType() << " is born!" << std::endl;
}

Cat::Cat(Cat& copy)
{
	*this = copy;
	std::cout << getType() << " is cloned!" << std::endl;
}

Cat& Cat::operator=(Cat& copy)
{
	if (this != &copy)
		type = copy.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << getType() << " is dead!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

