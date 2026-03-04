# ==========================================
# 1. 配置区 (请根据实际情况修改)
# ==========================================
<<<<<<< HEAD
$ContestName = "牛客小白月赛129"
$ProblemMap = @{
    "A" = "小橘编译器"
    "B" = "小橙的好序列"
    "C" = "小橙的完美序列"
    "D" = "小橙的幸运数 (easy)"
    "E" = "小橙的幸运数 (hard)"
    "F" = "小橙的异或和"
    "G" = "小橙交换水果"
=======
$ContestName = "[LGR-271-Div.3] 洛谷基础赛 #31 & 「WYZOI」中国新年跨年赛 2025→2026"
$ProblemMap = @{
    "A" = "「WYZOI R2」红包"
    "B" = "「WYZOI R2」春运"
    "C" = "「WYZOI R2」烟花"
    "D" = "「WYZOI R2」拜年"
>>>>>>> 1e8cd75ec24a383e65c4f137ee27a1549175f02a
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

