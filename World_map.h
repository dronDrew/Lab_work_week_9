#pragma once
#include "dependies.h"
class World_map
{
	std::map<std::string, std::list<std::string>> word;
public:
	void Menu();
	void Action_void_res(std::function<void()>a);
};

/*class Functor_load {
public:
	void operator()(std::map<std::string, std::list<std::string>> &word);
};
class Functor_save {
public:
	void operator()(std::map<std::string, std::list<std::string>>& word);
};
class Functor_search {
public:
	bool operator()(std::map<std::string, std::list<std::string>>& word,std::string country,std::string city);
};
class Functor_edit_city_name {
public:
	bool operator()(std::map<std::string, std::list<std::string>>& word, std::string city_name, std::string city_new_name);
};
class Functor_add_city {
public:
	bool operator()(std::map<std::string, std::list<std::string>>& word, std::string country, std::string new_city);
};
class Functor_add_country {
public:
	bool operator()(std::map<std::string, std::list<std::string>>& word, std::string new_country);
};
class Functor_remove_country {
public:
	bool operator()(std::map<std::string, std::list<std::string>>& word, std::string country);
};
class Functor_remove_city {
public:
	bool operator()(std::map<std::string, std::list<std::string>>& word, std::string country, std::string city);
};
class Functor_total_cities {
public:
	int operator()(std::map<std::string, std::list<std::string>>& word);
};
class Functor_list_countries {
public:
	void operator()(std::map<std::string, std::list<std::string>>& word);
};*/