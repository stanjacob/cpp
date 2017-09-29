#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <typeinfo>

template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={})
{
	first = std::lower_bound(first, last, value, comp);
	return first != last && value == *first ? first : last;
}

int main() 
{
	std::vector<int> someNumber = {1, 3, 4, 24, 64, 234};

	auto lower = std::lower_bound(someNumber.begin(), someNumber.end(), 4);
	auto upper = std::upper_bound(someNumber.begin(), someNumber.end(), 69);

	std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	auto it = binary_find(someNumber.cbegin(), someNumber.cend(), 64);

	if (it != someNumber.cend())
		std::cout << *it << " found at index " << std::distance(someNumber.cbegin(), it) << std::endl;
	
	return 0;
}
