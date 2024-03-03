#include "gol.hpp"
#include <vector>
using namespace std;

int main(int argc, char** argv){
    vector< vector <int> > board;
    int i;
    string fn;
    char buf[1000];

    if(argc != 3){
        fprintf(stderr, "usage: play_gol num_ticks output_dir\n");
        return 1;
    }   

    board = readGol();
    
    for(i = 0; i < atoi(argv[1]); i++){
        sprintf(buf, "%s/%03d.jgr", argv[2], i);
        fn = string(buf);
        //printGol(board);
        writeGol(fn, board);
        nextGol(board);
    }

    return 0;
}
