package game.resistencias;
import game.danos.*;

public class ResistenciaFisico extends Resistencia {

      public ResistenciaFisico(int c, int t){
          super(c,t);
      }

      public int atenua(DanoFisico g){
         return atenuar(g.getDano());
      }

      public String toString(){ return "I("+atenuador()+") "; }
}
