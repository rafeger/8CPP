#pragma once

#include <vector>

# define BOLDWHITE "\e[1;37m"
# define BOLDRED "\e[1;91m"
# define DEFAULT "\x1b[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define CYAN 	"\e[0;36m"

//chuis vrm debile javais commence a faire un int *_array alors quon peut utiliser un vector bref
//idiotidiotidiot
class Span
{
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int value);

        template <typename InputIterator>
        void addRange(InputIterator first, InputIterator last);

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

    private:
        unsigned int _maxSize;
        std::vector<int> _values;
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last)
{
	for (; first != last; ++first)
		addNumber(*first);
}
