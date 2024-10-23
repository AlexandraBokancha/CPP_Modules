#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <iostream>
# include <algorithm>

template <typename T>
int easyfind(const T& var1, int var2){
	typename T::const_iterator it = std::find(var1.begin(), var1.end(), var2);
	if (it != var1.end()){
		std::cout << "An occurence of " << var2 << " was found in your container at subscript "
			<< it - var1.begin() << std::endl;
		return 1;
	}
	std::cout << "No occurence was found" << std::endl;
	return 0;
}

#endif