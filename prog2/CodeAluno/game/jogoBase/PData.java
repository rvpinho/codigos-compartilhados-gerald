package game.jogoBase;

import game.personagens.Entidade;
import game.celulas.Posicao;

class PData {
         public Object e; /* <-- Essa linha pode ser alterada para conter alguma outra informação necessária. Lebre-se de alterar o construtor também  !*/
         public Entidade p;
         public int accExpr;
         public Posicao pos;
         public boolean moveu;

         public PData(Object e, Entidade p, Posicao pos){ //Pos pos
             this.e = e;
             this.p = p;
             this.pos = pos;
             moveu = false;
         }
}
