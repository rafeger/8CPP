#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>
#include <vector>

int main()
{
	std::cout << BOLDWHITE << "---------- Subject test ----------" << DEFAULT << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
		std::cout << "std::stack copy size: " << s.size() << std::endl;
	}

	std::cout << BOLDWHITE << std::endl << "---------- meme test avec un std::list<int> (doit donner le meme resultat) ----------" << DEFAULT << std::endl;
	{
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << BOLDWHITE << std::endl << "---------- meme test avec un std::vector<int> (doit donner le meme resultat) ----------" << DEFAULT << std::endl;
	{
		std::vector<int> mvec;

		mvec.push_back(5);
		mvec.push_back(17);
		std::cout << mvec.back() << std::endl;
		mvec.pop_back();
		std::cout << mvec.size() << std::endl;
		mvec.push_back(3);
		mvec.push_back(5);
		mvec.push_back(737);
		mvec.push_back(0);

		std::vector<int>::iterator it = mvec.begin();
		std::vector<int>::iterator ite = mvec.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << BOLDWHITE << std::endl << "---------- MutantStack rempli via addRange-like loop puis compare a un vector ----------" << DEFAULT << std::endl;
	{
		std::vector<int> src;
		for (int i = 0; i < 20; i++)
			src.push_back(i * i);

		MutantStack<int> mstack;
		for (std::vector<int>::iterator it = src.begin(); it != src.end(); ++it)
			mstack.push(*it);

		std::vector<int> fromStack(mstack.begin(), mstack.end());
		std::cout << std::boolalpha << "same content as src: " << (fromStack == src) << std::endl;
	}

	std::cout << BOLDWHITE << std::endl << "---------- MutantStack<int, std::vector<int>> (container au choix) ----------" << DEFAULT << std::endl;
	{
		MutantStack<int, std::vector<int> > vstack;

		vstack.push(5);
		vstack.push(17);
		std::cout << vstack.top() << std::endl;
		vstack.pop();
		std::cout << vstack.size() << std::endl;
		vstack.push(3);
		vstack.push(5);
		vstack.push(737);
		vstack.push(0);

		MutantStack<int, std::vector<int> >::iterator it = vstack.begin();
		MutantStack<int, std::vector<int> >::iterator ite = vstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int, std::vector<int> > s(vstack);
		std::cout << "std::stack<vector> copy size: " << s.size() << std::endl;
	}

	std::cout << BOLDWHITE << std::endl << "---------- const_iterator ----------" << DEFAULT << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);

		const MutantStack<int> cstack(mstack);
		for (MutantStack<int>::const_iterator it = cstack.begin(); it != cstack.end(); ++it)
			std::cout << *it << std::endl;
	}

	std::cout << BOLDWHITE << std::endl << "---------- copy constructor / operator= independence ----------" << DEFAULT << std::endl;
	{
		MutantStack<int> original;
		original.push(1);
		original.push(2);

		MutantStack<int> copyCtor(original);
		MutantStack<int> copyAssign;
		copyAssign = original;

		original.push(100);

		std::cout << "original   size: " << original.size() << std::endl;
		std::cout << "copyCtor   size: " << copyCtor.size() << std::endl;
		std::cout << "copyAssign size: " << copyAssign.size() << std::endl;
	}

	std::cout << BOLDWHITE << std::endl << "---------- stack encore utilisable normalement (empty/top) ----------" << DEFAULT << std::endl;
	{
		MutantStack<int> mstack;
		std::cout << std::boolalpha << "is empty: " << mstack.empty() << std::endl;
		mstack.push(42);
		std::cout << std::boolalpha << "is empty: " << mstack.empty() << std::endl;
		std::cout << "top: " << mstack.top() << std::endl;
	}

	return (0);
}
