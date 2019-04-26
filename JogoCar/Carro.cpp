#include "Carro.h"

Carro::Carro()
{	
	//Inicializando variáveis.
	this->x = 400;
	this->y = 300;

}
Carro::~Carro()
{
}

void Carro::move(int dx, int dy, float dir2)
{
	this->x = dx;
	this->y = dy;
	this->dir = dir2;

	
	if (gTeclado.segurando[TECLA_W])
	{
		y -= 1;
		dir = 3;
		car.setAnimacao(0, false);
		setRot(0);

		mov = true;
			
	}
	if (gTeclado.segurando[TECLA_S])
	{
		y += 1;
		dir = 0;
		car.setAnimacao(2, false);
		setRot(0);

		mov = true;
	}
	if (gTeclado.segurando[TECLA_D])
	{
		x += 1;
		dir = 1;
		car.setAnimacao(3, false);
		mov = true;
		if (gTeclado.segurando[TECLA_D] && gTeclado.segurando[TECLA_S])
		{				
			setRot(50);
			dir = 1 - 0.5; //Dir. inferior
			
		}
		else if (gTeclado.segurando[TECLA_D] && gTeclado.segurando[TECLA_W])
		{
			
			setRot(-50);//-50
			dir = 1 + 0.5; //Dir. superior
			
		}
		else
		{
			setRot(0);
			
		}		
		
	}
	if (gTeclado.segurando[TECLA_A])
	{
		x -= 1;
		dir = 2;
		car.setAnimacao(1, false);
		mov = true;
		
		if (gTeclado.segurando[TECLA_A] && gTeclado.segurando[TECLA_S])
		{  
			
			setRot(-50);   //-50
			dir = 2 - 0.5; //Esq. inferior
			
		}
		else if (gTeclado.segurando[TECLA_A] && gTeclado.segurando[TECLA_W])
		{
			
			setRot(50);	//50
			dir = 2 + 0.5; //Esq. superior
			
		}
		else
		{
			setRot(0);
			
		}	
		
	}	
	
	if (!gTeclado.segurando[TECLA_S] && !gTeclado.segurando[TECLA_D] && !gTeclado.segurando[TECLA_W] && !gTeclado.segurando[TECLA_A] && getSpeed() == 0)
	{
		
		//setar animação para carro parado.
	}

	car.avancarAnimacao();
	
}

bool Carro::isMovendo()
{	
	return mov;
}

int Carro::getX()
{
	return x;
}

int Carro::getY()
{
	return y;
}

void Carro::draw()
{
	car.desenhar(x, y, getRot());	
}

void Carro::update()
{
	this->move(x, y, dir);
	especialAtk();
}

void Carro::especialAtk()
{
	if (gTeclado.segurando[TECLA_ESPACO])
	{			
		gGraficos.desenharTexto("PADRÃO!", getX(), getY(), 255, 255, 255, 255);
	}
}


void Carro::setSpriteSheet(std::string Sprite)
{
	car.setSpriteSheet(Sprite);
    setSprite(&car); 	
	
}

void Carro::setSpeed(float speed2)
{
	speed = speed2;
	speed = 1;		

}

void Carro::setSoundCar(std::string i)
{

	somCarro = i;

	somCarro = "eqParado";
		
}

Sprite Carro::getSprite()
{
	return car;
}

float Carro::getDir()
{
	return dir;
}

float Carro::getSpeed()
{
	return speed;
}

std::string Carro::getSomCarro()
{
	
	return somCarro;
}
