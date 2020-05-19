# pydotplot

A simple C and Python program using matplotlib and numpy for generating dotplots

## Use

1. First clone or download this repository from: https://github.com/estebanpw/pydotplot

2. If on linux, run "make all" to compile. If on windows, use "gcc src/generate_dotplot.c src/common.c -o bin/generate_dotplot"

3. Make sure you have python 3 installed. You can download it from here: https://www.python.org/downloads/

4. Add the following libraries to your python installation:
 - pip install numpy
 - pip install matplotlib

5. Then run the dotplot generator as "./bin/generate_dotplot fastaX fastaY outdotplot"

6. This will generate a dotplot file which you can plot using "python ./bin/dotplot.py outdotplot"

7. A .png will be created on the folder

## Example

Run bin/generate_dotplot fastas/hemoglobine.fasta fastas/hemoglobine.fasta output/hemo-dotplot && python bin/dotplot.py output/hemo-dotplot
