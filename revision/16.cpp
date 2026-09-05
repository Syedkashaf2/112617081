#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int current_player{18}, max_player{20};
	bool is_vip{true};	
	bool can_join;

	can_join = ( current_player < max_player || is_vip == true );
	cout << "First player (VIP) can join : " << can_join << '\n';

	++current_player;
	is_vip = false;

	can_join = ( current_player < max_player || is_vip == true );

        cout << "Second player (Regular) can join : " << can_join << '\n';

	bool is_server_full = ( current_player ==  max_player || is_server_full == true );

        cout << "Is the server completely full ? "<< is_server_full  << '\n';

	return 0;
}
