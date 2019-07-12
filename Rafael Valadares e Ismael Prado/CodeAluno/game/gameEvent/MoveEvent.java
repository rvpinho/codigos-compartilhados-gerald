 package game.gameEvent;

 import game.personagens.Entidade;
 import game.comuns.Direcao;

 public class MoveEvent extends GEvent{
    private Direcao d;

    public MoveEvent(Entidade p, Direcao d){
        super(p);
        this.d=d;
    }

    public Direcao getDirecao(){return d;}

    public String toString(){return getNomeAtor() + " moveu para " + d + "!";}

 }
