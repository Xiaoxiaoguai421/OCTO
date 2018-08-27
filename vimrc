""基础配置
"直接用  https://github.com/ma6174/vim-deprecated/blob/master/.vimrc
"
set sw=4
set ts=4
set et
set smarttab
set smartindent
set lbr
set fo+=mB
set sm
set selection=inclusive
set wildmenu

syntax on
set cul "高亮光标所在行
set cuc
set shortmess=atI   " 启动的时候不显示那个援助乌干达儿童的提示  
set go=             " 不要图形按钮  
"color desert     " 设置背景主题  
color ron     " 设置背景主题  
"color torte     " 设置背景主题  
"set guifont=Courier_New:h10:cANSI   " 设置字体  
"autocmd InsertLeave * se nocul  " 用浅色高亮当前行  
autocmd InsertEnter * se cul    " 用浅色高亮当前行  
set ruler           " 显示标尺  
set showcmd         " 输入的命令显示出来，看的清楚些  
"set whichwrap+=<,>,h,l   " 允许backspace和光标键跨越行边界(不建议)  
set scrolloff=3     " 光标移动到buffer的顶部和底部时保持3行距离  
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   "状态行显示的内容  
set laststatus=2    " 启动显示状态行(1),总是显示状态行(2)  
"set foldenable      " 允许折叠  
""set foldmethod=manual   " 手动折叠  
set nocompatible  "去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限  
" 显示中文帮助
if version >= 603
	set helplang=cn
	set encoding=utf-8
endif
" 自动缩进
set autoindent
set cindent
" Tab键的宽度
set tabstop=4
" 统一缩进为4
set softtabstop=4
set shiftwidth=4
" 使用空格代替制表符
set expandtab
" 在行和段开始处使用制表符
set smarttab
" 显示行号
"set number
" 历史记录数
set history=1000
"搜索逐字符高亮
set hlsearch
set incsearch
"语言设置
set langmenu=zh_CN.UTF-8
set helplang=cn
" 总是显示状态行
set cmdheight=2

""定义函数SetTitle，自动插入文件头 
autocmd BufNewFile *.py,*.c,*.h,*.cpp,*.sh,*.java exec ":call SetTitle()"
func Set_sh()
	call setline(1,"/#############################################################")
	call setline(2,"#	File Name: ".expand("%"))
	call setline(3,"#	Author: GZ")
	call setline(4,"#	Maill: 194463810@qq.com")
	call setline(5,"#	Created Time: ".strftime("%c"))
	call setline(6,"#############################################################/")
	call setline(7,"")
endfunc

func Set_common()
	call setline(1, "/*******************************************************************************")
	call append(line("."),"    >  File Name: ".expand("%"))
	call append(line(".")+1,"    >  Author: GZ")
	call append(line(".")+2,"	>  Mail: 194463810@qq.com")
	call append(line(".")+3,"	>  Created Time: ".strftime("%c"))
	call append(line(".")+4,"*******************************************************************************/")
	call append(line(".")+5,"")
endfunc

func SetTitle()
    "如果文件类型为.sh文件 
    if expand("%:e") == 'sh'
        call Set_sh()
    elseif expand("%:e") == 'py'
        call setline(1,"#!/usr/bin/env python")
		call setline(2,"")
	elseif expand("%:e") == 'cpp'
		call Set_common()
        
        ""使用opencv格式
        call append(line(".")+6,"")
        call append(line(".")+7,"/*")
        call append(line(".")+8," *")
        call append(line(".")+9," */")
        call append(line(".")+10,"")
        call append(line(".")+11,"#include <iostream>")
        call append(line(".")+12,"using namespace cv;")
        call append(line(".")+13,"using namespace std;")
        call append(line(".")+14,"")
        call append(line(".")+15, "int main(int argc, char* argv[])")
        call append(line(".")+16, "{")
        call append(line(".")+17,"")
        call append(line(".")+18,"    return 0;")
        call append(line(".")+19,"}") 

"       call append(line(".")+6, "#include <algorithm>")
"		call append(line(".")+7, "#include <cstdlib>")
"		call append(line(".")+8, "#include <iostream>")
"		call append(line(".")+9, "#include <string>")
"       call append(line(".")+10, "using namespace std;")
"		call append(line(".")+11,"")
"       call append(line(".")+12, "int main(int argc, char* argv[])")
"       call append(line(".")+13, "{")
"		call append(line(".")+14,"")
"       call append(line(".")+15,"    return 0;")
"       call append(line(".")+16,"}")
    elseif expand("%:e") == 'c'
		call Set_common()
		call append(line(".")+6, "#include <stdio.h>")
		call append(line(".")+7, "#include <stdlib.h>")
		call append(line(".")+8, "")
		call append(line(".")+9, "int main(int argc, char* argv[])")
		call append(line(".")+10,"{")
		call append(line(".")+11,"")
		call append(line(".")+12,"    return 0;")
		call append(line(".")+13,"}")
	elseif expand("%:e") == 'h'
		call Set_common()
		call append(line(".")+6,"#ifndef "."_".toupper(expand("%:r:s"))."_H_")
		call append(line(".")+7,"#define "."_".toupper(expand("%:r:s"))."_H_")
		call append(line(".")+8,"")
		call append(line(".")+9,"")
		call append(line(".")+10,"#endif")
    else
        call Set_common()
    endif
endfunc
"新建文件后，自动定位到文件末尾
autocmd BufNewFile * normal G	

map <F4> ms:call Set_md()<cr>'s
func Set_md()
     call setline(1,"~~~")
     call setline(2,"layout    : post")
     call setline(3,"title     : ")
     call setline(4,"subtitle  : ")
     call setline(5,"date      : 20".strftime("%y")."-".strftime("%m")."-".strftime("%d"))
     call setline(6,"auther    : GZ")
     call setline(7,"header-img: img/home-bg.jpg")
     call setline(8,"catelog   : true")
     call setline(9,"tags      : ")
     call setline(10,"")
     call setline(11,"~~~")
     call setline(12,"")
     call setline(13,"")
endfunc


""插件部分
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

""代码风格 格式化
Plugin 'Chiel92/vim-autoformat'
noremap <F3> :Autoformat<CR>
"
""代码自动补全
Plugin 'Valloric/YouCompleteMe'
let g:ycm_global_ycm_extra_conf = '/home/gz_zhu/.ycm_extra_conf.py.'
let g:ycm_collect_identifiers_from_tags_files = 1
let g:ycm_collect_identifiers_from_comments_and_strings = 1
let g:syntastic_ignore_files=[".*\.py$"]
let g:ycm_seed_identifiers_with_syntax = 1
let g:ycm_complete_in_comments = 1
let g:ycm_confirm_extra_conf = 0

"
""语法检查
Plugin 'vim-syntastic/syntastic'
"
""显示当前文件中的宏、全局变量、函数等 tag(C++)
Plugin 'majutsushi/tagbar'
"
""状态栏
Plugin 'powerline/powerline'
"
""文件浏览器（树形目录）
Plugin 'scrooloose/nerdtree' " 加入NERDTree
"
"
""提供多文件同时编辑功能
"Plugin 'fholgado/minibufexpl.vim'
"
