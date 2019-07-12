package game.comuns;

/**
 * Os métodos comuns a entidades Indentificaveis no jogo. Um Identificavel 
 * é qualquer elemento do jogo que pode ser sondado por dados de identificação e por
 * por HP.
 */

public interface Identificavel {
     
     public char descClasse();
     public char[] descEspefica(); 
     public char[] getDesc();
     
     public int getHP();
     public int id();
}
