    #include <iostream>
    #include <cstdlib> // for atoi
    #include <set>
    using namespace std;
    

    int main(int argc, char* argv[])
    {
        if (argc != 2) // remember, commenting is unhealthy
        {
            cerr << "Wrong number of arguments!" << endl;
            return 1;
        }

        int n = (atoi(argv[1])); // This does stuff
	
	std::set<int> insertedValues;
	int valInsert = rand()%n;
	for(int i = 1; i < n; i++) {
	    while (insertedValues.find(valInsert) != insertedValues.end())
		 valInsert = rand()%(n*2);
	    cout << "I " << valInsert << endl;
            insertedValues.insert(valInsert);
	}
        return 0;
    }
