# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"
USER=gjacome-
MAIL=gjacome-@student.42lisboa.com
export USER
export MAIL
export EDITOR='nvim'

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes

ZSH_THEME="my_theme"
#ZSH_THEME="my_theme"

plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# aliases ------------------------------

alias sl='ls'
alias ls="eza --color=always --long --git --no-filesize --icons=always --no-time --no-user --no-permissions"
alias la='ls -Alght --color=auto'
alias grep='grep --color=auto'
alias vim='nvim'
alias vi='nvim'
alias nivm='nvim' # Lmao só porque eu escrevo mal o tempo todo
alias ..='cd ..'
alias GO="Hyprland"
alias cat="bat" # Using bat instead of cat obviously

# ----------------------------

alias francinette=/home/bag/francinette/tester.sh

alias paco=/home/bag/francinette/tester.sh

eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"


# FZF CONFIG -------------------------------------

eval "$(fzf --zsh)"

export FZF_CTRL_T_OPTS="--preview 'bat -n --color=always --line-range :500 {}'"
export FZF_ALT_C_OPTS="--preview 'eza --tree --color=always {} | head -200'"

# Advanced customization of fzf options via _fzf_comprun function
# - The first argument to the function is the name of the command.
# - You should make sure to pass the rest of the arguments to fzf.
_fzf_comprun() {
  local command=$1
  shift

  case "$command" in
    cd)           fzf --preview 'eza --tree --color=always {} | head -200' "$@" ;;
    export|unset) fzf --preview "eval 'echo \$'{}"         "$@" ;;
    ssh)          fzf --preview 'dig {}'                   "$@" ;;
    *)            fzf --preview "bat -n --color=always --line-range :500 {}" "$@" ;;
  esac
}

# ----------------------------------------------



#export BAT_THEME=

# Terminal colors and neofetch (but in C)
("cat" ~/.cache/wal/sequences &)
fastfetch

