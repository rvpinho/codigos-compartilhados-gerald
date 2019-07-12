package game.exceptions;

public class InvalidPersonageException extends Exception {
      public InvalidPersonageException(String nome){
         super("Tentativa de criar um jogador inválido\n.O Jogador "+ nome + " contém um controlador de experiência clandestino");
      }
}
