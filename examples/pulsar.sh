#!/bin/sh

mkdir pulsar

bin/play_gol 9 pulsar < examples/pulsar.txt

for f in pulsar/*
do
    jgraph -P $f | ps2pdf - | convert -density 300 - -quality 200 -crop 904x904+823+1406 "${f%.*}".jpg
    rm $f
done

ffmpeg -framerate 5 -i pulsar/%03d.jpg -loop -0 pulsar.gif

rm -r pulsar
