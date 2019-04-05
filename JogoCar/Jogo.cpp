#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	
	gRecursos.carregarSpriteSheet("car_red", "assets/spritesheets/car_red.png", 4, 1);

	
	p1->setSpriteSheet("car_red");


	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		p1->draw();
		p1->update();
		
		//	Seu código vem aqui!
		//	...

		uniTerminarFrame();
	}
}