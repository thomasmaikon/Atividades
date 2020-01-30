#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define HEIGHT 960 // altura
#define WIDTH 540 // largura
#define MAX_LETTER_FIELD 3
#define MAX_LETTER 5 // maximo de cartas que eu vou ler do arquivo .csv
#define SIZE_NAME_DECK 50 // tamanho do nome de um deck
#define SIZE_NAME_LETTER 30 // tamanho do nome de uma carta
#define ERRO 0 // tomar cuidado, anteriormente estava retornando -1
#define SUCCESSFUL 1 // 
#define IMAGE_SIZE_X 240
#define IMAGE_SIZE_Y 393
#define INIT_HAND_CARD 5
#define INIT_PLAYER_1 


typedef struct
{
	char name[SIZE_NAME_LETTER];
	char defensive_name[SIZE_NAME_LETTER];
	int attack;
	int defense;
	char mode[SIZE_NAME_LETTER];
}tLetter;

typedef struct
{
	int end;
	char  name[SIZE_NAME_DECK];
	tLetter letter[MAX_LETTER];
}tDeck;

typedef struct sCard_hand
{
	tLetter letter;
	struct sCard_hand* previous;
	struct sCard_hand* next;
}tCard_hand;

typedef struct
{
	int start;
	int end;
	tLetter letter[MAX_LETTER_FIELD];
}tField;

typedef struct
{
	int  life; 
	char  name[SIZE_NAME_DECK];
	int qtd_hand_card;
	tCard_hand* hand;// lista duplamente encadeada para cartas na mao
	tField field; // fila para os monstros em campo
	tDeck deck; // pilha do meu baralho
}tPlayer;

// ======================================Funcoes DE FILAS===================================
void start(tField* field)
{
	field->start = -1;
	field->end = -1;
}

tLetter get_letter(char* name,char* defensive,int attack,int defense)
{
		tLetter letter;
		strcpy(letter.name,name);
		strcpy(letter.defensive_name,defensive);
		letter.attack = attack;
		letter.defense = defense;
		
		return letter;
}

int insert_letter(tField* field, tLetter letter)
{
	int position = (field->end+1) % MAX_LETTER_FIELD;
	
	if(position == field->start)
	{
		fprintf(stderr,"\nFila cheia\n");
		return ERRO;
	}
	
		fprintf(stderr,"\nInserindo Carta\n");
	
	if(field->start == -1)
	{
		field->start += 1;
	}
	
	field->end = position;
	field->letter[field->end] = letter;
	return SUCCESSFUL;
}
// ======================================Funcoes DE pilha===================================
void set_deck(char* nome,tDeck* deck)
{

	FILE* file = fopen(nome,"r");
	if(!file){
		fprintf(stderr,"Falaha ao tentar ler Deck:%s",nome);
	}else{
	
		int line_position = 0;
    	char line[100];
    
    	char name[SIZE_NAME_LETTER];
    	char defense_name[SIZE_NAME_LETTER];
    	int attack;
    	int defense;
    
		fgets(line,100,file);
		do{
		
			sscanf(strtok(line,";"),"%s",name);
			
			sscanf(strtok(NULL,";"),"%s",defense_name);
		
			sscanf(strtok(NULL,";"),"%d",&attack);
	
			sscanf(strtok(NULL,";"),"%d",&defense);
	
			++line_position;
			fgets(line,100,file);	

			add_stack(deck,get_letter(name,defense_name,attack,defense));	
		}while(line_position < MAX_LETTER );		
	}	
}

void start_stack(tDeck* deck)
{
	deck->end = -1;
}

int add_stack(tDeck* deck, tLetter letter)
{
	if(deck->end == MAX_LETTER)
	{
		fprintf(stderr,"Pilha cheia");
		return ERRO;
	}
	
	deck->end = deck->end+1;
	deck->letter[deck->end] = letter;
	return 1;
}

int remove_stack(tDeck* deck)
{
	if(deck->end == -1)
	{
		fprintf(stderr,"Erro, pilha vasia");
		return ERRO;
	}
	deck->end = deck->end-1;
	return SUCCESSFUL;
}
// ======================================Funcoes DE Lista duplamente encadeada ===================================
tCard_hand* get_card_hand(tLetter letter)
{
	tCard_hand* New = (tCard_hand*)calloc(1,sizeof(tCard_hand));
	
	New->letter = letter;
	New->next = NULL;
	New->previous = NULL;
	
	return New;
}

