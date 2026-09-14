#pragma once

#include <stack>
#include <deque>

# define BOLDWHITE "\e[1;37m"
# define BOLDRED "\e[1;91m"
# define DEFAULT "\x1b[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define CYAN 	"\e[0;36m"

// std::stack planque son container (une deque par defaut) mais nexpose pas
// de begin()/end() dessus, du coup impossible diterer normalement.
// Ici on herite juste de std::stack pour recuperer toute son interface
// (push, pop, top, size...) et on rajoute des iterators qui viennent
// taper direct dans le membre protected "c" (le container interne).
// Container est un 2eme template param, comme le vrai std::stack, pour
// pouvoir backer la MutantStack avec autre chose quune deque (vector...).
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator       iterator;
		typedef typename Container::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"
