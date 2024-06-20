
# EX0_TRY

不需要交实验报告，属于玩玩的性质。

关于linux的操作，可以看看教师的PPT，虽然一眼没用，但还是得检查一下有没有没见过的，请添加到`Linux 使用指南.md`中。

编写一个sh脚本，完成以下要求

1. 在主目录下创建自己的子目录。
2. 对根目录进行详细列表并将结果存入新文件lsl.log中，并用cat命令显示该文件内容，再用file命令查看该文件类型。
3. 用cat命令将自己建立的lsl.log文件扩展3次形成一个新文件，并用more命令显示该文件内容，统计该文件的行数，并将此信息追加到文件末尾。
4. 对自己的子目录打包并压缩，查看形成的新文件信息后，在进行解压和解包。
5. 为自己创建一个新的目录，将自己原目录下的文件拷贝到新目录中。
6. 删除新目录及其下的所有文件。
7. 用定向的方法把who命令形成的结果保存到文件who.log中，并查看该文件内容。
8. 用chmod命令修改文件who.log的可执行权限使其成为可执行文件，并运行该文件查看结果。
9. 再次修改文件who.log的可执行权限，使得其权限形式为“r w x r- x r - -”。
10. 进入VI编辑器修改lsl.log文件内容，利用全局替换命令将“root”修改为“user”。
11. 利用find命令查找用户主目录下的所有子目录。
12. 用grep命令查找根目录列表文件中含有“sys”的行，并用管道命令统计行数。
13. 用man命令查看ls命令的手册页，中途用ctrl-Z终止该进程，再利用kill命令完全终止该进程在后台的运行。
14. 修改某文本文件的内容后生成一个新文件，用cmp命令进行比较。
15. 利用一条命令来显示根目录列表文件的第8、9、10三行内容。
16. 用history命令查询以前执行过的命令，并用历史替换的方法重复执行最近的一条ls命令。
17. 用read命令同时给3个变量赋值。
18. 用env命令查询系统中的环境变量。
19. 用alias命令为自己建立一个新命令，命令的功能为对自己的子目录进行详细列表。
20. 编辑一个shell脚本，可以提示用户以下信息：

    a. the working directory
    b. home directory
    c. system time
    d. the users of the system
    e. we can use the following aliases
    f. the number of the env variables

```bash
#!/bin/bash

#1. Create subdirectory in home directory
mkdir ~/mydir

#2. List root directory in detail and save to lsl.log, display with cat and check type with file
ls -al / > ~/lsl.log
cat ~/lsl.log
file ~/lsl.log

#3. Concatenate lsl.log 3 times to new file, display with more, append line count 
cat ~/lsl.log ~/lsl.log ~/lsl.log > ~/new.log
more ~/new.log
wc -l ~/new.log >> ~/new.log

#4. Archive and compress subdirectory, check new file, uncompress and unpack
tar -cvf ~/mydir.tar ~/mydir 
ls -l ~/mydir.tar
tar -xvf ~/mydir.tar

#5. Create new directory, copy files from original dir
mkdir ~/newdir
cp ~/mydir/* ~/newdir

#6. Delete new directory and contents
rm -r ~/newdir

#7. Redirect who output to who.log, display contents
who > ~/who.log
cat ~/who.log

#8. Make who.log executable, run it
chmod +x ~/who.log 
~/who.log

#9. Set permissions on who.log <- 这个真对吗？
chmod 751 ~/who.log

#10. Replace "root" with "user" in lsl.log
vi ~/lsl.log
:%s/root/user/g

#11. Find all subdirectories in home
find ~/ -type d

#12. Find "sys" in root dir list, pipe to wc
grep sys ~/lsl.log | wc -l

#13. View ls man page, kill with ctrl-Z and kill 
man ls
ctrl-Z
kill %1

#14. Compare new and old file with cmp
echo "new text" > ~/new.txt
cmp ~/new.txt ~/original.txt

#15. Display lines 8-10 of lsl.log 
sed -n '8,10p' ~/lsl.log

#16. Repeat last ls command with history 
!ls

#17. Assign values to 3 variables with read
read var1 var2 var3

#18. Display environment variables
env 

#19. Create alias for subdir listing
alias dirlist='ls -al ~/mydir'

#20. Script to display info
echo "Your working directory is $(pwd)"
echo "Your home directory is $HOME"  
echo "The current time is $(date)"
echo "The users are: $(who)"
echo "You can use the aliases: $(alias)" !
echo "There are $(printenv | wc -l) environment variables"
```
