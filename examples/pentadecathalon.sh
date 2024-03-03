#!/bin/sh

mkdir pentadecathalon

bin/play_gol 15 pentadecathalon < examples/pentadecathalon.txt

for f in pentadecathalon/*
do
    jgraph -P $f | ps2pdf - | convert -density 300 - -quality 200 -crop 904x904+823+1406 "${f%.*}".jpg
    rm $f
done

ffmpeg -framerate 5 -i pentadecathalon/%03d.jpg -loop -0 pentadecathalon.gif

rm -r pentadecathalon
