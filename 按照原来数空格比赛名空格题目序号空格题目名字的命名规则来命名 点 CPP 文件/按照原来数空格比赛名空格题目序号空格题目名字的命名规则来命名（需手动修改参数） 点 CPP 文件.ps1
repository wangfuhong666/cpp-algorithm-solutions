# ==========================================
# 1. 配置区 (请根据实际情况修改)
# ==========================================
$ContestName = "2026牛客寒假算法基础集训营6"
$ProblemMap = @{
    "A" = "小L的三角尺"
    "B" = "小L的彩球"
    "C" = "小L的线段树"
    "D" = "小L的扩展"
    "E" = "小L的空投"
    "F" = "小L的极大团"
    "G" = "小L的散步"
    "H" = "小L的数组"
    "I" = "小L的构造2"
    "J" = "小L的字符串"
    "K" = "小L的游戏1"
    "L" = "小L的游戏2"
}


# ==========================================
# 2. 脚本执行区 (仅修改了正则匹配行)
# ==========================================
Write-Host "开始重命名文件..." -ForegroundColor Cyan
$files = Get-ChildItem -Path . -Filter *.cpp -File

foreach ($file in $files) {
    $oldName = $file.Name
    $baseName = $file.BaseName

    # 核心修改：\s* 适配 数字后无空格/有空格 两种情况
    if ($baseName -match "^(\d+)\s*([A-Z]).*") {
        $numberPart = $matches[1]
        $problemId = $matches[2]
    } else {
        Write-Host "警告: 文件名'$oldName'无有效格式（数字+[空格]字母），跳过" -ForegroundColor Yellow
        continue
    }

    if (-not $ProblemMap.ContainsKey($problemId)) {
        Write-Host "警告: 题号'$problemId'未配置，跳过'$oldName'" -ForegroundColor Yellow
        continue
    }
    $problemTitle = $ProblemMap[$problemId]
    $newName = "$numberPart $ContestName $problemId $problemTitle.cpp"

    if (Test-Path -Path $newName -PathType Leaf) {
        Write-Host "跳过: '$newName' 已存在" -ForegroundColor Gray
    } else {
        try {
            Rename-Item -Path $file.FullName -NewName $newName -ErrorAction Stop
            Write-Host "已重命名: $oldName -> $newName" -ForegroundColor Green
        } catch {
            Write-Host "错误: 重命名'$oldName'失败：$($_.Exception.Message)" -ForegroundColor Red
        }
    }
}

Write-Host "`n所有.cpp文件处理完毕！" -ForegroundColor Magenta

