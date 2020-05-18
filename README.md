# pydotplot

A simple C and Python program using matplotlib and numpy for generating dotplots

## Use

1. First clone or download this repository from: https://github.com/estebanpw/pydotplot

2. If on linux, run "make all" to compile. If on windows, use "gcc generate_dotplot.c -o generate_dotplot"

3. Make sure you have python 3 installed. You can download it from here: https://www.python.org/downloads/

4. Add the following libraries to your python installation:
 - pip install numpy
 - pip install matplotlib

5. Then run the dotplot generator as "./generate_dotplot fastaX fastaY"

6. This will generate a "dotplot.txt" file which you can plot using "python dotplot.py"

7. A "dotplot.png" will be created on the folder

