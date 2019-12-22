import csv
import os
import matplotlib.image as mping
import matplotlib.pyplot as plt
from skimage.transform import resize
import numpy as np


def rgb2gray(rgb):
    r, g, b = rgb[:, :, 0], rgb[:, :, 1], rgb[:, :, 2]
    gray = 0.2989 * r + 0.5870 * g + 0.1140 * b
    return gray


def test(file):
    csv_reader = csv.reader(open(file, encoding='utf-8'))
    for row in csv_reader:
        row = [float(i) for i in row]
        row = np.asarray(row)
        print(row.shape)
        tmp = row.reshape((200, 200))
        plt.imshow(tmp, cmap=plt.get_cmap('gray'))
        plt.show()
        break


# input_path 文件输入路径
# name csv名称 如 test
# num 数据量
def makeCsvFile(input_path, name, num):
    # 默认在当前目录下 建立
    outfile = os.path.join('./', name + str(num) + '.csv')
    files = os.listdir(input_path)
    out = open(outfile, 'w', encoding='utf8', newline='')
    csv_writer = csv.writer(out, dialect='excel')
    count = 0
    for file in files:
        print(count)
        name = os.path.join(input_path, file)
        img = mping.imread(name)
        # resized = resize(img, (100, 100))
        # print(resized.shape)
        grayImg = rgb2gray(img)
        row = grayImg.flatten()
        # print(row.shape)
        # tmp = row.reshape((200, 200))
        # plt.imshow(tmp, cmap=plt.get_cmap('gray'))
        # plt.show()
        csv_writer.writerow(row)
        if count == num:
            break
        count += 1


if __name__ == '__main__':
    makeCsvFile('D:\\cropped', 'test', 200)
    # test('./test50.csv')
