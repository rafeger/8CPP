#include "Span.hpp"
#include <algorithm>
#include <stdexcept>


//mm pas besoin dinitialiser lautre noeuil parceque enft 
Span::Span() : _maxSize(0)
{
}

//prealloue la memoire necessaire pour eviterles reallocs excessif
//si je fais plein de push_back comme un neuil
//permet de ne pas avoir besoin dun int pour track cmb de ints jai ajoute
//vu quon remplit pas tous le reste du vecteur avec des 0 quoi !
Span::Span(unsigned int N) : _maxSize(N)
{
	_values.reserve(N);
}

Span::Span(const Span &src) : _maxSize(src._maxSize), _values(src._values)
{
}

//lowkey un peu inutile jcroives parceque aec un vector le test
// this != &other est plus necessaire, il gere les v = v sans crash normalement
//vu que les vecteurs cest goatesque
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_values = other._values;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int value)
{
	if (_values.size() >= _maxSize)
		throw std::length_error("Span::addNumber: container is full");
	_values.push_back(value);
}

unsigned int	Span::shortestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error("Span::shortestSpan: not enough numbers stored");

	std::vector<int> sorted(_values);
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = sorted[1] - sorted[0];
	for (std::vector<int>::size_type i = 2; i < sorted.size(); i++)
	{
		unsigned int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int	Span::longestSpan() const
{
	if (_values.size() < 2)
		throw std::logic_error("Span::longestSpan: not enough numbers stored");

	int minVal = *std::min_element(_values.begin(), _values.end());
	int maxVal = *std::max_element(_values.begin(), _values.end());
	return (maxVal - minVal);
}


