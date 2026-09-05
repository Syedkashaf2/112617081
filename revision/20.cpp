#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	const int max_layers {5};
	double layer_sizes [] {15.5, 20.2, 12.8};
	vector<double> export_queue;

	export_queue.push_back(layer_sizes[0]);
	export_queue.push_back(layer_sizes[2]);

	cout << "Queue size: " << export_queue.size() << '\n';
	cout << "Last rendered layer: " << export_queue.at(1) << '\n'


	return 0;
}

