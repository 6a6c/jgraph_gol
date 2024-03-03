#!/bin/sh

mkdir toad

bin/play_gol 6 toad < examples/toad.txt

for f in toad/*
do
    jgraph -P $f | ps2pdf - | convert -density 300 - -quality 200 -crop 904x904+823+1406 "${f%.*}".jpg
    rm $f
done

ffmpeg -framerate 2 -i toad/%03d.jpg -loop -0 toad.gif

rm -r toad
