package game.resistencias;
import game.danos.*;

public class ResistenciaGelo extends Resistencia{

      public ResistenciaGelo(int c, int t){
         super(c,t);
      }

      public int atenua(DanoGelo g){
         return atenuar(g.getDano());
      }

      public String toString(){ return "G("+atenuador()+") "; }

}
