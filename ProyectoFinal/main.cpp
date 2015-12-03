#include <allegro.h>
#include <cstdlib>

#define MAXFILAS 20
#define MAXCOLS 32

BITMAP *vid;
BITMAP *vidas;
BITMAP *combmp;
BITMAP *complemento;
BITMAP *buffer;
BITMAP *roca;
BITMAP *pacbmp;
BITMAP *pacman;
BITMAP *comida;
BITMAP *muertebmp;
BITMAP *ataqueb;
BITMAP *atabmp;
SAMPLE *intro;
SAMPLE *sirenafantasma;
SAMPLE *muertes;

int z=0;
int vida=3;
int dir=4;
int px=30*1,py=30*1;
int ax, ay;
int anteriorpx,anteriorpy;
int dd;
int _ax,_ay;
int anterior_x,anterior_y;

char m[MAXFILAS][MAXCOLS] ={
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
     "X    |     |XXXXX|     |    X",
     "X XXX XXXXX       XXXXX XXX X",
     "X XXX XXXXX XXXXX XXXXX XXX X",
     "X    |  |     O     |  |    X",
     "X XXX XX XXXXXXXXXXX XX XXX X",
     "X    |XX     XXX     XX|    X",
     "X XXX XXXXXX XXX XXXXXX XXX X",
     "X XXX XX    |   |    XX XXX XX",
     " |   |   XXXXXXXXXXX XX|   | ",
     "X XXX XX XXXXXXXXXXX    XXX XX",
     "X XXX XX    |   |    XX XXX X",
     "X XXX XX XXX XXX XXX XX XXX X",
     "X    |XX     XXX     XX|    X",
     "X XXX XX XXXXXXXXXXX XX XXX X",
     "X XXX|  |     O     |  |XXX X",
     "X XXX XXXX XXXXXXXX XXX XXX X",
     "X XXX XXXX          XXX XXX X",
     "X    |     XXXXXXXX    |    X",
     "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",

};

class mapa1
{
    public:
     void pantalla();
     void dibujar_mapa();
     bool game_over();
private:
};
void mapa1::dibujar_mapa()
{
    int row,col;
    for(row = 0; row < MAXFILAS; row ++)
    {
        for(col = 0; col <MAXCOLS; col++)
        {
            if(m[row][col] == 'X')
            {
                draw_sprite(buffer, roca , col*30 , row*30); //escala de 30 a 1 por eso se multiplica por 30
            }
            else if(m[row][col] == 'O')
            {
                draw_sprite(buffer, comida , col*30 , row*30); //escala de 30 a 1 por eso se multiplica por 30                if(py/30 == row && px/30 == col)
                {
                    m[row][col] = ' ';
                    z++;
                }
            }
        }
    }
    blit(combmp,complemento,0,0,0,0,400,600);
    draw_sprite(buffer,complemento,880,0);



    for(int i=0; i<vida; i++)
    {
        int m=33*i;
        blit(vidas,vid,0,0,0,0,33,33);
        draw_sprite(buffer,vid,1054+m,184);
    }

}
void mapa1::pantalla()
{
    blit(buffer, screen ,0,0,0,0,1280,600);

};
bool mapa1::game_over()
{
    if(vida!=0)
    {
        return true;
    }
    return false;
}

class personaje1
{
    public:
        void mover_personaje();
        void dibujar_personaje();
        void ataque();
        void ataque1();
        int a=0;
        int d;
    private:
};

