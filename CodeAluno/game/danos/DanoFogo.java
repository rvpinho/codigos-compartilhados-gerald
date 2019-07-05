package game.danos;
import  game.resistencias.Resistencia;


public class DanoFogo extends Dano {     
     private int d;
     public DanoFogo(int v){ d = v;}
     public  int getDano(){ return d;}
     
     public void atenuar(Resistencia r){
         d = r.atenua(this);
     }
}
 
