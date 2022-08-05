/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaFila;

import java.util.Scanner;

import javax.swing.border.SoftBevelBorder;

import java.rmi.server.SocketSecurityException;
import java.util.Random;
/**
 *
 * @author gusta
 */


public class FilaFromLista {
    static Random rnd = new Random();
    static int TAM = 5;
    public static void inserInFront(Fila fil){
        for(int i = 0; i < TAM; i++){
            fil.insertInit(rnd.nextInt(1000));
            System.out.print(fil.printList());
        }
    }
    public static void inserInBack(Fila fil){
        for(int i = 0; i < TAM; i++){
            fil.insertFinal(rnd.nextInt(1000));
            System.out.print(fil.printList());
        }
    }

    public static void removeInFront(Fila fil){
        for(int i = 0; i < TAM; i++){
            if(fil.isEmpty())System.out.println("Lista vazia"){break;}else{
                fil.removeInit();
                System.out.print(fil.printList());
            }
        }
    }
    public static void removeInBack(Fila fil){
        for(int i = 0; i < TAM; i++){
            if(fil.isEmpty())System.out.println("Lista vazia"){break;}else{
                fil.removeFinal();
                System.out.print(fil.printList());
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        Fila fil = new Fila();
        System.out.print(fil.printList());
        System.out.println("Foram inseridos pelo inicio "+TAM+" elementos na fila.");
        inserInFront(fil);

        System.out.println("");
        
        System.out.println("Busca o valor 100 na fila");
        int[] a = new int[2];
        a = fil.search(100);
        if(a[1]==0) System.out.println("Valor não encontrado");
        else System.out.println("Valor encontrado na posição "+a[2]);

        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram inseridos pelo final "+TAM+" elementos na fila.");
        inserInBack(fil);

        System.out.println("");
    
        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram inseridos pelo inicio "+TAM+" elementos na fila.");
        inserInFront(fil);

        System.out.println("");    

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram inseridos pelo final "+TAM+" elementos na fila.");
        inserInBack(fil);
       
        //--
        
        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram removidos pelo final "+TAM+" elementos na fila.");
        removeInBack(fil);

        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram removidos pelo inicio "+TAM+" elementos na fila.");
        removeInFront(fil);
       
        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram removidos pelo final "+TAM+" elementos na fila.");
        removeInBack(fil);

        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Foram removidos pelo inicio "+TAM+" elementos na fila.");
        removeInFront(fil);

        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Tenta remover pela frente a fila estando vazia.");
        removeInFront(fil);

        System.out.println("");

        System.out.print("Estado atual, ");
        System.out.print(fil.printList());
        System.out.println("Tenta remover pelo final a fila estando vazia.");
        removeInFront(fil);
        
        //area de teste interativo
        /* 
        boolean para = true;
        while(para){
            int x, escolha;
            System.out.print("Inser 1\nSearch 2\nRemove 3\nPrint 4\nInserir no final 5\nRemove Final 6\nSair 0\n>>");
            escolha = ler.nextInt();
            switch(escolha){
                case 1:
                    System.out.print("Valor = ");
                    x = ler.nextInt();
                    fil.insertInit(x);
                    break;
                case 2:
                    if(fil.isEmpty())System.out.println("Lista vazia");
                    else{
                        System.out.print("Valor search = ");
                        x = ler.nextInt();
                        int[] a = new int[2];
                        a = fil.search(x);
                        if(a[1]==0) System.out.println("Valor não encontrado");
                        else System.out.println("Valor encontrado na posição "+a[2]);
                    }
                    break;
                case 3:
                    if(fil.isEmpty())System.out.println("Lista vazia");else fil.removeInit();
                    break;
                case 4:
                    if(fil.isEmpty())System.out.println("Lista vazia");else System.out.print(fil.printList());
                    break;
                case 5:
                    System.out.print("Valor = ");
                    x = ler.nextInt();
                    fil.insertFinal(x);
                    break;
                case 6:
                    if(fil.isEmpty())System.out.println("Lista vazia");else fil.removeFinal();
                    break;
                case 0:
                    para = false;
                    break;
            }
        }*/
    }
}
