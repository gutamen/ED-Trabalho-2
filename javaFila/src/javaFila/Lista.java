/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package javaFila;
import java.util.Scanner;
/**
 *
 * @author gusta
 */
public class Lista {
    /**
     * @param args the command line arguments
     */
        //usado para iniciar a lista
    public dataStructLista init;
    
    //construtor da lista
    public void list(){  
        init = null;
    }
   

    //limpar lista
    public boolean isEmpty(){
        return init == null;
    }
    
    //buscar elementos
    public int[] search(int x){
        dataStructLista nodo;
        int i = 0;
        int[] aux = new int[2];
        for(nodo = init; nodo != null; nodo = nodo.getNext()){
            i++;
        }
        //caso encontrar elementos
        if (x == nodo.getVal()){
            aux[1] = 1;
            aux[2] = i;
            return aux;
        }
        aux[1] = 0;
        aux[2] = i;
        return aux;         
    }   

    //insercao de elementos
    public void insertInit(int x){ 
        dataStructLista novoNo = new dataStructLista();
        novoNo.setVal(x);
        //novoNo referencia o inicio antigo
        novoNo.setNext(init);
        // inicio referenciao novoNo 
        init = novoNo;     
    }
    
    //remove elementos do inicio
    public void removeInit(){
        //remove o primiero elemento e reposiciona o o tamanho
        init = init.getNext(); 
    }
    
    //insere no fim
    public void insertFinal(int x){
        dataStructLista ex = new dataStructLista();
        dataStructLista aux1 = new dataStructLista();
        dataStructLista aux = new dataStructLista();
        ex.setVal(x);
        ex.setNext(init);
        init = ex;
        
       
        aux = init;
        aux1 = init;
        int aj, ajd;
        for(ex = init; ex.getNext() != null; ){
            aj = aux.getVal();
            aux1 = aux1.getNext();
            ajd = aux1.getVal();
            ex.setVal(ajd);
            ex = ex.getNext();
            ex.setVal(aj);
            aux = aux.getNext();
        }
    }
    
    //remove no fim
    public void removeFinal(){
        dataStructLista exx = new dataStructLista();
        exx = init;
        if(exx.getNext() == null){
            removeInit();
        }else{
            dataStructLista ex = exx;
            exx = init;
            int i = 0;
            for(ex = init;ex.getNext() != null ; ){
                ex = ex.getNext();
                if(i > 0) exx = exx.getNext();
                i++;
                if(ex.getNext() == null){
                    exx.setNext(null);
                    break;
                }
            }
        }
    }
   
    
    //printar os elemntos da lista
    public String printList(){
        //testar se esta vazia antes de printar
        if(isEmpty()) return "Lista vazia\n"; 
        String str = "Fila :";
        for (dataStructLista nodo = init; nodo != null; nodo = nodo.getNext())
            str += " "+ nodo.getVal();
        return str + "\n";
    }
}