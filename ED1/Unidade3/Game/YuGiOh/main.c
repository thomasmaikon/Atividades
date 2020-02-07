#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define HEIGHT 960 // altura
#define WIDTH 540 // largura
#define MAX_LETTER_FIELD 3
#define MAX_LETTER 8 // maximo de cartas que eu vou ler do arquivo .csv
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

typedef struct sLinked_list
{
	tLetter letter;
	struct sLinked_list* previous;
	struct sLinked_list* next;
}tLinked_list;

typedef struct
{
	int  life; 
	char  name[SIZE_NAME_DECK];
	int qtd_hand_card;
	int qtd_field_card;
	tLinked_list* hand;// lista duplamente encadeada para cartas na mao
	tLinked_list* field; // lista de campos
	tDeck deck; // pilha do meu baralho
	
	float position[2];
}tPlayer;

tLetter get_letter(char* name,char* defensive,int attack,int defense)
{
		tLetter letter;
		strcpy(letter.name,name);
		strcpy(letter.defensive_name,defensive);
		letter.attack = attack;
		letter.defense = defense;
		
		return letter;
}

// ======================================Funcoes DE pilha===================================
void start_stack(tDeck* deck){
	deck->end = -1;
}
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
			//fprintf(stderr,"\n -> Carta inserida no Deck:%s",name)
			sscanf(strtok(NULL,";"),"%s",defense_name);
		
			sscanf(strtok(NULL,";"),"%d",&attack);
	
			sscanf(strtok(NULL,";"),"%d",&defense);
	
			++line_position;
			fgets(line,100,file);	

			add_stack(deck,get_letter(name,defense_name,attack,defense));	
		}while(line_position < MAX_LETTER );		
	}	
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
tLinked_list* get_Linked_list(tLetter letter)
{
	tLinked_list* New = (tLinked_list*)calloc(1,sizeof(tLinked_list));
	
	New->letter = letter;
	New->next = NULL;
	New->previous = NULL;
	
	return New;
}

