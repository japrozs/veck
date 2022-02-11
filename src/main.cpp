#include <iostream>
#include <veck.hpp>

int main()
{
	Vector v;
	for (int i = 0; i < 11; i++)
	{
		v.push(i);
	}

	Vector w;
	w.push(4);
	w = v;
	std::cout << w << std::endl;
	w.erase(4);
	w.erase(7);
	std::cout << w << std::endl;

	return 0;
}
