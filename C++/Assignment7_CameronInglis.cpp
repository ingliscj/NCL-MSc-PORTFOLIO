#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>



using namespace std;

const int N = 247;   // number of countries 

struct Country {
	string name;   // name in English
	string continent;
	unsigned int population;
	float area;    // sq. km
	float coastline;  // km
	string government;
	string currency;
	string currency_code;  // a 3-letter abbreviation
	float birth_rate;  // annual per 100 persons
	float death_rate;  // annual per 100 persons
	float life_expectancy;
	float density;
	string countries1[N];
};

 

Country countries[N];
string continents[N];
int number_of_continents = 0;


void find_continents() {

	for (int i = 0; i<N; i++) {
		bool found = false;
		for (int j = 0; j<number_of_continents; j++)
			if (countries[i].continent == continents[j]) {
				found = true;
				break;
			}
		if (!found)
			continents[number_of_continents++] = countries[i].continent;
	}

	for (int i = 0; i < number_of_continents; i++) {
		cout << continents[i];
		cout << "\n";
	}
}



int rank_by_population_density(const string& country)
{
	struct density {
		string country;
		float dense;
	};
	density dense_arr[N]; 
	

	for (int i = 0; i < N; i++)
	{
			dense_arr[i].country = countries[i].name;
			dense_arr[i].dense = (countries[i].population / countries[i].area);
		
	}
	string temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if ((dense_arr[j].dense) < (dense_arr[i].dense))
			{
				temp = dense_arr[j].country;
				dense_arr[j].country = dense_arr[i].country;
				dense_arr[i].country = temp;
			}
		}
	}
		for (int i = 0; i < N; i++)
			if (country == dense_arr[i].country) 
			{
				cout << country << " is rank " << i + 1 << " with a population density of: " << dense_arr[i].dense << "ppl/km" << endl;
			}
		return 0;
}



void load_countries(const char filename[]) {
	ifstream input;
	string line;
	char delimiter = ';';
	size_t prev = 0, pos;

	input.open(filename);
	if (!input.is_open()) {
		cerr << "Cannot open file " << filename << endl;
		exit(0);
	}
	getline(input, line); // ignore the first line

	for (int i = 0; i<N; i++) {
		getline(input, line);
		prev = 0;
		pos = line.find(delimiter, prev);
		countries[i].name = line.substr(prev + 1, pos - prev - 2);
		prev = pos + 1;
		prev = line.find(delimiter, prev) + 1; // skip Gername name
		prev = line.find(delimiter, prev) + 1; // skip native name
		prev = line.find(delimiter, prev) + 1; // skip country code
		pos = line.find(delimiter, prev);
		countries[i].continent = line.substr(prev + 1, pos - prev - 2);
		prev = pos + 1;
		prev = line.find(delimiter, prev) + 1;  // skip capital
		pos = line.find(delimiter, prev);
		countries[i].population = stoi(line.substr(prev, pos - prev));
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].area = stof(line.substr(prev, pos - prev));
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].coastline = stof(line.substr(prev, pos - prev));
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].government = line.substr(prev + 1, pos - prev - 2);
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].currency = line.substr(prev + 1, pos - prev - 2);
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].currency_code = line.substr(prev + 1, pos - prev - 2);
		prev = pos + 1;
		prev = line.find(delimiter, prev) + 1; // skip dialing prefix
		pos = line.find(delimiter, prev);
		countries[i].birth_rate = stof(line.substr(prev, pos - prev));
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].death_rate = stof(line.substr(prev, pos - prev));
		prev = pos + 1;
		pos = line.find(delimiter, prev);
		countries[i].life_expectancy = stof(line.substr(prev, pos - prev));
	}
	input.close();
}

void print_country(int i) {
	cout << "COUNTRY: " << countries[i].name << " (" << countries[i].continent << ") " << endl;
	cout << "  Population: " << countries[i].population << endl;
	cout << "  Area:       " << countries[i].area << " (km^2)" << endl;
	cout << "  Population density: " << countries[i].population / countries[i].area << " (persons per km^2)" << endl;
	cout << "  Coastline:  " << countries[i].coastline << " (km)" << endl;
	cout << "  Currency:   " << countries[i].currency << " (" << countries[i].currency_code << ")" << endl;
	cout << endl;
}

