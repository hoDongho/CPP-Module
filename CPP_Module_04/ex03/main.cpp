#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

		std::cout << std::endl;
		system("leaks -quiet a.out");
	}
	std::cout << "-----------------------------------------" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource;
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		ICharacter* me = new Character("Player1");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		me->unequip(0);
		me->unequip(1);
		me->unequip(2);

		Ice* a = new Ice();
		std::cout << a << std::endl;
		a = 0;
		std::cout << a << std::endl;

		int *b = (int*)malloc(sizeof(int));
		std::cout << b << std::endl;
		b = 0;
		std::cout << b << std::endl;

		int* c = new int();
		std::cout << c << std::endl;
		c = 0;
		std::cout << c << std::endl;

		delete bob;
		delete me;
		delete src;

		std::cout << std::endl;
		system("leaks -quiet a.out");
	}
	return 0;
}
