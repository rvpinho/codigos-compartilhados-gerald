package game.resistencias;
import game.danos.*;


public class ResistenciaFogo extends Resistencia {

      public ResistenciaFogo(int c, int t){
         super(c,t);
      }

      public int atenua(DanoFogo g){
         return atenuar(g.getDano());
      }

      public String toString(){ return "F("+atenuador()+") "; }
}
