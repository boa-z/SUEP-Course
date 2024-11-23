%%
% The SUEPThesis Template for Bachelor Graduation Thesis
%
% 上海电力大学毕业设计（论文）中英文摘要 —— 使用 XeLaTeX 编译
%
% Copyright 2020-2023 SUEPaper
%
% This work may be distributed and/or modified under the
% conditions of the LaTeX Project Public License, either version 1.3
% of this license or (at your option) any later version.
% The latest version of this license is in
%   http://www.latex-project.org/lppl.txt
% and version 1.3 or later is part of all distributions of LaTeX
% version 2005/12/01 or later.
%
% This work has the LPPL maintenance status `maintained'.
%
% The Current Maintainer of this work is Haiwen Zhang.
%%
\RequirePackage{expl3,l3keys2e}
\ProvidesExplClass{suepthesis}
{2023-03-05}{3.4.2}{SUEP Thesis Templates}
\int_new:N \g__suepthesis_thesis_type_int
\int_new:N \g__suepthesis_head_zihao_int
\bool_new:N \g__suepthesis_twoside_bool
\bool_new:N \g__suepthesis_thesis_type_english_bool
\bool_new:N \g__suepthesis_blind_mode_bool
\bool_new:N \g__suepthesis_quirks_mode_bool
\tl_new:N \g__suepthesis_label_divide_char_tl
\seq_new:N \l__suepthesis_right_seq
\seq_new:N \l__suepthesis_left_seq
\cs_generate_variant:Nn \tl_if_empty:nTF {x}
\cs_generate_variant:Nn \seq_set_split:Nnn {Nnx}

\cs_new:Npn \__suepthesis_same_page: {
  \let\clearpage\relax
  \let\cleardoublepage\relax
}

\cs_new_protected:Npn \__suepthesis_define_label:nn #1#2
{ \tl_const:cn { c__suepthesis_label_ #1 _tl } {#2} }

\cs_new_protected:Npn \__suepthesis_define_label_by_thesis_type:nnn #1#2#3
{
  \tl_const:cn { c__suepthesis_ #1 _label_ #2 _tl } {#3}
}

\cs_new_protected:Npn \__suepthesis_define_label:nnn #1#2#3
{
  \tl_const:cn { c__suepthesis_label_ #1    _tl } {#2}
  \tl_const:cn { c__suepthesis_label_ #1 _en_tl } {#3}
}

\cs_new_protected:Npn \__suepthesis_define_label_by_thesis_type:nnnn #1#2#3#4
{
  \tl_const:cn { c__suepthesis_ #1 _label_ #2 _tl } {#3}
  \tl_const:cn { c__suepthesis_ #1 _label_ #2 _en_tl } {#4}
}

\cs_new:Npn \smallgap: {
  \hspace{0.45ex}
}

\cs_new:Npn \label_space: {
  \quad
}

\clist_map_inline:nn
{
  {originality} {本科毕业设计（论文）原创性声明},
  {originality_clause} {
    本人郑重申明：本人所呈交的毕业论文，是在指导老师的指导下独立进行研究所取得的成果。
    论文中凡引用他人已经发布或未发表的成果、数据、观点等，均已明确注明出处。
    论文中除已经注明引用的内容外，不包含任何其他个人或集体已经发表或撰写过的研究成果。
    对本文的研究成果做出重要贡献的个人和集体，均已在论文中以明确的方式标明。 \par
    本声明的法律责任由本人承担。
  },
  {authorization} {本科毕业设计（论文）使用授权声明},
  {authorization_clause} {
    本人在指导老师的指导下所完成的论文及相关的资料，
    知识产权归属上海电力大学。
    本人完全了解上海电力大学有关保存、使用毕业论文的规定，
    同意学校保存或向国家有关部门或机构送交论文的纸质版或电子版，
    允许论文被查阅或借阅。
    本人授权上海电力大学可以将本毕业论文的全部或部分内容编入有关数据库进行检索，
    可以采用任何复制手段保存或编汇本毕业论文。
    如果发表相关成果，一定征得指导教师同意，
    且第一署名单位为上海电力大学。
    本人毕业后使用毕业论文或与该论文直接相关的学术论文或成果时，
    第一署名单位仍然为上海电力大学。
  },
  {originality_author_signature}
    {论文作者签名：\hspace{40mm}日\hspace{2.5mm}期：\hspace{30mm}\quad},
  {originality_supervisor_signature}
    {指导老师签名：\hspace{40mm}日\hspace{2.5mm}期：\hspace{30mm}\quad},
} 
{\__suepthesis_define_label_by_thesis_type:nnn {bachelor} #1}

\clist_map_inline:nn
{
  {school} {学\qquad 校} {School},
  {bachelor_title} {本科毕业设计（论文）} {Undergraduate~Thesis},
  {title}{题 \qquad 目} {Title},
  {institution}{院 \qquad 系} {Institution},
  {major} {专业年级} {Degree},
  {author} {学生姓名} {Author},
  {student_id} {学号} {Student~ID},
  {supervisor} {指导教师} {Supervisor},
  {keywords} {关键词：} {Key~Words:~},
  {toc} {目\label_space: 录} {Table~of~Contents},
  {abstract} {摘\label_space: 要} {Abstract},
  {conclusion} {结\label_space: 论} {Conclusions},
  {appendix} {附\label_space: 录} {Appendices},
  {ack} {致\label_space: 谢} {Acknowledgement},
  {figure} {插\quad 图} {Illustrations},
  {table} {表\quad 格} {Tables},
  {appendix_prefix} {附录} {Appendix},
  {reference} {参考文献} {References},
  {university} {上海电力大学} {Shanghai~University~of~Electric~Power},
}
{\__suepthesis_define_label:nnn #1}

\keys_define:nn { suepthesis }
{
  info .meta:nn = { suepthesis / info } {#1},
  misc .meta:nn = { suepthesis / misc } {#1},
  cover .meta:nn = { suepthesis / cover } {#1},
  style .meta:nn = { suepthesis / style } {#1},
  option .meta:nn = { suepthesis / option } {#1},
  TOC .meta:nn = { suepthesis / TOC } {#1},
  appendices .meta:nn = { suepthesis / appendices } {#1},
  publications .meta:nn = { suepthesis / publications } {#1},
}

\keys_define:nn { suepthesis / option }
{
  type .choice:,
  type .value_required:n = true,
  twoside .bool_gset:N = \g__suepthesis_twoside_bool,
  blindPeerReview .bool_gset:N = \g__suepthesis_blind_mode_bool,
  ctex .tl_set:N = \l__suepthesis_options_to_ctex_tl,
  quirks .bool_gset:N = \g__suepthesis_quirks_mode_bool,
}

\keys_define:nn { suepthesis / cover }
{
  date .tl_set:N = \l__suepthesis_cover_date_tl,
  headerImage .tl_set:N = \l_bit_coverheaderimage_tl,
  xiheiFont .tl_set:N = \l__suepthesis_cover_xihei_font_path_tl,
  xiheiFont .default:n = {STXihei},
  %% cover entry
  dilimiter .tl_set:N = \l__suepthesis_cover_dilimiter_tl,
  labelAlign .tl_set:N = \l__suepthesis_cover_label_align_tl,
  labelAlign .initial:n = {r},
  valueAlign .tl_set:N = \l__suepthesis_cover_value_align_tl,
  valueAlign .initial:n = {c},
  labelMaxWidth .dim_set:N = \l__suepthesis_cover_label_max_width_dim,
  valueMaxWidth .dim_set:N = \l__suepthesis_cover_value_max_width_dim,
  autoWidthPadding .dim_set:N = \l__suepthesis_cover_auto_width_padding_dim,
  autoWidthPadding .initial:n = {0.25em},
  autoWidth .bool_set:N = \l__suepthesis_cover_auto_width_bool,
  autoWidth .initial:n = {true},
  underlineThickness .dim_set:N = \l__suepthesis_cover_underline_thickness_dim,
  underlineThickness .initial:n = {1pt},
  underlineOffset .dim_set:N = \l__suepthesis_cover_underline_offset_dim,
  underlineOffset .initial:n = { -10pt },
}

\keys_define:nn { suepthesis / info }
{
  title .tl_set:N = \l__suepthesis_value_title_tl,
  title .initial:n = {上海电力大学本科生毕业},
  subtitle .tl_set:N = \l__suepthesis_value_subtitle_tl,
  subtitle .initial:n = {设计（论文）题目},
  titleEn .tl_set:N = \l__suepthesis_value_title_en_tl,
  titleEn .initial:n = {The~Subject~of~Undergraduate~Graduation~Project~(Thesis)~of~Shanghai~University~of~Electric~Power},

  institution .tl_set:N = \l__suepthesis_value_institution_tl,
  institution .initial:n = {数理学院数学系},

  % 因为是覆盖选项，所以不需要设置初始值。
  verticalTitle .tl_set:N = \l__suepthesis_value_vertical_title_tl,
  school .tl_set:N = \l__suepthesis_value_school_tl,
  school .initial:n = {上海电力大学},

  major .tl_set:N = \l__suepthesis_value_major_tl,
  major .initial:n = {信息与计算科学专业2018级},

  author .tl_set:N = \l__suepthesis_value_author_tl,
  author .initial:n = {某同学},
  studentId .tl_set:N = \l__suepthesis_value_student_id_tl,
  studentId .initial:n = {2018****},
  supervisor .tl_set:N = \l__suepthesis_value_supervisor_tl,
  supervisor .initial:n = {某老师},
  % 因为默认不显示，所以不需要设置初始值。
  externalSupervisor .tl_set:N = \l__suepthesis_value_external_supervisor_tl,
  keywords .tl_set:N = \l__suepthesis_value_keywords_tl,
  keywords .initial:n = {聚氨酯,形状记忆,织物（示例）},
  keywordsEn .tl_set:N = \l__suepthesis_value_keywords_en_tl,
  keywordsEn .initial:n = {Polyurethane,Shape Memory,Textiles (example)},
  translationTitle .tl_set:N = \l__suepthesis_value_trans_title_tl,
  translationOriginTitle .tl_set:N = \l__suepthesis_value_trans_origin_title_tl,
}

\keys_define:nn { suepthesis / misc }
{
    arialFont .tl_set:N = \l__suepthesis_misc_arial_font_path_tl,
}

\keys_define:nn { suepthesis / style }
{
  head .tl_set:N = \l__suepthesis_style_head_tl,
  head .initial:n = {
  },
  bibliographyIndent .bool_set:N = \l__suepthesis_style_bibliography_indent_bool,
  bibliographyIndent .initial:n = {true},
}

\keys_define:nn { suepthesis / TOC }
{
  abstract .bool_set:N = \l__suepthesis_add_abstract_to_toc_bool,
  abstract .initial:n = {true},
  abstractEn .bool_set:N = \l__suepthesis_add_abstract_en_to_toc_bool,
  abstractEn .initial:n = {true},
  symbols .bool_set:N = \l__suepthesis_add_symbols_to_toc_bool,
  symbols .initial:n = {true},
}

\keys_define:nn { suepthesis / appendices }
{
  chapterLevel .bool_set:N = \l__suepthesis_appendices_chapter_level_bool,
  title .tl_set:N = \l__suepthesis_appendices_title_tl,
  TOCTitle .tl_set:N = \l__suepthesis_appendix_toc_title_tl,
}

\keys_define:nn { suepthesis / publications }
{
  % mode .choice:,
  % mode .value_required:n = true,
  % mode .choices:Vn =
  %   \c__suepthesis_publication_modes_clist
  %   {
  %     \int_new:N \l__suepthesis_publication_mode_int
  %     \int_set:Nn \l__suepthesis_publication_mode_int \l_keys_choice_int
  %   },
  % mode .initial:n = biblatex,
  sorting .bool_set:N = \l__suepthesis_publications_sorting_bool,
  sorting .initial:n = {true},
  omit .bool_set:N = \l__suepthesis_publications_omit_bool,
  omit .initial:n = {false},
  maxbibnames .int_set:N = \l__suepthesis_publications_maxbibnames_int,
  maxbibnames .initial:n = {3},
  minbibnames .int_set:N = \l__suepthesis_publications_minbibnames_int,
  minbibnames .initial:n = {1},
}
\ProcessKeysOptions { suepthesis / option }


% \__suepthesis_if_thesis_english:T {
%   \PassOptionsToClass{scheme=plain}{ctexbook}
% }
\bool_if:NTF \g__suepthesis_twoside_bool {} {
  \PassOptionsToClass{oneside}{ctexbook}
}
\PassOptionsToClass{openany}{ctexbook}
\DeclareOption*{
  \PassOptionsToClass{\l__suepthesis_options_to_ctex_tl}{ctexbook}
}
\PassOptionsToPackage{quiet}{xeCJK}
\ProcessOptions\relax
\LoadClass[zihao=-4,]{ctexbook}
\RequirePackage{geometry}
\RequirePackage{xeCJK}
\RequirePackage{titletoc}
\RequirePackage{setspace}
\RequirePackage{graphicx}
% jing: ccaption宏包不能出现在 caption 宏包之后
% 设置浮动体的标题
\RequirePackage[justification=centering]{caption}
\RequirePackage[justification=centering]{subcaption}
\RequirePackage{bicaption}
\RequirePackage{fancyhdr}
\RequirePackage{pdfpages}
\RequirePackage[hidelinks,bookmarksnumbered]{hyperref}
\RequirePackage{xcolor}
\RequirePackage{array}
\RequirePackage{amsmath}
\RequirePackage{unicode-math}
\RequirePackage{pifont}
\RequirePackage{amsthm}

% 算法排版宏包
\RequirePackage{enumitem}
\RequirePackage{fmtcount}
\RequirePackage[most,minted]{tcolorbox}
\RequirePackage{minted}
\RequirePackage{ulem}
\RequirePackage{tabularray}
\RequirePackage{zhlipsum}
\RequirePackage{longtable}

% 默认情况下, \LaTeX{} 要求每页的文字至少占据 20%,否则该页就只单独放置一个浮动环境,
% 而这通常不是我们想要的, 我们将这个要求降低到 5%.
\renewcommand*{\textfraction}{0.05}
% 有时如果多个浮动环境连续放在一起, \LaTeX{}
% 会将它们分在几个不同页，即使它们可在同一页放
% 得下. 我们可以通过修改 |\topfraction| 和 |\bottomfraction| 分别设置顶端和底端的浮
% 动环境的最大比例.
\renewcommand*{\topfraction}{0.9} 
\renewcommand*{\bottomfraction}{0.8}
% 有时\LaTeX{}会把一个浮动环境单独放在一页,
% 我们要求这个环境至少要占据 85% 才能单独放在一页.
% 注意:  |\floatpagefraction| 的数值必须小于 |\topfraction|.
\renewcommand*{\floatpagefraction}{0.85}

% ==============================================================================
% 字体设置
% ==============================================================================

% 英文默认为Times New Roman
\setmainfont[Path=./fonts/, BoldFont={*Bold}, ItalicFont={*Italic}, BoldItalicFont={*BoldItalic}]{TimesNewRoman}

% 伪粗体等级
% \xeCJKsetup{EmboldenFactor=3} 
% 宋体
\renewcommand{\songti}{\CJKfontspec[Path=fonts/,FallBack=simsunb.ttf,AutoFakeBold={3.17}]{simsun.ttc}}
% 中文默认为宋体,小四在\documentclass处设置
\setCJKmainfont[Path=fonts/,FallBack=simsunb.ttf,AutoFakeBold={3.17}]{simsun.ttc} 
% \newcommand{\宋体}{\songti}

% 黑体
\renewcommand{\heiti}{\CJKfontspec[Path=fonts/,AutoFakeBold={3.17}]{simhei.ttf}}
\setCJKsansfont[Path=fonts/]{simhei.ttf}
% \newcommand{\黑体}{\heiti}

% 华文仿宋
\newcommand{\STfangsong}{\CJKfontspec[Path=fonts/,AutoFakeBold={3.17}]{STfangsong.ttf}}
% \newcommand{\仿宋}{\fangsong}

% 楷体
\newcommand{\kaiti}{\CJKfontspec[Path=fonts/,AutoFakeBold={3.17}]{simkai.ttf}}


% 字号汉化设置
\newcommand{\chuhao}{\zihao {0}}
\newcommand{\xiaochu}{\zihao{-0}}
\newcommand{\yihao}{\zihao {1}}
\newcommand{\xiaoyi}{\zihao{-1}}
\newcommand{\erhao}{\zihao {2}}
\newcommand{\xiaoer}{\zihao{-2}}
\newcommand{\sanhao}{\zihao {3}}
\newcommand{\xiaosan}{\zihao{-3}}
\newcommand{\sihao}{\zihao {4}}
\newcommand{\xiaosi}{\zihao{-4}}
\newcommand{\wuhao}{\zihao {5}}
\newcommand{\xiaowu}{\zihao{-5}}
\newcommand{\liuhao}{\zihao {6}}
\newcommand{\xiaoliu}{\zihao{-6}}
\newcommand{\qihao}{\zihao {7}}
\newcommand{\bahao}{\zihao {8}}

% 代码格式和颜色定义
% \usemintedstyle{emacs}

\pdfstringdefDisableCommands{%
  \let\quad\empty
}


\int_set:Nn \g__suepthesis_head_zihao_int {4}

% \geometry{
%   a4paper,
%   left=3.17cm,
%   bottom=2.6cm + 7bp,
%   top=3.5cm + 7bp,
%   right=2.5cm,
%   % `headsep' is affected by `top' option.
%   headsep = 3.5cm + 7bp - 2.4cm - 20bp,
%   headheight = 20 bp,
%   % `footskip' is affected by `bottom' option.
%   footskip = 2.6cm + 7bp - 2cm,
% }