void personaje1::dibujar_personaje()
{
    blit(pacbmp,pacman,0,dir*33,0,0,33,33);
    draw_sprite(buffer,pacman,px,py);
}
void personaje1::ataque()
{
    if(key[KEY_X] && a==0)
    {
        ax=px;
        ay=py;
        d=dir;
    }
}
void personaje1::ataque1()
{
    if(d == 3)
    {
        if (m[ay/30][(ax-30)/30] != 'X')
        {
            ax -= 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,ax,ay);
            a=1;
        }
        if (m[ay/30][(ax-30)/30] == 'X')
        {
            a=0;
            ay=0;
        }
    }
    if(d == 1)
    {
        if (m[ay/30][(ax+30)/30] != 'X')
        {
            ax += 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,ax,ay);
            a=1;
        }
        if (m[ay/30][(ax+30)/30] == 'X')
        {
            a=0;
            ay=0;
        }
    }    if(d == 0)
    {
        if (m[(ay-30)/30][ax/30] != 'X')
        {
            ay -= 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,ax,ay);
            a=1;
        }
        if (m[(ay-30)/30][ax/30] == 'X')
        {
            a=0;
            ax=0;
        }
    }    if(d == 2)
    {
        if (m[(ay+30)/30][ax/30] != 'X')
        {
            ay += 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,ax,ay);
            a=1;
        }
        if (m[(ay+30)/30][ax/30] == 'X')
        {
            a=0;
            ax=0;
        }
    }

}
void personaje1::mover_personaje()
{

    anteriorpx = px;
    anteriorpy = py;

        if(key[KEY_RIGHT])dir = 1;
        else if(key[KEY_LEFT])dir = 3;        else if(key[KEY_UP])dir = 0;        else if(key[KEY_DOWN])dir = 2;

        if(dir == 3)
        {
            if (m[py/30][(px-30)/30] != 'X')
                px -= 30;
            else dir = 4;
        }
        if(dir == 1)
        {
            if (m[py/30][(px+30)/30] != 'X')
                px += 30;
            else dir = 4;
        }        if(dir == 0)
        {
            if (m[(py-30)/30][px/30] != 'X')
                py -= 30;
            else dir = 4;
        }        if(dir == 2)
        {
            if (m[(py+30)/30][px/30] != 'X')
                py += 30;
            else dir = 4;
        }
        if(dir == 4)
        {
            blit(pacbmp,pacman,0,2*33,0,0,33,33);
        }        //rutina para atajo
        if(px <= -30) px = 840;
        else if(px >840) px=-30;

        clear(buffer);
}

class personaje2 : public personaje1
{
public:

     int _px=30*1, _py=30*1;
     void mover_personaje();
     void dibujar_personaje();
     void ataque();
     void ataque1();
};


void personaje2::mover_personaje()
{
    if(m[_py/30][_px/30]=='|')
    {
        dd = rand()%3;
    }

    if(dd == 3)
    {
        if(m[_py/30][(_px-30)/30] != 'X') _px-=30;
        else dd =rand()%3;
    }
    if(dd == 1)
    {
        if(m[_py/30][(_px+30)/30] != 'X') _px+=30;
        else dd =rand()%3;
    }
    if(dd == 0)
    {
        if(m[(_py-30)/30][_px/30] != 'X') _py-=30;
        else dd =rand()%3;
    }
    if(dd == 2)
    {
        if(m[(_py+30)/30][_px/30] != 'X') _py+=30;
        else dd =rand()%3;
    }
        //rutina
    if(_px <= -30) _px =870;
        else if(_px>= 870) _px =-30;
}
void personaje2::dibujar_personaje()
{
    if (z==2)
    {
        blit(pacbmp,pacman,0,dd*33,0,0,33,33);
        draw_sprite(buffer,pacman,_px,_py);
    }
}
void personaje2::ataque()
{
    if(key[KEY_X] && a==0 && z==2)
    {
        _ax=_px;
        _ay=_py;
        d=dd;
    }
}
void personaje2::ataque1()
{
    if(d == 3)
    {
        if (m[_ay/30][(_ax-30)/30] != 'X')
        {
            _ax -= 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,_ax,_ay);
            a=1;
        }
        if (m[_ay/30][(_ax-30)/30] == 'X')
        {
            a=0;
            _ay=0;
        }
    }
    if(d == 1)
    {
        if (m[_ay/30][(_ax+30)/30] != 'X')
        {
            _ax += 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,_ax,_ay);
            a=1;
        }
        if (m[_ay/30][(_ax+30)/30] == 'X')
        {
            a=0;
            _ay=0;
        }
    }    if(d == 0)
    {
        if (m[(_ay-30)/30][_ax/30] != 'X')
        {
            _ay -= 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,_ax,_ay);
            a=1;
        }
        if (m[(_ay-30)/30][_ax/30] == 'X')
        {
            a=0;
            _ax=0;
        }
    }    if(d == 2)
    {
        if (m[(_ay+30)/30][_ax/30] != 'X')
        {
            _ay += 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,_ax,_ay);
            a=1;
        }
        if (m[(_ay+30)/30][_ax/30] == 'X')
        {
            a=0;
            _ax=0;
        }
    }

}


