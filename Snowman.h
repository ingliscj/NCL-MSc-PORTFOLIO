package snowman;
import java.awt.*;
import java.awt.event.*;

public class snowman {
    public static void main(String[] args) {
        myFrame s = new myFrame();
        s.setVisible(true);
    } 
}

class myFrame extends Frame {
    int width = 600;
    int height = 600;
    
    public myFrame(){
        
        // Exit Window
        this.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent set){
                System.exit(0);
            }
        });
        
        this.setSize(width, height);
        this.setBackground(new Color(0, 140, 220));
    }
    
    public void paint(Graphics g){
	// brown floor
    g.setColor(new Color(120, 90, 60));
    g.fillRect(0, (height*3/5), width, height*2/5);
        
	// sun
    g.setColor(Color.YELLOW);
    g.fillArc(-60, -5, 150, 150, 270, 90);
    
	// bottom
    g.setColor(Color.WHITE);
    int bottomHeight = 120;
    int bottomWidth = 180;
    int bottomX = width/2 - bottomWidth/2;
    int bottomY = height/2 - 30;
    g.fillOval(bottomX, bottomY, bottomWidth, bottomHeight);
    
	// middle
    g.setColor(Color.WHITE);
    int middleHeight=90;
    int middleWidth=130;
    int middleX = width/2 - middleWidth/2;
    int middleY = bottomY - middleHeight +10;
    g.fillOval(middleX, middleY, middleWidth, middleHeight);
    
	// top
    int topHeight=80;
    int topWidth=80;
    int topX = width/2 - topWidth/2;
    int topY = middleY - topHeight +10;
    g.setColor(Color.WHITE);
    g.fillOval(topX, topY, topWidth, topHeight);
    
	// hat
    g.setColor(Color.BLACK);
    int hatHeight = 60;
    int hatWidth = 50;
    int hatX = width/2 - hatWidth/2;
    int hatY = 70;
    g.fillRect(hatX, hatY, hatWidth, hatHeight);
    	// hat base
    g.fillRect(hatX-10, hatY + hatHeight - 5, hatWidth+20, 5);
    
	// eyes
    int eyeSize = 10;
    g.fillOval(width/2 - topHeight/4, topY + 20, eyeSize, eyeSize);
    g.fillOval(width/2 - topHeight/4 + eyeSize, topY + 20, eyeSize, eyeSize);
    
	// mouth
    g.drawArc(280, 160, 40, 20, 0, -180);
    
    }
}
