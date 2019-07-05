package game.jogoBase;

import java.util.ArrayList;
import game.comuns.Identificavel;
import game.comuns.ArenaInfo;
import game.celulas.*;
import game.personagens.Personagem;
import game.personagens.Entidade;
import game.personagens.Monster;
import game.acoes.*;
import game.acoes.acoesBatalha.*;
import game.danos.*;
import game.resistencias.*;
import game.gameEvent.*;
import java.util.LinkedList;

class  Arena  {
     private ArrayList<PData> group;
     private ArrayList<PData> mortos;
     private Identidade[]  ids;
     private ArrayList<EntidadeInfo> ltds;
     private int size;
     private int pc;
     private Posicao cell;
    
    
     public Arena(int size, Posicao cell) {
           group = new ArrayList<PData>(size);
           mortos = new ArrayList<PData>(size-1);
           ltds = new ArrayList<EntidadeInfo>(size); 
           pc = 0;
           this.size = size;
           this.cell = cell;
     }

     public void add(PData p){
            if(pc <size){
                 group.add(p);
                 ltds.add( new EntidadeInfo(p.p));
                 pc++;
            }
     }

     public void add(Monster m){
           group.add(new PData(null,m,null) );
           ltds.add( new EntidadeInfo(m));
     }

     private PData buscar(int id){
           for(int i = 0; i < group.size(); i++){
                 if(group.get(i).p.getID() == id){
                        return group.get(i);
                 }
           }
           return null;
     }

     private int buscarPos(int id){
           for(int i = 0; i < group.size(); i++){
                 if(group.get(i).p.getID() == id){
                        return i;
                 }
           }
           return -1;
     }

    private void refreshIds(){
             ids = new Identidade[group.size()];
             for(int i =0; i < group.size(); i++){
                   ids[i] = new Identidade(group.get(i).p.classeDesc(), group.get(i).p.subDesc(), group.get(i).p.getHPMax(),group.get(i).p.getID());
             }
    }
    
    public EntidadeInfo[] lutadores(){
             return ltds.toArray(new EntidadeInfo[ltds.size()]);
    }


    private void removerMorto(int i,LinkedList<GEvent> lst){
         if(group.get(i).e != null){
                mortos.add(group.get(i));
                pc--;
         }
         lst.add(new DeadEvent(group.get(i).p));
         group.remove(i);
    }

    public LinkedList<GEvent> run(){
         AcaoBatalha a;
         PData p;
         PData d;
         PData midleDead;
         int i = 0;
         LinkedList<GEvent> lst = new LinkedList<GEvent>();
         while( i < group.size()){
              d = group.get(i);
              if(d.p.morto()){
                      removerMorto(i,lst);
               }else {
                     midleDead = null;
                     refreshIds();
                     a = d.p.agir(ids);
                     p = buscar(a.getAlvo());
                     if(p != null){
                          Dano dn = a.getDano();
                          if( ((int)(Math.random()*1050)) >= p.p.getEsq() ){
                                  Resistencia r[] = p.p.resitencias();
                                  for(int k =0; k < r.length; k++){
                                           dn.atenuar(r[k]);
                                  }
                                  p.p.danificar(dn.getDano());
                                  if(p.p.morto()){
                                         d.accExpr += p.p.getExp();
                                         midleDead = p;
                                  }
                                  lst.add(new BattleEvent(d.p,dn.getDano(),p.p));
                          }else{
                                 lst.add(new DogeEvent(p.p) );
                          }

                     }
                     if(midleDead != null){
                         int di = buscarPos(midleDead.p.getID());
                         removerMorto(di,lst);
                         if(di > i){
                            i++;
                         }
                     }else{ i++ ;}
               }
         }
         return lst;
    }

    public boolean terminou(){return (pc == 0) || group.size() == 1;}

    public Posicao getCell(){return cell;}

    public PData vencedor(){
         if(pc > 0){ return group.get(0); }
         else{return null;}
    }

    public ArrayList<PData> getMortos(){ return mortos;}

}
