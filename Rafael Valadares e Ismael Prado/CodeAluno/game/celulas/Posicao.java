package game.celulas;

import game.personagens.Personagem;
import game.personagens.Monster;
import java.util.Random;

public class Posicao implements Celula {

         private int probCombate;
         private Monster[] hab;
         private static Random rg;
         private Posicao[] adjs;
         private int n;
         private boolean b;
         private static int counter;

         public Posicao(Monster p[], int c){
                  hab = p;
                  probCombate = c;
                  if(rg == null ){
                      rg = new Random();
                  }
                  adjs = new Posicao[4];
                  n = counter++;
         }

         public boolean testeBatalha(){
                b = rg.nextInt(100) <  probCombate;
                return b;
         }

         public void setAcima(Posicao p){adjs[0] = p;}
         public void setDireita(Posicao p){adjs[1] = p;}
         public void setAbaixo(Posicao p){adjs[2] = p;}
         public void setEsquerda(Posicao p){adjs[3] = p;}


         public Posicao getAcima(){return adjs[0];}
         public Posicao getDireita(){return adjs[1];}
         public Posicao getAbaixo(){return adjs[2];}
         public Posicao getEsquerda(){return adjs[3];}


         public boolean emBatalha(){ return b; }

         public boolean mvAcima(){ return (adjs[0] != null) && (!adjs[0].emBatalha()); }
         public boolean mvAbaixo(){ return adjs[2] != null && (!adjs[2].emBatalha());}
         public boolean mvEsquerda(){ return adjs[3] != null && (!adjs[3].emBatalha());}
         public boolean mvDireita(){ return adjs[1] != null && (!adjs[1].emBatalha()) ; }
         public int getUID(){ return n;}

         public Monster[] habitantes(){return hab.clone();}
         public int numHabitantes(){return hab.length;} 

         public void fimBatalha(){b = false;}
         public void iniciaBatalha(){b = true;}
}
