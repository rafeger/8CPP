#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <exception>

int main()
{
	std::cout << "---------- Subject test ----------" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 2)" << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << " (expected 14)" << std::endl;
	}

	std::cout << std::endl << "---------- addNumber: container full ----------" << std::endl;
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try
		{
			sp.addNumber(3);
			std::cout << "ERROR: exception not thrown" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "---------- span queries with fewer than 2 numbers ----------" << std::endl;
	{
		Span empty(5);
		try
		{
			empty.shortestSpan();
			std::cout << "ERROR: exception not thrown" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught as expected (0 numbers, shortestSpan): " << e.what() << std::endl;
		}
		empty.addNumber(42);
		try
		{
			empty.longestSpan();
			std::cout << "ERROR: exception not thrown" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught as expected (1 number, longestSpan): " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << "---------- addRange from a std::vector<int> ----------" << std::endl;
	{
		std::vector<int> src;
		for (int i = 0; i < 100; i++)
			src.push_back(i * 2);
		Span sp(src.size());
		sp.addRange(src.begin(), src.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 2)" << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << " (expected 198)" << std::endl;
	}

	std::cout << std::endl << "---------- addRange from a std::list<int> (negative values) ----------" << std::endl;
	{
		std::list<int> src;
		for (int i = 0; i < 50; i++)
			src.push_back(-i);
		Span sp(src.size());
		sp.addRange(src.begin(), src.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 1)" << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << " (expected 49)" << std::endl;
	}

	std::cout << std::endl << "---------- addRange bigger than remaining space ----------" << std::endl;
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
			std::cout << "Caught as expected: " << e.what() << std::endl;
			std::cout << "(note: the first 3 values were already inserted before the throw, addRange is not atomic)" << std::endl;
		}
	}

	std::cout << std::endl << "---------- copy constructor / operator= independence ----------" << std::endl;
	{
		Span original(4);
		original.addNumber(1);
		original.addNumber(2);
		original.addNumber(3);

		Span copyCtor(original);
		Span copyAssign(1);
		copyAssign = original;

		original.addNumber(100);

		std::cout << "original   longestSpan (should reflect the 4th number): " << original.longestSpan() << std::endl;
		std::cout << "copyCtor   longestSpan (should NOT reflect it):         " << copyCtor.longestSpan() << std::endl;
		std::cout << "copyAssign longestSpan (should NOT reflect it):         " << copyAssign.longestSpan() << std::endl;
	}

	std::cout << std::endl << "---------- big test: 10 000 numbers ----------" << std::endl;
	{
		const unsigned int N = 10000;
		Span big(N);
		for (unsigned int i = 0; i < N; i++)
			big.addNumber(i);
		std::cout << "shortestSpan: " << big.shortestSpan() << " (expected 1)" << std::endl;
		std::cout << "longestSpan:  " << big.longestSpan() << " (expected " << N - 1 << ")" << std::endl;
	}

	return (0);
}
