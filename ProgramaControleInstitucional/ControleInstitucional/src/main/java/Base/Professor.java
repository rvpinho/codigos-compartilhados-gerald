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
public class Professor {
    
    public static ArrayList<Professor> professor = new ArrayList<Professor>();
    private int ID;
    private String nome;
    private String disciplina;
    

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDisciplina() {
        return disciplina;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

  

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    private final ArrayList<Integer> turma = new ArrayList<>();
    private String email;
    
}
