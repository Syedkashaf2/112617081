#include <iostream>
#include <vector>
using namespace std;

int main()
{
	bool has_pro_subscription{false};
	int ram_available{6}, clip_resolution{1080};
	bool can_render;
	
	can_render = (has_pro_subscription == true || (ram_available >= 8 && clip_resolution == 1080 ) ? true : false );

	cout <<"Initial render check: " << can_render << '\n';

	// after refresh 
	ram_available = 8;
	
	can_render = (has_pro_subscription = true || (ram_available >= 8 && clip_resolution == 1080 ) ? true : false );

	cout <<"Render check after RAM clear: " << can_render << '\n';

	return 0;
}

