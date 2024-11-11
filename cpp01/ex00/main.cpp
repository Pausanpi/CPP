#include "Zombie.hpp"

int	main(void){
	Zombie z("Brayan");
	Zombie*	newZ;

	z.announce();
	newZ = newZombie("Zara");
	newZ->announce();
	randomChump("Jony");
	delete newZ;
	return 0;
}