\geometry{
  a4paper,
  left=3.17cm,
  bottom=2.54cm,
  top=2.54cm,
  right=2.5cm,
  % `headsep' is affected by `top' option.
  headsep = 20pt ,
  % headheight = 9pt,
  % `footskip' is affected by `bottom' option.
  footskip = 25pt,
}


% 浮动体的间距
\setlength{\intextsep}{1.0\baselineskip plus 0.2\baselineskip minus 0.2\baselineskip}

\cs_new:Npn \l__suepthesis_title_font_cs:n #1 {
    \heiti #1
}

\cs_new:Npn \l__suepthesis_unnumchapter_style_cs:n #1 {
  % 本科全英文、研究生学位论文需要加粗
  \int_compare:nNnTF {\g__suepthesis_thesis_type_int} > {2}
  {
    \bfseries #1
  } {
    \mdseries #1
  }
}

\cs_set:Npn \arabicHeiti #1 {#1}

\fancypagestyle{suepthesis}{
  \fancyhf{}
  % 定义页眉、页码
  \fancyhead[C]{
    \xiaowu
    \ziju{0.1}
    % 移除页眉中的章节编号显示
    % \songti{\tl_use:N \l__suepthesis_value_title_tl \l__suepthesis_value_subtitle_tl}
  }
  \fancyfoot[C]{\songti\xiaowu -\ \thepage\ -}
  % % 页眉分割线稍微粗一些
  % \RenewDocumentCommand \headrulewidth {} {0.6pt}
  % 不可以使用页眉的
  \RenewDocumentCommand \headrulewidth {} {0pt}
}

