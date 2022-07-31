/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaLista;

import java.util.Scanner;

/**
 *
 * @author gusta
 */
public class FilaFromLista {
      
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        // TODO code application logic here
        Fila fil = new Fila();
    
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
        }
    }
}
