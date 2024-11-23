import matplotlib.pyplot as plt

# 定义一个函数来解析数据并绘制曲线
def plot_id_vgs(data_file):
    # 初始化一个字典来存储每个 vi 值的数据
    data_dict = {}

    # 读取数据文件
    with open(data_file, 'r') as file:
        lines = file.readlines()
        
        # 跳过标题行和 Step Information 行
        for i, line in enumerate(lines):
            if line.startswith('vi') or line.startswith('Step Information'):
                continue
            # 解析数据行
            parts = line.split('\t')
            vgs = float(parts[1].replace('e+00', ''))
            id_value = float(parts[3].replace('e+00', ''))
            vi = float(parts[0].replace('e+00', ''))

            # 将数据存储到字典中
            if vi not in data_dict:
                data_dict[vi] = {'VGS': [], 'ID': []}
            data_dict[vi]['VGS'].append(vgs)
            data_dict[vi]['ID'].append(id_value)

    # 绘制每个 vi 值下的 ID-VGS 曲线
    for vi, values in data_dict.items():
        plt.plot(values['VGS'], values['ID'], marker='o', label=f'VI = {vi}V')

    # 打印每一组 vi 值的数据
    for vi, values in data_dict.items():
        print(f'VI = {vi}V:')
        for vgs, id_value in zip(values['VGS'], values['ID']):
            print(f'VGS = {vgs}V, ID = {id_value}A')

    # 设置图例和标签
    plt.legend()
    plt.xlabel('VGS (Volts)')
    plt.ylabel('ID (A)')
    plt.title('ID-VGS Characteristic Curves')
    plt.grid(True)
    plt.show()

# 调用函数，传入数据文件路径
plot_id_vgs('2639018-模拟集成电路设计实践/report/lab02/data/data.txt')
