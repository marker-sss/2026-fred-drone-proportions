#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
	ifstream events, labels;
	string s;

	if (argc != 3){
		cerr << "Usage: ./merge events labels" << endl;
		return 1;
	}

	events.open(argv[1]);

	if(events.fail()){
		cerr << "failed to open events file" << endl;
		return 1;
	}

	labels.open(argv[2]);

	if(labels.fail()){
		cerr << "Failed to open labels file" << endl;
		return 1;
	}

	while(getline(events, s)){
		cout << s << " ";
		getline(labels, s);
		cout << s << endl;
	}
	
	return 0;
}