\fancypagestyle{supethesisabstract}{
  \fancyhf{} 
  \fancyhead[C]{
    \xiaowu
    \ziju{0.1}
    % \songti{\tl_use:N \l__suepthesis_value_title_tl \l__suepthesis_value_subtitle_tl}
  }

  % % 页眉分割线稍微粗一些
  % \RenewDocumentCommand \headrulewidth {} {0.6pt}
  % 不可以使用页眉的
  \RenewDocumentCommand \headrulewidth {} {0pt}
}


% 一级标题格式：第*章  后空一格 黑体　小三号字　居中 1.5倍行距 段前0行 段后0.5行
\ctexset{chapter={
    % number = {\arabicHeiti{ \arabic{chapter} }},
    % number = {chapter},
    format = { \xiaosan \heiti \centering },
    nameformat = {},
    titleformat = {},
    % aftername = \hspace{9bp},
    aftername = \quad,
    beforeskip = 0pt,
    afterskip = 22.5pt,
    fixskip = true,
  }
}

% 二级标题格式： 1.1  后空一格 黑体四号字 居左 1.5倍行距 段前0.5行 段后0行
\ctexset{section={
    % number = {\arabicHeiti{\thechapter.\hspace{1bp}\arabic{section}}},
    number = {
      \thechapter.\hspace{1bp}
      \arabic{section}
    },
    format = {\sihao \heiti \raggedright},
    nameformat = {},
    titleformat = {},
    aftername = \quad,
    beforeskip = 20bp plus 1ex minus .2ex,
    afterskip = 18bp plus .2ex,
    fixskip = true,
  }
}

