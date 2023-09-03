import os


def lines_strip(filename):
    """get list of lines in file"""
    return [ln.rstrip() for ln in open(filename, 'r').readlines()]


def code(lines, start=1):
    for ln in lines[start:]:
        print(ln)


def section(name):
    print("\n" + "%"*20 + "\n% " + name + "\n" + "%"*20 + "\n")
    print("\\section{" + name + "}\n")


def listing(filename):
    lines = lines_strip(filename)
    name = lines[0][3:]  # remove '// '
    print("\\subsection{" + name + "}")
    start = 1
    if lines[1] == "/* latex":
        start += 1
        for ln in lines[2:]:
            start += 1
            if ln == "*/":
                break
            print(ln)
    print("\\begin{lstlisting}")
    code(lines, start=start)
    print("\\end{lstlisting}\n")


if __name__ == "__main__":
    base_path = os.path.join(os.getcwd(), "../code")
    code_dirs = os.listdir(base_path)
    code_dirs.sort()
    # extra comes last
    code_dirs.pop(code_dirs.index("extra"))
    code_dirs.append("extra")
    for d in code_dirs:
        section(d[0].upper() + d[1:])
        d_path = os.path.join(base_path, d)
        files = os.listdir(d_path)
        if d == "extra":
            files.pop(files.index("bashrc.sh"))
        for f in os.listdir(d_path):
            listing(os.path.join(d_path, f))
    print("\\pagebreak")
    print("\\end{document}")
