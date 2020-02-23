#include "World_map.h"
void World_map::Menu() {
	int choice;
	std::string coountry, city, city_new_name;
	bool run{ true };
	try
	{
	while (run)
	{
		system("CLS");
		std::cout << "Press 1 to load info from file\n";
		std::cout << "Press 2 to Save info from file\n";
		std::cout << "Press 3 to Search city\n";
		std::cout << "Press 4 to Edit city name\n";
		std::cout << "Press 5 to add city\n";
		std::cout << "Press 6 to add country\n";
		std::cout << "Press 7 to remove city\n";
		std::cout << "Press 8 to remove country\n";
		std::cout << "Press 9 to count total city\n";
		std::cout << "Press 10 to show list of county\n";
		std::cout << "Press 11 to exit\n ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			this->Action_void_res([&]() {std::string path;
			std::cout << "Enter path to file from witch you wont load info\n";
			std::cin >> path;
			std::ifstream file;
			file.open(path);
			if (!file.is_open())
			{
				std::cout << "file no exist or wrong path\n";
				return;
			}
			else {
				std::string country;
				std::list<std::string> city;
				std::string city_temp;
				while (true)
				{
					file >> country;
					if (file.eof())
					{
						break;
					}
					while (city_temp != "--")
					{
						file >> city_temp;
						if (city_temp == "--")
						{
							break;
						}
						city.push_back(city_temp);
					}
					std::pair<std::string, std::list<std::string>>temp(country, city);
					word.insert(temp);
					city.clear();
					city_temp = "0";
				}
			}
			file.close();
				}
			);
			Sleep(1000);
			break;
		case 2:
			this->Action_void_res([&]() {std::string path;
			std::cout << "Enter path to file in witch you want save info\n";
			std::cin >> path;
			std::ofstream file;
			file.open(path);
			if (!file.is_open())
			{
				std::cout << "file no exist or wrong path\n";
				return;
			}
			else {
				for (auto iter = word.begin(); iter != word.end(); ++iter)
				{
					file << iter->first << "\n";
					for (auto iter_temp = iter->second.begin(); iter_temp != iter->second.end(); ++iter_temp)
					{
						file << *iter_temp << " ";
					}
					file << "\n--\n";
				}
			}
			file.close(); });
			Sleep(1000);
			break;
		case 3:
			std::cout << "Enter country\n";
			std::cin >> coountry;
			std::cout << "Enter city\n";
			std::cin >> city;
			this->Action_void_res([&]() {
				auto iter = word.find(coountry);
				if (iter != word.end()) {
					for (auto iter_temp = iter->second.begin(); iter_temp != iter->second.end(); ++iter_temp) {
						if (*iter_temp == city)
						{
							std::cout << "city exist\n";
							return;
						}
					}
					std::cout << "Not such city in databse\n";
					return;
				}
				std::cout << "Not such country in databse\n";
				return;
				});
			Sleep(1000);
			break;
		case 4:
			this->Action_void_res([&]() {
				std::cout << "Enter city\n";
				std::cin >> city;
				std::cout << "Enter new name of city\n";
				std::cin >> city_new_name;
				for (auto iter = word.begin(); iter != word.end(); ++iter)
				{
					for (auto iter_temp = iter->second.begin(); iter_temp != iter->second.end(); ++iter_temp)
					{
						if (*iter_temp == city) {
							*iter_temp = city_new_name;
							std::cout << "Name changed\n";
							return;
						}
					}
				}
				std::cout << "Name not changed\n";
				return;
				});
			Sleep(1000);
			break;
		case 5:
			std::cout << "Enter country in wich you want add city\n";
			std::cin >> coountry;
			std::cout << "Enter new  city\n";
			std::cin >> city;
			this->Action_void_res([&]() {
				auto iter = word.find(coountry);
				if (iter != word.end()) {
					iter->second.push_back(city);
					std::cout << "new city added\n";
					return;
				}
				std::cout << "new city not added\n";
				return;
				});
			Sleep(1000);
			break;
		case 6:
			std::cout << "Enter new country for adding\n";
			std::cin >> coountry;
			this->Action_void_res([&]() {
				std::list<std::string>temp;
				word.emplace(coountry, temp);
				std::cout << "country added\n";
				return;
				});
			Sleep(1000);
			break;
		case 7:
			std::cout << "Enter country in wich you want remove city\n";
			std::cin >> coountry;
			std::cout << "Enter  city for removing \n";
			std::cin >> city;
			this->Action_void_res([&]() {
				auto iter = word.find(coountry);
				if (iter != word.end()) {
					for (auto iter_temp = iter->second.begin(); iter_temp != iter->second.end(); ++iter_temp) {
						if (*iter_temp == city)
						{
							iter->second.erase(iter_temp);
							return true;
						}
					}
					return false;
				}
				return false;
				});
			Sleep(1000);
			break;
		case 8:
			std::cout << "Enter country for removing\n";
			std::cin >> coountry;
			word.erase(coountry);
			Sleep(1000);
			break;
		case 9:
			this->Action_void_res([&]() {
				int res{ 0 };
				for (auto iter = word.begin(); iter != word.end(); ++iter)
				{
					res += iter->second.size();
				}
				std::cout << "In your databse is " << res << " cities\n";
				});
			Sleep(1000);
			break;
		case 10:
			this->Action_void_res([&]() {
				std::cout << "List of country : \n";
				for (auto iter = word.begin(); iter != word.end(); ++iter)
				{
					std::cout << iter->first << std::endl;
				}
				});
			Sleep(1000);
			break;
			case 11:
				system("CLS");
				std::cout << "Exit\n";
				run = false;
				break;
		}
		//return true;
	}}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
		run = false;
	}
}
void World_map::Action_void_res(std::function<void()> a)
{
	a();
}
/*void Functor_load::operator()(std::map<std::string, std::list<std::string>> &word) {
std::string path;
std::cout << "Enter path to file from witch you wont load info\n";
std::cin >> path;
std::ifstream file;
file.open(path);
if (!file.is_open())
{
	std::cout << "file no exist or wrong path\n";
	return;
}
else {
	std::string country;
	std::list<std::string> city;
	std::string city_temp;
	while (true)
	{
		file >> country;
		if (file.eof())
		{
			break;
		}
		while (city_temp!="--")
		{
			file >> city_temp;
			if (city_temp=="--")
			{
				break;
			}
			city.push_back(city_temp);
		}
		std::pair<std::string, std::list<std::string>>temp(country, city);
		word.insert(temp);
		city.clear();
		city_temp ="0";
	}
}
file.close();
}
void Functor_save::operator()(std::map<std::string, std::list<std::string>>& word) {
	std::string path;
	std::cout << "Enter path to file in witch you want save info\n";
	std::cin >> path;
	std::ofstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cout << "file no exist or wrong path\n";
		return;
	}
	else {
		for(auto iter=word.begin();iter!=word.end();++iter)
		{
			file << iter->first << "\n";
			for (auto iter_temp=iter->second.begin();iter_temp!= iter->second.end();++iter_temp)
			{
				file << *iter_temp << " ";
			}
			file << "\n--\n";
		}
	}
	file.close();
}
bool Functor_search::operator()(std::map<std::string, std::list<std::string>>& word, std::string country, std::string city) {
	auto iter=word.find(country);
	if (iter != word.end()) {
		for (auto iter_temp = iter->second.begin(); iter_temp != iter->second.end(); ++iter_temp) {
			if (*iter_temp==city)
			{
				return true;
			}
		}
		return false;
	}
	return false;
}
bool Functor_edit_city_name::operator()(std::map<std::string, std::list<std::string>>& word, std::string city_name, std::string city_new_name) {
	for (auto iter=word.begin();iter!=word.end();++iter)
	{
		for (auto iter_temp=iter->second.begin();iter_temp!= iter->second.end();++iter_temp)
		{
			if (*iter_temp == city_name) {
				*iter_temp = city_new_name;
				return true;
			}
		}
	}
	return false;
}
bool Functor_add_city::operator()(std::map<std::string, std::list<std::string>>& word, std::string country, std::string new_city) {
	auto iter = word.find(country);
	if (iter != word.end()) {
		iter->second.push_back(new_city);
		return true;
	}
	return false;
}
bool Functor_add_country::operator()(std::map<std::string, std::list<std::string>>& word, std::string new_country) {
	std::list<std::string>temp;
	word.emplace(new_country, temp);
	return true;
}
bool Functor_remove_country::operator()(std::map<std::string, std::list<std::string>>& word, std::string country) {
	return word.erase(country);
}
bool Functor_remove_city::operator()(std::map<std::string, std::list<std::string>>& word, std::string country, std::string city) {
	auto iter = word.find(country);
	if (iter != word.end()) {
		for (auto iter_temp = iter->second.begin(); iter_temp != iter->second.end(); ++iter_temp) {
			if (*iter_temp == city)
			{
				iter->second.erase(iter_temp);
				return true;
			}
		}
		return false;
	}
	return false;
}
int Functor_total_cities::operator()(std::map<std::string, std::list<std::string>>& word) {
	int res{ 0 };
	for (auto iter=word.begin();iter!=word.end();++iter)
	{
		res += iter->second.size();
	}
	return res;
}
void Functor_list_countries::operator()(std::map<std::string, std::list<std::string>>& word) {
	for (auto iter = word.begin(); iter != word.end(); ++iter)
	{
		std::cout << iter->first << std::endl;
	}
}*/