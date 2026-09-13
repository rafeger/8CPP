#pragma once

#include <algorithm>
#include <exception>
#include <iostream>

# define BOLDWHITE "\e[1;37m"
# define BOLDRED "\e[1;91m"
# define DEFAULT "\x1b[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define CYAN 	"\e[0;36m"

// en gros ce template pour etre appele necessite
// une classe avec un type const_iterator (donc capable dappeler operator++ operator-- etc)
// donc par exemple si je fais typedef int const_iterator ca ne compile pas
// mais si je fais typedef int* const_iterator la oui !

// et deux methodes dans la classe qui sont begin() et end() !
// si la classe appelant cette methode de template remplie toutes les conditions alors ca compile !
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator res;
	res = std::find(container.begin(), container.end(), value);
	if (res != container.end())
		return res;
	throw(std::out_of_range("value not found in container sry mate !"));
}
