package game.resistencias;
import game.danos.*;
import game.comuns.StatusControle;

public abstract class Resistencia {
      private int c,t;      
      private StatusControle ec;

      public Resistencia(int c, int t){ 
              this.c = c;
              this.t = t;
      }
      protected int atenuador(){
  	  	    return (int)(c*(1 - (float)Math.exp(-((double)ec.getExp()/t))));
      }
      
      protected int atenuar(int x){ 
    	  return (int)(((double)100/(double)(100+atenuador()))*((double)x));}
      
      public int atenua(DanoFisico d){ return d.getDano() ;}
      public int atenua(DanoFogo d){return d.getDano();}
      public int atenua(DanoGelo d){return d.getDano();}
      
      public void setExpControle(StatusControle ec){ this.ec = ec;}
      
      
}
