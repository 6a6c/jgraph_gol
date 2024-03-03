#!/bin/sh

mkdir glider_gun

bin/play_gol 30 glider_gun < examples/glider_gun.txt

for f in glider_gun/*
do
    jgraph -P $f | ps2pdf - | convert -density 300 - -quality 200 -crop 904x904+823+1406 "${f%.*}".jpg
    rm $f
done

ffmpeg -framerate 10 -i glider_gun/%03d.jpg -loop -0 glider_gun.gif

rm -r glider_gun
