 package game.gameEvent;

 import game.personagens.Entidade;
 import game.comuns.Direcao;
 import game.celulas.Posicao;

 public class EndBattle extends GEvent{
    
    private Posicao ps;
    public EndBattle(Posicao s){
        super(null);
        ps = s;
    }

    public String toString(){return "A arena de batalha em " + ps.getUID() + " terminou";}

 }