class enemigo
{
    private:
        BITMAP *enemigobmp;
        BITMAP *enemigom;
        int fdir;
        int vidaenemigo;
        int _x,_y;
        int _a,a_x,a_y,fd;
    public:
        enemigo(){};
        enemigo(int x,int y);
        void dibujar_enemigo() const;
        void mover_enemigo();
        void choque_personaje();
        void ataque_enemigo();
        void ataque2();
        void muerte_enemigo();
        int getvida();
        mapa1 mapa;

};

enemigo::enemigo(int x, int y)
{
    _x = x;
    _y = y;
    fdir = rand()%4;
    _a=1;
    vidaenemigo=1;
    enemigom = create_bitmap(30,30);
    enemigobmp = load_bitmap("images/enemigo2.bmp",NULL);
}
int enemigo::getvida()
{
    return vidaenemigo;
}
void enemigo::dibujar_enemigo() const
{
    blit(enemigobmp,enemigom,0,fdir*33,0,0,30,30);
    draw_sprite(buffer,enemigom,_x,_y);

}

void enemigo::choque_personaje()
{
    if((py == a_y && px == a_x) || (a_y == anteriorpy && a_x == anteriorpx))
    {

        play_sample(muertes,250,150,1000,0);

            clear (pacman);
            mapa.dibujar_mapa();

            blit(muertebmp,pacman,0,0,0,0,33,33);
            draw_sprite(buffer,pacman,px,py);
            blit(buffer, screen ,0,0,0,0,1280,600);
            rest(80);

        px = 30*1;
        py = 30*1;
        dir = 4;
        vida --;

    }
}
void enemigo::mover_enemigo()
{
    dibujar_enemigo();
    choque_personaje();
    anterior_x = _x;
    anterior_y = _y;

    if(m[_y/30][_x/30]=='|')
    {
        fdir = rand()%4;
    }

    if(fdir == 2)
    {
        if(m[_y/30][(_x-30)/30] != 'X') _x-=30;
        else fdir =rand()%3;
    }
    if(fdir == 0)
    {
        if(m[_y/30][(_x+30)/30] != 'X') _x+=30;
        else fdir =rand()%3;
    }
    if(fdir == 1)
    {
        if(m[(_y-30)/30][_x/30] != 'X') _y-=30;
        else fdir =rand()%3;
    }
    if(fdir == 3)
    {
        if(m[(_y+30)/30][_x/30] != 'X') _y+=30;
        else fdir =rand()%3;
    }
    if(_x <= -30) _x =870;
        else if(_x>= 870) _x =-30;

}
void enemigo::ataque2()
{
    if((py == _y || px == _x) && (_a==1) )
    {
        a_x=_x;
        a_y=_y;
        fd=fdir;
    }
}
void enemigo::ataque_enemigo()
{

    if(fd == 2)
    {
        if (m[a_y/30][(a_x-30)/30] != 'X')
        {
            a_x -= 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,a_x,a_y);
            _a=0;
        }
        if (m[a_y/30][(a_x-30)/30] == 'X')
        {
            _a=1;
            a_y=0;
        }
    }
    if(fd == 0)
    {
        if (m[a_y/30][(a_x+30)/30] != 'X')
        {
            a_x += 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,a_x,a_y);
            _a=0;
        }
        if (m[a_y/30][(a_x+30)/30] == 'X')
        {
            _a=1;
            a_y=0;
        }
    }    if(fd == 1)
    {
        if (m[(a_y-30)/30][a_x/30] != 'X')
        {
            a_y -= 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,a_x,a_y);
            _a=0;
        }
        if (m[(a_y-30)/30][a_x/30] == 'X')
        {
            _a=1;
            a_x=0;
        }
    }    if(fd == 3)
    {
        if (m[(a_y+30)/30][a_x/30] != 'X')
        {
            a_y += 30;
            blit(atabmp,ataqueb,0,0,0,0,33,33);
            draw_sprite(buffer,ataqueb,a_x,a_y);
            _a=0;
        }
        if (m[(a_y+30)/30][a_x/30] == 'X')
        {
            _a=1;
            a_x=0;
        }
    }
}
void enemigo::muerte_enemigo()
{

    if((ay == _y && ax == _x)  || (_ay == _y && _ax == _x))
    {

        play_sample(muertes,250,150,1000,0);

            mapa.dibujar_mapa();

            blit(muertebmp,enemigom,0,0,0,0,33,33);//carga la imagen sobre el buffer pacman
            draw_sprite(buffer,enemigom,_x,_y);
            blit(buffer, screen ,0,0,0,0,1280,600);
            rest(80);

        _x = 0;
        _y = 0;
        vidaenemigo--;
    }
}

