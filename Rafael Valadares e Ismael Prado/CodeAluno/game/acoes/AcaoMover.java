package game.acoes;

import game.personagens.Personagem;
import game.comuns.Direcao;

/** Especificação para ação de movimento.
 * 
 */

public class AcaoMover extends Acao{
     
     private Direcao d;
     
     public AcaoMover(Personagem a,Direcao d ){
          super(a);
          this.d = d;
     }
     
     public Direcao getDirecao(){return d;} 

}
