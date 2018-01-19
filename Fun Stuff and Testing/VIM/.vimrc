set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'gmarik/Vundle.vim'

"put plugins under this line
Bundle 'Valloric/YouCompleteMe'
Plugin 'tmhedberg/SimpylFold'
Plugin 'scrooloose/syntastic'
Plugin 'vim-airline/vim-airline'
Plugin 'scrooloose/nerdtree'
Plugin 'tpope/vim-fugitive'
Plugin 'Lokaltog/powerline', {'rtp': 'powerline/bindings/vim'}
Plugin 'jistr/vim-nerdtree-tabs'
Plugin 'nvie/vim-flake8'
Plugin 'vim-scripts/indentpython.vim'
call vundle#end()
filetype plugin indent on

au BufNewFile,BufRead *.py
    \ set tabstop=4
    \ set softtabstop=4
    \ set shiftwidth=4
    \ set textwidth=79
    \ set expandtab
    \ set autoindent
    \ set fileformat=unix
let python_highlight_all = 1
syntax on
imap jk <esc>
set nu
set splitbelow
set splitright
set foldmethod=indent
set foldlevel=99
set encoding=utf-8
set hls
set clipboard=unnamed
