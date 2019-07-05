package game.acoes;
import game.personagens.Entidade;

/** Super classe Acao serve de base para todos os tipos ações dos personagems.
 * 
 */
public abstract class Acao {
     
     private Entidade agente;
     
     public Acao(Entidade agente){
          this.agente = agente;
     }
     
     public Entidade getAgente(){ return agente;}
     
     
}
