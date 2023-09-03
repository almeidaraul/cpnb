#!/bin/bash

cp header.tex pdf/notebook.tex
cp -r TTF pdf/
python3 listings.py >> pdf/notebook.tex
cd pdf
lualatex notebook.tex
mv *.pdf ../../
