#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct City {
	string name;
	int pop;
	float lat;
	float lon;
};

vector<City> cities;
vector<vector<int>> solutions;
int counter;

void fillCities() {
	City city1;
	city1.name = "Rome";
	city1.pop = 2837;
	city1.lat = 41.9028;
	city1.lon = 12.4964;
	cities.push_back(city1);

	City city2;
	city2.name = "Milan";
	city2.pop = 1366;
	city2.lat = 45.4642;
	city2.lon = 9.1900;
	cities.push_back(city2);

	City city3;
	city3.name = "Naples";
	city3.pop = 959;
	city3.lat = 40.8522;
	city3.lon = 14.2681;
	cities.push_back(city3);

	City city4;
	city4.name = "Turin";
	city4.pop = 878;
	city4.lat = 45.0703;
	city4.lon = 7.6869;
	cities.push_back(city4);

	City city5;
	city5.name = "Palermo";
	city5.pop = 675;
	city5.lat = 38.1157;
	city5.lon = 13.3615;
	cities.push_back(city5);

	City city6;
	city6.name = "Genoa";
	city6.pop = 583;
	city6.lat = 44.4056;
	city6.lon = 8.9463;
	cities.push_back(city6);

	City city7;
	city7.name = "Bologna";
	city7.pop = 393;
	city7.lat = 44.4949;
	city7.lon = 11.3426;
	cities.push_back(city7);

	City city8;
	city8.name = "Florence";
	city8.pop = 383;
	city8.lat = 43.7696;
	city8.lon = 11.2558;
	cities.push_back(city8);

	City city9;
	city9.name = "Bari";
	city9.pop = 325;
	city9.lat = 41.1171;
	city9.lon = 16.8719;
	cities.push_back(city9);

	City city10;
	city10.name = "Catania";
	city10.pop = 311;
	city10.lat = 37.5079;
	city10.lon = 15.0830;
	cities.push_back(city10);

	City city11;
	city11.name = "Venice";
	city11.pop = 260;
	city11.lat = 45.4408;
	city11.lon = 12.3155;
	cities.push_back(city11);

	City city12;
	city12.name = "Verona";
	city12.pop = 257;
	city12.lat = 45.4384;
	city12.lon = 10.9916;
	cities.push_back(city12);

	City city13;
	city13.name = "Messina";
	city13.pop = 236;
	city13.lat = 38.1938;
	city13.lon = 15,5540;
	cities.push_back(city13);

	City city14;
	city14.name = "Padua";
	city14.pop = 209;
	city14.lat = 45.4064;
	city14.lon = 11.8768;
	cities.push_back(city14);

	City city15;
	city15.name = "Trieste";
	city15.pop = 200;
	city15.lat = 45.6495;
	city15.lon = 13.7768;
	cities.push_back(city15);
}

struct Node {
	int value;
	int depth;
	vector<Node*> children;
	vector<int> used;
};

bool isUsed(vector<int> v, int val) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == val) {
			return true;
		}
	}
	return false;
}

void generate_tree(Node* node, int m, int n, int reps) {
	for (int i = 1; i <= n; i++) {
		if (reps == 0) {
			if (!isUsed(node->used, i)) {
				Node* child = new Node;
				child->value = i;
				child->depth = node->depth + 1;
				child->used = node->used;
				child->used.push_back(i);
				node->children.push_back(child);
				if (child->depth < m)
					generate_tree(child, m, n, reps);
			}
		}
		else {
			Node* child = new Node;
			child->value = i;
			child->depth = node->depth + 1;
			child->used = node->used;
			child->used.push_back(i);
			node->children.push_back(child);
			if (child->depth < m)
				generate_tree(child, m, n, reps);
		}
	}
}

bool isDistinct(vector<int> v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] > v[i])
			return false;
	}
	return true;
}