struct cont {
	unsigned int population;
	float area;
	float coastline;
	int Num_of_Countries = 0;
}; 

cont conts[N];

void print_continents_stats(const string& continent)
{
	int contcountnum = 0;
	int contpop = 0;
	float contarea = 0;
	float contcoast = 0;

	for (int i = 0; i < N; i++)
	{
		if (countries[i].continent == continent)
		{
			contcountnum++;
			contpop += countries[i].population;
			contarea += countries[i].area;
			contcoast += countries[i].coastline;
		}
	}



	cout << continent << endl;
	cout << "Coastline: " << contcoast << " km." << endl;
	cout << "Area: " << contarea << " km^2" << endl;
	cout << "Population: " << contpop << endl;
	cout << "Number of Countries: " << contcountnum << endl;

}

void sort_by_population_growth(const string& continent)
{
	struct growth_type 
	{
		string country;
		float pop_g;
	};
	
	growth_type pop_growth[N];
	int count=0;
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		if (countries[i].continent == continent)
		{
			pop_growth[k].country = countries[i].name;
			pop_growth[k].pop_g = (countries[i].birth_rate - countries[i].death_rate);
			count++;
			k++;
		}
	}
	string temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count - 1; j++)
		{
			if ((pop_growth[j].pop_g) < (pop_growth[i].pop_g))
			{
				temp = pop_growth[j].country;
				pop_growth[j].country = pop_growth[i].country;
				pop_growth[i].country = temp;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << pop_growth[i].country << "  " << pop_growth[i].pop_g << endl;
	}
}

void top_landlocked(int n)
{
	struct land_only
	{
		string country;
		float area;
	};

	land_only no_coast[N];
	int count = 0;
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		if (countries[i].coastline == 0)
		{
			no_coast[k].country = countries[i].name;
			no_coast[k].area = countries[i].area;
			count++;
			k++;
		}
			
	}

	string temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count - 1; j++)
		{
			if ((no_coast[i].area) < (no_coast[j].area))
			{
				temp = no_coast[j].country;
				no_coast[j].country = no_coast[i].country;
				no_coast[i].country = temp;
			}
		}
	}
	for (int i = count; i > count-n-1; i--)
		cout << no_coast[i].country << endl;

}

void top_beaches(int n)
{
	struct beach_only
	{
		string country;
		float area;
	};

	beach_only more_coast[N];
	int count = 0;
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		if (countries[i].coastline != 0)
		{
			more_coast[k].country = countries[i].name;
			more_coast[k].area = countries[i].area;
			count++;
			k++;
		}

	}

	string temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count - 1; j++)
		{
			if ((more_coast[j].area) < (more_coast[i].area))
			{
				temp = more_coast[j].country;
				more_coast[j].country = more_coast[i].country;
				more_coast[i].country = temp;
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << more_coast[i].country << endl;

}

void long_live_eu()
{
	struct money
	{
		string country;
		string life_exp;
	};
	money euro[N];
	int count = 0;
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		if (countries[i].currency_code == "EUR" && countries[i].life_expectancy != 0)
		{
			euro[k].country = countries[i].name;
			euro[k].life_exp = countries[i].life_expectancy;
			count++;
			k++;
		}

	}

	string temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count - 1; j++)
		{
			if ((euro[j].life_exp) < (euro[i].life_exp))
			{
				temp = euro[j].country;
				euro[j].country = euro[i].country;
				euro[i].country = temp;
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < k; i++)
		cout << euro[i].country << " " <<  endl;
}

int main() {
	load_countries("countries.csv");
	find_continents();
	rank_by_population_density("Ukraine");
	print_continents_stats("Asia");
	sort_by_population_growth("Europe");
	top_landlocked(5);
	top_beaches(5);
	long_live_eu();


	return 0;
}
