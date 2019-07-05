package game;

import game.comuns.*;
import game.personagens.*;
import game.jogoBase.*;
import game.exceptions.*;
import game.gameEvent.*;
import java.util.LinkedList;
import java.util.Scanner;

import game.celulas.*;


public class Main  {
     public static void  main(String args[]) throws Exception {
        GMap map = new MapaSimplismente();
        Maquina m = new Maquina(map);
        /*
         * Prepare o jogo aqui
         *
         */
        LinkedList<GEvent> eventos = new LinkedList<GEvent>();
        int rod = 0;
        while(!m.acabou()){
           System.out.println("------------------ Turno("+ rod +")------------------ ");
           eventos = m.turno();
           for(GEvent e : eventos){
              System.out.println(e);
           }
          String sep = "     ";
           for(ArenaInfo ai : m.arenas()){
                    System.out.println(sep + "[" + ai.getCellID() + "]");
                    for(StatsInfo s: ai.getEntidades()){
                               System.out.println(sep + "   > " + s.statsStr());
                    }
           }
           rod++;
           System.out.println("------------------------------------------- ");
        }
        System.out.println("Quantidade de rodadas : " + rod);
     }
}