void add_hand_card(tCard_hand** hand,tLetter letter)
{
	tCard_hand* p = *hand;
	tCard_hand* New = get_card_hand(letter);
	
	if(*hand == NULL)
	{
		*hand = New;
	}
	else
	{
		while(p->next != NULL)
		{	
			p = p->next;
		}
		p->next = New;
		p->next->previous = p;
	}
}

void remove_hand_card(tCard_hand** hand,tCard_hand* card)
{
	tCard_hand* p = *hand;
	

	while(p != card)
	{
		fprintf(stderr,"\nProcurando Carta ...");
		p = p->next;
	}
	if(p == *hand)
	{
		*hand = p->next;	
	}else
	{
		if(p->next != NULL)
		{
		p->next->previous = p->previous;
		}
	
		if(p->previous != NULL)
		{
			p->previous->next = p->next;
		}
	}
	
	
	
}

// ======================================Funcoes DE JANELAS===================================
ALLEGRO_DISPLAY* window(ALLEGRO_DISPLAY *home_screen,int x,int y)
{
	if (!al_init())
  	{
    	fprintf(stderr, "Falha ao inicializar a Allegro.\n");
 	}
 
	home_screen = al_create_display(x, y);
	if(!home_screen)
	 {
		fprintf(stderr,"Falha ao abrir janela 'home_screen' !!\n");
	 }
	
	if(!al_init_image_addon())
  	{
  		fprintf(stderr,"Problema no addon !!\n");
  	}
  	
  	if(!al_install_mouse())
	{
		fprintf(stderr,"Problema ao adicionar mouse !!\n");
  		al_destroy_display(home_screen);
	}
  	
	  //SO PODE SETAR CURSOR SE TIVER INICIALIZADO A JANELA
  	if (!al_set_system_mouse_cursor(home_screen, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
  	{
   		fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
    	al_destroy_display(home_screen);
  	} 
	 return home_screen;
}

int verifica_bitmap(ALLEGRO_BITMAP* bitmap,char* img){
	if(!bitmap){
		fprintf(stderr,"\nA imagem nao Abre %s",img);
		return -1;
	}
	return SUCCESSFUL;
}
 
int home(ALLEGRO_DISPLAY* home_screen){
	  
  	
  	ALLEGRO_BITMAP *image_home_screen 	= NULL;
  	ALLEGRO_BITMAP *image_play_home 	= NULL;
    ALLEGRO_EVENT_QUEUE *queue 			= NULL;
	int play = 0;
    
  	
  	al_set_window_title(home_screen,"Yu-Gi-Oh!");
  	
	 
  	image_home_screen  = al_load_bitmap("bg.jpg");
	verifica_bitmap(image_home_screen,"image_home_screen");
	 
  	image_play_home = al_load_bitmap("play.png");
 	verifica_bitmap(image_play_home,"image_play_home");
	 
  	
	queue = al_create_event_queue();
	if(!queue)
	{
		fprintf(stderr,"Falha ao tentar criar uma Fila de eventos 'queue'");
		al_destroy_bitmap(image_play_home);
		al_destroy_bitmap(image_home_screen);
		al_destroy_display(home_screen);
  		return -1;	 	
	}
	
	//coloca na fila as acoes do mouse
	al_register_event_source(queue,al_get_mouse_event_source());

 	al_draw_bitmap(image_home_screen ,0, 0, 0);
  	al_draw_bitmap(image_play_home ,104, 386, 0);
 
	
	while(!play)
	{
			while(!al_is_event_queue_empty(queue))
			{
				ALLEGRO_EVENT event;
				al_wait_for_event(queue, &event);
				
				if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
				{
					if(event.mouse.x >=104  && event.mouse.x <=(104 + 75) && event.mouse.y >=386  && event.mouse.y <= (386+75))
					{
						
						play = 1;
					}
					
				}
			}
			 	al_flip_display();
	}
 	al_destroy_bitmap(image_play_home);
	al_destroy_bitmap(image_home_screen);
	al_destroy_event_queue(queue);
	al_clear_to_color(al_map_rgb(0, 0, 0));
  	return SUCCESSFUL;
}

int Deck(ALLEGRO_DISPLAY* home_screen,tDeck* deck)
{
	ALLEGRO_EVENT_QUEUE *queue 	= NULL;
	ALLEGRO_BITMAP* logo 		= NULL;
	ALLEGRO_BITMAP* deck1 		= NULL;
	ALLEGRO_BITMAP* deck2 		= NULL;
	ALLEGRO_BITMAP* deck3 		= NULL;
	ALLEGRO_BITMAP* deck4 		= NULL;
	
	int play=0;
  	
	  //SO PODE SETAR CURSOR SE TIVER INICIALIZADO A JANELA
  	
	logo  = al_load_bitmap("logo.jpg");
	verifica_bitmap(logo,"logo");
	
	deck1  = al_load_bitmap("kaiba.png");
	verifica_bitmap(deck1,"deck1");
	 
	deck2  = al_load_bitmap("yugi.png");
	verifica_bitmap(deck2,"deck2");
	 
	deck3  = al_load_bitmap("joey.png");
	verifica_bitmap(deck3,"deck3");
	 
	deck4  = al_load_bitmap("marik.png");
	verifica_bitmap(deck4,"deck4");
	 
	al_set_window_title(home_screen,"Yu-Gi-Oh! -> SELECIONE O DECK REFERENTE AO PERSSONAGEM");
  	
	queue = al_create_event_queue();
	if(!queue)
	{
		fprintf(stderr,"Falha ao tentar criar uma Fila de eventos 'queue'");
		al_destroy_display(home_screen);
  		return -1;	 	
	}
	
	//coloca na fila as acoes do mouse
	al_register_event_source(queue,al_get_mouse_event_source());
  	
  	al_draw_bitmap(logo,0,394,0);
	al_draw_bitmap(deck1,0,0,0);
	al_draw_bitmap(deck2,IMAGE_SIZE_X,0,0);
	al_draw_bitmap(deck3,2*IMAGE_SIZE_X,0,0);
	al_draw_bitmap(deck4,3*IMAGE_SIZE_X,0,0);
	al_flip_display();
	  
	 while(!play)
	{
			while(!al_is_event_queue_empty(queue))
			{
				ALLEGRO_EVENT event;
				al_wait_for_event(queue, &event);
				
				if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
				{
					if(event.mouse.x >=0  && event.mouse.x <=IMAGE_SIZE_X && event.mouse.y >=0  && event.mouse.y <= IMAGE_SIZE_Y)
					{
						play = 1;
						strcpy(deck->name,"kaiba");
						set_deck("test.csv",deck);
						
					}else if(event.mouse.x >IMAGE_SIZE_X && event.mouse.x <= 2*IMAGE_SIZE_X && event.mouse.y >=0  && event.mouse.y <= IMAGE_SIZE_Y)
					{
						play = 1;
						strcpy(deck->name,"yugi");
						set_deck("yugi.csv",deck);
					}else if(event.mouse.x >2*IMAGE_SIZE_X && event.mouse.x <= 3*IMAGE_SIZE_X && event.mouse.y >=0  && event.mouse.y <= IMAGE_SIZE_Y)
					{
						play = 1;
						strcpy(deck->name,"joey");
						set_deck("joey.csv",deck);
					}else if(event.mouse.x >3*IMAGE_SIZE_X && event.mouse.x <= 4*IMAGE_SIZE_X && event.mouse.y >=0  && event.mouse.y <= IMAGE_SIZE_Y)
					{
						play = 1;
						strcpy(deck->name,"marik");
						set_deck("marik.csv",deck);
					}
					
				}
			}
		 	al_flip_display();
	}

	al_destroy_bitmap(deck1);
	al_destroy_bitmap(deck2);
	al_destroy_bitmap(deck3);
	al_destroy_bitmap(deck4);
	al_destroy_bitmap(logo);
	al_destroy_event_queue(queue);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	return SUCCESSFUL;
}


//======================================FUNCAO GAME===================================
void init_game(tPlayer* player,tDeck deck)
{
	player->life = 4000;
	player->deck = deck;
	player->qtd_hand_card = INIT_HAND_CARD;
}

void start_hand(tPlayer* player)
{
	player->hand = NULL;
	
	int i;
	for(i=0;i< INIT_HAND_CARD;++i)
	{
		add_hand_card(&player->hand,player->deck.letter[i]);
		remove_stack(&player->deck);
	}
	
}

float space_cards(tPlayer player, float space)
{
		ALLEGRO_BITMAP* img = NULL;
	
		img = al_load_bitmap(player.hand->letter.name);
		verifica_bitmap(img,"img");
	
		float range = al_get_bitmap_width(img);
		float x;
		x = (space / player.qtd_hand_card)- range;
		return x;
}

void display_hand_card(tPlayer player, float x, float y)
{
	ALLEGRO_BITMAP* img = NULL;
	int i=0;
	int dist = space_cards(player,520);
	
	while(player.hand != NULL)
	{
		img = al_load_bitmap(player.hand->letter.name);
		verifica_bitmap(img,"img");
		al_draw_bitmap(img,x + i*dist,y,0);	
		player.hand = player.hand->next;
		++i;
		x=x+75;
	}
	
	fprintf(stderr,"\n Cartas Da mao exibidas");
	// falta configurar o espacamento das cartas para poder ler a carta e para poder deixal-as organizado
}

tCard_hand* select_card(tPlayer player,float space_card,float position_x,float position_y)
{
	
	ALLEGRO_EVENT_QUEUE *queue 	= NULL;
	ALLEGRO_BITMAP* img = NULL;
	
	img = al_load_bitmap(player.hand->letter.name);
	verifica_bitmap(img,"img");
	
	int range_x = al_get_bitmap_width(img);
	int range_y = al_get_bitmap_height(img);
	int select=0;
	al_destroy_bitmap(img);
	
	queue = al_create_event_queue();
	if(!queue)
	{
		fprintf(stderr,"Falha ao tentar criar uma Fila de eventos 'queue'");
	}
	
	//coloca na fila as acoes do mouse
	al_register_event_source(queue,al_get_mouse_event_source());
	int i=0;
	while(!select)
	{
			while(!al_is_event_queue_empty(queue))
			{
				ALLEGRO_EVENT event;
				al_wait_for_event(queue, &event);
				
				if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
				{
					if(event.mouse.x >=position_x+75*i+(space_card*i)  && event.mouse.x <=position_x+75*(i+1)+(space_card*i) && event.mouse.y >=position_y  && event.mouse.y <=position_y+range_y)           
					{
						int card=0;
						while(card != i)
						{
							++card;
							player.hand = player.hand->next;
						}
						select = 1;
					}
				}
				
				i = (i+1) % player.qtd_hand_card;
			}
		 	al_flip_display();
	}
	fprintf(stderr,"\n Carta Selecionada");
	al_destroy_event_queue(queue);
  	return player.hand ;
}

void mode(ALLEGRO_BITMAP* card, int x, int y)
{
	
}

void monster_field(tField field, int x, int y)
{
	ALLEGRO_BITMAP* image_monster = NULL;
	
	int i=0;
	while(i<=field.end)
	{
	
			fprintf(stderr,"\nExibindo Carta");
			if(!strcmp(field.letter[i].mode,"attack"))
			{
				image_monster = al_load_bitmap(field.letter[i].name);
				verifica_bitmap(image_monster,"image_monster");
				al_draw_bitmap(image_monster,x + i*100,y,0);
				al_flip_display();
				
			}else if(!strcmp(field.letter[i].mode,"defensive"))
			{
				image_monster = al_load_bitmap(field.letter[i].defensive_name);
				verifica_bitmap(image_monster,"image_monster");
				al_draw_bitmap(image_monster,x + i*100,y,0);
				al_flip_display();
			}
	++i;
	}
}

void window_game_field()
{
	ALLEGRO_BITMAP* game = NULL;
	game = al_load_bitmap("game.jpg");
	verifica_bitmap(game,"game");
	al_draw_bitmap(game,0,0,0);	
}

int select_mode(tCard_hand* hand, tPlayer* player)
{
	ALLEGRO_BITMAP* mode_attack = NULL;
	ALLEGRO_BITMAP* mode_defensive = NULL;
	ALLEGRO_EVENT_QUEUE *queue 	= NULL;
	
	mode_attack = al_load_bitmap("attack.png");
	verifica_bitmap(mode_attack,"mode_attack");
	al_draw_bitmap(mode_attack,105,140,0);
	int attack_x = al_get_bitmap_width(mode_attack);
	int attack_y = al_get_bitmap_height(mode_attack);
	
	
	mode_defensive = al_load_bitmap("defensive.jpg");
	verifica_bitmap(mode_defensive,"mode_defensive");
	al_draw_bitmap(mode_defensive,805,140,0);
	int defensive_x = al_get_bitmap_width(mode_defensive);
	int defensive_y = al_get_bitmap_height(mode_defensive);
	
	
	int select = 0;
	queue = al_create_event_queue();
	if(!queue)
	{
		fprintf(stderr,"Falha ao tentar criar uma Fila de eventos 'queue'");
	}
	
	al_flip_display();
	
	//coloca na fila as acoes do mouse
	al_register_event_source(queue,al_get_mouse_event_source());
	while(!select)
	{
			while(!al_is_event_queue_empty(queue))
			{
				ALLEGRO_EVENT event;
				al_wait_for_event(queue, &event);
				
				if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
				{
					if(event.mouse.x >=105  && event.mouse.x <=105+attack_x && event.mouse.y >=140  && event.mouse.y <=140+attack_y)           
					{
						if(insert_letter(&player->field,hand->letter)){
							remove_hand_card(&player->hand,hand);
							player->qtd_hand_card -=1;
							strcpy(player->field.letter[player->field.end].mode,"attack");
							select = 1;
						}else{
							return ERRO;
						}
					}else if(event.mouse.x >=805  && event.mouse.x <=805+defensive_x && event.mouse.y >=140  && event.mouse.y <=140+defensive_y)
					{
						if(insert_letter(&player->field,hand->letter)){
							remove_hand_card(&player->hand,hand);
							player->qtd_hand_card -=1;
							strcpy(player->field.letter[player->field.end].mode,"defensive");
							select = 1;	
						}else{
							return ERRO;
						}
					}
				}
				
		
			}
		 	al_flip_display();
	}
	al_destroy_event_queue(queue);
	return SUCCESSFUL;
}

int battle(tPlayer* player)
{
	
}
// ======================================FUNCAO MAIN===================================

int main(void)
{
	ALLEGRO_DISPLAY *home_screen = NULL; // janela DEFAULT para tudo, o que mudamos é apenas o conteudo que será apresentado
	home_screen = window(home_screen,HEIGHT,WIDTH);
	
	tDeck deck1,deck2;
	start_stack(&deck1);
	start_stack(&deck2);

	int play = home(home_screen);
	int p1 = Deck(home_screen,&deck1);
	int p2 = Deck(home_screen,&deck2);
	int round = 0;
	tPlayer	player[2];
	init_game(&player[0],deck1);
	init_game(&player[1],deck2);
	
	al_destroy_display(home_screen);
	home_screen = window(home_screen,HEIGHT,WIDTH);
	
		int position_player1[2] = {246,30}; // posicao aonde ficam as cartas do jogador 
	 	int position_player2[2] = {246,372};
	 	
		int space_card = 520; // espacamento entre as cartas
	
	start_hand(&player[0]);// inicia a mao com 5 cartas;
	start_hand(&player[1]);
	
	start(&player[0].field); // inicializo a fila de monstros em campo de cada jogador
	start(&player[1].field);
	
	
	window_game_field();
	
	ALLEGRO_BITMAP* test = NULL;
	
	while(1){
	
	display_hand_card(player[0],position_player1[0],position_player1[1]);// Exibe cartas de cada jogador da mao
	display_hand_card(player[1],position_player2[0],position_player2[1]);
	

// Renderiza a tela com as cartas em questao	
	select_mode(select_card(player[0],space_cards(player[0],space_card),position_player1[0],position_player1[1]),&player[0]); //Seleciona carta e define seu modo
	window_game_field();
	monster_field(player[0].field,position_player1[0],position_player1[1]+100);
	monster_field(player[1].field,position_player2[0],position_player2[1]-100);
	display_hand_card(player[0],position_player1[0],position_player1[1]);// Exibe cartas de cada jogador da mao
	display_hand_card(player[1],position_player2[0],position_player2[1]);
	al_flip_display();
	
		if(round > 1){
			//battle(&player[0]);	
		}
		++round;
	
	select_mode(select_card(player[1],space_cards(player[1],space_card),position_player2[0],position_player2[1]),&player[1]);
	window_game_field();
	monster_field(player[1].field,position_player2[0],position_player2[1]-100);
	monster_field(player[0].field,position_player1[0],position_player1[1]+100);
	display_hand_card(player[1],position_player2[0],position_player2[1]);
	al_flip_display();
	
	
		if(round > 1){
			//battle(&player[1]);	
		}
		++round;
	
	
	}
	
	
	while(1);
}
