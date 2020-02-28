public class Luta {
	public Personagem p1,p2;
	
	public Luta(Personagem p1,Personagem p2) {
		this.p1=p1;
		this.p2=p2;
	}
	
	public int ataqueP1(int i) {
		if(i==1) { // p2 escolhe esquivar
			int dano=p1.ataque()-p2.esquivar();
			if(dano<0) {
				dano=0;
			}
			p2.perderVida(dano);
			if(p2.getVida()<0) {
				p2.setVida(0);
			}
			return dano;
		}else {	// p2 escolhe defender
			int dano=p1.ataque()-p2.defesa();
			if(dano<0) {
				dano=0;
			}
			p2.perderVida(dano);
			if(p2.getVida()<0) {
				p2.setVida(0);
			}
			return dano;
		}
	}
	
	public int ataqueP2(int i) {
		if(i==1) {	// p1 escolhe esquivar
			int dano=p2.ataque()-p1.esquivar();
			if(dano<0) {
				dano=0;
			}
			p1.perderVida(dano);
			if(p1.getVida()<0) {
				p1.setVida(0);
			}
			return dano;
		}else {	// p1 escolhe defender
			int dano=p2.ataque()-p1.defesa();
			if(dano<0) {
				dano=0;
			}
			p1.perderVida(dano);
			if(p1.getVida()<0) {
				p1.setVida(0);
			}
			return dano;
		}
	}
	
}
