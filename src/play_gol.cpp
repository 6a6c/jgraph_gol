#include "gol.hpp"
#include <vector>
using namespace std;

// play_gol will take a board on stdin to start from
// it will also take the number of ticks to play game of life for
// as well as the directory to output the graph files in 
// as command line arguments
int main(int argc, char** argv){
    vector< vector <int> > board;
    int i;
    string fn;
    char buf[1000];

    if(argc != 3){
        fprintf(stderr, "usage: play_gol num_ticks output_dir\n");
        return 1;
    }   

    // Reads board from stdin
    board = readGol();
    
    // for num_ticks specified on command line args
    for(i = 0; i < atoi(argv[1]); i++){
        //  loads dir / current tick into fn
        sprintf(buf, "%s/%03d.jgr", argv[2], i);
        fn = string(buf);
       
        // Makes jgraph and advances for next tick
        // DEBUG: printGol(board);
        writeGol(fn, board);
        nextGol(board);
    }

    return 0;
}
