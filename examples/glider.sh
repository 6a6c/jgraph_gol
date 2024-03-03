#!/bin/sh

mkdir glider

bin/play_gol 160 glider < examples/glider.txt

for f in glider/*
do
    jgraph -P $f | ps2pdf - | convert -density 300 - -quality 200 -crop 904x904+823+1406 "${f%.*}".jpg
    rm $f
done

ffmpeg -framerate 10 -i glider/%03d.jpg -loop -0 glider.gif

rm -r glider
