# TYMA-2021

Code, data and programs for TYMA exercises.

## Use

1. First clone or download this repository from [here](https://github.com/estebanpw/TYMA-2021)

2. If on linux, run "make all" to compile. If on windows, execute the "make-windows.bat" 

3. Make sure you have python 3 installed. You can download it from here: https://www.python.org/downloads/

4. Add the following libraries to your python installation:
 - pip install numpy
 - pip install matplotlib
 
## Running dotplots

Run the dotplot generator as `./bin/generate_dotplot fastaX fastaY outdotplot`

This will generate a dotplot file which you can plot using `python ./bin/dotplot.py outdotplot`

And a `.png` file will be created on the folder

## Creating word dictionaries

Run `bin/dictionary fastas/hemoglobine.fasta output/dictionary`

A dictionary will be created on folder `output` with name `dictionary`

## Sorting word dictionaries

Run `bin/sort_words inputDictionary outputSortedDictionary 6`

(The `inputDictionary` must be created with the previous command)


