package game.celulas;

import game.personagens.Personagem;
import game.personagens.Monster;


public class MapaSimplismente extends GMap{


    public MapaSimplismente(){
         super();
         
         Posicao tmp = getCelula(0);
         Posicao tmp2 = new Posicao(new Monster[0], 0);
         tmp.setEsquerda(tmp2);
         add(tmp2);
    }
    
    public void setCelulaInicial(Personagem p, int c){}

}
