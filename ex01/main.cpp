#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <exception>

int main()
{
	std::cout << BOLDWHITE<< "---------- Subject test ----------" << DEFAULT <<std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	std::cout << BOLDWHITE<< std::endl << "---------- addNumber: container full ----------" << DEFAULT<< std::endl;
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try
		{
			sp.addNumber(3);
		}
		catch (const std::exception &e)
		{
			std::cout << BOLDRED << e.what() << DEFAULT << std::endl;
		}
	}

	std::cout << BOLDWHITE<< std::endl << "---------- span queries with fewer than 2 numbers ----------" << DEFAULT<< std::endl;
	{
		Span empty(5);
		try
		{
			empty.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cout <<BOLDRED<< e.what() << DEFAULT <<std::endl;
		}
		empty.addNumber(42);
		try
		{
			empty.longestSpan();
		}
		catch (const std::exception &e)
		{
			std::cout <<BOLDRED<< e.what() <<DEFAULT<< std::endl;
		}
	}

	std::cout << BOLDWHITE<< std::endl << "---------- addRange from a std::vector<int> ----------" << DEFAULT<< std::endl;
	{
		std::vector<int> src;
		for (int i = 0; i < 100; i++)
			src.push_back(i * 2);
		Span sp(src.size());
		sp.addRange(src.begin(), src.end());
		std::cout << "shortestSpan: " << sp.shortestSpan()  << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	std::cout << BOLDWHITE<< std::endl << "---------- addRange from a std::list<int> (negative values) ----------" << DEFAULT<< std::endl;
	{
		std::list<int> src;
		for (int i = 0; i < 50; i++)
			src.push_back(-i);
		Span sp(src.size());
		sp.addRange(src.begin(), src.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	std::cout << BOLDWHITE<< std::endl << "---------- addRange bigger than remaining space ----------" << DEFAULT<< std::endl;
	{
		Span sp(3);
		int arr[5] = {1, 2, 3, 4, 5};
		try
		{
			sp.addRange(arr, arr + 5);
			std::cout << "ERROR: exception not thrown" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout <<BOLDRED<< e.what() << std::endl;
		}
	}

	std::cout << BOLDWHITE<< std::endl << "---------- copy constructor / operator= independence ----------" << DEFAULT<< std::endl;
	{
		Span original(4);
		original.addNumber(1);
		original.addNumber(2);
		original.addNumber(3);

		Span copyCtor(original);
		Span copyAssign(1);
		copyAssign = original;

		original.addNumber(100);

		std::cout << "original   longestSpan " << original.longestSpan() << std::endl;
		std::cout << "copyCtor   longestSpan" << copyCtor.longestSpan() << std::endl;
		std::cout << "copyAssign longestSpan " << copyAssign.longestSpan() << std::endl;
	}

	std::cout << BOLDWHITE<< std::endl << "---------- big test: 10 000 numbers ----------" << DEFAULT<< std::endl;
	{
		std::list<int> src;
		for (int i = 0; i < 999999; i++)
			src.push_back(-i);
		Span sp(src.size());
		sp.addRange(src.begin(), src.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	return (0);
}
