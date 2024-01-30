import csv

import matplotlib
import pandas as pd
from pandas import Series
from scipy.interpolate import interp1d

matplotlib.rcParams['font.sans-serif'] = ['SimHei']

in_file = open("BeijingPM.csv", "r")
reader = csv.reader(in_file)

csvfile = pd.read_csv('BeijingPM.csv')
# index
index = list(csvfile.No)
for i in range(len(index)):
    index[i] = index[i] - 1
temp_index = Series(index)
# HUMI
x = list(csvfile.HUMI)
temp_x = Series(x)
x_right = temp_x.mean() + 3 * temp_x.std()  # HUMI的三倍标准差:132.5764351956605
x_left = temp_x.mean() - 3 * temp_x.std()  # HUMI的三倍标准差:-23.371592626993646
# PRES
y = list(csvfile.PRES)
temp_y = Series(y)
y_right = temp_y.mean() + 3 * temp_y.std()  # PRES的三倍标准差:1047.350652998935
y_left = temp_y.mean() - 3 * temp_y.std()  # PRES的三倍标准差:985.5802303391837
# TEMP
z = list(csvfile.TEMP)
temp_z = Series(z)
z_right = temp_z.mean() + 3 * temp_z.std()  # TEMP的三倍标准差:48.882620897953274
z_left = temp_z.mean() - 3 * temp_z.std()  # TEMP的三倍标准差:-23.70853999112724
# PM_Dongsi
PM_Dongsi = list(csvfile.PM_Dongsi)
temp_pm1 = Series(PM_Dongsi)
# PM_Dongsihuan
PM_Dongsihuan = list(csvfile.PM_Dongsihuan)
temp_pm2 = Series(PM_Dongsihuan)
# PM_Nongzhanguan
PM_Nongzhanguan = list(csvfile.PM_Nongzhanguan)
temp_pm3 = Series(PM_Nongzhanguan)
# PM_US Post
PM_US_Post = list(csvfile['PM_US Post'])
temp_pm4 = Series(PM_US_Post)
# cbwd
cbwd = list(csvfile.cbwd)
temp_cbwd = Series(cbwd)


def update_cbwd(cbwd):
    for i in range(len(cbwd)):
        if i < len(cbwd) - 1 and cbwd[i] == 'cv':
            cbwd[i] = cbwd[i + 1]
        else:
            cbwd[i] = cbwd[i - 1]
    return cbwd


def update_PM(pm, temp_pm):
    for i in range(len(pm)):
        if not pd.isnull(temp_pm[i]):
            if pm[i] > 500:
                pm[i] = 500
                # print(i)
    return pm


def change(x, temp_x, x_right, x_left):
    Y_x = []
    X_index = []
    for i in range(len(temp_x)):
        if not pd.isnull(temp_x[i]):
            Y_x.append(x[i])

    for i in range(len(temp_index)):
        if not pd.isnull(temp_x[i]):
            X_index.append(index[i])

    IRFunction = interp1d(X_index, Y_x, kind='linear')
    Fill_X = []
    for i in range(len(temp_index)):
        if pd.isnull(temp_x[i]):
            Fill_X.append(index[i])

    Fill_Y = IRFunction(Fill_X)
    for i in range(len(Fill_X)):
        x[Fill_X[i]] = Fill_Y[i]
    for i in range(len(x)):
        if x[i] > x_right:
            x[i] = x_right
        elif y[i] < x_left:
            x[i] = x_left
    return x
    # plt.plot(index, x, color='b')
    # plt.show()


ucbwd = update_cbwd(cbwd)

upm1 = update_PM(PM_Dongsi, temp_pm1)
upm2 = update_PM(PM_Dongsihuan, temp_pm2)
upm3 = update_PM(PM_Nongzhanguan, temp_pm3)
upm4 = update_PM(PM_US_Post, temp_pm4)

out_file = open("out.csv", "w", newline='')
writer = csv.writer(out_file)
cx = change(x, temp_x, x_right, x_left)
cy = change(y, temp_y, y_right, y_left)
cz = change(z, temp_z, z_right, z_left)

i = 0
flag = 0
for row in reader:
    if flag != 0:

        row[6] = upm1[i]
        row[7] = upm2[i]
        row[8] = upm3[i]
        row[9] = upm4[i]

        row[11] = round(cx[i])
        row[12] = round(cy[i])
        row[13] = round(cz[i])

        row[14] = cbwd[i]
        i += 1
    flag = 1
    writer.writerow(row)
out_file.close()


