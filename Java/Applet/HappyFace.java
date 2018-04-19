/*************************************************************************
	> File Name: HappyFace.java
	> Author: GZ
	> Mail: 194463810@qq.com
	> Created Time: 2018年03月29日 星期四 11时27分09秒
 ************************************************************************/
import javax.swing.*;
import java.awt.*;

public class HappyFace extends JApplet{

	public void paint(Graphics canvas){
		canvas.drawOval(100,50,200,200);
		canvas.fillOval(155,100,10,20);
		canvas.fillOval(230,100,10,20);
		canvas.drawArc(155,160,100,50,180,180);
	}
}
