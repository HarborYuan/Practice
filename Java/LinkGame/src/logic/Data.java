package logic;
import java.util.Random;

public class Data {
	public int map[][];
	public int m,n;
	
	public boolean JudgeCol(int x1, int x2,int y) {
		for (int i=Math.min(x1,x2)+1;i<Math.max(x1,x2);i++) {
			if (this.map[i][y]!=0)
				return false;
		}
		if (this.map[x1][y]!=this.map[x2][y]&&this.map[x1][y]!=0&&this.map[x2][y]!=0) {
			return false;
		}
		return true;
	}
	
	public boolean JudgeRow(int y1,int y2, int x) {
		for (int i=Math.min(y1,y2)+1;i<Math.max(y1,y2);i++) {
			if (this.map[x][i]!=0)
				return false;
		}
		if (this.map[x][y1]!=this.map[x][y2]&&this.map[x][y1]!=0&&this.map[x][y2]!=0) {
			return false;
		}
		return true;
	}
	
	public boolean JudgeOneTurn(int x1, int y1, int x2, int y2) {
		return ((JudgeRow(y1,y2,x1)&&JudgeCol(x1,x2,y2))||(JudgeRow(y1,y2,x2)&&JudgeCol(x1,x2,y1)));
	}
	
	public boolean Judge(int x1, int y1, int x2, int y2) {
		for (int i = 0;i <= this.m+1; i++) {
			if ((this.map[i][y1]==0||i==x1)&&JudgeCol(i,x1,y1)&&JudgeOneTurn(i,y1,x2,y2)) {
				return true;
			}
		}
		
		for (int i = 0;i <= this.n+1; i++) {
			if ((this.map[x1][i]==0||i==y1)&&JudgeRow(i,y1,x1)&&JudgeOneTurn(x1,i,x2,y2)) {
				return true;
			}
		}
		
		return false;
	}
	
	public void change() {
		System.out.println("ÖØÅÅÁÐ£¡");
		Random random = new Random();
		int x1,y1;
		int x2,y2;
		x1= random.nextInt(m)+1;
		y1= random.nextInt(n)+1;
		x2= random.nextInt(m)+1;
		y2= random.nextInt(n)+1;
		int tmp = this.map[x1][y1];
		this.map[x1][y1] = this.map[x2][y2];
		this.map[x2][y2] = tmp;
	}
	
	public boolean JudgeStatus() {
		do {
			boolean Zero = true;
			for (int i = 1;i <= this.m; i++) {
				for (int j = 1;j <=this.n; j++) {
					if (this.map[i][j]!=0) {
						Zero = false;
						for (int k = 1 ; k <= this.m; k++) {
							for (int l = 1; l <= this.n; l++) {
								if ((!(i==k&&j==l))&&this.map[i][j]==this.map[k][l]&&Judge(i,j,k,l)) {
									return false;
								}
							}
						}
					}
				}
			}
			if (Zero) {
				return true;
			}
			this.change();
		}while (true);
	}
	
	public Data(int m,int n) {
		this.m=m;
		this.n=n;
		this.map = new int[m+2][n+2];
		Random random = new Random();
		for (int i=0;i<=m+1;i++)
			for (int j=0;j<=n+1;j++)
				this.map[i][j] = 0;
		int tmp = m*n;
		int now=0;
		int x1,y1;
		int x2,y2;
		while (tmp>0){
			x1= random.nextInt(m)+1;
			y1= random.nextInt(n)+1;
			if (this.map[x1][y1]!=0)
				continue;
			this.map[x1][y1]=now+1;
			do {
			x2= random.nextInt(m)+1;
			y2= random.nextInt(n)+1;
			}while (this.map[x2][y2]!=0);
			this.map[x2][y2]=now+1;
			tmp-=2;
			now=(now+1) % 10;
		}
	}
}
