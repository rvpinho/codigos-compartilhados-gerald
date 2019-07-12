 package game.gameEvent;

 import game.personagens.Entidade;

 public abstract class GEvent{
    private Entidade p;

    public GEvent(Entidade p){this.p=p;}

    public Entidade getAtor(){return p;}

    public String getNomeAtor(){return p.getNome();}

 }
