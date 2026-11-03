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


## 阅读与排版

正文保留课堂随记和原始代码。文档站使用蓝色顶栏、搜索、右侧章节目录、返回顶部按钮、提示框、代码高亮及数学公式排版。GitHub 原生 Markdown 使用 GitHub 自身样式；完整主题可通过本地预览或发布文档站查看。

> [!NOTE]
> 图片集中存放在本仓库的 `assets/images/`，不列入文档导航。正文中的配图继续显示；GitHub 文件列表会显示资源文件夹，无法通过仓库配置彻底隐藏已跟踪文件。

## 仓库结构与项目隔离

原有 Markdown 文件名、笔记目录和代码目录保持独立；图片移动后已同步修正相对引用。`assets/image-manifest.json` 记录图片原路径、现路径、SHA-256 和原有缺失配图。内容相同的图片仅在本仓库内合并，不共享其他仓库的文件。

- `assets/images/`：本项目的图片。
- `assets/stylesheets/`、`assets/javascripts/`：本项目的排版与公式配置。
- `mkdocs.yml`、`requirements-docs.txt`、`tools/`：独立构建配置与检查工具。
- `.build/`：忽略的临时文档和页面输出，不提交到 Git。

## 本地预览与检查

在本仓库根目录执行以下命令（Python 3.10 或更高版本）：

```bash
python -m pip install -r requirements-docs.txt
python tools/build_docs.py
python -m http.server 8000 --directory .build/site
```

在浏览器打开 `http://localhost:8000`。修改源文件后重新运行构建命令；预览其他项目时使用不同端口。只检查文档链接、标题层级及图片校验值时，运行 `python tools/build_docs.py check`。

## 自动构建与发布

每个仓库各自运行 Documentation 工作流，检查并生成 `documentation-site` 页面包。发布到 GitHub Pages 时，在本仓库 Settings → Pages 中选择 GitHub Actions，然后手动运行 Publish documentation 工作流。每个仓库拥有独立配置和发布地址。

## 许可证

[MIT License](LICENSE) © 2026 limingyu-jpg
