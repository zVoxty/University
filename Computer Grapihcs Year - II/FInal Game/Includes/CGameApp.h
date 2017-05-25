#ifndef _CGAMEAPP_H_
#define _CGAMEAPP_H_
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_W 0x57
#define NUMBER_OF_CAR 6
#define NUMBER_OF_TRAIN 2

#include "Main.h"
#include "CTimer.h"
#include "CPlayer.h"
#include "BackBuffer.h"
#include "ImageFile.h"
#include "ResizeEngine.h"
#include "Street.h"
#include "Car.h"
#include <deque>
#include "Railroad.h"
#include <time.h>
#include "Train.h"
#include "Lives.h"
#include "../Shield.h"
#include "../Coin.h"

class CGameApp
{
public:
	CGameApp();
	virtual ~CGameApp();

	
	LRESULT	 DisplayWndProc( HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam );
	bool		InitInstance( LPCTSTR lpCmdLine, int iCmdShow );
	int		 BeginGame( );
	bool		ShutDown( );

public: // Public variables

	ULONG				   m_nViewWidth;	   // Width of render viewport
	ULONG				   m_nViewHeight;	  // Height of render viewport
	
private:
	
	int			invincibleTime;
	void		Logic();
	bool		BuildObjects	  ( );
	void		ReleaseObjects	( );
	void		FrameAdvance	  ( );
	bool		CreateDisplay	 ( );
	void		ChangeDevice	  ( );
	void		SetupGameState	( );
	void		AnimateObjects	( );
	void		DrawObjects	   ( );
	void		ProcessInput	  ( );
	void        Edge(CPlayer& player);
	void        Car_Street();
	void        UpdateGame(CPlayer& player,Street& street,Railroad& raiload);
	void        RandomDraw(Street& street, Railroad& raiload);
	void        collision(CPlayer*, Train*);
	void        collision2(CPlayer*, Car*);
	void        collision3(CPlayer*, Shield*);
	void        collision4(CPlayer*, Coin*);
	void        Draw_statusP1();
	void        Draw_statusP2();
	void		Draw_FPS();
	void		GameOver(const char * imagePath);

	static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

	//-------------------------------------------------------------------------
	// Private Variables For This Class
	//-------------------------------------------------------------------------
	CTimer				  m_Timer;			// Game timer
	ULONG				   m_LastFrameRate;	// Used for making sure we update only when fps changes.
	
	HWND					m_hWnd;			 // Main window HWND
	HICON				   m_hIcon;			// Window Icon
	HMENU				   m_hMenu;			// Window Menu
	
	bool					m_bActive;		  // Is the application active ?
	CImageFile				Intro;
	ULONG				   m_nViewX;		   // X Position of render viewport
	ULONG				   m_nViewY;		   // Y Position of render viewport


	POINT				   m_OldCursorPos;	 // Old cursor position for tracking
	HINSTANCE				m_hInstance;

	CResizableImage			m_imgBackground;

	BackBuffer*				m_pBBuffer;
	CPlayer*				m_pPlayer;
	CPlayer*				m_pPlayerTwo;
	Street*                 m_Street;
	Railroad*               m_Railroad;
	Car*                 	m_Car[NUMBER_OF_CAR];
	Train*                  m_Train[NUMBER_OF_TRAIN];
	Shield*					shield;
	Coin*					coin;
	
};

#endif 