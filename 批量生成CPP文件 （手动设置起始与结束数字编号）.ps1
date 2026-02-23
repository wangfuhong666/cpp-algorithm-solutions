# 设置起始和结束数字
$N = 201
$M = 400

# 定义 C++ 代码模板 (关键修改：模板从第一行代码开始，不要空行)
$template = "#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}"

# 循环创建文件
for ($i = $N; $i -le $M; $i++) {
    # 构建文件名
    $filename = "$i.cpp"
    
    # 创建文件并写入模板
    $template | Out-File -FilePath $filename -Encoding UTF8
    
    Write-Host "已创建文件: $filename"
}

