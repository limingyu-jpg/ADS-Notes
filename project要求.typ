#set page(
  paper: "a4",
  margin: (x: 2.5cm, y: 2.5cm),
  numbering: "1",
)
#set text(
  font: ("Times New Roman", "SimSun"), // 英文 Times，中文宋体（typst.app 网页版请再加 "Noto Serif CJK SC"）
  size: 10.5pt,
)
#set par(justify: true, leading: 0.9em) 
#set heading(numbering: "1.1")      
#show heading.where(level: 1): set text(size: 15pt)
#show heading.where(level: 2): set text(size: 12.5pt)
#show heading: set text(font: ("SimHei", "Microsoft YaHei"), weight: "regular")

#align(center)[
  #text(size: 18pt, font: ("SimHei", "Microsoft YaHei"))[Lab1实验报告]
  #v(0.2em)
]
#v(0.5em)
#line(length: 100%, stroke: 0.5pt)
#v(0.5em)
= PPT要求
PPT字大一点，色差，字号一定是能看清楚的,最小20号字
= 报告要求
在给出报告的时候和先前的报告进行对比改善
= 代码注释要求
代码数量最好多一点，但是不是废话，需要将代码的功能和作用写清楚，便于理解