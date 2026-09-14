#pragma once

# define BOLDWHITE "\e[1;37m"
# define BOLDRED "\e[1;91m"
# define DEFAULT "\x1b[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define CYAN 	"\e[0;36m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		//on vole les 
	typedef typename std::deque<T>::iterator       iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	MutantStack();
	MutantStack(const MutantStack& other) : std::stack<T>(other);
	MutantStack &operator=(const MutantStack& other);
	~MutantStack();
	{
		std::stack<T>::operator=(other);
		return *this;
	}


	iterator begin() { return this->c.begin(); }
	iterator end()   { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end()   const { return this->c.end(); }
};