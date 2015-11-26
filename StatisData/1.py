#
#!coding:utf-8

import re
import sys
import urllib2


# 测试匹配中文信息
def ReSaltStatisData( ):

    # 这段HTML代码是从博客列表页面中摘取出来的单个博客的信息， 我们要从中摘取出
    file = open("./data.xml", 'r')
    linesList = file.read()
    file.close()
    #print linesList.decode('GBK').encode('utf-8')

    reData = r'''<record>\s*<field name=".*?">(.*?)</field>\s*<field name=".*?">(.*?)</field>\s*<field name=".*?">(.*?)</field>\s*</record>'''

    pattern = re.compile(reData, re.S)
    myItems = re.findall(pattern, linesList)
 

    print len(myItems) / 4
    # print myItems
    for item in myItems:
        name = item[0].replace("\n", "")
        month = item[1].replace("\n", "")
        data = item[2].replace("\n", "")
        print name, month, data
	

if __name__ == "__main__" :
    # 测试正则表达式

    reload(sys)
    sys.setdefaultencoding("utf-8")

    ReSaltStatisData( )
