#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv)
{
	int events;
	ifstream data;
	stringstream ss;
	string line;
	int pixel;
	int i, j;

	if (argc != 2){
		cout << "Not enough arguments. Usage: ./count_pixels data" << endl;
		return 1;
	}

	data.open(argv[1]);

	if (data.fail()){
		cout << "Failed to open data file." << endl;
		return 1;
	}

	events = 0;
	i = 0;
	while(getline(data, line)){
		i++;
		
		ss.clear();
		ss.str(line);
		for(j = 0; j < 39; j++){
			ss >> pixel;
			if( pixel == 1) events++;
		}

		if (i >= 31){
			i = 0;
			cout << events << endl;
			events = 0;
		}
	}
	return 0;
}
