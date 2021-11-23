#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;



class Cache {
public:
    int entry1;
    int entry2;
};

int retrieve_addr(int);  // find address function
//*********************************************************************************
int main(int argc, char*argv[]) {

    /* check if the correct number of arguments have been passed; bail otherwise */
    if (argc < 4) {
        cout << "Usage: " << endl;
        cout << "   ./cache num_entries associativity filename" << endl;
        return 0;
    }

    /* get args; all args come in as strings; need to convert to int with atoi() */
    unsigned int entries = atoi(argv[1]);
    unsigned int assoc = atoi(argv[2]);



    int cachesize = entries/assoc;

    string input_filename = argv[3];
    string output_filename = argv[3];

    /* create input and output files streams */
    ofstream output;
    ifstream input;


    /* open input stream for reading */
    input.open(input_filename);

    /* check if input stream has been succesfully opened; bail otherwise */
    if (!input.is_open()) {
        cerr << "Could not open input file " << input_filename << ". Exiting ..." << endl;
        exit(0);
    }

    unsigned long *nums = new unsigned long[100];
    int count = 0;
    while (!input.eof() && count < 100) {
        input >> nums[count];
        count++;
    }

    bool last_accessed1 = 0;    //determine last accessed entry
    bool last_accessed2;
    bool changed = 0;
    Cache cache;        // creating the cache

for (int i = 0; i <= count; i++){
    int addr = retrieve_addr(nums[i]);

    if (addr == cache.entry1) {
        output << nums[i]<<" : HIT";    //mark as hit and recently used. output to file
        last_accessed1 = 1;
        last_accessed2 = 0;
        changed=1;
    }
    if (addr == cache.entry2) {
        output << nums[i]<<" : HIT";  // mark as hit and recently used. output to file
        last_accessed2 = 1;
        last_accessed1 = 0;
        changed=1;
    }
    if(changed == 0) {           //  report if it already entered the new address into the cache
        if (last_accessed1 == 0) {
            cache.entry1 = addr;                                 //
            output << nums[i] << " : MISS";                     // changed the least recently used
            last_accessed1 = 1;                                 // entry if not already changed.
            last_accessed2 = 0;                                 // output a miss to the file.
                                                                //
        }                                                       //
                                                                //
        if (last_accessed2 == 0) {                              //

            output << nums[i] << " : MISS";
            cache.entry2 = addr;
            last_accessed2 = 1;
            last_accessed1 = 0;

        }
    }
    changed=0;
}
    /* done reading from input file; close the stream */
    input.close();
    output.close();
    return 0;
}

//***********************************************************************
int retrieve_addr(int index) {

    int binary[16];                     //
    int i = 0;                          //   Converts decimal to binary
    while (index > 0) {                 //    in order to find the cache address.
        binary[i] = index % 2;          //      contains the tag and index.
        index = index / 2;              //
        i++;                            //
    }
    int size=i;
    int reverse[size];                            //    reverse binary array into correct order.
    int j = 0;                                    //
    for( int i = size -1 ; i >= 0; i-- )          //
        reverse[j++] = binary [i];

    stringstream ss;                          //
    for (i = 0; i < size;i++)                 //    converts the array of numbers into one binary number.
        ss << reverse[i];                     //

    int result;
    ss >> result;

    return result;
}
//**************************************************************************
