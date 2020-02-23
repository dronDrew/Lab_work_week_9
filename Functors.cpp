#include "Functors.h"
int Functor_min::operator()(std::vector<int> &a) {
	int min = a[0];
	for (int var: a){
		if (var < min) {
			min = var;
		}
	}
	return min;
}
int Functor_max::operator()(std::vector<int> &a) {
	int max = a[0];
	for (int var : a) {
		if (var > max) {
			max = var;
		}
	}
	return max;
}
void Functor_sort_to_greatest::operator()(std::vector<int>& a) {
	std::sort(a.begin(), a.end());
}
void Functor_sort_to_less_value::operator()(std::vector<int>& a) {
	std::sort(a.begin(), a.end(),std::greater<int>());
}
void Functor_increment ::operator()(std::vector<int>& a, const int value_of_increment) {
	for (int &var : a) {
		var += value_of_increment;
	}
}
void Functor_decrement ::operator()(std::vector<int>& a, const int value_of_increment) {
	for (int& var : a) {
		var -= value_of_increment;
	}
}
void Functor_cut_size ::operator()(std::vector<int>& a,  int cut_on) {
	while (cut_on>0)
	{
		a.pop_back();
		cut_on--;
	}
}
void Functor_find_and_delete ::operator()(std::vector<int>& a, int key_value) {
	auto res = std::find(a.begin(), a.end(), key_value);
	while (res!=a.end())
	{
		a.erase(res);
		res = std::find(a.begin(), a.end(), key_value);
	}
	
}