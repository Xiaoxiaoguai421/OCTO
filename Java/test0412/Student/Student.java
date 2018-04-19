/*************************************************************************
    > File Name: Student.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月12日 星期四 11时26分52秒
 ************************************************************************/
public class Student {
	private String name;
	private int age;

	public Student() {
		name = "无名氏";
		age = 20;
	}
	public void setName(String name) {	this.name = name;}
	public String getName() {	return name;}
	public void setAge(int age) {	this.age = age;}
	public int getAge() {	return age;}
	public boolean isSameAge(Student s) {	return this.age == s.age;}
}
