# Competitive Programming Notebook

## Table of Contents
+ [About](#about)
+ [Getting started](#getting_started)
+ [Usage](#usage)

## About <a name = "about"></a>
Notebook for competitive programming, written mostly in LaTeX and C++.
Some of the material is taken from other notebooks
(see [fmkiotheka's maratona](https://gitlab.c3sl.ufpr.br/fmkiotheka/maratona/) and [brunomaletta's Biblioteca](https://github.com/brunomaletta/Biblioteca)).

## Getting started <a name = "getting_started"></a>
You will need `luatex` and `python3`, besides running on linux.

Generating the notebook:
```bash
cd src
./getlatex.sh
```

## Usage <a name = "usage"></a>
There are two parts to the generated notebook. One is a collection of manually typed notes and tables which go into the Theory section. The other is a collection of algorithm implementations.

The Theory part is in `src/header.tex`. You can directly edit things there.

### Directory structure
Code is in the `code` directory, which is organized as follows:
```
code/
  dir1/
    file1.cpp
    file2.sh
    file3.etc
  dir2/
    sameAsAbove.cpp
    ...
  ...
```

### File structure
Each directory in `code` gets a section with the same name as the directory, and each file gets a subsection. You can add, remove and edit these files.

Every file is expected to have its name in the first line, and the 3 first characters are ignored.

You can also add a description in LaTeX (tables, math, etc) right after the name (optional).

```cpp
// Subsection Title Goes Here
/* latex
it is necessary to write /* latex in the second line to add these latex comments
$math$ and tables are okay
after these comments, add the line below:
*/
// actual code starts here
vector<int> v(112345, -1);
...
```
