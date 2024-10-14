\NeedsTeXFormat{LaTeX2e}[1995/12/01]
\ProvidesClass{math}
[2023/02/08 v0.2 Standard LaTeX Template for math Report]
\LoadClass[UTF8,a4paper]{ctexrep}
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
  student-name = {
    default = {某同学},
    name    = student@name
  },
  student-id = {
    default = {2022****},
    name    = student@id
  },
  student-class = {
    default = {2022****},
    name    = student@class
  },
  institution = {
    default = {数理学院}
  },
  discipline = {
    default = {信息与计算科学专业}
  },
  course-number = {
    default = {2639015.01},
    name    = course@number
  },
  course-name = {
    default = {数值计算方法训练},
    name    = course@name
  },
  teacher = {
    default = {某教授}
  },
  year = {
    default = {2023}
  },
  month = {
    default = {11}
  },
  day = {
    default = {27}
  },
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
\renewcommand{\songti}{\CJKfontspec[Path=fonts/,FallBack=simsunb.ttf,AutoFakeBold]{simsun.ttc}}
\setCJKmainfont[Path=fonts/,FallBack=simsunb.ttf,AutoFakeBold]{simsun.ttc} % 中文默认为宋体,小四在\documentclass处设置
% \newcommand{\宋体}{\songti}
% 黑体
\renewcommand{\heiti}{\CJKfontspec[Path=fonts/,AutoFakeBold]{simhei.ttf}}
\setCJKsansfont[Path=fonts/]{simhei.ttf}

\newcommand{\kaiti}{\CJKfontspec[Path=fonts/,AutoFakeBold]{kaiti.ttf}}
\renewcommand{\fangsong}{\CJKfontspec[Path=fonts/,AutoFakeBold]{fangsong.ttf}}
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


% % 设置章节样式
% \ctexset{
%   % 需要使用ctexart文类，否则报错键不存在
%   section = {
%     % format用于设置章节标题全局格式，作用域为标题和编号
% 		% 字号为小三，字体为黑体，左对齐
% 		% +号表示在原有格式下附加格式命令
% 		format+ =\bfseries \zihao{-3} \heiti \raggedright,
% 		% name用于设置章节编号前后的词语
% 		% 前、后词语用英文状态下,分开
% 		% 如果没有前或后词语可以不填
% 		name = {,、},
% 		% number用于设置章节编号数字输出格式
% 		% 输出section编号为中文
% 		number = \chinese{section},
% 		% \hspace用于增加水平间距
% 		aftername = \hspace{0pt}
%   },
%   subsection = {
%     name = {,.},
%     number = \arabic{subsection},
%     % 黑体四号
%     format+ =  \zihao{4} \heiti \raggedright ,
% 		aftername = \hspace{0.5em}
%   },
%   subsubsection = {
%     name = {, },
%     number = （\arabic{subsubsection}）,
%     % 黑体小四
%     format+ = \zihao{-4} \heiti \raggedright,
% 		aftername = \hspace{0pt}
%   },
%   paragraph = {
%     name = {, },
%     number = \textcircled{\arabic{paragraph}},
%     format+ = \zihao{-4} \heiti \raggedright,
%   }
% }

\ctexset{
  chapter = {
    % 设置章节标题的全局格式：小二号，宋体，居中对齐
    format+ = \bfseries \zihao{-3} \songti \centering,
    % 在章节编号前后添加词语
    name = {第,章},
    % 设置章节编号为中文格式
    number = \chinese{chapter},
    % 设置编号和标题之间的间距
    aftername = \hspace{1em},
    % 设置章节标题与正文之间的垂直间距
    beforeskip = 50pt,
    afterskip = 20pt,
    % 开启章节标题时新页
    indent = 0pt,
    pagestyle = plain % 设置章节页面为plain风格（页眉为空，仅显示页码）
  },
  section = {
    format+ =\bfseries \zihao{-3} \heiti \raggedright,
    name = {,、},
    number = \chinese{section},
    aftername = \hspace{0pt}
  },
  subsection = {
    name = {,.},
    number = \arabic{subsection},
    format+ = \zihao{5} \songti \raggedright,
    aftername = \hspace{0.5em}
  },
  subsubsection = {
    name = {, },
    number = （\arabic{subsubsection}）,
    format+ = \zihao{-5} \songti \raggedright,
    aftername = \hspace{0pt}
  },
  paragraph = {
    name = {, },
    number = \textcircled{\arabic{paragraph}},
    format+ = \zihao{-5} \songti \raggedright
  }
}

% 设置图片文件夹路径
\graphicspath{{figures/}{figure/}{pictures/}%
{picture/}{pic/}{pics/}{image/}{images/}}


% 代码格式和颜色定义
\usemintedstyle{emacs}


% 页眉
\pagestyle{fancy}
\setlength{\headheight}{13pt}


% 封面
\newcommand{\makecover}{
  \newgeometry{%
    top=2.5cm,bottom=2.5cm,
    left=2.5cm,right=2.5cm
  }
  \songti
  \begin{center}
    \zihao{4}
    {\kaiti \bfseries\zihao{0} 上海电力大学 } \\
    \vskip 20pt
    {\kaiti \bfseries\zihao{-0} 实践课程报告 } \\
    \vskip 25pt
    \begin{center}
      \includegraphics[width=0.4\linewidth]{shiep-logo}
    \end{center}
	  \vskip 20pt
    \begin{center}
      \def\arraystretch{2}
      % \zihao{4}
      % \songti
      \begin{large}
        \begin{tabular}{rcrcrc}
          学 \qquad 院：& \multicolumn{5}{c}{\math@institution}\\
          \cline{2-6}
          专 \qquad 业：& \multicolumn{5}{c}{\math@discipline} \\
          \cline{2-6}
          课程编号： & \multicolumn{2}{c}{\math@course@number} & 课程名称： & \multicolumn{2}{c}{\math@course@name} \\
          \cline{2-3} \cline{5-6}
          学生姓名： & \math@student@name & 学号：& \math@student@id & 班级：& \math@student@class \\
          \cline{2-2}         \cline{4-4}        \cline{6-6}
          指导老师：& \multicolumn{5}{c}{\math@teacher} \\
          \cline{2-6}
        \end{tabular}
      \end{large}
	  \end{center}
    \vskip 10pt
    \underline{\hspace{10pt}\math@year\hspace{10pt}}年
    \underline{\hspace{10pt}\math@month\hspace{10pt}}月
    \underline{\hspace{10pt}\math@day\hspace{10pt}}日
    \vskip 20pt
    \begin{center}
      \begin{large}
        \begin{tabular}{rp{5cm}}
          成绩：&  \\
          \cline{2-2}
        \end{tabular}
      \end{large}
	  \end{center}
  \end{center}
  \thispagestyle{empty}
  \newpage
  \setcounter{page}{1}
}

\renewcommand{\contentsname}{{\hfill \zihao{3} \bfseries 目\quad 录 \hfill}}

