#! /bin/bash

pdflatex Rapport-TER.tex
bibtex Rapport-TER.aux
pdflatex Rapport-TER.tex

rm *.aux *.bbl *.blg *.log *.out *.toc