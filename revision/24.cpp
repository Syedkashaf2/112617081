#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	const int max_storage{500};
	vector<int> render_cache {150, 210, 95};

	int total_size {
		render_cache.at(0) +
		render_cache.at(1) +
		render_cache.at(2)
	};

	string storage_status;

	storage_status = (total_size >= max_storage) ? "Warning : Storage limit Exceeded" : "Optimal" ;

	cout << "Storage: " << storage_status << '\n';
	
	int export_codec{2};

	switch (export_codec)
	{
		case 1:
			cout << "Exporting: H.246 (MP4)\n";
			break;
		case 2:
                        cout << "Exporting: ProRes (MOV)\n";
			break;
		default:
                        cout << "Unknown Codec\n";
			break;
	}


	return 0;
}
