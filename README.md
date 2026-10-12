# ADS 课程笔记（Advanced Data Structures）

浙江大学《数据结构与算法分析》（ADS）课程笔记，按主题拆分成多篇 Markdown，配套课件 / 手写截图。本仓库用于把笔记集中托管到 GitHub，方便随时在网页端复习与检索。

> 笔记为课堂随记，术语中英混写、保留原始表述，方便对照课件。

## 目录导航

| 笔记 | 主题 | 内容概要 |
| --- | --- | --- |
| [搜索 / AVL / Splay](笔记/搜索AVL_Splay笔记.md) | 查找与平衡树（1） | BST 的缺陷、AVL 树四种旋转（LL / RR / LR / RL）、Splay 树、摊还分析（Aggregate / Accounting / Potential） |
| [红黑树 / B+ 树](笔记/红黑树B+树.md) | 平衡树（2） | 红黑树定义与 black-height、插入删除各类 Case、AVL 与红黑树对比、B+ 树的建立 / 查找 / 插入 |
| [堆](笔记/Heaps.md) | 左式堆与斜堆 | 为什么需要 merge、Leftist Heap（NPL）、Skew Heap |
| [二项队列](笔记/Binomial_Queue.md) | Binomial Queue | 一种优先队列，二项树结构、合并效率分析 |
| [倒排文件索引](笔记/Inverted_File_Index.md) | Inverted File Index | 搜索引擎核心技术：词项-文档矩阵 → 倒排索引 |

## 代码

- [代码/AVL.c](代码/AVL.c) — AVL 树实现
- [代码/hw.c](代码/hw.c) — 课程作业代码

## 仓库结构

```
ads课程/
├── README.md          # 本文件（导航）
├── 笔记/              # 5 篇 Markdown 笔记 + 配套截图（png/jpg）
└── 代码/             # AVL.c、hw.c
```

## 在 GitHub 上查看

- 笔记里的图片与对应 Markdown 放在同一目录，GitHub 可直接渲染，**点击上方表格中的笔记链接**即可阅读。
- 公式以 LaTeX 书写（`$...$`），GitHub Markdown 原生支持数学公式渲染。
- 想全局检索某关键词，可使用 GitHub 仓库顶部的 **Search** 或按 `t` 打开文件查找面板。

---
MIT License © 2026 limingyu-jpg
