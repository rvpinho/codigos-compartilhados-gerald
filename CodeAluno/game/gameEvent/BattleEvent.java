 package game.gameEvent;

 import game.personagens.Entidade;

 public class BattleEvent extends GEvent{
    private Entidade alvo;
    private int dano;

    public BattleEvent(Entidade p, int dano, Entidade alvo){
        super(p);
        this.dano = dano;
        this.alvo = alvo;
    }

    public Entidade getAlvo(){return alvo;}
    public int getDano(){return dano;}
    public String toString(){return getNomeAtor() + " atacou " + alvo.getNome() + " com " + dano + " de dano!";}
 }
