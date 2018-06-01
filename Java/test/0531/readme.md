Java Note
2018-05-31
GZ

## 声明 ##
声明对象时只是声明还没有自动分配空间，需要配合new使用

## 字符串 ##
1. 字符串比较

- 忽略大小写的字符串比较
    public boolean equalsIgnoreCase( String str );

- 给定字符串是否以prefix开始
    startsWith( String prefix );

- 字符串连接
    pubic conect

2. 字符串截取子串

- 返回从beginIndex到结束的子串
    public String substring( int beginIndex );

> begingIndex是String的下标索引
public String substring( int beginIndex, int endIndex ); 返回beginIndex到endIndex的子串

3. 查找

4. 字符串修改
- 将原有的oldChar全部换成newChar
    public String replace( char oldChar, char newChar)
- 转成小写
    public String toLowerCase();
- 转成大写
    public String toUpper();
- 去掉前后空格
    public String trim();

# 异常处理  #
1. 异常情况
    - 用户的非正常输入
    - 出现异常，**程序不处理**
    - 不可预知的错误等，试图打开的文件不存在、网络连接中断、算数运算被0除、数组下标越界、要加载的文件不存在
2. 异常类
- java.lang.Error
    - java.lang.VirtualMachneError
- java.lang.Exception
    - java.lang.ClassNoteFound

捕获子类异常的代码必须放在捕获父类异常的前面
> 

3. 异常处理模块 try-catch-finally

try不能单独使用，必须搭配catch或者finally

~~~
try(){
   //可能出现异常的java语句
}
//try{}中第i行发生异常，则跳过try{}中i行之后的语句，转到catch或fianlly

catch(异常类j 对象名j){

}
//写了很多个异常，但是匹配一个异常时，不在匹配其他异常

finally{

}
//finally语句一般都会执行（若之前的try或catch执行System.exit()语句，则强制退出），多用来释放资源:关闭文件、关闭数据库、关闭网络等
~~~

人为抛出异常
~~~
try{
    throw new Exception("人为抛出异常");
}catch(Exception e){
    System.out.println("异常以捕获");
~~~


# 实验 #
1. 编写一个程序，从命令行参数输入10个数作为学生成绩，需对成绩进行有效性判断，若成绩有误则通过异常处理显示错误信息，并将成绩按高到低排序打印输出。提出：如果输入数据不为整数，要捕获Integer.parseInt()产生的异常，显示“请输入成绩”，捕获输入参数不足10个的异常，显示“请输入至少10个成绩”。



2. 编写一个银行类Bank，要求如下：

(1) 变量balance为存款余额。

(2) deposite()方法为存款操作。

(3) withdraw()方法为取款操作。

(4) getbalawal()方法为获取余额操作，如果银行余额少于取款额时，显示当前余额，并告知不能取款的提示，否则显示取款成功的信息。要求用户自定义异常来处理余额不足的问题。
