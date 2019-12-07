/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Base;

import java.util.ArrayList;

/**
 *
 * @author Rafael
 */
public class Turma {
    
    private int ID; 
    private ArrayList<Materia> materia = new ArrayList<>();
  
    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }
    
    public ArrayList<Materia>  getmateria() {
        return materia;
    }

    public void setmateria(ArrayList<Materia> materia) {
        this.materia = materia;
    }

    public Turma(int ID,ArrayList<Materia> materia) {
        this.ID = ID;
        this.materia = materia;
    }
}

