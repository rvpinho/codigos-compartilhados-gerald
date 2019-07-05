package game.jogoBase; 

import game.comuns.Identificavel;

class Identidade implements Identificavel {
     
     private char classe;
     private char[] descEsp;
     private int id;
     private int hp;
     
     public Identidade(char c, char[] d, int hp, int i) {
           classe = c;
           descEsp = d;
           this.hp = hp;
           id = i;
     }
     
     public char descClasse(){ return classe;}
     
     public char[] descEspefica(){return descEsp;}
     
     public char[] getDesc(){ 
          char v[] = new char[descEsp.length+1];
          for(int i =1;i<descEsp.length; i++){ v[i] = descEsp[i-1]; }
          v[0] = classe;
          return v;
     }
     
     public int getHP(){return hp;}
     
     public int id(){return id;}
}
