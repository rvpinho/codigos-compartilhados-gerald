package game.acoes.acoesBatalha;

import game.personagens.Entidade;
import game.danos.Dano;
import game.acoes.Acao;

/** Especificação de ação de batalha.
 *
 */
public abstract class AcaoBatalha extends Acao {

     private int alvo;
     private int dano;

     public AcaoBatalha(Entidade agente, int IDAlvo, int dano ){
           super(agente);
           alvo = IDAlvo;
           this.dano = Math.min(300,dano);
     }

     public int dano(){
         int ls  = (int)Math.ceil(((double)getAgente().getAtk()/100)*dano);
         double px = Math.abs(0.0017*(100-getAgente().getAtk())*dano);
         int li = Math.max(0,(int)(ls-px));
         return li + (int)(Math.random()*(ls-li));
     }

     public int getAlvo(){ return alvo; }
     public abstract Dano getDano();
}
