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
alias ll='ls -hl'

# open file with sublime
export EDITOR='subl -w'

