 package game.gameEvent;

 import game.personagens.Entidade;

 public class NothingEvent extends GEvent{

    public NothingEvent(Entidade p){super(p);}

    public String toString(){return getNomeAtor() + " não realizou ação!";}

 }
