import matplotlib
import pandas as pd
from matplotlib import pyplot as plt
from matplotlib import font_manager as fm

df = pd.read_csv('out.csv', encoding='utf-8', usecols=[1, 6, 7, 8, 9])

df['PM_ave'] = df.iloc[:, 1:5].mean(axis=1)

sections = [0, 50, 100, 150, 200, 300, 1200]
section_names = ["green", "yellow", "orange", "red", "purple", "Brownish red"]
result = pd.cut(df.PM_ave, sections, labels=section_names)

color = ['lime', 'yellow', 'orange', 'red', 'purple', 'maroon']
matplotlib.rcParams['font.sans-serif'] = ['SimHei']  # 支持中文的细黑体
label_list = ["优", "良", "轻度污染", "中度污染", "重度污染", "严重污染"]
patches, texts, autotexts = plt.pie(pd.value_counts(result), labels=label_list, colors=color,
                                    labeldistance=1.1, autopct="%1.1f%%",
                                    startangle=0, pctdistance=0.6)

# 调整字体大小
proptease = fm.FontProperties()
proptease.set_size('xx-large')
plt.setp(texts, fontproperties=proptease)
plt.setp(autotexts, fontproperties=proptease)
plt.show()
