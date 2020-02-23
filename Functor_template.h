#pragma once
#include "dependies.h"
template<class T>
class Functor_min
{
public:
	T operator ()(std::vector<T>& a);
};
template<class T>
class Functor_max
{
public:
	T operator ()(std::vector<T>& a);
};
template<class T>
class Functor_sort_to_greatest {
public:
	void operator ()(std::vector<T>& a);

};
template<class T>
class Functor_sort_to_less_value {
public:
	void operator ()(std::vector<T>& a);

};
template<class T>
class Functor_increment {
public:
	void operator ()(std::vector<T>& a, const T value_of_increment);

};
template<class T>
class Functor_decrement {
public:
	void operator ()(std::vector<T>& a, const T value_of_increment);

};
template<class T>
class Functor_cut_size {
public:
	void operator ()(std::vector<T>& a, T cut_on);

};
template<class T>
class Functor_find_and_delete {
public:
	void operator ()(std::vector<T>& a, T key_value);
};
template<class T>
T Functor_min<T>::operator()(std::vector<T>& a) {
	T min = a[0];
	for (T var : a) {
		if (var < min) {
			min = var;
		}
	}
	return min;
}
template<class T>
T Functor_max<T>::operator()(std::vector<T>& a) {
	T max = a[0];
	for (T var : a) {
		if (var > max) {
			max = var;
		}
	}
	return max;
}
template<class T>
void Functor_sort_to_greatest<T>::operator()(std::vector<T>& a) {
	std::sort(a.begin(), a.end());
}
template<class T>
void Functor_sort_to_less_value<T>::operator()(std::vector<T>& a) {
	std::sort(a.begin(), a.end(), std::greater<int>());
}
template<class T>
void Functor_increment<T>::operator()(std::vector<T>& a, const T value_of_increment) {
	for (int& var : a) {
		var += value_of_increment;
	}
}
template<class T>
void Functor_decrement<T> ::operator()(std::vector<T>& a, const T value_of_increment) {
	for (int& var : a) {
		var -= value_of_increment;
	}
}
template<class T>
void Functor_cut_size<T>::operator()(std::vector<T>& a, T cut_on) {
	while (cut_on > 0)
	{
		a.pop_back();
		cut_on--;
	}
}
template<class T>
void Functor_find_and_delete<T> ::operator()(std::vector<T>& a, T key_value) {
	auto res = std::find(a.begin(), a.end(), key_value);
	while (res != a.end())
	{
		a.erase(res);
		res = std::find(a.begin(), a.end(), key_value);
	}

}