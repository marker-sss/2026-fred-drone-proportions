#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv){
	
	fstream events;
	stringstream ss;
	int threshold, matches, num_events, is_drone, label, total;
	string s;
	
	matches = 0;
	is_drone = 0;
	total = 0;

	if (argc != 3) {
		cerr << "Wrong arguments. Usage: ./thresholding events threshold" << endl;
		return 1;
	}
	
	threshold = stoi(argv[2]);

	events.open(argv[1]);

	if (events.fail()){
		cerr << "Failed to open events file." << endl;
		return 1;
	}

	while(getline(events, s)){
		ss.clear();
		ss.str(s);

		ss >> num_events >> label;

		if(num_events >= threshold) is_drone = 1;
		else is_drone = 0;
	
		if (is_drone == label) matches++;
		total++;

	}
	
	cout << ((double) matches/(double) total) << endl;

	return 0;
}