void print_tree(Node* node, int m, vector<int> collector, int distinct) {
	if (distinct == 0) {
		if (node->depth == m) {
            counter++;
			cout << counter << ". [";
			for (int i = 0; i < m - 1; i++) {
				cout << collector[i] << ", ";
			}
			cout << collector[m - 1] << "]" << endl;
			solutions.push_back(collector);
		}
		else {
			for (int i = 0; i < node->children.size(); i++) {
				collector[node->depth] = node->children[i]->value;
				print_tree(node->children[i], m, collector, distinct);
			}
		}
	}
	else {
		if (node->depth == m && isDistinct(collector)) {
            counter++;
			cout << counter << ". [";
			for (int i = 0; i < m - 1; i++) {
				cout << collector[i] << ", ";
			}
			cout << collector[m - 1] << "]" << endl;
			solutions.push_back(collector);
		}
		else {
			for (int i = 0; i < node->children.size(); i++) {
				collector[node->depth] = node->children[i]->value;
				print_tree(node->children[i], m, collector, distinct);
			}
		}
	}
}

void print_Cities(vector<int> v) {
	cout << "Solution: ";
	for (int i = 0; i < v.size(); i++) {
		cout << cities[v[i]-1].name << ", ";
	}
	cout << endl;
}

float countDistance(int city1, int city2) {
	float x1 = cities[city1-1].lat, x2 = cities[city2 - 1].lat, y1 = cities[city1 - 1].lon, y2 = cities[city2 - 1].lon;
	float distance = sqrt((x1 - x2)*(x1-x2) + (y1- y2)*(y1 - y2));
	return distance;
}

float countDistancesVector(vector<int> v) {
	float distanceSum = 0;
	for (int i = 1; i < v.size(); i++) {
		distanceSum += countDistance(v[i-1], v[i]);
	}
	distanceSum += countDistance(v[v.size() - 1], v[0]);
	return distanceSum;
}

int factorial(int k) {
    if (k <= 1)
        return 1;
    return k*factorial(k-1);
}

void Zad1(int n, int m) {
	int shortestIndex = 0;
	float shortest = INT_MAX;
	float temp;
	vector<int> distances;
	for (int i = 0; i < solutions.size(); i++) {
		temp = countDistancesVector(solutions[i]);
		if (temp < shortest) {
			shortest = temp;
			shortestIndex = i;
		}
	}
    
	cout << "Shortest distance: " << shortest << endl;
	print_Cities(solutions[shortestIndex]);
}

float countPopAll(int n) {
	float pop = 0;
	for (int i = 0; i < n; i++) {
		pop += cities[i].pop;
	}
	return pop / 2;
}

int countPop(vector<int> v) {
	int pop = 0;
	vector<int> used;
	for (int i = 0; i < v.size(); i++) {
		if (!isUsed(used, v[i])) {
			used.push_back(v[i]);
			pop += cities[v[i] - 1].pop;
		}
	}
	return pop;
}

void Zad2(int n, int m) {
	int bestPop = 0;
	int bestPopIndex = 0;
	int temp;
	float targetPop = countPopAll(n);
	for (int i = 0; i < solutions.size(); i++) {
		temp = countPop(solutions[i]);
		if (abs(targetPop - temp) < abs(targetPop - bestPop)) {
			bestPop = temp;
			bestPopIndex = i;
		}
	}
	cout << "Target Pop: " << targetPop << endl;
	cout << "Closest Pop: " << bestPop << endl;
	print_Cities(solutions[bestPopIndex]);
}

int main() {
	int n = 5, m = 3, reps = 0, distinct = 0;
	fillCities();
	Node* root = new Node;
	root->value = -1;
	root->depth = 0;
	generate_tree(root, m, n, reps);
    counter = 0;
	print_tree(root, m, vector<int>(m), distinct);
    cout << "Wariacje: " << factorial(n)/factorial(n-m) << endl;
	Zad1(n, m);
	solutions.clear();
	root = new Node;
	root->value = -1;
	root->depth = 0;
	reps = 1; 
	distinct = 1;
	n = 3;
	m = 3;
	generate_tree(root, m, n, reps);
    counter = 0;
	print_tree(root, m, vector<int>(m), distinct);
    cout << "Kombinacje: " << factorial(n+m-1)/(factorial(m)*factorial(n-1)) << endl;
	Zad2(n, m);
}
