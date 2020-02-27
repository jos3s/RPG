import java.util.Random;
import java.util.Scanner;
public class Program {
	public static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args) {
		
		Personagem p1=criarPersonagem();
		System.out.println();
		Personagem p2=criarPersonagem();
		//System.out.println(p1.toString());
		//System.out.println(p2.toString());
		
		Luta l=new Luta(p1,p2);
		Random r= new Random();
		int qAtacar=r.nextInt(2);
		while(p1.getVida()>0 || p2.getVida()>0) {
			if(qAtacar==0) {
				linha();
				System.out.printf("\nO "+p1.getNome()+" vai atacar."+"\nJogador %s escolha 1 para esquivar ou 2 para defender:", p2.getNome());
				int escolha=sc.nextInt();
				int dano=l.ataqueP1(escolha);
				System.out.println("O dano de "+p1.getNome() +" em " +p2.getNome() +" foi de "+dano+" a vida atual de " +p2.getNome()+" é de "+p2.getVida()+"\n");
				if(p2.getVida()<=0) {
					System.out.println("O jogador "+p1.getNome()+" ganhou.");
					break;
				}
				linha();
				System.out.printf("\nO "+p2.getNome()+" vai atacar."+"\nJogador %s escolha 1 para esquivar ou 2 para defender:", p1.getNome());
				escolha=sc.nextInt();
				dano=l.ataqueP2(escolha);
				System.out.println("O dano de "+p2.getNome() +" em " +p1.getNome() +" foi de "+dano+" a vida atual de " +p1.getNome()+" é de "+p1.getVida()+"\n");
				if(p1.getVida()<=0) {
					System.out.println("O jogador "+p2.getNome()+" ganhou.");
					break;
				}
			}else {
				linha();

				System.out.printf("\nO "+p2.getNome()+" vai atacar."+"\nJogador %s escolha 1 para esquivar ou 2 para defender:", p1.getNome());
				int escolha=sc.nextInt();
				int dano=l.ataqueP2(escolha);
				System.out.println("O dano de "+p2.getNome() +" em " +p1.getNome() +" foi de "+dano+" a vida atual de " +p1.getNome()+" é de "+p1.getVida()+"\n");
				if(p1.getVida()<=0) {
					System.out.println("O jogador "+p2.getNome()+" ganhou.");
					break;
				}
				linha();
				System.out.printf("\nO "+p1.getNome()+" vai atacar."+"\nJogador %s escolha 1 para esquivar ou 2 para defender:", p2.getNome());
				escolha=sc.nextInt();
				dano=l.ataqueP1(escolha);
				System.out.println("O dano de "+p1.getNome() +" em " +p2.getNome() +" foi de "+dano+" a vida atual de " +p2.getNome()+" é de "+p2.getVida()+"\n");
				if(p2.getVida()<=0) {
					System.out.println("O jogador "+p1.getNome()+" ganhou.");
					break;
				}
			}
		}
		
		
	}
	
	public static Personagem criarPersonagem() {
		Personagem p;
		String nome;
		int forca,vel,def;
		System.out.println("Digite os dados do jogador:");
		System.out.print("Nome:");
		nome=sc.nextLine();
		System.out.print("Força: ");
		forca=sc.nextInt();
		System.out.print("Velocidade: ");
		vel=sc.nextInt();
		System.out.print("Defesa: ");
		def=sc.nextInt();
		p=new Personagem(nome,vel,forca,def);
		sc.nextLine();
		
		return p;
	}

	public static void linha() {
		System.out.println("-------------------------------------------------------");
	}

}
