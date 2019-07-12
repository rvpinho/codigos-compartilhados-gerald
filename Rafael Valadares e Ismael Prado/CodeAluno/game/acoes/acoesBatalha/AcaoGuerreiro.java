package game.acoes.acoesBatalha;

import game.personagens.Entidade;
import game.danos.Dano;

/** Especificação de ação de batalha.
 *
 */
public abstract class AcaoGuerreiro extends AcaoBatalha {

     public AcaoGuerreiro(Entidade agente, int IDAlvo, int dano ){
           super(agente,IDAlvo, dano);
     }


}
