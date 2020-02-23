#include "dependies.h"
//#include"Functors.h"
#include "Functor_template.h"
#include "World_map.h"
using namespace std;

int main() {
	/*vector<int> a;
	a.push_back(10);
	a.push_back(1);
	a.push_back(13);
	a.push_back(-9);
	a.push_back(15);
	a.push_back(200);
	a.push_back(200);
	a.push_back(200);
	a.push_back(200);
	a.push_back(30);
	Functor_min<int> f;
	Functor_max<int> g;
	std::cout<<f(a)<<endl;
	std::cout << g(a)<<endl;
	Functor_sort_to_greatest<int> lkj;
	lkj(a);
	Functor_sort_to_less_value<int> hnk;
	hnk(a);
	Functor_increment<int> jhg;
	//jhg(a, 10);
	Functor_decrement<int> olp;
	//olp(a, 100);
	Functor_cut_size<int> rdf;
	//rdf(a, 4);
	Functor_find_and_delete<int> hbv;
	hbv(a, 200);*/
	World_map worf;
	/*Functor_load test;
	test(worf.word);
	Functor_search search;
	cout << boolalpha << search(worf.word, "Ukraine", "Lviv") << endl;
	Functor_add_country count;
	count(worf.word, "Poland");
	Functor_edit_city_name edit;
	cout << boolalpha << edit(worf.word, "Lviv", "LVIV") << endl;
	Functor_add_city add;
	add(worf.word, "Poland", "Krakow");
	Functor_remove_country rem;
	rem(worf.word, "Poland");
	Functor_remove_city rem_cit;
	rem_cit(worf.word, "Ukraine", "LVIV");
	Functor_total_cities tot;
	cout << tot(worf.word) << endl;
	Functor_list_countries list;
	list(worf.word);*/
	worf.Menu();
	return 0;
}