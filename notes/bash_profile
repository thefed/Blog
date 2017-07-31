# updated 6/5/2017
# cleaning up duplicate entries in PATH
#PATH=$(echo "$PATH" | awk -v RS=':' -v ORS=":" '!a[$1]++')

#export PATH=/usr/local/mysql/bin:$PATH

# edit prompt statement 1, "\u@\h \w> "
export PS1="\[\033[36m\]\u\[\033[m\]@\[\033[32m\]\h:\[\033[33;1m\]\w\[\033[m\]\$ "
export CLICOLOR=1
#export LSCOLORS=ExFxBxDxCxegedabagacad
export LSCOLORS=GxFxCxDxCxegedabagaced
#alias ls='ls -GFh'
alias l='ls'
alias ll='ls -hla'

# ls -i # print file serial num (inode num), hard link vs soft link

# open file with sublime
export EDITOR='subl -w'

alias lc='leetcode'
alias grep='grep --color'

# find file by name (case insensitive) in current directory
alias findi='find . -iname'

# use g++ -std=c++11 by default
alias g++='g++ -Wall -g -std=c++11'