void add_list_card(tLinked_list** list,tLetter letter)
{
	tLinked_list* p = *list;
	tLinked_list* New = get_Linked_list(letter);
	fprintf(stderr,"\n Adicionando carta -> %s", letter.name);
	if(*list == NULL)
	{
		*list = New;
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

void remove_list_card(tLinked_list** list,tLinked_list* card)
{
	tLinked_list* p = *list;

	while(p != card)
	{
	//	fprintf(stderr,"\nProcurando Carta ...");
		p = p->next;
	}
	
	//	fprintf(stderr,"\ncarta encontrada: %s carta esperada :%s",p->letter.name,card->letter.name );
	if(p == *list)
	{
		*list = p->next;	
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
void start(tPlayer* player,tDeck deck,float px,float py)
{
	player->hand = NULL;
	player->field = NULL;
	player->deck.end = -1;
	player->life = 4000;
	player->deck = deck;
	player->qtd_hand_card = INIT_HAND_CARD;
	player->qtd_field_card = 0;
	player->position[0] = px;
	player->position[1] = py;
	
	int i;

		add_list_card(&player->hand,player->deck.letter[player->deck.end]);
		remove_stack(&player->deck);
		add_list_card(&player->hand,player->deck.letter[player->deck.end]);
		remove_stack(&player->deck);
		add_list_card(&player->hand,player->deck.letter[player->deck.end]);
		remove_stack(&player->deck);
		add_list_card(&player->hand,player->deck.letter[player->deck.end]);
		remove_stack(&player->deck);
		add_list_card(&player->hand,player->deck.letter[player->deck.end]);
		remove_stack(&player->deck);
	
	
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

void display_hand_card(tPlayer player)
{
	ALLEGRO_BITMAP* img = NULL;
	int i=0;
	float x = player.position[0]; 
	float y = player.position[1];
	int dist = space_cards(player,520);
	
	fprintf(stderr,"\n Exibindo as Cartas da Mao:");
	while(player.hand != NULL)
	{
		fprintf(stderr," mao -> %s",player.hand->letter.name);
		img = al_load_bitmap(player.hand->letter.name);
		verifica_bitmap(img,"img");
		al_draw_bitmap(img,x + i*dist,y,0);	
		player.hand = player.hand->next;
		++i;
		x=x+75;
	}
}

tLinked_list* select_card(tPlayer player,float space_card,int adicional)
{

	ALLEGRO_EVENT_QUEUE *queue 	= NULL;
	ALLEGRO_BITMAP* img = NULL;
	
	img = al_load_bitmap(player.hand->letter.name);
	verifica_bitmap(img,"img");
	
	int range_x = al_get_bitmap_width(img); // pega largura e altura de uma imagem
	int range_y = al_get_bitmap_height(img);
	
	float position_x = player.position[0]; // pega a posi��o em que as imagens vao ficar
	float position_y = player.position[1] + adicional;
	
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
	//fprintf(stderr,"\n Carta Selecionada");
	al_destroy_event_queue(queue);
	fprintf(stderr,"\nCarta Selecionada -> %s",player.hand->letter.name);
  	return player.hand ;
}

void monster_field(tPlayer player, int adicional)
{
	fprintf(stderr,"\nExibindo Cartas do Campo:");
	ALLEGRO_BITMAP* image_monster = NULL;

	tLinked_list* field = player.field;

	int i=0;
	int x = player.position[0];
	int y = player.position[1] + adicional;
	
	while(field != NULL)
	{
		fprintf(stderr,"\n ->Carta:%s",field->letter.name);
		if(!strcmp(field->letter.mode,"attack"))
		{
			image_monster = al_load_bitmap(field->letter.name);
			verifica_bitmap(image_monster,"image_monster");
			al_draw_bitmap(image_monster,x + i*150,y,0);
			al_flip_display();
		}else if(!strcmp(field->letter.mode,"defensive"))
		{
			image_monster = al_load_bitmap(field->letter.defensive_name);
			verifica_bitmap(image_monster,"image_monster");
			al_draw_bitmap(image_monster,x + i*150,y+20,0);
			al_flip_display();
		}
	++i;
	field=field->next;
	}
}

void window_game_field()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	ALLEGRO_BITMAP* game = NULL;
	game = al_load_bitmap("game.jpg");
	verifica_bitmap(game,"game");
	al_draw_bitmap(game,0,0,0);	
}

int select_mode(tLinked_list* hand, tPlayer* player)
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
						if(player->qtd_field_card<MAX_LETTER_FIELD){
							strcpy(hand->letter.mode,"attack");
							add_list_card(&player->field,hand->letter);
							remove_list_card(&player->hand,hand);
							player->qtd_hand_card -=1;
							player->qtd_field_card +=1;
							select = 1;
						}else{
							return ERRO;
						}
					}else if(event.mouse.x >=805  && event.mouse.x <=805+defensive_x && event.mouse.y >=140  && event.mouse.y <=140+defensive_y)
					{
						if(player->qtd_field_card<MAX_LETTER_FIELD){
							strcpy(hand->letter.mode,"defensive");
							add_list_card(&player->field,hand->letter);
							remove_list_card(&player->hand,hand);
							player->qtd_hand_card -=1;
							player->qtd_field_card +=1;
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

tLinked_list* select_card_filed(tPlayer player,int adicional)
{
	
	//fprintf(stderr,"\nSelecione sua carta do campo");
	tLetter letter;
	
	ALLEGRO_EVENT_QUEUE* queue 	= NULL;
	ALLEGRO_BITMAP* img = NULL;
	
	img = al_load_bitmap(player.hand->letter.name);
	verifica_bitmap(img,"select_card_field");
	
	int range_x = al_get_bitmap_width(img); // pega largura e altura de uma imagem
	int range_y = al_get_bitmap_height(img);
	
	float position_x = player.position[0]; // pega a posi��o em que as imagens vao ficar
	float position_y = player.position[1] + adicional;
	
	int select=0;
	
	
	queue = al_create_event_queue();
	if(!queue)
	{
		fprintf(stderr,"Falha ao tentar criar uma Fila de eventos 'queue'");
	}
	
	if(player.qtd_field_card >= 1){
		al_register_event_source(queue,al_get_mouse_event_source());
		int i=0;
		while(!select)
		{
				while(!al_is_event_queue_empty(queue))
				{
					ALLEGRO_EVENT event;
					al_wait_for_event(queue, &event);
					
					if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
					{
						if(event.mouse.x >=position_x+75*i+(75*i)  && event.mouse.x <=position_x+75*(i+1)+(75*i) && event.mouse.y >=position_y  && event.mouse.y <=position_y+range_y)           
						{
							int card = 0;
							while(card != i ){
								player.field = player.field->next;
								++card;
							}
							select = 1;
						}
					}
					i = (i+1) % (player.qtd_field_card);
				}
		 		al_flip_display();
		}
	}else{
		return NULL;
	}
	//coloca na fila as acoes do mouse
	
	
	al_destroy_event_queue(queue);
	al_destroy_bitmap(img);
  	return player.field;
}

int battle(tLinked_list* attack,tLinked_list* attacked, tPlayer* atacante, tPlayer* defensor){
	
	int value;

	if(!strcmp(attack->letter.mode,"defensive")){
		
	}else{
		if(attacked != NULL){	
			if(!strcmp(attacked->letter.mode,"defensive")){
				value = attacked->letter.defense;
			}else{
				value = attacked->letter.attack;
			}
			int result = (attack->letter.attack - value);
		//fprintf(stderr,"\n result:%d",result);
			if(result < 0 ){
				remove_list_card(&atacante->field,attack);
				atacante->life = atacante->life + result;
				atacante->qtd_field_card -=1;
			}else if(result > 0){
				remove_list_card(&defensor->field,attacked);
				if(!strcmp(attacked->letter.mode,"defensive")){
					defensor->qtd_field_card -=1;
				}else{
				defensor->life = defensor->life - result;
				defensor->qtd_field_card -=1;	
				}
			}else if(result == 0 ){
				remove_list_card(&atacante->field,attack);
				remove_list_card(&defensor->field,attacked);
				atacante->qtd_field_card -=1;
				defensor->qtd_field_card -=1;
			}
		}else{
		defensor->life = defensor->life - attack->letter.attack;
		}
	}

	fprintf(stderr,"\nVida do jogador q ataca-> %d",atacante->life);
	fprintf(stderr,"\nVida do jogador q defende-> %d",defensor->life);

	return SUCCESSFUL;
}
void add_hand_card(tPlayer* player)
{
	fprintf(stderr,"\n Adicionando carta do deck");
	if(player->deck.end >=0){
		fprintf(stderr,"\n Carta do Deck-> %s",player->deck.letter[player->deck.end].name);
		add_list_card(&player->hand,player->deck.letter[player->deck.end]);
		remove_stack(&player->deck);
		player->qtd_hand_card+=1;
	}
}


tLinked_list* best_letter_field_bot(tPlayer player){
	tLinked_list* p = player.field;
	
	int i;
	for(i=1;i<=player.qtd_field_card;++i){
		if((player.field->letter.attack+player.field->letter.defense) > (p->letter.attack+p->letter.defense))	{
			p = player.field;
		}
		player.field = player.field->next;
	}
	
	return p;
}
tLinked_list* most_letter_field_bot(tPlayer player){
	tLinked_list* p = player.field;
	int i=1;

	while(i<=player.qtd_field_card)
	{
		if((player.field->letter.attack+player.field->letter.defense) < (p->letter.attack+p->letter.defense))	{
			p = player.field;
		}
		++i;
		player.field = player.field->next;
	}
	return p;
}
tLinked_list* select_letter_hand_bot(tPlayer player){
	
	tLinked_list* p = player.hand;
	
	while(player.hand!=NULL){
		if((player.hand->letter.attack+player.hand->letter.defense) > (p->letter.attack+p->letter.defense))
		{
			p = player.hand;
		}
		player.hand = player.hand->next;
	}
	//fprintf(stderr,"\n Peguei a minha melhor carta");
	return p;
}

tLinked_list* remove_letter_hand_bot(tPlayer player,tLinked_list* letter){
	while(player.hand != letter){
		player.hand = player.hand->next;
	}
//	fprintf(stderr,"\n -->Carta encontrada %s",player.hand->letter.name);
	return player.hand;
}

void bot(tPlayer* p1,tPlayer* bot,int round){
	
	add_hand_card(bot);
	
	while(bot->qtd_field_card <3){
		tLinked_list* best = select_letter_hand_bot(*bot);
		tLinked_list* remove = remove_letter_hand_bot(*bot,best);
		if(best->letter.attack >= best->letter.defense){
			strcpy(best->letter.mode,"attack");
			add_list_card(&bot->field,best->letter);
			remove_list_card(&bot->hand,remove);
			bot->qtd_hand_card -=1;
			bot->qtd_field_card+=1;
		}else{
			strcpy(best->letter.mode,"defensive");
			add_list_card(&bot->field,best->letter);
			remove_list_card(&bot->hand,bot->hand);
			bot->qtd_hand_card -=1;
			bot->qtd_field_card+=1;
		}
		//fprintf(stderr,"\nsetando carta do bot");
	}

	if(bot->field != NULL){
			tLinked_list* best = best_letter_field_bot(*bot);
			tLinked_list* most = most_letter_field_bot(*p1);
			
			battle(best,most,bot,p1);
	}
	
}
void mod(tLinked_list* letter){
	
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
						if(!strcmp(letter->letter.mode,"defensive")){
							strcpy(letter->letter.mode,"attack");
						}
						select = 1;
					}else if(event.mouse.x >=805  && event.mouse.x <=805+defensive_x && event.mouse.y >=140  && event.mouse.y <=140+defensive_y)
					{
						if(!strcmp(letter->letter.mode,"attack")){
							strcpy(letter->letter.mode,"defensive");
						}
						select = 1;
					}
				}
			}
		 	al_flip_display();
	}
	al_destroy_event_queue(queue);
}
int escolha(){
	ALLEGRO_EVENT_QUEUE* queue 	= NULL;
	ALLEGRO_BITMAP* escolha = NULL;
	
	escolha = al_load_bitmap("escolha.png");
	verifica_bitmap(escolha,"escolha");
	al_draw_bitmap(escolha ,0, 0, 0);
	int select=0, result = 0;

	queue = al_create_event_queue();
	if(!queue)
	{
		fprintf(stderr,"Falha ao tentar criar uma Fila de eventos 'queue'");
	}
	
		al_register_event_source(queue,al_get_mouse_event_source());
	while(!select)
	{
			while(!al_is_event_queue_empty(queue))
			{
				ALLEGRO_EVENT event;
				al_wait_for_event(queue, &event);
				
				if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{
					if(event.mouse.x >=0  && event.mouse.x <=35 && event.mouse.y >=0 && event.mouse.y <=40)           
					{
						result = 1;
						select = 1;
					}else if (event.mouse.x >=0  && event.mouse.x <=35 && event.mouse.y >=40 && event.mouse.y <=90){
						result =  2;
						select = 1;

					}else if(event.mouse.x >=0  && event.mouse.x <=35 && event.mouse.y >=40 && event.mouse.y <=130){
						result = 3;
						select = 1;
					}
				}
				}
	 		al_flip_display();
	}
	//coloca na fila as acoes do mouse
	al_destroy_event_queue(queue);
	al_destroy_bitmap(escolha);
  	return result;
}

// ======================================FUNCAO MAIN===================================

int main(void)
{
	ALLEGRO_DISPLAY *home_screen = NULL; // janela DEFAULT para tudo, o que mudamos � apenas o conteudo que ser� apresentado
	home_screen = window(home_screen,HEIGHT,WIDTH);
	
	tDeck deck1,deck2;
	start_stack(&deck1);
	start_stack(&deck2);

	int play = home(home_screen);
	int p1 = Deck(home_screen,&deck1);
	int p2 = Deck(home_screen,&deck2);
	int round = 1;
	int space_card = 520; // espacamento para as cartas
	
	tPlayer	player[2];

	start(&player[0],deck1, 246,20);// inicia todas as estrutura de fila e listas encadeadas sendo a mao com 5 elementos;
	start(&player[1],deck2,246,362);

	al_destroy_display(home_screen);
	home_screen = window(home_screen,HEIGHT,WIDTH);
	
	window_game_field();
	
	ALLEGRO_BITMAP* test = NULL;
	int ganhador = 0;
	while(!ganhador){
	
		

// Renderiza a tela com as cartas em questao	
	window_game_field();
	display_hand_card(player[0]);// Exibe cartas de cada jogador da mao
	display_hand_card(player[1]);
	monster_field(player[0],+115);
	monster_field(player[1],-115);
	char opcao = 'e';
	while(opcao != 's'){
		switch (escolha())
		{
			case 1:
				window_game_field();
				display_hand_card(player[0]);// Exibe cartas de cada jogador da mao
				monster_field(player[0],+115);
				monster_field(player[1],-115);
				select_mode(select_card(player[0],space_cards(player[0],space_card),0),&player[0]); //Seleciona carta e define seu modo
				window_game_field();
				display_hand_card(player[0]);// Exibe cartas de cada jogador da mao
				display_hand_card(player[1]);
				monster_field(player[0],+115);
				monster_field(player[1],-115);
				al_flip_display();
			break;
	
			case 2:
				if(round > 1){
					if(player->field != NULL){
					
					window_game_field();
					monster_field(player[0],+115);
					monster_field(player[1],-115);
					
					tLinked_list* atacador = select_card_filed(player[0],+115);
					
					mod(atacador);
					window_game_field();
					display_hand_card(player[0]);// Exibe cartas de cada jogador da mao
					display_hand_card(player[1]);
					monster_field(player[0],+115);
					monster_field(player[1],-115);
					
					tLinked_list* atacado = select_card_filed(player[1],-115);
					
					battle(atacador,atacado,&player[0],&player[1]);	
			
					window_game_field();
					display_hand_card(player[0]);// Exibe cartas de cada jogador da mao
					display_hand_card(player[1]);
					monster_field(player[0],+115);
					monster_field(player[1],-115);
				
					}
				
					al_flip_display();
				}
			break;
				
			case 3:
				opcao = 's';
			break;
		}
	}
		
		++round;
		if(player[0].life <=0 || (player[1].life <= 0)){
			break;
		}
		bot(&player[0],&player[1],round);
	
		window_game_field();
		display_hand_card(player[0]);// Exibe cartas de cada jogador da mao
		display_hand_card(player[1]);
		monster_field(player[0],+115);
		monster_field(player[1],-115);
		al_flip_display();
		
		if(player[0].life <=0 || (player[1].life <= 0)){
			al_clear_to_color(al_map_rgb(0, 0, 0));
			ganhador = 1;
			
		}else{
			add_hand_card(&player[0]);
		}
	}
	
	 
	if( player[0].life <= 0){
		ALLEGRO_BITMAP* lose = NULL;
		lose = al_load_bitmap("lose.png");
		verifica_bitmap(lose,"Lose");
		al_draw_bitmap(lose,WIDTH/4,HEIGHT/4,0);	
	}else{
		ALLEGRO_BITMAP* winner = NULL;
		winner = al_load_bitmap("winner.png");
		verifica_bitmap(winner,"Winner");
		al_draw_bitmap(winner,WIDTH/4,HEIGHT/4,0);
	}
	al_flip_display();

	
	al_rest(10.0);
	
	al_destroy_display(home_screen);
	//free(player);
}
