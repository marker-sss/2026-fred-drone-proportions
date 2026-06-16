#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv){
	int min_events, max_events;
	ifstream data, event_count;
	ofstream labels_out;
	stringstream ss;
	string s, line;
	int events, label;
	int i, j, pixel;

	if(argc != 6){
		cerr << "Usage: ./bin/make_dataset data event_count new_label_file min_events(inclusive) max_events(exclusive)" << endl;
		return 1;
	}

	data.open(argv[1]);

	if(data.fail()){
		cerr << "Failed to open data file" << endl;
		return 1;
	}

	event_count.open(argv[2]);

	if(event_count.fail()){
		cerr << argv[2] << endl;
		cerr << "Failed to open event file" << endl;
		return 1;
	}

	labels_out.open(argv[3]);
	if (labels_out.fail()){
		cerr << "Failed to open new label file" << endl;
		return 1;
	}

	min_events = stoi(argv[4]);
	max_events = stoi(argv[5]);

	i = 0;
	while(getline(event_count, s)){
		ss.clear();
		ss.str(s);
		ss >> events >> label;

		if(events >= min_events && events < max_events) labels_out << label << endl;

		while(getline(data, line)){
			i++;

			ss.clear();
			ss.str(line);
			for(j = 0; j < 39; j++){
				ss >> pixel;
				if (events >= min_events && events < max_events) cout << pixel << ',';
			}
			if (events >= min_events && events < max_events) cout << endl;

			if (i >= 31){
				i = 0;
				if (events >= min_events && events < max_events) cout << endl;
				break;
			}
		}

	}


	return 0;
}
