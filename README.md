
## Lab 1 - Game of Life in Jgraph
### Jake Looney, March 3, 2024

This repo implements [John Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) using [jgraph](https://web.eecs.utk.edu/~jplank/plank/jgraph/jgraph.html).
This is done with a program, `play_gol`, which takes the number of ticks to simulate and a directory for the output jgraph files as command line arguments, as well as a strarting board
on stdin. `play_gol` will then simulate Game of Life from the starting board, and will output each tick of simulation as a jgraph file in the directory.
For example `echo "00000\n00000\n11111\n00000\n00000" | bin/play_gol 2 tmp` will create two jgraph files in the directory `tmp` that show an oscillating structure.
After running `play_gol`, the user can then run jgraph on the output files to create the desired postscripts, pdfs, jpgs, or gifs.

Included in this repo are a few examples. These examples use a shell script to run `play_gol` on example input files, then run 
jgraph and convert on the output files to create a directory of jpgs, and then run ffmpeg on that directory to make a gif of the simulation.
To run these examples, you must first make sure that `jgraph`, `convert`, and `ffmpeg` are inside your path.
Then, running `examples/glider.sh` or similar will create the output gif for you.

Running `make` will not only make the binary to play Game of Life, but will also run all the examples.
Note that some of these examples take a long time to run, so you'll have to command c out of make if you don't wanna see them.
The example gifs are also inside the GitHub repository, under the `example_gifs` directory, just in case some problem arises


If you have any questions about this, please email me at either jlooney6@vols.utk.edu or jlooney314@gmail.com