% 三级标题格式： 1.1.1 前空两格、后空一格 黑体小四号字 居左 1.5倍行距 段前0.5行 段后0行
\ctexset{subsection={
    number = {
        \thechapter.\hspace{1bp}
        \arabic{section}.\hspace{1bp}
        \arabic{subsection}
    },
    format = \xiaosi \heiti \raggedright,
    aftername = \quad,
    indent = 2\ccwd,
    afterindent  = true,
    beforeskip = 17bp plus 1ex minus .2ex,
    afterskip = 14bp plus .2ex,
    fixskip = true,
  }
}

% 第三级以下单独占行的标题顺序采用 A、B、C和 a、b、c两层，标题均空两格书写序数，后空一格写标题。
\ctexset{
  secnumdepth = 3,
  subsubsection={
    numbering = true,
    number = {
      \Alph{subsubsection}
    },
    format={\xiaosi \songti \raggedright},
    aftername = \quad,
    indent = 2\ccwd,
    nameformat = {},
    titleformat = {},
    fixskip=true,
  }
}

\addtocontents{toc}{\protect\hypersetup{hidelinks}}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 5. 目录 %
% -----------------------------------------------%



\titlecontents{chapter}[0pt]{\songti \zihao{-4} \bfseries}
{\thecontentslabel\hspace{\ccwd}}{}
{\hspace{.5em}\titlerule*{.}\contentspage}

