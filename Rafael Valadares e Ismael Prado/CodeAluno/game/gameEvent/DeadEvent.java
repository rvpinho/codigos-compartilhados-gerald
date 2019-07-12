 package game.gameEvent;

 import game.personagens.Entidade;

 public class DeadEvent extends GEvent{
    public DeadEvent(Entidade p){super(p);}
    public String toString(){return getNomeAtor() + " está morto!";}
 }
