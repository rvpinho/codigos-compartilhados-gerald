 package game.gameEvent;

 import game.personagens.Entidade;
 import game.comuns.Direcao;
 import game.celulas.Posicao;

 public class StartBattle extends GEvent{
    
    private Posicao ps;
    public StartBattle (Entidade p,Posicao s){
        super(p);
        ps = s;
    }

    public String toString(){return getNomeAtor() + " iniciou batalha em " + ps.getUID();}

 }