\titlecontents{section}[1\ccwd]{\songti \zihao{-4}}
{\thecontentslabel\hspace{\ccwd}}{}
{\hspace{.5em}\titlerule*{.}\contentspage}

\titlecontents{subsection}[2\ccwd]{\songti \zihao{-4}}
{\thecontentslabel\hspace{\ccwd}}{}
{\hspace{.5em}\titlerule*{.}\contentspage}

\RenewDocumentCommand \frontmatter {} {
  % \int_compare:nNnTF {\g__suepthesis_thesis_type_int} = {3}
  % {
  %   % 本科全英文专业论文，页码使用小罗马数字。
  %   \pagenumbering{roman}
  % } {
  %   \pagenumbering{Roman}
  % }
  % 这部分的章节标题不进行编号。
  \ctexset{
    chapter = {
      numbering = false,
      pagestyle = supethesisabstract,
    }
  }
  \pagestyle{supethesisabstract}
}

\RenewDocumentCommand \mainmatter {} {
  % 这部分的章节标题进行编号。
  \ctexset{
    chapter = {
      numbering = true,
      pagestyle = suepthesis,
    }
  }
  % 页码使用阿拉伯数字。
  \pagenumbering{arabic}
  \pagestyle{suepthesis}
  % 正文 1.25倍行距
  \renewcommand{\baselinestretch}{1.25}  
  % 修复脚注出现跨页的问题
  \interfootnotelinepenalty=10000
}

\RenewDocumentCommand \backmatter {} {
  % 同样，所有的章节标题不进行编号。
  \setcounter{section}{0}
  \setcounter{subsection}{0}
  \setcounter{subsubsection}{0}
  \ctexset{
    chapter = {
      numbering = false,
      beforeskip = 18bp,
      format = {
        \l__suepthesis_title_font_cs:n \l__suepthesis_unnumchapter_style_cs:n \centering \zihao{3}
      },
      afterskip = 26bp,
    }
  }
}

% \setlength{\abovecaptionskip}{5pt}
% \setlength{\belowcaptionskip}{5pt}


\tl_set:Nn \g__suepthesis_label_divide_char_tl {-}

\cs_set:Npn \thefigure {\thechapter\g__suepthesis_label_divide_char_tl\arabic{figure}}
\captionsetup[figure]{font=small,labelsep=space}

\cs_set:Npn \thetable {\thechapter\g__suepthesis_label_divide_char_tl\arabic{table}}
\captionsetup[table]{font=small,labelsep=space,skip=2pt}

\cs_set:Npn \theequation {\thechapter\g__suepthesis_label_divide_char_tl\arabic{equation}}

\cs_set:Npn \thelstlisting {\thechapter\g__suepthesis_label_divide_char_tl\arabic{lstlisting}}


\tolerance=1
\emergencystretch=\maxdimen
\hyphenpenalty=10000
\hbadness=10000
\definecolor{codegreen}{rgb}{0,0.6,0}
\definecolor{codegray}{rgb}{0.5,0.5,0.5}
\definecolor{codepurple}{rgb}{0.58,0,0.82}
\definecolor{backcolour}{rgb}{0.95,0.95,0.92}
\lstdefinestyle{examplestyle}{
    backgroundcolor=\color{backcolour},
    commentstyle=\color{codegreen},
    keywordstyle=\color{magenta},
    numberstyle=\tiny\color{codegray},
    stringstyle=\color{codepurple},
    basicstyle=\ttfamily\footnotesize,
    breakatwhitespace=false,
    breaklines=true,
    captionpos=b,
    keepspaces=true,
    numbers=left,
    numbersep=5pt,
    showspaces=false,
    showstringspaces=false,
    showtabs=false,
    tabsize=2
}

\lstset{style=examplestyle}
\cs_set:Npn \listfigurename {\c__suepthesis_label_figure_tl}
\cs_set:Npn \listtablename {\c__suepthesis_label_table_tl}

% 使用 \pkg{unicode-math} 配置数学字体。
\unimathsetup{
  math-style = ISO,
  bold-style = ISO,
  nabla      = upright,
  partial    = upright,
}


\theoremstyle{plain}
  \newtheorem{algo}{算法}[chapter]
  \newtheorem{them}{定理}[chapter]
  \newtheorem{lem}[them]{引理}
  \newtheorem{prop}[them]{命题}
  \newtheorem{cor}[them]{推论}
  \newtheorem{axi}[them]{公理}
\theoremstyle{definition}
  \newtheorem{defn}{定义}[chapter]
  \newtheorem{conj}{猜想}[chapter]
  \newtheorem{exmp}{例}[chapter]
  \newtheorem{case}{情形}
\theoremstyle{remark}
  \newtheorem{rem}{注}
  \renewcommand{\qedsymbol}{\ensuremath{\QED}}