int main()
{

    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280, 600 , 0, 0);

    //inicializa la musica en allegro
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
        {
            allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
            return 1;
        }
    // ajuste de volumen
    set_volume(70, 70);//cuanto se oye a la izquierdsa y a la derecha

    intro = load_wav("music/start.wav");
    sirenafantasma = load_wav("music/sirene.wav");
    muertes = load_wav("music/muerte.wav");

    buffer = create_bitmap(1280,600); //870 570
    pacman = create_bitmap(33,33);
    complemento = create_bitmap(400,600);
    vid =create_bitmap(33,33);
    ataqueb = create_bitmap(33,33);

    atabmp = load_bitmap("images/ataque.bmp",NULL);
    roca = load_bitmap("images/tile2.bmp",NULL);
    pacbmp =load_bitmap("images/tank2.bmp", NULL);
    comida = load_bitmap("images/Comida.bmp",NULL);
    muertebmp = load_bitmap("images/muerte1.bmp",NULL);
    combmp =load_bitmap("images/complemento.bmp",NULL);
    vidas = load_bitmap("images/vidas.bmp",NULL);

    mapa1 mapa;
    enemigo A1(30*1,30*18) ;
    enemigo A2(30*27,30*1) ;
    enemigo A3(30*14,30*11) ;
    enemigo A4(30*27,30*18) ;
    enemigo A5(30*27,30*18);
    personaje1 personaje;
    personaje2 personaje3;



    play_sample(intro,200,150,1000,0); // volumen,sonido,,velocidad a la que se reproduce,distribucion 1000 es punto medio,para que no se repita
    rest(4000);

    play_sample(sirenafantasma,150,150,1000,1);

    while (!key[KEY_ESC] && mapa.game_over())
    {
        if(A1.getvida()==0 && A2.getvida()==0 && A3.getvida()==0 && A4.getvida()==0) return false;

        personaje.mover_personaje();
        mapa.dibujar_mapa();
        personaje.dibujar_personaje();
        personaje.ataque();
        personaje.ataque1();
        personaje3.dibujar_personaje();
        personaje3.mover_personaje();
        A1.mover_enemigo();
        A2.mover_enemigo();
        A4.mover_enemigo();
        A3.mover_enemigo();
        personaje3.ataque();
        personaje3.ataque1();
        A1.ataque2();
        A1.ataque_enemigo();
        A2.ataque2();
        A2.ataque_enemigo();
        A4.ataque2();
        A4.ataque_enemigo();
        A3.ataque2();
        A3.ataque_enemigo();
        A1.muerte_enemigo();
        A2.muerte_enemigo();
        A3.muerte_enemigo();
        A4.muerte_enemigo();

        mapa.pantalla();
        rest(80); // da tiempo para que se ejecute son 70 milisengundos

        mapa.pantalla();
        rest(70);

    }
    return 0;
}
END_OF_MAIN();
