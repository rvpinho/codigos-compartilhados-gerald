package game.danos;
import game.resistencias.Resistencia;

public abstract class Dano {     
     public abstract int getDano();
     public abstract void atenuar(Resistencia r);
}