\cs_new:Npn \__suepthesis_dunderline:nnn #1#2#3 {
  {\setbox0=\hbox{#3}\ooalign{\copy0\cr\rule[\dimexpr#1-#2\relax]{\wd0}{#2}}}
}
\cs_new:Npn \__suepthesis_dunderline:nn #1#2 {
  \__suepthesis_dunderline:nnn {#1} {1pt} {#2}
}
\cs_new:Npn \__suepthesis_dunderline:n #1 {
  \__suepthesis_dunderline:nnn {-10pt} {1pt} {#1}
}

\newcommand\dunderline[3][-1pt]{{%
  \setbox0=\hbox{#3}
  \ooalign{\copy0\cr\rule[\dimexpr#1-#2\relax]{\wd0}{#2}}}}

\cs_new:Npn \__suepthesis_render_cover_entry:nn #1#2 {
  \makebox[\l__suepthesis_cover_label_max_width_dim][\l__suepthesis_cover_label_align_tl]{
    \tl_if_blank:VTF #1 {} {#1\l__suepthesis_cover_dilimiter_tl}
  }
  \hspace{1ex}
  \__suepthesis_dunderline:nnn{\l__suepthesis_cover_underline_offset_dim}
    {\l__suepthesis_cover_underline_thickness_dim}{
    \makebox[\l__suepthesis_cover_value_max_width_dim][\l__suepthesis_cover_value_align_tl]{#2}
  }\par
}

\cs_new:Npn \__suepthesis_get_text_width:Nn #1#2
  {
    \hbox_set:Nn \l_tmpa_box {#2}
    \dim_set:Nn #1 { \box_wd:N \l_tmpa_box }
  }
\cs_generate_variant:Nn \__suepthesis_get_text_width:Nn { NV }
\cs_new:Npn \__suepthesis_get_max_text_width:NN #1#2
  {
    \group_begin:
      \seq_set_eq:NN \l__suepthesis_tmpa_seq #2
      \dim_zero_new:N \l__suepthesis_tmpa_dim
      \bool_until_do:nn { \seq_if_empty_p:N \l__suepthesis_tmpa_seq }
        {
          \seq_pop_left:NN \l__suepthesis_tmpa_seq \l__suepthesis_tmpa_tl
          \__suepthesis_get_text_width:NV \l__suepthesis_tmpa_dim \l__suepthesis_tmpa_tl
          % 在两边加上空白，避免文本太靠边。
          \dim_gset:Nn #1 { \dim_max:nn {#1} { \l__suepthesis_tmpa_dim + \l__suepthesis_cover_auto_width_padding_dim * 2} }
        }
    \group_end:
  }

\cs_new:Npn \__suepthesis_parse_entry #1 #2 {
  \seq_set_split:Nnx \l__suepthesis_tmp_right_seq {\\} {#2}
  \seq_clear:N \l__suepthesis_tmp_left_seq
  \seq_map_inline:Nn \l__suepthesis_tmp_right_seq {
    \seq_put_right:Nn \l__suepthesis_tmp_left_seq {}
  }
  \seq_put_left:Nn \l__suepthesis_tmp_left_seq {#1}
  \seq_pop_right:NN \l__suepthesis_tmp_left_seq \g__suepthesis_trashcan_tl
}

\cs_new:Npn \__suepthesis_render_cover_entry:n #1 {
  % 左边是标签，右边是值。
  % 形如：
  % { {label_1} {value_1}, {label_2} {value 2} }
  % 首先转换成 seq 类型。
  \seq_set_from_clist:NN \l__suepthesis_input_seq #1
  \seq_map_inline:Nn \l__suepthesis_input_seq {
    % 然后对于每一对 label 和 value，首先查找
    % value 中是否含有 \\ 字符，如果有，则将其分割成多个
    % label - value 对。
    % 比如 {label_1} {value \\ 1} 会被转换成
    % { {label_1} {value}, {} {1} }
    \__suepthesis_parse_entry ##1
    % 然后将这些 label - value 对添加到 \l__suepthesis_right_seq
    % 或者 \l__suepthesis_left_sql 中。
    % left 就是 label，right 就是 value。
    \seq_concat:NNN \l__suepthesis_right_seq \l__suepthesis_right_seq \l__suepthesis_tmp_right_seq
    \seq_concat:NNN \l__suepthesis_left_seq \l__suepthesis_left_seq \l__suepthesis_tmp_left_seq
  }

  % 如果用户选择自动计算最大宽度，则计算最大宽度。
  \bool_if:NT \l__suepthesis_cover_auto_width_bool {
    \__suepthesis_get_max_text_width:NN \l__suepthesis_cover_label_max_width_dim \l__suepthesis_left_seq
    \__suepthesis_get_max_text_width:NN \l__suepthesis_cover_value_max_width_dim \l__suepthesis_right_seq
  }

  % 最后，根据宽度渲染 label 和 value 对。
  \group_begin:
    \bool_until_do:nn { \seq_if_empty_p:N \l__suepthesis_left_seq }
      {
        \seq_pop_left:NN \l__suepthesis_left_seq \l__suepthesis_tmpa_tl
        \seq_pop_left:NN \l__suepthesis_right_seq \l__suepthesis_tmpb_tl
        \tl_if_empty:xTF \l__suepthesis_tmpb_tl {} {
          \__suepthesis_render_cover_entry:nn {\l__suepthesis_tmpa_tl} {\l__suepthesis_tmpb_tl}
        }
      }
  \group_end:
}

\cs_new:Npn \__suepthesis_ungraduate_originality:
{
  % 取消页眉页脚。
  \ctexset {
    chapter / pagestyle = plain,
  }

  \renewcommand{\baselinestretch}{2.0}

  \begin{titlepage}
    \newgeometry{%
      top=3.57cm,bottom=2.54cm,
      left=3.1cm,right=3.1cm
    }
    % 不计算页码。
    \pagenumbering{gobble}

    % 原创性声明部分
    \begin{center}
      \__suepthesis_same_page:
      \renewcommand{\baselinestretch}{1.5}
      \heiti\xiaoer
      \l__suepthesis_value_school_tl \par
      \c__suepthesis_bachelor_label_originality_tl
    \end{center}~\par

    \songti\sihao
    \c__suepthesis_bachelor_label_originality_clause_tl

    \vspace{17mm}

    \begin{flushright}
      \c__suepthesis_bachelor_label_originality_author_signature_tl\par
    \end{flushright}
  \end{titlepage}

  \newpage
  
  \begin{titlepage}
    \newgeometry{%
    top=3.57cm,bottom=2.54cm,
    left=3.1cm,right=3.1cm
    }
    % 使用授权声明部分。
    \begin{center}
      \__suepthesis_same_page:
      \renewcommand{\baselinestretch}{1.5}
      \heiti\xiaoer
      \l__suepthesis_value_school_tl \par
      \c__suepthesis_bachelor_label_authorization_tl 
    \end{center}~\par
    
    \songti\sihao
    \c__suepthesis_bachelor_label_authorization_clause_tl

    \vspace*{15mm}

    \begin{flushright}
      \c__suepthesis_bachelor_label_originality_author_signature_tl\par
      \vspace*{5ex}
      \c__suepthesis_bachelor_label_originality_supervisor_signature_tl\par
    \end{flushright}
  \end{titlepage}
  \cleardoublepage
}

\DeclareDocumentCommand \SUEPSetup { m }
  { \keys_set:nn { suepthesis } { #1 }}

\DeclareDocumentCommand \BigStar { }
  { \ding{72} }
  \NewDocumentEnvironment {blindPeerReview} {O{\c_true_bool} +b}
  {
    \bool_if:nTF {\g__suepthesis_blind_mode_bool && #1} {} {
      #2
    }
  } {}

% \begin{macro}{\cleardoublepage}
% 重定义 \tn{cleardoublepage}，使得偶数页面在没有内容时也不显示页眉页脚，见
% \url{https://tex.stackexchange.com/a/1683}。
%    \begin{macrocode}
\RenewDocumentCommand \cleardoublepage { }
  {
    \clearpage
    \bool_if:NT \g__suepthesis_twoside_bool
      {
        \int_if_odd:nF \c@page
          { \hbox:n { } \thispagestyle { empty } \newpage }
      }
  }

\def\ubox@right@shift{0.5\ccwd}
\def\cover@tab@entry@width{210pt}
\def\cover@tab@last@entry@width{\cover@tab@entry@width - 2\ccwd - 0.5\ccwd}
\def\cover@tab@uline@thick{0.4pt}

\def\cover@tab@small@width{50pt}

\ProvideDocumentCommand{\suep@cover@uline}{%
    O{\cover@tab@uline@thick} %
    O{\ubox@right@shift} %
    m}{%
  \def\ULthickness{#1}%
  \setlength{\ULdepth}{0.2em}%
  \hspace*{#2}%
  \uline{#3}%
}
\ProvideDocumentCommand{\suep@cover@bigbox}{%
    O{\cover@tab@entry@width} %
    m}{%
  \makebox[#1][c]{ #2 }%
}

\ProvideDocumentCommand{\suep@cover@smallbox}{%
    O{79pt} %
    m}{%
  \makebox[#1][c]{ #2 }%
}

\DeclareDocumentCommand \MakeCover {}
{
  \group_begin:
    {
      \newgeometry{%
        top=3.57cm,bottom=2.54cm,
        left=3.17cm,right=3.17cm
      }
      \begin{titlepage}

        \centering

        \chuhao\textbf{\kaiti{\c__suepthesis_label_university_tl}} \par

        \vspace{16mm}
        
        \xiaochu\textbf{\STfangsong{\c__suepthesis_label_bachelor_title_tl}}\par


        \vspace{15mm}

        \includegraphics[width=4.82cm, height=4.82cm]{logo_red} \par

        \vspace{15mm}

        % \vskip 40pt
        {
          \songti
          \sihao
          % 调整列距
          \def\tabcolsep{0.5pt}
          % 调整行距
          \def\arraystretch{1.4}
          \begin{tabular}{rcrc}
            \c__suepthesis_label_title_tl：& \multicolumn{3}{c}{
                \suep@cover@uline{\suep@cover@bigbox{\l__suepthesis_value_title_tl}}
            }  \\

            % 移除副标题
            % & \multicolumn{3}{c}{
            %     \suep@cover@uline{\suep@cover@bigbox{\l__suepthesis_value_subtitle_tl}}
            % }   \\

            \c__suepthesis_label_institution_tl：& \multicolumn{3}{c}{
                \suep@cover@uline{\suep@cover@bigbox{\l__suepthesis_value_institution_tl}}
            } \\

            \c__suepthesis_label_major_tl：& \multicolumn{3}{c}{
                \suep@cover@uline{\suep@cover@bigbox{\l__suepthesis_value_major_tl}} 
            } \\

            \c__suepthesis_label_author_tl：& \suep@cover@uline{\suep@cover@smallbox{\l__suepthesis_value_author_tl}}  
            & \c__suepthesis_label_student_id_tl： &  \suep@cover@uline{\suep@cover@smallbox{\l__suepthesis_value_student_id_tl}}  \\

            \c__suepthesis_label_supervisor_tl：& \multicolumn{3}{c}{
                \suep@cover@uline{\suep@cover@bigbox{\l__suepthesis_value_supervisor_tl}}  
            } \\
          \end{tabular} 
        }

        \par

        % \vspace*{\fill}
        \vspace{12mm}

        \centering

        \sihao\ziju{0.5}\songti{
          \tl_if_empty:NTF \l__suepthesis_cover_date_tl {
            \today
          } {
            \l__suepthesis_cover_date_tl
          }
        }
      \end{titlepage}
    }
  \group_end:
}

\NewDocumentCommand \MakeOriginality {}
{
  \group_begin:
    \__suepthesis_ungraduate_originality:
    % 单独成页
    \clearpage
  \group_end:
}

\DeclareDocumentCommand \MakeTOC {}
{
  {

    \renewcommand{\baselinestretch}{1.4}


    \tl_set:Nn \l__suepthesis_toc_title_tl {\c__suepthesis_label_toc_tl}

    % 自定义目录样式
    \cs_set:Npn \contentsname {
      \fontsize{16pt}{\baselineskip}
      \l__suepthesis_unnumchapter_style_cs:n
        \l__suepthesis_title_font_cs:n
          {\l__suepthesis_toc_title_tl}
      \vspace{-8pt}
    }

    % 制作目录
    \tableofcontents

    % 单独成页
    \clearpage
  }
}

\NewDocumentEnvironment {abstract} {}
{

  \cleardoublepage

  \setstretch{1.74}

  % \begin{center}
  %   \vspace*{-17bp}
  %   \heiti\zihao{-2}\textbf{
  %     \l__suepthesis_value_title_tl \l__suepthesis_value_subtitle_tl
  %   }
  % \end{center}

  \vspace*{2mm}

  \ctexset{
    chapter/numbering = false,
  }

  % \__suepthesis_if_bachelor_thesis:T {
    % \ctexset{
    %   chapter/titleformat = {\textmd}
    % }
  % }

  {
    \__suepthesis_same_page:
    \chapter*{\c__suepthesis_label_abstract_tl}
    \currentpdfbookmark{\c__suepthesis_label_abstract_tl}{ch:abstract}
  }
  \vspace*{1mm}
  \par
}
{
  \par
  \vspace{4ex}
  \noindent

  % 本科生模板中，关键词为宋体小四
  \heiti{\textbf{\c__suepthesis_label_keywords_tl} \songti{\l__suepthesis_value_keywords_tl}}\par
  \newpage
}

\NewDocumentEnvironment {abstractEn} {}
{
  \setstretch{1.74}


  \begin{spacing}{0.95}
    \centering
    \vspace*{-2bp}

    \zihao{-2}\textbf
    \l__suepthesis_value_title_en_tl\\

  \end{spacing}
  \vspace*{10mm}


  \ctexset{
    chapter/numbering = false,
  }

  % \ctexset {
  %   chapter/titleformat = {\heiti\xiaosan\centering\textbf}
  % }

  {
    \__suepthesis_same_page:
 
    \chapter*{\c__suepthesis_label_abstract_en_tl}
    \currentpdfbookmark{\c__suepthesis_label_abstract_en_tl}{ch:abstract:en}

  }
}
{
  \par\vspace{3ex}\noindent
  \sihao{\textbf{\c__suepthesis_label_keywords_en_tl } \l__suepthesis_value_keywords_en_tl}
  \newpage
}

\NewDocumentEnvironment {conclusion} {}
{
  \ctexset{
    section/number = \arabic{section}
  }

  % \__suepthesis_if_thesis_english:TF {
  %   \chapter{\c__suepthesis_label_conclusion_en_tl}
  % } {
  \chapter{\c__suepthesis_label_conclusion_tl}
  % }
}
{}

\NewDocumentEnvironment {bibprint} {}
{
  % 设置参考文献字号为 5 号
  \renewcommand*{\bibfont}{\zihao{5}}
  % 设置参考文献各个项目之间的垂直距离为 1mm
  \setlength{\bibitemsep}{1mm}
  \setlength{\bibitemindent}{0em} % bibitemindent表示一条文献中第一行相对后面各行的缩进
  \setlength{\bibhang}{0pt} % 著者-出版年制中 bibhang 表示的各行起始位置到页边的距离 
  % 「本科生」设置1.25倍行距
  \renewcommand{\baselinestretch}{1.25}

  % 设置参考文献顺序标签 `[1]` 与文献内容 `作者. 文献标题...` 的间距
  \setlength{\biblabelsep}{2.5mm}

  % \__suepthesis_if_thesis_english:TF {
  %   \chapter{\c__suepthesis_label_reference_en_tl}
  % } {
  \chapter{\c__suepthesis_label_reference_tl}
  % }
}
{}

\NewDocumentEnvironment {appendices} {}
{
  % 附录节（section）级别
  \ctexset{
    section/number = \c__suepthesis_label_appendix_prefix_tl\hspace{1ex}\chinese{section},
    subsection/number = \chinese{section}. \arabic{subsection},
  }
  \chapter*{\c__suepthesis_label_appendix_tl}
  \stepcounter{chapter}
  \addcontentsline{toc}{chapter}{\c__suepthesis_label_appendix_tl}
}
{}

\NewDocumentEnvironment {acknowledgements} {+b}
  {
    % 将此章节视为特殊的附录页，关闭附录编号，重定义 section 编号。
    % 不知为何，需要手动重置 section 计数器。
    \setcounter{section}{0}
    \ctexset{
      appendix/numbering = false,
      section/number = \arabic{section},
      subsection/number = \arabic{section}. \arabic{subsection},
      subsubsection/number = \arabic{section}. \arabic{subsection}. \arabic{subsubsection},
    }

    \chapter{\c__suepthesis_label_ack_tl}
    #1
  } {}

\endinput
%%
%% End of file `suepthesis.cls'.
