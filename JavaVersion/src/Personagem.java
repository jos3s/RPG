import java.util.Random;

public class Personagem {
	private String nome;
	private int vel,forca,def;
	private int vida;
	
	public Personagem(String nome, int vel, int forca, int def) {
		this.setNome(nome);
		this.setVel(vel);
		this.setForca(forca);
		this.setDef(def);
		this.vida=1000;
	}

	public String getNome() {
		return nome;
	}
	protected void setNome(String nome) {
		this.nome = nome;
	}
	public int getVel() {
		return vel;
	}
	protected void setVel(int vel) {
		this.vel = vel;
	}
	public int getForca() {
		return forca;
	}
	protected void setForca(int forca) {
		this.forca = forca;
	}
	public int getDef() {
		return def;
	}
	protected void setDef(int def) {
		this.def = def;
	}
	public int getVida() {
		return vida;
	}
	protected void setVida(int vida) {
		this.vida = vida;
	}

	public void perderVida(int dano) {
		this.setVida(this.getVida()-dano);
	}
	
	public int ataque(){
	    int at=this.forca*(this.vel/2);
	    return at;
	}
	
	public int defesa(){
		Random r= new Random();
	    this.def*=(r.nextInt(2)+1);
	    return this.getDef();
	}
	
	public int esquivar(){
		Random r= new Random();
	    int es= this.vel*((r.nextInt(2)+1)*2);
	    return es;
	 }

	@Override
	public String toString() {
		return "Personagem [Nome=" + nome + ", Velocidade=" + vel + ", Forca=" + forca + ", Defesa=" + def + ", Vida=" + vida
				+ "]";
	}

}
