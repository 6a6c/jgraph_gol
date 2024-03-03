#include "gol.hpp"
#include <cstdio>
#include <iostream>
using namespace std;

vector <vector <int> > readGol(){
    vector <vector <int> > ret;
    vector<int> v;
    string line;
    int i;

    v.clear();
    while(getline( cin, line)){
        v.clear();
        for( i = 0; i < line.length(); i++){
            v.push_back(line[i] - '0');
        }
        ret.push_back(v);
    }

    return ret;        
}

// Print GOL will just print the board to stdout, and is just here for dev/debug
void printGol(vector< vector <int> > &board){
    int i, j;

    for (i = 0; i < board.size(); i++){
        for (j = 0; j < board[0].size(); j++){
            printf("%d", board[i][j]);
        }   
        printf("\n");
    }
}

// writeGol will write the game of life board to a jgraph file fn
void writeGol(string fn, vector< vector <int> > &board){ 
    FILE *f;
    int i, j;
    int w, h;
    
    w = board[0].size();
    h = board.size();

    f = fopen(fn.c_str(), "w");
    
    fprintf(f, "newgraph\n");
    fprintf(f, "xaxis min 0 max %d nodraw\n", w, w);
    fprintf(f, "yaxis min 0 max %d nodraw\n", h, h);
   
    for(i = 0; i < w; i++){
        for(j = 0; j < h; j++){
            if(board[j][i] == 0) fprintf(f, "newline poly color 0 0 0 pcfill 1 1 1 \n");
            else                 fprintf(f, "newline poly color 0 0 0 pcfill 0 0 0 \n");
            
            fprintf(f, "    pts %d %d %d %d %d %d %d %d\n",
                            i, h - j,       // top left
                            i, h - j - 1,   // bottom left
                        i + 1, h - j - 1,   // bottom right
                        i + 1, h - j);      // top right
            
        }
    }


    fclose(f);
}

// nextGol will modify a board vector in place to be the next 
// board after GOL proceeds a certain amount of ticks
void nextGol(vector <vector <int> > &board){
    vector <int> prev, curr, next, zero; // Since we're doing this in place, we'll need
                                         // a few vectors to keep track of everything 
    int i, j, sum;
   

   
    zero = board[0];
    prev = board[board.size() - 1];
    curr = board[0];
    next = board[1];
    for(i = 0; i < board.size(); i++){
        
        for(j = 0; j < curr.size(); j++){
            sum = prev[j] + next[j];
            sum += prev[j - 1 % curr.size()] + curr[j - 1 % curr.size()] + next[j - 1 % curr.size()];
            sum += prev[j + 1 % curr.size()] + curr[j + 1 % curr.size()] + next[j + 1 % curr.size()];

            if(curr[j] == 1){
                if(sum < 2 || sum > 3) board[i][j] = 0; // under/overpopulation
            }
            else{
                if(sum == 3) board[i][j] = 1; // spontaneous generation via unknown means
            }
        }

        prev = curr;
        curr = next;
        next = (i != board.size() - 2) ? board[i + 2] : zero;
    }

}
