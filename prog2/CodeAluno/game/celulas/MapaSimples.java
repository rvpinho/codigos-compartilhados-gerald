package game.celulas;

import game.personagens.Personagem;
import game.personagens.Monster;
import game.personagens.Goblin;
import java.util.*;
import game.personagens.*;

public class MapaTorneio extends GMap{

  /** Essa classe cria um mapa de torneio para n competidores, cada um dos quais possui uma trilha de comprimento k.  
    * Cada uma das trilhas é composta por k células e é completamente independente das demais. Em cada célula o jogado pode se mover apena para cima. 
    * Em cada trilha,  após a k-ésima célula há uma célula (comum a todas as trilhas) que contém  um boss (um monstro com muita experiência !).
    * Em cada célula haverá z monstros inimigos.
    *Exemplo de uso: Um mapa para 3 personagens (com 3 trilhas),onde cada célula tem 2 inimigos, cada trilha tem 4 células, mais a célula do chefe:
    * MapaTorneio t = new MapaTorneio(3,4,2);
    *
    */
    public MapaTorneio(int n, int k,int z){
         super(n);
         Posicao[] ps = new Posicao[n];
         Posicao tmp;
         for(int i =0; i < n; i++){
              ps[i] = getCelula(i);
         }
         for(int i =1; i< k; i++){
             for(int j = 0; j < n; j++){
                 Monster[] grupo = new Monster[z];
                 for(int q=0;q<z;q++){grupo[q] = mkMinions(10+(int)Math.pow(i,2) );}
                 tmp = new Posicao(grupo,90);
                 ps[j].setAcima(tmp);
                 ps[j] = tmp;
                 add(tmp);
             }
         }
         tmp = new Posicao(new Monster[]{mkBoss(1000)},100);
         for(int j = 0; j < ps.length; j++){
             ps[j].setAcima(tmp);
         }
    }
    
    private Monster mkMinions(int expr){
    
       /**
       * Crie seus monstros aqui !
       */
        return null;
    }
    
    public Monster mkBoss(int expr){
        /**
       * Crie o monstro  chefe aqui !
       */
       return null;
    }
    

}