package game.danos;
import  game.resistencias.Resistencia;


public class DanoGelo extends Dano {     
     private int d;
     public DanoGelo(int v){ d = v;}
     public  int getDano(){ return d;}
     
     public void atenuar(Resistencia r){
         d = r.atenua(this);
     }
}
 
