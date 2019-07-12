package game.jogoBase;

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.util.Map.Entry;
import game.acoes.*;
import game.comuns.StatusControle;
import game.personagens.Personagem;
import game.personagens.Monster;
import game.personagens.Entidade;
import game.exceptions.*;
import game.celulas.Celula;
import game.celulas.Posicao;
import game.gameEvent.*;
import game.comuns.Direcao;
import game.comuns.ArenaInfo;
import game.celulas.GMap;


/** Classe base para maquina de Jogo.
 * Essa classe deve ser usada para gerir as arenas de batalhas, personagens e ações de personagens.
 * A máquina de jogo deve realizar um único turno por vez, quando invocado o método turno. Ao final de cada
 * turno deve-se produzir uma lista de eventos que relatam as açoes realizadas por cada personagem.
 */
public class Maquina {

    
     private ArrayList<PData> prs;
     private ArrayList<Arena> arenas;
     private GMap m;
     private HashMap<Posicao,LinkedList<PData>> arenasPendentes;
     private Experi eMaquina;

    /** Constrói a máquina de jogo com base um Mapa.
     *  O mapa é usado para atribulir um local a cada personagem.
     */
     public Experi criarStatusControle(){
         Experi EM = new Experi();
         return EM;
     }
     
     public void receberE(){
         eMaquina = criarStatusControle()
     }

     public boolean verificarE(Personagem p){
         return p.secCheck((StatusControle)eMaquina);
    }
     
     
     
     
     
     
     
     public Maquina(GMap m){
         prs = new ArrayList<PData>(10);
         
         this.m = m;
         prs = new ArrayList<PData>();
         arenas = new ArrayList<Arena>();
         arenasPendentes = new HashMap<Posicao,LinkedList<PData>>();
     }
     

     
     public void add(Personagem p) throws InvalidPersonageException {
     
     }

     public LinkedList<GEvent> turno(){

         AcaoMover m;
         LinkedList<GEvent> eventos = new LinkedList<GEvent>();
         arenasPendentes.clear();
         for(Arena a : arenas){
               eventos.addAll(a.run());
         }

         for(PData pd : prs){
               m = pd.p.mover();
               if(m != null){
                   eventos.add(atualizaLocal(pd, m));
               }
         }
         checarBatalha(eventos);
         checarFimArena(eventos);
         return eventos;
     }


     private void tracePos( Posicao p, PData g){
            LinkedList<PData> x = arenasPendentes.get(p);
            if(x != null){
                 x.add(g);
            }else{
                x = new  LinkedList<PData>();
                x.add(g);
                arenasPendentes.put(p,x);
            }
     }
     
     public ArenaInfo[] arenas(){
             ArenaInform ai[] = new ArenaInform[arenas.size()];
             int i = 0;
             for(Arena a :arenas){
                  ai[i] = new ArenaInform(a);
                  i++;
             }
             return ai;
     }

     private GEvent atualizaLocal(PData p, AcaoMover m){
            switch( m.getDirecao() ){
               case ACIMA:
                    if(p.pos.mvAcima()){
                        p.pos = p.pos.getAcima();
                        p.p.updatePos(p.pos);
                        tracePos(p.pos,p);
                        return new MoveEvent(p.p, Direcao.ACIMA);
                    }
                    break;
               case ABAIXO:
                    if(p.pos.mvAbaixo()){
                        p.p.updatePos(p.pos.getAbaixo());
                        p.pos = p.pos.getAbaixo();
                        tracePos(p.pos,p);
                        return new MoveEvent(p.p, Direcao.ABAIXO);
                    }
                    break;
               case ESQUERDA:
                    if(p.pos.mvEsquerda()){
                        p.p.updatePos(p.pos.getEsquerda());
                        p.pos= p.pos.getEsquerda();
                        tracePos(p.pos,p);
                        return new MoveEvent(p.p, Direcao.ESQUERDA);
                    }
                    break;
               case DIREITA:
                    if(p.pos.mvDireita()){
                        p.p.updatePos(p.pos.getEsquerda());
                         p.pos = p.pos.getEsquerda();
                         tracePos(p.pos,p);
                        return new MoveEvent(p.p, Direcao.DIREITA);
                    }
                    break;
            }
            return new NothingEvent(p.p);
     }

    private void transferMonster(Posicao p, Arena a){
         Monster h[] =  p.habitantes();
         for(int i = 0; i < h.length; i++){
                a.add(h[i]);
         }
    }
    
   private void pegos(Posicao p, Arena a){
         int i = 0;
         while(i < prs.size()){
            if(prs.get(i).pos == p){
                a.add(prs.get(i));
                prs.remove(i);
            }else{i++;}
         }
   
   }

    private void checarBatalha(LinkedList<GEvent> lst){
              Set<Entry<Posicao,LinkedList<PData>>> s = arenasPendentes.entrySet();
              for(Entry<Posicao, LinkedList<PData>> e : s){
                        if(e.getValue().size() > 1){
                              Arena a = new Arena( e.getKey().numHabitantes() + e.getValue().size(), e.getKey()  );
                              LinkedList<PData> lpd =  e.getValue();
                              for(PData d : lpd ){
                                     a.add(d);
                                     prs.remove(d);
                              }
                              pegos(e.getKey(),a);
                              transferMonster(e.getKey(), a);
                              arenas.add(a);
                              e.getKey().iniciaBatalha();
                              lst.add(new StartBattle(e.getValue().getFirst().p, e.getKey()));
                        }else if (e.getValue().size() == 1){
                              if(e.getKey().testeBatalha()){
                                     Arena a = new Arena( e.getKey().numHabitantes()+1, e.getKey()  );
                                     a.add(e.getValue().getFirst());
                                     prs.remove(e.getValue().getFirst());
                                     pegos(e.getKey(),a);
                                     transferMonster(e.getKey(), a);
                                     arenas.add(a);
                                     lst.add(new StartBattle(e.getValue().getFirst().p, e.getKey()));
                              }
                        }
              }
     }

     private void checarFimArena(LinkedList<GEvent> lst){
        int i = 0;
        while(i<arenas.size()){
           if(arenas.get(i).terminou()){
              if(arenas.get(i).vencedor() != null){
                  PData v = arenas.get(i).vencedor();
                  prs.add(v);         
                  //----------------
                  //  Implmentar o ganho de experiência aqui.
                  //----------------
                   v.accExpr = 0;
              }
              if(arenas.get(i).getMortos().size() > 0 ){
                  coronte(arenas.get(i).getMortos());
              }
              lst.add(new EndBattle(arenas.get(i).getCell()));
              arenas.get(i).getCell().fimBatalha();
              arenas.remove(i);

           }else{i++;}
        }
     }

     public boolean acabou(){
           return prs.size() <= 1 && arenas.size() == 0;
     }
     /** Implementa a política de reintegração de personagens mortos.
      *  Por padrão os personagens mortos são excluídos do jogo. Sobreescreva este método se você
      * deseja customizar esse comportamento.
      * @param mortos: O vetor de personagens derrotados;
      */
     public void coronte(ArrayList<PData> mortos){}
}
