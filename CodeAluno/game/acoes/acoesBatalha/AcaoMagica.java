package game.acoes.acoesBatalha;

import game.personagens.Entidade;
import game.danos.Dano;

/** Especificação de ação de batalha.
 *
 */
public abstract class AcaoMagica extends AcaoBatalha {
     private int mpCusto;
     
     public AcaoMagica(Entidade agente, int IDAlvo, int dano, int custo ){
           super(agente,IDAlvo, dano);
           mpCusto = custo;
     }
     
    public final int dano(){
           if(getAgente().useMP(mpCusto)){
                 return super.dano();
           }
           else{ return 0;}
     }
    
     public int custoMP(){return mpCusto; }

}
