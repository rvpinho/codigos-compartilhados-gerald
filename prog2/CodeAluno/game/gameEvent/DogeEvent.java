 package game.gameEvent;

 import game.personagens.Entidade;

  public class DogeEvent extends GEvent{
       public DogeEvent(Entidade p){super(p);}
       public String toString(){return getNomeAtor() + " Esquivou de ataque.";}
  }
