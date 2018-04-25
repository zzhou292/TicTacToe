//***************************************************
//ECE 210 Final Project
//Jason Zhou; Dawanit Satitsumpun; Avinash Narisetty
//**********GLOBAL VARIABLE**************************
#include "lab_buttons.h"
#include "ece210_api.h"
#include "Invader.black.h"

#define LCD_SIZE_X 240              //X size of LCD screen in pixels
#define LCD_SIZE_Y 320              //Y size of LCD screen in pixels

#define	LCD_INIT_X			LCD_HALF_SIZE_X - INVADER_WIDTH_PXL/2		// Start image in the center of the screen X
#define	LCD_INIT_Y			LCD_HALF_SIZE_Y - INVADER_HEIGHT_PXL/2	// Start image in the center of the screen Y
#define LCD_MAX_DRAW_X	LCD_SIZE_X-1	// 0 to LCD_MAX_DRAW_X is = LCD_SIZE_X
#define LCD_MAX_DRAW_Y	LCD_SIZE_Y-1	// 0 to LCD_MAX_DRAW_Y is = LCD_SIZE_Y
#define LCD_HALF_SIZE_X	LCD_SIZE_X/2	// X center of screen in pixels
#define LCD_HALF_SIZE_Y	LCD_SIZE_Y/2	// Y center of screen in pixels


#define LOCAL_ID 0x01
#define REMOTE_ID 0x00
uint32_t character;              //if character==0, then I'm "X"
                                 //if character==1, then I'm "O"
//**********FUNCTION DECLARATION*********************
void start();

//***************************************************
int main(void)
{
    //main method starts
    ece210_initialize_board();  //start initializing the board
    start();        //call method start
}

void start()
{
    //***********LOCAL VARIABLE*************************
    uint32_t ready = 0;
    //**************************************************
    //display message first
    
    ece210_lcd_add_msg("Welcome to TIC-TAC-TOE", TERMINAL_ALIGN_CENTER, LCD_COLOR_RED);             
    ece210_lcd_add_msg("Press Any Key to Start", TERMINAL_ALIGN_CENTER, LCD_COLOR_BLUE);
    ece210_lcd_add_msg("Jason Zhou; Dawanit Satitsumpun; Avinash Narisetty", TERMINAL_ALIGN_CENTER, LCD_COLOR_YELLOW);
    
    
      ece210_lcd_draw_image(LCD_INIT_X,INVADER_WIDTH_PXL,LCD_INIT_Y-50 ,INVADER_HEIGHT_PXL, invader_bitmap,LCD_COLOR_RED, LCD_COLOR_BLACK);    //display the logo of the TIC-TAC-TOE
    
    //initialize wireless connection
    ece210_wireless_init(LOCAL_ID, REMOTE_ID);
    
    while(!ready){
        //when the board detects that a key is pressed, start play() method
        //which will call up the "x" and "o" selection page
    
        if(ece210_wireless_data_avaiable()) {
            ready = ece210_wireless_get();
            if(ready) {
               
            }
        }
        
        if(AlertButtons)
        {
            AlertButtons=false; //set AlertButton to false
            ready = 1;
            ece210_wireless_send(1);
            
        }
    }
}


