#coding=utf-8
import sys
while (2>1):
    a=raw_input('''欢迎使用成绩录入系统
首次使用请输入0进行初始化
录入请输入1
查询请输入2
删除请按3
排序请按4
结束请按5\n''')
    if a=="0":
        f=open("test1.data",'w')
        f.close()
        print("初始化成功\n")
        continue
    if a=="1":
        print "请按照\"姓名 成绩\"输入，结束请输入eof\n名字中的空格请用下划线表示，成绩必须为整数"
        b=raw_input()
        f=open("test1.data",'a')
        while b!="eof":
            c=b[b.index(' ')+1:]
            if c.isdigit():
                f.write("# "+b+"\n")
            else:
                print "error,please try again"
            b=raw_input()
        f.close
        continue
    if a=="2":
        c=raw_input("请输入要查询的学生\n")
        f=open("test1.data",'r')
        flag=False
        for b in f:
            if b[0]=='#':
                b=b[2:]
                if b[0:b.index(' ')]==c:
                    b=b[b.index(' ')+1:]
                    print b,
                    flag=True
                    break
        f.close
        if (not flag):
            print ("Can't find")
        continue
    if a=="3":
        c=raw_input("请输入要删除的学生\n")
        f=open("test1.data",'r')
        list1=[]
        flag=False
        for b in f:
            if b[0]=='#':
                b=b[2:]
                if b[0:b.index(' ')]!=c:
                    name=b[0:b.index(' ')]
                    grade=int(b[b.index(' ')+1:])
                    list1=list1+[[name,grade]]
                else:
                    flag=True
        f.close
        f=open("test1.data",'w')
        for [name,grade] in list1:
            f.write('#'+' '+name+' '+str(grade)+'\n')
        f.close
        if flag:
            print("Successfully deleted")
        else:
            print("Can't find")
        continue
    if a=="4":
        f=open("test1.data",'r')
        list1=[]
        for b in f:
            if b[0]=='#':
                b=b[2:]
                name=b[0:b.index(' ')]
                grade=int(b[b.index(' ')+1:])
                list1=list1+[[grade,name]]
        f.close
        list1.sort(reverse=True)
        f=open("test1.data",'w')
        for [grade,name] in list1:
            f.write('#'+' '+name+' '+str(grade)+'\n')
        f.close
        print ("Successfully sorted")
        for [grade,name] in list1:
            print (name+' '+str(grade))
        continue
    if a=="5":
        sys.exit()
    print "输入错误，请重新输入"
