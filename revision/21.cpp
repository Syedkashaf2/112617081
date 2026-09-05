#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int total_iron_ingots{345}, active_players{4}, ingots_per_player, leftover_ingots;

	ingots_per_player = total_iron_ingots/active_players;
	leftover_ingots = total_iron_ingots%active_players;

	cout << "Ingots per player: " << ingots_per_player << '\n';
	cout << "Leftover ingots: " << leftover_ingots << '\n';

	int total_kick_time {142};
	int measured_ticks {3};
	double average_tick_time{};

	average_tick_time = static_cast<double> (total_kick_time) / measured_ticks;

	cout << "Average tick time: " << average_tick_time << '\n';

	return 0;
}
