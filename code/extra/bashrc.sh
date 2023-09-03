## Shell
# caps -> esc
xmodmap -e 'clear lock' -e 'keycode 66=Escape' 
alias e=vim
alias c='g++ -Wall -Wconversion -Wfatal-errors -g -O2 -std=gnu++20 -fsanitize=undefined,address'
alias p3='pypy3 -m py_compile'
