#pragma once
#include"dependies.h"
class Functor_min
{
public:
	int operator ()(std::vector<int> &a);
};
class Functor_max
{
public:
	int operator ()(std::vector<int> &a);
};
class Functor_sort_to_greatest {
public:
	void operator ()(std::vector<int>& a);

};
class Functor_sort_to_less_value {
public:
	void operator ()(std::vector<int>& a);

};
class Functor_increment {
public:
	void operator ()(std::vector<int>& a, const int value_of_increment);

};
class Functor_decrement {
public:
	void operator ()(std::vector<int>& a, const int value_of_increment);

};
class Functor_cut_size {
public:
	void operator ()(std::vector<int>& a, int cut_on);

};
class Functor_find_and_delete {
public:
	void operator ()(std::vector<int>& a, int key_value);

};