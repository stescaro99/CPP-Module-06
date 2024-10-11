#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base default destructor" << std::endl;
}

Base *generate(void)
{
	int rnd = rand() % 3;
	
	switch (rnd)
	{
	case 0:
		std::cout << "A instance created" << std::endl;
		return new A();
	case 1:
		std::cout << "B instance created" << std::endl;
		return new B();
	default:
		std::cout << "C instance created" << std::endl;
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception & e)
	{
	}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception & e)
	{
	}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception & e)
	{
	}
}