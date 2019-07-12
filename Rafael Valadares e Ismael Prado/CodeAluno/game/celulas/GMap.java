package game.celulas;

import game.personagens.Personagem;
import java.util.*;
import game.personagens.*;

public class GMap {

    private HashMap<Personagem,Posicao> locs;
    private ArrayList<Posicao> cs;
    
    public GMap(){
         cs = new ArrayList<Posicao>();
         locs = null;
         cs.add(new Posicao(null,0));
    }
    
    public GMap(Personagem p[]){
         cs = new ArrayList<Posicao>();
         locs = new HashMap<Personagem, Posicao>();
         Posicao ps;
         for(int i =0; i < p.length; i++){ 
              ps = new Posicao(null,0);
              locs.put(p[i],ps);
              cs.add(ps);
         }
    }
    
    public GMap(int k){
         cs = new ArrayList<Posicao>();
         locs = new HashMap<Personagem, Posicao>(k);
         Posicao ps;
         for(int i =0; i < k; i++){ 
              ps = new Posicao(null,0);
              cs.add(ps);
         }
    }
    
    public void setCelulaInicial(Personagem p, int c){
          Posicao ps = cs.get(c);
          if(ps != null){
              locs.put(p,ps);
          }
    }
    
    public Posicao celulaInicial(Personagem p){
         if(locs == null){
             return cs.get(0);
         }
         else{
             return locs.get(p);
         }
    }
    
    public void add(Posicao p){
        cs.add(p);
    }
    public void addAcima (int i, Posicao p)   { cs.get(i).setAcima(p);   }
    public void addAbaixo (int i, Posicao p)  { cs.get(i).setAbaixo(p);  }
    public void addEsquerda (int i, Posicao p){ cs.get(i).setEsquerda(p);}
    public void addDireita (int i, Posicao p) { cs.get(i).setDireita(p); }
    
    public Posicao getCelula(int i){ return cs.get(i);}
    
    
}
