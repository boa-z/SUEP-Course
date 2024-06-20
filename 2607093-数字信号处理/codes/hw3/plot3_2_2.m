% 定义 x(n) 的函数
function x = x_n (n)
    % n 是一个向量，表示离散时间的取值范围
    % x 是一个向量，表示 x(n) 的取值
    x = zeros (size (n)); % 初始化 x 为全零向量
    for i = 1:length (n) % 遍历 n 的每个元素
      if n (i) >= -2 && n (i) <= 3 % 如果 n 在 [-2, 3] 之间
        x (i) = 2 * n (i) + 1; % 计算 x(n) 的值
      end
    end
  end
  
% 定义 y(n) 的函数
function y = y_n (n)
    % n 是一个向量，表示离散时间的取值范围
    % y 是一个向量，表示 y(n) 的取值
    y = zeros (size (n)); % 初始化 y 为全零向量
    for i = 1:length (n) % 遍历 n 的每个元素
      y (i) = x_n (mod (n (i), 4)); % 计算 y(n) 的值，利用 x(n) 的周期性
    end
  end % 这里加上 end 关键字，表示 y_n 函数的结束  

  % 定义离散时间的取值范围，这里假设为 [-10, 10]
n = -10:10;

% 计算 x(n) 和 y(n) 的取值
x = x_n (n);
y = y_n (n);

% 画出 x(n) 和 y(n) 的波形
figure % 创建一个新的图形窗口
subplot (2, 1, 1) % 在第一行画 x(n) 的波形
stem (n, x) % 用 stem 函数画出离散时间信号的波形
xlabel ('n') % 设置 x 轴的标签为 n
ylabel ('x(n)') % 设置 y 轴的标签为 x(n)
title ('x(n) = (2n+1)[u(n+2) - u(n-3)]') % 设置标题为 x(n) 的表达式
subplot (2, 1, 2) % 在第二行画 y(n) 的波形
stem (n, y) % 用 stem 函数画出离散时间信号的波形
xlabel ('n') % 设置 x 轴的标签为 n
ylabel ('y(n)') % 设置 y 轴的标签为 y(n)
title ('y(n) = x((n))_4') % 设置标题为 y(n) 的表达式
