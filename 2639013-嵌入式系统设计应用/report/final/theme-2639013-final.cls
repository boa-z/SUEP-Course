\NeedsTeXFormat{LaTeX2e}[1995/12/01]
\ProvidesClass{math}
[2023/02/08 v0.2 Standard LaTeX Template for math Report]
\LoadClass[UTF8,a4paper]{ctexart}
\RequirePackage{graphicx}
\RequirePackage{geometry}
\RequirePackage{titlesec}
\RequirePackage{fancyhdr}
\RequirePackage[most,minted]{tcolorbox}
\RequirePackage{minted}
\RequirePackage{amsmath}
\RequirePackage{unicode-math}
\RequirePackage{multirow}
\RequirePackage{array}
\RequirePackage{float}
\RequirePackage{indentfirst}
\RequirePackage{zhnumber}
\RequirePackage{booktabs}
\RequirePackage{todonotes}

\geometry{a4paper,top=2.54cm,bottom=2.54cm,left=3.17cm,right=3.17cm}

\unimathsetup{math-style=ISO, bold-style=ISO}

% ==============================================================================
% Options and Declarations
% ==============================================================================
\RequirePackage{kvdefinekeys}
\RequirePackage{kvsetkeys}
\RequirePackage{kvoptions}
% ------------------------------------------------------------------------------
%   Define \mathsetup command
%
%   Following key-value setup mechanism is adapted from `thuthesis'.
%   thuthesis (https://github.com/xueruini/thuthesis) is licensed under the
%   conditions of the LaTeX Project Public License, either version 1.3. 
% ------------------------------------------------------------------------------
\newcommand\mathsetup{%
  \kvsetkeys{math}%
}
\newcommand\math@define@key[1]{%
  \kvsetkeys{math@key}{#1}%
}
\kv@set@family@handler{math@key}{%
  \@namedef{math@#1@@name}{#1}%
  \def\math@@default{}%
  \def\math@@choices{}%
  \kv@define@key{math@value}{name}{%
    \@namedef{math@#1@@name}{##1}%
  }%
  \kv@define@key{math@value}{code}{%
    \@namedef{math@#1@@code}{##1}%
  }%
  \@namedef{math@#1@@check}{}%
  \@namedef{math@#1@@code}{}%
  \@namedef{math@#1@@hook}{%
    \expandafter\ifx\csname\@currname.\@currext-h@@k\endcsname\relax
      \@nameuse{math@#1@@code}%
    \else
      \AtEndOfClass{%
        \@nameuse{math@#1@@code}%
      }%
    \fi
  }%
  \kv@define@key{math@value}{choices}{%
    \def\math@@choices{##1}%
    \@namedef{math@#1@@reset}{}%
    \@namedef{math@#1@@check}{%
      \@ifundefined{%
        ifmath@\@nameuse{math@#1@@name}@\@nameuse{math@\@nameuse{math@#1@@name}}%
      }{%
        \math@error{Invalid value "#1 = \@nameuse{math@\@nameuse{math@#1@@name}}"}%
      }%
      \@nameuse{math@#1@@reset}%
      \@nameuse{math@\@nameuse{math@#1@@name}@\@nameuse{math@\@nameuse{math@#1@@name}}true}%
    }%
  }%
  \kv@define@key{math@value}{default}{%
    \def\math@@default{##1}%
  }%
  \kvsetkeys{math@value}{#2}%
  \@namedef{math@\@nameuse{math@#1@@name}}{}%
  \kv@set@family@handler{math@choice}{%
    \ifx\math@@default\@empty
      \def\math@@default{##1}%
    \fi
    \expandafter\newif\csname ifmath@\@nameuse{math@#1@@name}@##1\endcsname
    \expandafter\g@addto@macro\csname math@#1@@reset\endcsname{%
      \@nameuse{math@\@nameuse{math@#1@@name}@##1false}%
    }%
  }%
  \kvsetkeys@expandafter{math@choice}{\math@@choices}%
  \expandafter\let\csname math@\@nameuse{math@#1@@name}\endcsname\math@@default
  \expandafter\ifx\csname math@\@nameuse{math@#1@@name}\endcsname\@empty\else
    \@nameuse{math@#1@@check}%
    \@nameuse{math@#1@@hook}%
  \fi
  \kv@define@key{math}{#1}{%
    \@namedef{math@\@nameuse{math@#1@@name}}{##1}%
    \@nameuse{math@#1@@check}%
    \@nameuse{math@#1@@hook}%
  }%
}

\math@define@key{
  title = {
    default = {上海电力大学},
  },
  sub-title = {
    default = {《嵌入式系统及应用》},
    name = sub@title,
  },
  kind = {
    default = {期末大作业报告},
    name = kind,
  },
  student-name = {
    default = {某同学},
    name    = student@name,
  },
  student-id = {
    default = {2021xxxx},
    name    = student@id,
  },
  experiment = {
    default = {},
    name    = experiment,
  },
  department = {
    default = {电子信息工程学院},
    name   = department,
  },
  major = {
    default = {集成电路设计与集成系统},
    name  = major,
  },
  class = {
    default = {2021xxx 班},
  },
  % date = {
  %   default = {1919 年 8 月 10 日},
  % },
}

% 行间距
\linespread{1.25}

% 字号汉化设置
% \newcommand{\初号}{\zihao {0}}
% \newcommand{\小初}{\zihao{-0}}
% \newcommand{\一号}{\zihao {1}}
% \newcommand{\小一}{\zihao{-1}}
% \newcommand{\二号}{\zihao {2}}
% \newcommand{\小二}{\zihao{-2}}
% \newcommand{\三号}{\zihao {3}}
% \newcommand{\小三}{\zihao{-3}}
% \newcommand{\四号}{\zihao {4}}
% \newcommand{\小四}{\zihao{-4}}
% \newcommand{\五号}{\zihao {5}}
% \newcommand{\小五}{\zihao{-5}}
% \newcommand{\六号}{\zihao {6}}
% \newcommand{\小六}{\zihao{-6}}
% \newcommand{\七号}{\zihao {7}}
% \newcommand{\八号}{\zihao {8}}
% 字体汉化设置
\xeCJKsetup{EmboldenFactor=2.5} % 伪粗体等级
% 字体设置
\renewcommand{\songti}{\CJKfontspec[AutoFakeBold]{Songti SC}}
% \renewcommand{\STXingkai}{\CJKfontspec{STXingkai}} % 会报错： ! Package fontspec Error: The font "STXingkai" cannot be found.
\setCJKmainfont[AutoFakeBold]{Songti SC} % 中文默认为宋体,小四在\documentclass处设置
% 黑体
\renewcommand{\heiti}{\CJKfontspec[AutoFakeBold]{Heiti SC}} \setCJKsansfont{Heiti SC}
% \newcommand{\黑体}{\heiti}
% % 其他
% \newcommand{\仿宋}{\fangsong}
% \newcommand{\楷书}{\kaishu}
% \newcommand{\隶书}{\lishu}
% \newcommand{\幼圆}{\youyuan}
% \newcommand{\雅黑}{\yahei}
% \newcommand{\苹方}{\pingfang}
% % 字体效果汉化设置
% \newcommand{\粗体}{\bfseries}
% \newcommand{\斜体}{\itshape}


% 设置章节样式
\ctexset{
  % 需要使用ctexart文类，否则报错键不存在
  section = {
    % format用于设置章节标题全局格式，作用域为标题和编号
		% 字号为小三，字体为黑体，左对齐
		% +号表示在原有格式下附加格式命令
		format+ = \zihao{-3} \heiti \raggedright,
		% name用于设置章节编号前后的词语
		% 前、后词语用英文状态下,分开
		% 如果没有前或后词语可以不填
		name = {,、},
		% number用于设置章节编号数字输出格式
		% 输出section编号为中文
		number = \chinese{section},
		% beforeskip用于设置章节标题前的垂直间距
		% ex为当前字号下字母x的高度
		% 基础高度为1.0ex，可以伸展到1.2ex，也可以收缩到0.8ex
		beforeskip = 1.0ex plus 0.2ex minus .2ex,
		% afterskip用于设置章节标题后的垂直间距
		afterskip = 1.0ex plus 0.2ex minus .2ex,
		% aftername用于控制编号和标题之间的格式
		% \hspace用于增加水平间距
		aftername = \hspace{0pt}
  },
  subsection = {
    name = {,.{ } },
    number = \arabic{subsection},
    % 黑体四号
    format+ = \zihao{4} \songti \raggedright,
		beforeskip = 1.0ex plus 0.2ex minus .2ex,
		afterskip = 1.0ex plus 0.2ex minus .2ex,
		aftername = \hspace{0pt}
  },
  subsubsection = {
    name = {,.{ } },
    % number = \arabic{subsubsection},
    number = \arabic{subsection}.\arabic{subsubsection},
    % 黑体小四
    format+ = \zihao{-4} \songti \raggedright,
		beforeskip = 1.0ex plus 0.2ex minus .2ex,
		afterskip = 1.0ex plus 0.2ex minus .2ex,
		aftername = \hspace{0pt}
  },
}

% 设置图片文件夹路径
\graphicspath{{figures/}{figure/}{pictures/}%
{picture/}{pic/}{pics/}{image/}{images/}}


% 代码格式和颜色定义
\usemintedstyle{emacs}


% 页眉
\pagestyle{fancy}
\lhead{课程名称：嵌入式系统及应用}
\chead{姓名：\math@student@name}
\rhead{学号：\math@student@id}
\setlength{\headheight}{13pt}


% 封面
\newcommand{\makecover}{
  \begin{center}
    \heiti
    \bfseries\zihao{-0}{\math@title}\\
    \vskip 30pt
    \bfseries\songti\zihao{1}{\math@sub@title} \\
    \vskip 10pt
    \songti\zihao{1}{\math@kind} \\
    \vskip 60pt
    \begin{center}
      \includegraphics[width=0.4\linewidth]{shiep-logo}
    \end{center}
	\vskip 60pt
    \begin{center}
		\begin{large}
			\zihao{-3}
			\begin{tabular}{rc}
				课题名称：& \math@experiment\\
						\cline{2-2}\\
        院（系）：& \math@department\\
          \cline{2-2}\\
				专\qquad 业：& \math@major\\
				  \cline{2-2}\\
        班\qquad 级：& \math@class\\
				  \cline{2-2}\\
				姓\qquad 名：& \math@student@name\\
				  \cline{2-2}\\
				学\qquad 号：&\hspace{2.5cm} \math@student@id \hspace{2.5cm} \\
				  \cline{2-2}
			\end{tabular}
		\end{large}
	\end{center}
    % \vskip 60pt
    % \zihao{4}{\math@date}
  \end{center}
  \thispagestyle{empty}
  \newpage
  \setcounter{page}{1}
}
