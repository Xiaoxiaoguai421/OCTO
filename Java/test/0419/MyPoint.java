/*************************************************************************
    > File Name: MyPoint.java
    > Author: GZ
    > Mail: 194463810@qq.com
    > Created Time: 2018年04月19日 星期四 10时34分48秒
 ************************************************************************/

public class MyPoint {

	private int x;
	private int y;

	public MyPoint() {
		this.x = 0;
		this.y = 0;
	}

	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public float getD( final MyPoint p1, final MyPoint p2) {
		return (float)Math.sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
	}
}
