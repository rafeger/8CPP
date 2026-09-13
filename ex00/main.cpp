#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

//on va tester avec les containers suivant
//vector list et deque. pas map et set parceque c des containers assiocatifs
//cgt
int	main()
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for (int i = 0; i < 10; i++)
		d.push_back(i);
	for (int i = 0; i < 10; i++)
		l.push_back(i);

	try
	{
		std::vector<int>::const_iterator uno = easyfind(v, 5);
		std::cout << "Value passed found at index : " << std::distance(std::vector<int>::const_iterator (v.begin()), uno) << " in vector " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator uno = easyfind(v, 5);
		std::cout << "Value passed found at index : " << std::distance(std::vector<int>::const_iterator (v.begin()), uno) << " in deque " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator uno = easyfind(v, 5);
		std::cout << "Value passed found at index : " << std::distance(std::vector<int>::const_iterator (v.begin()), uno) << " in list " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << CYAN << "---------- exceptions testxs ----------" << DEFAULT << std::endl << std::endl;
	try
	{
		std::vector<int>::const_iterator uno = easyfind(v, 14);
		std::cout << "Value passed found at index : " << std::distance(std::vector<int>::const_iterator (v.begin()), uno) << " in vector " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator uno = easyfind(v, -2);
		std::cout << "Value passed found at index : " << std::distance(std::vector<int>::const_iterator (v.begin()), uno) << " in deque " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator uno = easyfind(v, 1332131);
		std::cout << "Value passed found at index : " << std::distance(std::vector<int>::const_iterator (v.begin()), uno) << " in list " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}