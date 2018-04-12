### Rectangle ###
   创建一个名为Rectangle的类来表示一个使用宽度和高度来改变量的矩形，矩形的宽度和高度由构造方法来确定。为Rectangle类创建下列方法：
	getArea返回矩形的面积，要求长和高的范围为0~50;
	getPerimeter返回矩形的周长；
	draw使用星号(*)作为描绘字符画出该矩形(假设高度和宽度为整数)；
   在另一个类TestRectangle中编写main方法来测试Rectangle类。

1. 错误：无法从静态上写文中使用非静态数据
~~~
public class Rectangle{
	int length;
	int height;
	public static getArea(){	return length*height;}
	//coding...
~~~
变量length、height为非静态，而getArea()方法是静态的。
解释：静态(static)方法、变量存在与对象之前。static为类所有，该类实例化的所有对象均可共用，即static在栈中开辟固定空间，而非静态在堆中开辟空间，彼此独立。

2. 一个文件夹下有1.java、2.java、...、main.java、n.java等类，其中只有main.java为可执行的类,无需使用import

编译
> javac \*.java

运行
> java main


### Student ###
   根据一个的设计要求编写Java源代码。
	类名：Student
	变量(访问权限均为private);
  		name,//表示为姓名，类型为String
    	age，//表示年龄，类型为int
	方法如下：
		(1)	构造方法(没有参数，设置姓名为“无名氏”，年龄为20)。
		(2)	setName(有一个名为name的String型参数，将name的值设为这个新值)。
		(3)	getName(没有参数，返回姓名)。
		(4)	setAge(有一个名为age的int型参数，将age的值设为这个新值)。
		(5)	getAge(没有参数，返回年龄)。
		(6)	isSameAge(有一个参数s,是另一个Student对象的引用，如果两个Student对象的age相同，则返回true，否则返回false
		
1. java中每个变量都要分别设置权限，这与C++不同
~~~
//Java
public class Student{
	private String name;
	private int age;
	//coding...
}

//C++
class Student{
	private:
		string name;
		int age;
	//coding...
}
~~~

2.  java中传参只有传值
	java中所有对象变量都是对象的引用
参考：[java中的经典问题：传值与传引用](https://blog.csdn.net/jiangnan2014/article/details/22944075)

