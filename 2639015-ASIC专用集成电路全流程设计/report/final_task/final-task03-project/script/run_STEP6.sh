# Forked from: lab06

cd ../pr

# 将 ../syn/dc/frequency_counter_control.v 里的代码复制到 ../pr/frequency_counter_control.v，并给出运行成功的提示，若运行失败则给出失败提示

cp ../syn/dc/frequency_counter_control.v frequency_counter_control.v
if [ $? -eq 0 ]; then
    echo "Copy frequency_counter_control.v successfully."
else
    echo "Copy frequency_counter_control.v failed."
    exit 1
fi

innovus -files run_innovus.tcl
