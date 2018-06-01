/********************************************************************************
    > File Name: Grade.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年05月31日 星期四 10时46分27秒
********************************************************************************/

public class Grade {

    public static void main(String[] args) {
        try {
/*
            //查看命令行参数
            for (int i = 0; i < args.length; i++)
                System.out.print(args[i] + " ");
            System.out.println();
*/
            //检查人为定义的异常
            if (args.length < 10) {
                throw new Exception("请输入至少10个成绩");
            }

            //数据类型异常
            int[] student_grade = new int[args.length];
            for (int i = 0; i < args.length; i++) {
                student_grade[i] = Integer.parseInt(args[i]);
            }

            bubble_sort(student_grade);

            for (int i = 0; i < student_grade.length; i++)
                System.out.println(student_grade[i]);

        } catch (NumberFormatException nfx) {
            System.out.println("请输入成绩");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public static void bubble_sort(int[] array) {
        boolean flag = false;
        for (int i = 0; i < array.length - 1; i++) {
            flag = true;
            for (int j = array.length - 1; j > i ; j--)
                if (array[j - 1] < array[j]) {
                    swap(array, j - 1, j );
                    flag = false;
                }
            if (flag == true)
                break;
        }
    }

    //Java不支持对普通类型的引用使用，传参时使用类，或传数组
    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
